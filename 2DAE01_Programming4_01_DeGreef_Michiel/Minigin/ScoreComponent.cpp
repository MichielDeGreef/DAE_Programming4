#include "MiniginPCH.h"
#include "ScoreComponent.h"

dae::ScoreComponent::ScoreComponent(GameObject& subject, const std::shared_ptr<TextComponent>& textComponent)
{
	m_CurrentSubject = subject.getComponent<Qbert>();
	m_CurrentSubject->Attach(this);

	m_ScoreText = textComponent;
}

dae::ScoreComponent::~ScoreComponent()
{

}

void dae::ScoreComponent::Render()
{
	m_ScoreText->SetText("Score: " + std::to_string(m_Score));
}

void dae::ScoreComponent::Update(Notification notification, int amount)
{
	if (notification == Notification::ScoreAddition)
	{
		m_Score += amount;
		m_ScoreText->SetText("Score: " + std::to_string(m_Score));
	}
}