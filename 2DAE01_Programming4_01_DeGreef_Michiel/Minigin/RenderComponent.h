#pragma once
#include "Component.h"
#include "TextureComponent.h"
#include "TransformComponent.h"

namespace dae
{
	class RenderComponent : public Component
	{
	public:
		RenderComponent();
		~RenderComponent();

		void SetPosition(float x, float y);

		void AddTransformComponent(TransformComponent* transformComponent);

		void Render(const Texture2D* texture);

	private:
		TransformComponent m_TransformComponent;
	};
}