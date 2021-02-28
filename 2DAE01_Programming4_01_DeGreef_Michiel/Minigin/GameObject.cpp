#include "MiniginPCH.h"
#include <iostream>
#include "GameObject.h"
#include "ResourceManager.h"
#include "RenderComponent.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update(float msPerUpdate)
{
	for (std::shared_ptr<Component> component : m_Components)
	{
		component->Update(msPerUpdate);
	}
}

void dae::GameObject::Render() const
{
	for (std::shared_ptr<Component>  component : m_Components)
	{
		if (true) // change to check if the given component is a render component, if not skip the component.
		{
			component->Render();	
		}
	}
}

//void dae::GameObject::SetTexture(const std::string& filename)
//{
//	m_Texture = ResourceManager::GetInstance().LoadTexture(filename);
//}
//
//void dae::GameObject::SetPosition(float x, float y)
//{
//	m_Transform.SetPosition(x, y, 0.0f);
//}

void dae::GameObject::AddComponent(const std::shared_ptr<Component>& component)
{
	m_Components.push_back(component);
}