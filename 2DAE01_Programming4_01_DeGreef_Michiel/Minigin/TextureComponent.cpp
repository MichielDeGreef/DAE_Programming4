#include "MiniginPCH.h"
#include "TextureComponent.h"
#include "ResourceManager.h"
#include "Texture2D.h"

dae::TextureComponent::TextureComponent()
{
}

dae::TextureComponent::TextureComponent(const std::string& filename)
{
	m_Texture = ResourceManager::GetInstance().LoadTexture(filename);
}

dae::TextureComponent::~TextureComponent()
{

}

void dae::TextureComponent::SetTexture(SDL_Texture* texture)
{
	m_Texture = std::make_shared<Texture2D>(texture);
}

const dae::Texture2D& dae::TextureComponent::GetTexture()
{
	return *m_Texture;
}