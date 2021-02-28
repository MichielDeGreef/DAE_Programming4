#pragma once
#include "IObserver.h"
#include "Component.h"
#include "TextComponent.h"
#include "Qbert.h"

namespace dae
{
	class ScoreComponent : public IObserver, public Component
	{
	public:
		ScoreComponent(GameObject& subject, const std::shared_ptr<TextComponent>& textComponent);
		~ScoreComponent();
		void Update(Notification notification, int amount) override;
		void Render() override;

	private:
		Qbert* m_CurrentSubject;
		int m_Score{};
		std::shared_ptr<TextComponent> m_ScoreText;
	};
}