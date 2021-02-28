#include "MiniginPCH.h"
#include "Minigin.h"
#include <chrono>
#include <thread>
#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include <SDL.h>
#include "GameObject.h"
#include "Scene.h"

#include "TextComponent.h"
#include "ImageComponent.h"
#include "FPSComponent.h"
#include "Qbert.h"
#include "LivesComponent.h"
#include "ScoreComponent.h"

using namespace std;
using namespace std::chrono;

void dae::Minigin::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	m_Window = SDL_CreateWindow(
		"Programming 4 assignment",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640,
		480,
		SDL_WINDOW_OPENGL
	);
	if (m_Window == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	Renderer::GetInstance().Init(m_Window);
}

/**
 * Code constructing the scene world starts here
 */
void dae::Minigin::LoadGame() const
{
	auto& scene = SceneManager::GetInstance().CreateScene("Demo");
	auto go = std::make_shared<GameObject>();
	std::shared_ptr<ImageComponent> imageComponent = make_shared<ImageComponent>("background.jpg");
	go->AddComponent(imageComponent);
	scene.Add(go);

	go = std::make_shared<GameObject>();
	imageComponent = make_shared<ImageComponent>("logo.png");
	imageComponent->SetPosition(216, 180);
	go->AddComponent(imageComponent);
	scene.Add(go);
	
	go = std::make_shared<GameObject>();
	auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	std::shared_ptr<TextComponent> textComponent = make_shared<TextComponent>("Programming 4 Assignment", font, SDL_Color { 255,255,255 });
	textComponent->SetPosition(80, 20);
	go->AddComponent(textComponent);
	scene.Add(go);

	go = std::make_shared<GameObject>();
	font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 16);
	textComponent = make_shared<TextComponent>(" FPS", font, SDL_Color{ 255,255,0 });
	textComponent->SetPosition(0, 0);
	std::shared_ptr<FPSComponent> fpsComponent = make_shared<FPSComponent>(textComponent);
	go->AddComponent(fpsComponent);
	go->AddComponent(textComponent);
	scene.Add(go);

	//go = std::make_shared<GameObject>();
	//std::shared_ptr<Qbert> qbert = make_shared<Qbert>();
	//go->AddComponent(qbert);
	//scene.Add(go);

	// Player 1:
	auto qbertObject = std::make_shared<GameObject>();

	std::shared_ptr<Qbert> qbertScript = make_shared<Qbert>();
	qbertObject->AddComponent(qbertScript);

	font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 16);
	textComponent = make_shared<TextComponent>(" Lives", font, SDL_Color{ 255,0,0 });
	textComponent->SetPosition(0, 100);
	std::shared_ptr<LivesComponent> livesComponent = make_shared<LivesComponent>(*qbertObject, textComponent);
	qbertObject->AddComponent(textComponent);		// Lives component
	qbertObject->AddComponent(livesComponent);		// Lives component

	textComponent = make_shared<TextComponent>(" Lives", font, SDL_Color{ 0,255,0 });
	textComponent->SetPosition(0, 130);
	std::shared_ptr<ScoreComponent> scoreComponent = make_shared<ScoreComponent>(*qbertObject, textComponent);
	qbertObject->AddComponent(textComponent);		// Score component
	qbertObject->AddComponent(scoreComponent);		// Score component

	scene.Add(qbertObject);

	// Player 2:
	qbertObject = std::make_shared<GameObject>();

	qbertScript = make_shared<Qbert>();
	qbertScript->SetDieButton(ControllerButton::ButtonB);
	qbertScript->SetScoreAdditionButton(ControllerButton::ButtonX);
	qbertObject->AddComponent(qbertScript);

	font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 16);
	textComponent = make_shared<TextComponent>(" Lives", font, SDL_Color{ 255,0,0 });
	textComponent->SetPosition(0, 200);
	livesComponent = make_shared<LivesComponent>(*qbertObject, textComponent);
	qbertObject->AddComponent(textComponent);		// Lives component
	qbertObject->AddComponent(livesComponent);		// Lives component

	textComponent = make_shared<TextComponent>(" Lives", font, SDL_Color{ 0,255,0 });
	textComponent->SetPosition(0, 230);
	scoreComponent = make_shared<ScoreComponent>(*qbertObject, textComponent);
	qbertObject->AddComponent(textComponent);		// Score component
	qbertObject->AddComponent(scoreComponent);		// Score component

	scene.Add(qbertObject);
}

void dae::Minigin::Cleanup()
{
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
}

void dae::Minigin::Run()
{
	Initialize();

	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("../Data/");

	LoadGame();

	{
		auto& renderer = Renderer::GetInstance();
		auto& sceneManager = SceneManager::GetInstance();
		auto& input = InputManager::GetInstance();

		auto lastTime = high_resolution_clock::now();
		float lag = 0.0f;
		float msPerUpdate = 0.02f;

		bool doContinue = true;
		while (doContinue)
		{
			const auto currentTime = high_resolution_clock::now();
			float deltaTime = duration<float>(currentTime - lastTime).count();
			lastTime = currentTime; 
			lag += deltaTime;
			doContinue = input.ProcessInput();
			sceneManager.Update(deltaTime);
			while (lag >= msPerUpdate)
			{
				lag -= msPerUpdate;
			}
			
			renderer.Render();
		}
	}

	Cleanup();
}
