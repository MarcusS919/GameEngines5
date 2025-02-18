#include "GameScene.h"

GameScene::GameScene() : Scene()
{

}

GameScene::~GameScene()
{
	SceneGraph::GetInstance()->OnDestroy();
}

bool GameScene::OnCreate()
{
	/*
	
	Vertex v;
	std::vector<Vertex> vertexList;

	v.position = glm::vec3(-0.5f, 0.5f, 0.0f);
	v.colour = glm::vec3(0.0f, 0.5f, 0.0f);
	vertexList.push_back(v);
		
	v.position = glm::vec3(-0.5f, -0.5f, 0.0f);
	v.colour = glm::vec3(1.0f, 1.0f, 1.0f);
	vertexList.push_back(v);

	v.position = glm::vec3(0.5f, -0.5f, 0.0f);
	vertexList.push_back(v);
	v.colour = glm::vec3(1.0f, 0.0f, 5.0f);

	v.position = glm::vec3(0.5f, 0.5f, 0.0f);
	vertexList.push_back(v);
	v.colour = glm::vec3(1.0f, 0.0f, 0.0f);

	v.position = glm::vec3(0.5f, -0.5f, 0.0f);
	vertexList.push_back(v);
	v.colour = glm::vec3(0.5f, 0.0f, 0.0f);

	v.position = glm::vec3(-0.5f, 0.5f, 0.0f);
	vertexList.push_back(v);
	v.colour = glm::vec3(0.0f, 0.5f, 0.0f);


	Model* model = new Model(ShaderHandler::GetInstance()->GetShader("colourShader"), glm::vec3(0.0f));
	
	model->AddMesh(new Mesh(&vertexList, ShaderHandler::GetInstance()->GetShader("colourShader")));

	shape = new GameObject(model);
	*/
	Debugger::Info("Creating Game Scene ", "GameScene.cpp", __LINE__);

	CoreEngine::GetInstance()->SetCamera(new Camera);
	CoreEngine::GetInstance()->GetCamera()->SetPosition(glm::vec3(0.0f, 0.5f, 4.0f));

	lightSource = new LightSource(glm::vec3(0.0f), 0.0f, 0.0f, glm::vec3(0.0f));
	lightSource->SetPosition(glm::vec3(0.0f, 0.0f, 4.0f));
	lightSource->SetAmbient(0.1f); 
	lightSource->SetDiffuse(0.5f);
	lightSource->SetLightColour(glm::vec3(1.0f, 1.0f, 1.0f));

	CoreEngine::GetInstance()->GetCamera()->AddLightSource(lightSource);

	CollisionHandler::GetInstance()->OnCreate(100.0f);

	//Vertex v;
	//std::vector<Vertex> vertexList;
	
	Model* model1 = new Model("./Resources/Models/Dice.obj", "./Resources/Materials/Dice.mtl", ShaderHandler::GetInstance()->GetShader("basicShader"));
	SceneGraph::GetInstance()->AddModel(model1);
	
	Model* model2 = new Model("./Resources/Models/Apple.obj", "./Resources/Materials/Apple.mtl", ShaderHandler::GetInstance()->GetShader("basicShader"));
	SceneGraph::GetInstance()->AddModel(model2);

	//std::cout << "Min Vert: " << glm::to_string(model->GetBoundingBox().minVert) << std::endl;
	//std::cout << "Max Vert: " << glm::to_string(model->GetBoundingBox().maxVert) << std::endl;

	SceneGraph::GetInstance()->AddGameObject(new GameObject(model1));

	GameObject* apple = new GameObject(model2, glm::vec3(3.0f, 0.0f, 0.0f));
	apple->SetScale(glm::vec3(0.5f));
	apple->AddComponent<ComponentA>();
	apple->AddComponent<ComponentC>();
	apple->AddComponent<ComponentB>();
	apple->RemoveComponent<ComponentC>();

	SceneGraph::GetInstance()->AddGameObject(apple, "apple");

	/*
	v.position = glm::vec3(-1.0f, -1.0f, -1.0f);
	v.colour = glm::vec3(0.583f, 0.771f, 0.014f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, -1.0f, 1.0f);
	v.colour = glm::vec3(0.609f, 0.115f, 0.436f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, 1.0f, 1.0f);
	v.colour = glm::vec3(0.327f, 0.483f, 0.844f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, 1.0f, -1.0f);
	v.colour = glm::vec3(0.822f, 0.569f, 0.201f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, -1.0f, -1.0f);
	v.colour = glm::vec3(0.435f, 0.602f, 0.223f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, 1.0f, -1.0f);
	v.colour = glm::vec3(0.310f, 0.747f, 0.185f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, -1.0f, 1.0f);
	v.colour = glm::vec3(0.597f, 0.770f, 0.761f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, -1.0f, -1.0f);
	v.colour = glm::vec3(0.559f, 0.436f, 0.730f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, -1.0f, -1.0f);
	v.colour = glm::vec3(0.359f, 0.583f, 0.152f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, 1.0f, -1.0f);
	v.colour = glm::vec3(0.483f, 0.596f, 0.789f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, -1.0f, -1.0f);
	v.colour = glm::vec3(0.559f, 0.861f, 0.639f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, -1.0f, -1.0f);
	v.colour = glm::vec3(0.195f, 0.548f, 0.859f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, -1.0f, -1.0f);
	v.colour = glm::vec3(0.014f, 0.184f, 0.576f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, 1.0f, 1.0f);
	v.colour = glm::vec3(0.771f, 0.328f, 0.970f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, 1.0f, -1.0f);
	v.colour = glm::vec3(0.406f, 0.615f, 0.116f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, -1.0f, 1.0f);
	v.colour = glm::vec3(0.676f, 0.977f, 0.133f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, -1.0f, 1.0f);
	v.colour = glm::vec3(0.971f, 0.572f, 0.833f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, -1.0f, -1.0f);
	v.colour = glm::vec3(0.140f, 0.616f, 0.489f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, 1.0f, 1.0f);
	v.colour = glm::vec3(0.997f, 0.513f, 0.064f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, -1.0f, 1.0f);
	v.colour = glm::vec3(0.945f, 0.719f, 0.592f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, -1.0f, 1.0f);
	v.colour = glm::vec3(0.543f, 0.021f, 0.978f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, 1.0f, 1.0f);
	v.colour = glm::vec3(0.279f, 0.317f, 0.505f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, -1.0f, -1.0f);
	v.colour = glm::vec3(0.167f, 0.620f, 0.077f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, 1.0f, -1.0f);
	v.colour = glm::vec3(0.347f, 0.857f, 0.137f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, -1.0f, -1.0f);
	v.colour = glm::vec3(0.055f, 0.953f, 0.042f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, 1.0f, 1.0f);
	v.colour = glm::vec3(0.714f, 0.505f, 0.345f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, -1.0f, 1.0f);
	v.colour = glm::vec3(0.783f, 0.290f, 0.734f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, 1.0f, 1.0f);
	v.colour = glm::vec3(0.722f, 0.645f, 0.174f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, 1.0f, -1.0f);
	v.colour = glm::vec3(0.302f, 0.455f, 0.848f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, 1.0f, -1.0f);
	v.colour = glm::vec3(0.225f, 0.587f, 0.040f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, 1.0f, 1.0f);
	v.colour = glm::vec3(0.517f, 0.713f, 0.338f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, 1.0f, -1.0f);
	v.colour = glm::vec3(0.053f, 0.959f, 0.120f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, 1.0f, 1.0f);
	v.colour = glm::vec3(0.393f, 0.621f, 0.362f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, 1.0f, 1.0f);
	v.colour = glm::vec3(0.673f, 0.211f, 0.457f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, 1.0f, 1.0f);
	v.colour = glm::vec3(0.820f, 0.883f, 0.371f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, -1.0f, 1.0f);
	v.colour = glm::vec3(0.982f, 0.099f, 0.879f);
	vertexList.push_back(v);
	*/


	/*v.position = glm::vec3(-0.5f, -0.5f, -0.5f);
	v.normal = glm::vec3(0.0f, 0.0f, -1.0f);
	v.texCoords = glm::vec2(0.0f, 0.0f);
	v.colour = glm::vec3(0.583f, 0.771f, 0.014f);
	vertexList.push_back(v);

	v.position = glm::vec3(0.5f, -0.5f, -0.5f);
	v.normal = glm::vec3(0.0f, 0.0f, -1.0f);
	v.texCoords = glm::vec2(1.0f, 0.0f);
	v.colour = glm::vec3(0.609f, 0.115f, 0.436f);
	vertexList.push_back(v);

	v.position = glm::vec3(0.5f, 0.5f, -0.5f);
	v.normal = glm::vec3(0.0f, 0.0f, -1.0f);
	v.texCoords = glm::vec2(1.0f, 1.0f);
	v.colour = glm::vec3(0.327f, 0.483f, 0.844f);
	vertexList.push_back(v);

	v.position = glm::vec3(0.5f, 0.5f, -0.5f);
	v.normal = glm::vec3(0.0f, 0.0f, -1.0f);
	v.texCoords = glm::vec2(1.0f, 1.0f);
	v.colour = glm::vec3(0.822f, 0.569f, 0.201f);
	vertexList.push_back(v);

	v.position = glm::vec3(-0.5f, 0.5f, -0.5f);
	v.normal = glm::vec3(0.0f, 0.0f, -1.0f);
	v.texCoords = glm::vec2(0.0f, 1.0f);
	v.colour = glm::vec3(0.435f, 0.602f, 0.223f);
	vertexList.push_back(v);

	v.position = glm::vec3(-0.5f, -0.5f, -0.5f);
	v.normal = glm::vec3(0.0f, 0.0f, -1.0f);
	v.texCoords = glm::vec2(0.0f, 0.0f);
	v.colour = glm::vec3(0.310f, 0.747f, 0.185f);
	vertexList.push_back(v);

	v.position = glm::vec3(-0.5f, -0.5f, 0.5f);
	v.normal = glm::vec3(0.0f, 0.0f, 1.0f);
	v.texCoords = glm::vec2(0.0f, 0.0f);
	v.colour = glm::vec3(0.597f, 0.770f, 0.761f);
	vertexList.push_back(v);

	v.position = glm::vec3(0.5f, -0.5f, 0.5f);
	v.normal = glm::vec3(0.0f, 0.0f, 1.0f);
	v.texCoords = glm::vec2(1.0f, 0.0f);
	v.colour = glm::vec3(0.559f, 0.436f, 0.730f);
	vertexList.push_back(v);

	v.position = glm::vec3(0.5f, 0.5f, 0.5f);
	v.normal = glm::vec3(0.0f, 0.0f, 1.0f);
	v.texCoords = glm::vec2(1.0f, 1.0f);
	v.colour = glm::vec3(0.359f, 0.583f, 0.152f);
	vertexList.push_back(v);

	v.position = glm::vec3(0.5f, 0.5f, 0.5f);
	v.normal = glm::vec3(0.0f, 0.0f, 1.0f);
	v.texCoords = glm::vec2(1.0f, 1.0f);
	v.colour = glm::vec3(0.483f, 0.596f, 0.789f);
	vertexList.push_back(v);

	v.position = glm::vec3(-0.5f, 0.5f, 0.5f);
	v.normal = glm::vec3(0.0f, 0.0f, 1.0f);
	v.texCoords = glm::vec2(0.0f, 1.0f);
	v.colour = glm::vec3(0.559f, 0.861f, 0.639f);
	vertexList.push_back(v);

	v.position = glm::vec3(-0.5f, -0.5f, 0.5f);
	v.normal = glm::vec3(0.0f, 0.0f, 1.0f);
	v.texCoords = glm::vec2(0.0f, 0.0f);
	v.colour = glm::vec3(0.195f, 0.548f, 0.859f);
	vertexList.push_back(v);

	v.position = glm::vec3(-0.5f, 0.5f, 0.5f);
	v.normal = glm::vec3(-1.0f, 0.0f, 0.0f);
	v.texCoords = glm::vec2(0.0f, 0.0f);
	v.colour = glm::vec3(0.014f, 0.184f, 0.576f);
	vertexList.push_back(v);

	v.position = glm::vec3(-0.5f, 0.5f, -0.5f);
	v.normal = glm::vec3(-1.0f, 0.0f, 0.0f);
	v.texCoords = glm::vec2(1.0f, 0.0f);
	v.colour = glm::vec3(0.771f, 0.328f, 0.970f);
	vertexList.push_back(v);

	v.position = glm::vec3(-0.5f, -0.5f, -0.5f);
	v.normal = glm::vec3(-1.0f, 0.0f, 0.0f);
	v.texCoords = glm::vec2(1.0f, 1.0f);
	v.colour = glm::vec3(0.406f, 0.615f, 0.116f);
	vertexList.push_back(v);

	v.position = glm::vec3(-0.5f, -0.5f, -0.5f);
	v.normal = glm::vec3(-1.0f, 0.0f, 0.0f);
	v.texCoords = glm::vec2(1.0f, 1.0f);
	v.colour = glm::vec3(0.676f, 0.977f, 0.133f);
	vertexList.push_back(v);

	v.position = glm::vec3(-0.5f, -0.5f, 0.5f);
	v.normal = glm::vec3(-1.0f, 0.0f, 0.0f);
	v.texCoords = glm::vec2(0.0f, 1.0f);
	v.colour = glm::vec3(0.971f, 0.572f, 0.833f);
	vertexList.push_back(v);

	v.position = glm::vec3(-0.5f, 0.5f, 0.5f);
	v.normal = glm::vec3(-1.0f, 0.0f, 0.0f);
	v.texCoords = glm::vec2(0.0f, 0.0f);
	v.colour = glm::vec3(0.140f, 0.616f, 0.489f);
	vertexList.push_back(v);

	v.position = glm::vec3(0.5f, 0.5f, 0.5f);
	v.normal = glm::vec3(1.0f, 0.0f, 0.0f);
	v.texCoords = glm::vec2(0.0f, 0.0f);
	v.colour = glm::vec3(0.997f, 0.513f, 0.064f);
	vertexList.push_back(v);

	v.position = glm::vec3(0.5f, 0.5f, -0.5f);
	v.normal = glm::vec3(1.0f, 0.0f, 0.0f);
	v.texCoords = glm::vec2(1.0f, 0.0f);
	v.colour = glm::vec3(0.945f, 0.719f, 0.592f);
	vertexList.push_back(v);

	v.position = glm::vec3(0.5f, -0.5f, -0.5f);
	v.normal = glm::vec3(1.0f, 0.0f, 0.0f);
	v.texCoords = glm::vec2(1.0f, 1.0f);
	v.colour = glm::vec3(0.543f, 0.021f, 0.978f);
	vertexList.push_back(v);

	v.position = glm::vec3(0.5f, -0.5f, -0.5f);
	v.normal = glm::vec3(1.0f, 0.0f, 0.0f);
	v.texCoords = glm::vec2(1.0f, 1.0f);
	v.colour = glm::vec3(0.279f, 0.317f, 0.505f);
	vertexList.push_back(v);

	v.position = glm::vec3(0.5f, -0.5f, 0.5f);
	v.normal = glm::vec3(1.0f, 0.0f, 0.0f);
	v.texCoords = glm::vec2(0.0f, 1.0f);
	v.colour = glm::vec3(0.167f, 0.620f, 0.077f);
	vertexList.push_back(v);

	v.position = glm::vec3(0.5f, 0.5f, 0.5f);
	v.normal = glm::vec3(1.0f, 0.0f, 0.0f);
	v.texCoords = glm::vec2(0.0f, 0.0f);
	v.colour = glm::vec3(0.347f, 0.857f, 0.137f);
	vertexList.push_back(v);

	v.position = glm::vec3(-0.5f, -0.5f, -0.5f);
	v.normal = glm::vec3(0.0f, -1.0f, 0.0f);
	v.texCoords = glm::vec2(0.0f, 0.0f);
	v.colour = glm::vec3(0.055f, 0.953f, 0.042f);
	vertexList.push_back(v);

	v.position = glm::vec3(0.5f, -0.5f, -0.5f);
	v.normal = glm::vec3(0.0f, -1.0f, 0.0f);
	v.texCoords = glm::vec2(1.0f, 0.0f);
	v.colour = glm::vec3(0.714f, 0.505f, 0.345f);
	vertexList.push_back(v);

	v.position = glm::vec3(0.5f, -0.5f, 0.5f);
	v.normal = glm::vec3(0.0f, -1.0f, 0.0f);
	v.texCoords = glm::vec2(1.0f, 1.0f);
	v.colour = glm::vec3(0.783f, 0.290f, 0.734f);
	vertexList.push_back(v);

	v.position = glm::vec3(0.5f, -0.5f, 0.5f);
	v.normal = glm::vec3(0.0f, -1.0f, 0.0f);
	v.texCoords = glm::vec2(1.0f, 1.0f);
	v.colour = glm::vec3(0.722f, 0.645f, 0.174f);
	vertexList.push_back(v);

	v.position = glm::vec3(-0.5f, -0.5f, 0.5f);
	v.normal = glm::vec3(0.0f, -1.0f, 0.0f);
	v.texCoords = glm::vec2(0.0f, 1.0f);
	v.colour = glm::vec3(0.302f, 0.455f, 0.848f);
	vertexList.push_back(v);

	v.position = glm::vec3(-0.5f, -0.5f, -0.5f);
	v.normal = glm::vec3(0.0f, -1.0f, 0.0f);
	v.texCoords = glm::vec2(0.0f, 0.0f);
	v.colour = glm::vec3(0.225f, 0.587f, 0.040f);
	vertexList.push_back(v);

	v.position = glm::vec3(-0.5f, 0.5f, -0.5f);
	v.normal = glm::vec3(0.0f, 1.0f, 0.0f);
	v.texCoords = glm::vec2(0.0f, 0.0f);
	v.colour = glm::vec3(0.517f, 0.713f, 0.338f);
	vertexList.push_back(v);

	v.position = glm::vec3(0.5f, 0.5f, -0.5f);
	v.normal = glm::vec3(0.0f, 1.0f, 0.0f);
	v.texCoords = glm::vec2(1.0f, 0.0f);
	v.colour = glm::vec3(0.053f, 0.959f, 0.120f);
	vertexList.push_back(v);

	v.position = glm::vec3(0.5f, 0.5f, 0.5f);
	v.normal = glm::vec3(0.0f, 1.0f, 0.0f);
	v.texCoords = glm::vec2(1.0f, 1.0f);
	v.colour = glm::vec3(0.393f, 0.621f, 0.362f);
	vertexList.push_back(v);

	v.position = glm::vec3(0.5f, 0.5f, 0.5f);
	v.normal = glm::vec3(0.0f, 1.0f, 0.0f);
	v.texCoords = glm::vec2(1.0f, 1.0f);
	v.colour = glm::vec3(0.673f, 0.211f, 0.457f);
	vertexList.push_back(v);

	v.position = glm::vec3(-0.5f, 0.5f, 0.5f);
	v.normal = glm::vec3(0.0f, 1.0f, 0.0f);
	v.texCoords = glm::vec2(0.0f, 1.0f);
	v.colour = glm::vec3(0.820f, 0.883f, 0.371f);
	vertexList.push_back(v);

	v.position = glm::vec3(-0.5f, 0.5f, -0.5f);
	v.normal = glm::vec3(0.0f, 1.0f, 0.0f);
	v.texCoords = glm::vec2(0.0f, 0.0f);
	v.colour = glm::vec3(0.982f, 0.099f, 0.879f);
	vertexList.push_back(v);
	

	model->AddMesh(new Mesh(&vertexList, ShaderHandler::GetInstance()->GetShader("basicShader"),
		TextureHandler::GetInstance()->GetTexture("checkerBoard")));*/


	//shape = new GameObject(model);
 //   shape->SetScale(glm::vec3(0.5f));
	//shape->SetPosition(glm::vec3(0.0f, -0.5f, 0.0f));

	return true;
}

void GameScene::Update(const float deltaTime_)
{
	//std::cout << deltaTime_ << std::endl;
	/*shape->Update(deltaTime_);*/
	SceneGraph::GetInstance()->Update(deltaTime_);
}

void GameScene::Render()
{
	/*shape->Render(CoreEngine::GetInstance()->GetCamera());*/
	SceneGraph::GetInstance()->Render(CoreEngine::GetInstance()->GetCamera());
}
