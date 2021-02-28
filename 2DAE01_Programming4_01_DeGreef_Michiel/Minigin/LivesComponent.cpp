#include "MiniginPCH.h"
#include "LivesComponent.h"

dae::LivesComponent::LivesComponent(GameObject& subject, const std::shared_ptr<TextComponent>& textComponent)
{
	m_CurrentSubject = subject.getComponent<Qbert>();
	m_CurrentSubject->Attach(this);

	m_LivesText = textComponent;
}

dae::LivesComponent::~LivesComponent()
{

}

void dae::LivesComponent::Update(Notification notification, int)
{
	if (notification == Notification::Death)
		m_QbertLives--;
}

void dae::LivesComponent::Render()
{
	m_LivesText->SetText(std::to_string(m_QbertLives) + " lives");
}