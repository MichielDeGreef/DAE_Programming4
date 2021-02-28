#pragma once
#include "GameObject.h"

namespace dae
{
	enum class Notification
	{
		Death,
		ScoreAddition,
		Achievement,
	};

	class IObserver
	{
	public: 
		virtual void Update(Notification notification, int amount = 0) = 0;
	};
}