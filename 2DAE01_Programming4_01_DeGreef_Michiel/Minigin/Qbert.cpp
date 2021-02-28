#include "MiniginPCH.h"
#include "Qbert.h"
#include "InputManager.h"

dae::Qbert::Qbert()
{
}

dae::Qbert::~Qbert()
{
}

void dae::Qbert::Update(float)
{
	if (InputManager::GetInstance().IsPressed(m_DeathButton))
	{
		Die();
	}
	else if (InputManager::GetInstance().IsPressed(m_ScoreAdditionButton))
	{
		Scored(25);
	}
}

void dae::Qbert::Render()
{

}

void dae::Qbert::Die()
{
	m_DieCommand.Execute();
	Notify(Notification::Death);
}

void dae::Qbert::Scored(int amount)
{
	m_ScoredCommand.Execute();
	Notify(Notification::ScoreAddition, amount);
}


void dae::Qbert::Attach(IObserver* observer)
{
	m_ObserverList.push_back(observer);
}

void dae::Qbert::Detach(IObserver* observer)
{
	auto observerIndex = std::find(m_ObserverList.begin(), m_ObserverList.end(), observer);
	if (observerIndex != m_ObserverList.end())
		m_ObserverList.erase(m_ObserverList.begin() + (observerIndex - m_ObserverList.begin()));
}

void dae::Qbert::Notify(Notification notification, int amount)
{
	for (auto& observer : m_ObserverList)
	{
		observer->Update(notification, amount);
	}
}

void dae::Qbert::SetDieButton(ControllerButton button)
{
	m_DeathButton = button;
}

void dae::Qbert::SetScoreAdditionButton(ControllerButton button)
{
	m_ScoreAdditionButton = button;
}
