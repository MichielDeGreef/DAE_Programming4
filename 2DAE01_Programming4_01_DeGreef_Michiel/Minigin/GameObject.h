#pragma once
#include "Component.h"

namespace dae
{
	class Texture2D;
	class GameObject final
	{
	public:
		void Update(float msPerUpdate);
		void Render() const;

		//void SetTexture(const std::string& filename);
		//void SetPosition(float x, float y);

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		void AddComponent(const std::shared_ptr<Component>& component);

		template <typename T>
		T* getComponent()
		{
			for (auto& component : m_Components)
			{
				if (dynamic_cast<T*>(component.get()))
					return (T*)component.get();
			}
			return nullptr;
		}

	private:
		std::vector<std::shared_ptr<Component>> m_Components;
	};
}
