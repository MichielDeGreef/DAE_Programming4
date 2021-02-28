#include "MiniginPCH.h"
#include "TextComponent.h"
#include "Renderer.h"

#include "Font.h"

dae::TextComponent::TextComponent(const std::string& text, const std::shared_ptr<Font>& font, const SDL_Color& color)
	: m_NeedsUpdate(true), m_Text(text), m_Font(font), m_Color(color)
{ 
	dae::TextComponent::Update(0);
}

void dae::TextComponent::Update(float)
{
	if (m_NeedsUpdate)
	{
		const auto surf = TTF_RenderText_Blended(m_Font->GetFont(), m_Text.c_str(), m_Color);
		if (surf == nullptr) 
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}
		auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr) 
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}
		SDL_FreeSurface(surf);
		m_TextureComponent.SetTexture(texture);
		m_NeedsUpdate = false;
	}
}

// This implementation uses the "dirty flag" pattern
void dae::TextComponent::SetText(const std::string& text)
{
	m_Text = text;
	m_NeedsUpdate = true;
}

void dae::TextComponent::SetPosition(const float x, const float y)
{
	m_RenderComponent.SetPosition(x, y);
}


void dae::TextComponent::Render()
{
	m_RenderComponent.Render(&m_TextureComponent.GetTexture());
}