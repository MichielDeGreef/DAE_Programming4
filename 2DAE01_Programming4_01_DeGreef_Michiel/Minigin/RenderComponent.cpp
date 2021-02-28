#include "MiniginPCH.h"
#include "RenderComponent.h"
#include "Renderer.h"

dae::RenderComponent::RenderComponent()
{

}

dae::RenderComponent::~RenderComponent()
{

}

void dae::RenderComponent::SetPosition(float x, float y)
{
	m_TransformComponent.SetPosition(x, y);
}

void dae::RenderComponent::AddTransformComponent(TransformComponent* transformComponent)
{
	m_TransformComponent = *transformComponent;
}

void dae::RenderComponent::Render(const Texture2D* texture)
{
	Renderer::GetInstance().RenderTexture(*texture, m_TransformComponent.GetTransform().x, m_TransformComponent.GetTransform().y);
}
