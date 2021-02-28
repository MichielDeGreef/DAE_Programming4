#pragma once
#include "IObserver.h"
#include "Component.h"
#include "Qbert.h"
#include "TextComponent.h"
#include "GameObject.h"

namespace dae
{
	class LivesComponent : public IObserver, public Component
	{
	public:
		LivesComponent(GameObject& subject, const std::shared_ptr<TextComponent>& textComponent);
		~LivesComponent();
		void Update(Notification notification, int amount = 0) override;
		void Render() override;

	private:
		int m_QbertLives{3};
		Qbert* m_CurrentSubject;
		std::shared_ptr<TextComponent> m_LivesText;
	};
}