#include "MiniginPCH.h"
#include "FPSComponent.h"
#include <sstream>

dae::FPSComponent::FPSComponent(const std::shared_ptr<TextComponent>& textComponent)
{
	m_TextComponent = textComponent;
	m_TextComponent->Update(0);
}

dae::FPSComponent::~FPSComponent()
{

}

void dae::FPSComponent::Update(float msPerUpdate)
{
	m_TextComponent->Update(msPerUpdate); // Change
	m_FPS = int(1.f / msPerUpdate);
	m_TextComponent->SetText(std::to_string(m_FPS) + " FPS");

}

void dae::FPSComponent::Render()
{
	m_TextComponent->Render();
}