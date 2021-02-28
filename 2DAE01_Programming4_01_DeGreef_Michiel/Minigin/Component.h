#pragma once
namespace dae
{
	class Component
	{
	public:
		Component();
		~Component();

		virtual void Input();
		virtual void Update(float msPerUpdate);
		virtual void Render();
	};
}