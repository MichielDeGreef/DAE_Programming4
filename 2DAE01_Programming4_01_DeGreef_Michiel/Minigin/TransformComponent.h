#pragma once
#include "Component.h"
#include "Transform.h"

namespace dae
{
	class TransformComponent : Component
	{
	public:
		explicit TransformComponent();
		TransformComponent(float x, float y);
		~TransformComponent();

		void SetPosition(float x, float y);
		const glm::vec3 GetTransform();

	private:
		Transform m_Transform;
	};
}