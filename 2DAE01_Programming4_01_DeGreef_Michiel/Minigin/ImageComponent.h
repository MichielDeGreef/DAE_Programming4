#pragma once
#include "Component.h"
#include <iostream>	
#include "Texture2D.h"
#include "RenderComponent.h"

namespace dae
{
	class ImageComponent : public Component
	{
	public:
		ImageComponent(const std::string& filename);
		~ImageComponent();

		void SetPosition(float x, float y);
		void Render() override;


		void SetTexture(SDL_Texture* texture);
		const Texture2D& GetTexture();

	private:
		std::shared_ptr<Texture2D> m_Texture{};

		RenderComponent m_RenderComponent;
	};
}