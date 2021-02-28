#include "MiniginPCH.h"
#include <iostream>
#include "GameObject.h"
#include "ResourceManager.h"
#include "RenderComponent.h"
#include "Component.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update(float msPerUpdate)
{
	for (const std::shared_ptr<Component>& component : m_Components)
	{
		component->Update(msPerUpdate);
	}
}

void dae::GameObject::Render() const
{
	for (const std::shared_ptr<Component>&  component : m_Components)
	{
		if (true) // change to check if the given component is a render component, if not skip the component.
		{
			component->Render();	
		}
	}
}

void dae::GameObject::AddComponent(const std::shared_ptr<Component>& component)
{
	m_Components.push_back(component);
}