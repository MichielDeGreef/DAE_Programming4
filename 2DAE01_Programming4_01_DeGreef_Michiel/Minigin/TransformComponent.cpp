#include "MiniginPCH.h"
#include "TransformComponent.h"
#include "Transform.h"

dae::TransformComponent::TransformComponent()
{

}

dae::TransformComponent::TransformComponent(float x, float y)
{
	dae::TransformComponent::SetPosition(x, y);
}

dae::TransformComponent::~TransformComponent()
{

}

void dae::TransformComponent::SetPosition(float x, float y)
{
	m_Transform.SetPosition(x, y, 0);
}

const glm::vec3 dae::TransformComponent::GetTransform()
{
	return m_Transform.GetPosition();
}