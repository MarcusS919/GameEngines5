#include "Engine/Core/CoreEngine.h"
#include "GAME/Game1.h"

int main(int argc, char* argv[])
{
	CoreEngine::GetInstance()->SetGameInterface(new Game1);

	if (!CoreEngine::GetInstance()->OnCreate("Engine Window", 800, 600)) 
	{
		Debugger::Error("Engine failed to be created ", "main.cpp ", __LINE__);
		return 0;
	}

	CoreEngine::GetInstance()->Run();
			
	return 0;
}