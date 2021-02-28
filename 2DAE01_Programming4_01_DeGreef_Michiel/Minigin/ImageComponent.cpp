#include "MiniginPCH.h"
#include "ImageComponent.h"
#include "ResourceManager.h"

dae::ImageComponent::ImageComponent(const std::string& filename)
{
	m_Texture = ResourceManager::GetInstance().LoadTexture(filename);
}

dae::ImageComponent::~ImageComponent()
{

}

void dae::ImageComponent::SetPosition(float x, float y)
{
	m_RenderComponent.SetPosition(x, y);
}

void dae::ImageComponent::SetTexture(SDL_Texture* texture)
{
	m_Texture = std::make_shared<Texture2D>(texture);
}

const dae::Texture2D& dae::ImageComponent::GetTexture()
{
	return *m_Texture;
}

void dae::ImageComponent::Render()
{
	m_RenderComponent.Render(&*m_Texture);
}