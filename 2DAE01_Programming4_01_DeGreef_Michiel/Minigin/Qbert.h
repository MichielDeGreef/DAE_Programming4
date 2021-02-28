#pragma once
#include "component.h"
#include "ISubject.h"
#include "Command.h"
#include "InputManager.h"

namespace dae
{
	class Qbert : public Component
	{
	public:
		Qbert();
		~Qbert();

		void Die();
		void Scored(int amount);
		void Update(float elapsedSec) override;
		void Render() override;
		void Attach(IObserver* observer);
		void Detach(IObserver* observer);
		void Notify(Notification notification, int amount = 0);

		void SetDieButton(ControllerButton button);
		void SetScoreAdditionButton(ControllerButton button);

	private:
		std::vector<IObserver*> m_ObserverList;
		DieCommand m_DieCommand;
		ScoredCommand m_ScoredCommand;

		ControllerButton m_DeathButton = ControllerButton::ButtonA;
		ControllerButton m_ScoreAdditionButton = ControllerButton::ButtonY;
	};
}