#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Model.h"
#include "Component.h"

class GameObject
{
public:
	GameObject(Model* model_, glm::vec3 position_ = glm::vec3());
	~GameObject();
	
	void Render(Camera* camera_);
	void Update(const float deltaTime_);


	glm::vec3 GetPosition() const;
	glm::vec3 GetRotation() const;
	float GetAngle() const;
	glm::vec3 GetScale() const;
	std::string GetTag() const;
	bool GetHit() const;

	void SetPosition(glm::vec3 pos_);
	void SetAngle(float angle_);
	void SetRotation(glm::vec3 rotation_);
	void SetScale(glm::vec3 scale_);
	void SetTag(std::string tag_);
	void SetHit(bool hit_, int buttonType_);

	BoundingBox GetBoundingBox();

	template<typename TComponent>
	void AddComponent() {
		
		//TComponent* tComponentPTR = new Component();
		TComponent* tComponentPTR = new TComponent();
		std::cout << "adding component" << tComponentPTR<<"\n";

		//to verify if the component being added is a child of the Component class
		if (dynamic_cast<Component*>(tComponentPTR) == nullptr) {
			Debugger::FatalError("The component being added is not a child of the Component class!", "GameObject.h", __LINE__);
			delete tComponentPTR;
			tComponentPTR = nullptr;

			return;
		}

		
		//to check if the GameObject already has the same component type
		if (GetComponent<TComponent>() != nullptr) {
			Debugger::FatalError("The component being added already exist for this GameObject!", "GameObject.h", __LINE__);
			delete tComponentPTR;
			tComponentPTR = nullptr;

			return;
		}

		componentList.push_back(tComponentPTR);

		tComponentPTR->OnCreate(this);
		std::cout << "Component: " << tComponentPTR << " has been created\n";
	}

	template<typename TComponent>
	Component* GetComponent() {

		std::cout << "entered get component\n";

		if (componentList.size() <= 0) {
			std::cout << "Component list is empty\n";
			return nullptr;
		}

		for (auto element : componentList) {
			std::cout << "entered for loop for get\n";
			
			//if (tComponentPTR == dynamic_cast<TComponent*>(element)) {
			if(dynamic_cast<TComponent*>(element)!=nullptr){
				std::cout << "return tcompptr\n";
				return element;
			}
			else {
				std::cout << "return nullptr\n";
				return nullptr;
			}
		}
	}

	template<typename TComponent>
	void RemoveComponent() {
		std::cout << "entered RemoveComponent\n";

		for (int i = 0; i < componentList.size(); i++) {
			std::cout << "entered for loop for delete\n";

			if (dynamic_cast<TComponent*>(componentList[i])!=nullptr) {
				componentList.erase(componentList.begin() + i);
				std::cout << "Component deleted\n";
			}
		}
	}

private:
	Model* model;
	glm::vec3 position;
	glm::vec3 rotation;
	float angle;
	glm::vec3 scale;
	std::string tag;

	int modelInstance; 

	BoundingBox box;

	bool hit;

	std::vector<Component*> componentList;
};


#endif
