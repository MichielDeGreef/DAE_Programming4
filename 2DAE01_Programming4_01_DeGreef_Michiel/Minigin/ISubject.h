#pragma once
#include "IObserver.h"
namespace dae
{
	class ISubject 
	{
		virtual void Attach(IObserver* observer) = 0;
		virtual void Detach(IObserver* observer) = 0;
		virtual void Notify(Notification notification, int amount = 0) = 0;
	};
}