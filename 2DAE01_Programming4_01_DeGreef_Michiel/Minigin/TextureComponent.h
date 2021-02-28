#pragma once
#include "Component.h"
#include <iostream>
#include "Texture2D.h"

namespace dae
{
	class Texture2D;
	class TextureComponent : public Component
	{
	public:
		TextureComponent();
		TextureComponent(const std::string& filename);
		~TextureComponent();

		void SetTexture(SDL_Texture* texture);
		const Texture2D& GetTexture();

	private:
		std::shared_ptr<Texture2D> m_Texture{};
	};
}