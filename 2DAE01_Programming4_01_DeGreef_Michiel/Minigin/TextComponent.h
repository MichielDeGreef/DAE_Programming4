#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "Component.h"
#include "TextureComponent.h"
#include "RenderComponent.h"
#include "TransformComponent.h"


namespace dae
{
	class Font;
	class Texture2D;
	class TextComponent : public Component
	{
		public:
			void Update(float msPerUpdate) override;

			void SetText(const std::string& text);
			void SetPosition(float x, float y);

			void Render() override;

			explicit TextComponent(const std::string& text, const std::shared_ptr<Font>& font, const SDL_Color& color);
			virtual ~TextComponent() = default;
			TextComponent(const TextComponent& other) = delete;
			TextComponent(TextComponent&& other) = delete;
			TextComponent& operator=(const TextComponent& other) = delete;
			TextComponent& operator=(TextComponent&& other) = delete;
		private:
			bool m_NeedsUpdate;
			std::string m_Text;
			std::shared_ptr<Font> m_Font;
			SDL_Color m_Color;

			RenderComponent m_RenderComponent;
			TextureComponent m_TextureComponent;
	};
}