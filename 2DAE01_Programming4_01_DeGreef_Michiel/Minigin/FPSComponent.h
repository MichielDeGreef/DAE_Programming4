#pragma once
#include "Component.h"
#include "TextComponent.h"

namespace dae
{
	class FPSComponent : public Component
	{
	public:
		FPSComponent(const std::shared_ptr<TextComponent>& textComponent);
		~FPSComponent();

		void Update(float msPerUpdate) override;
		void Render() override;

	private:
		int m_FPS{};
		float m_ElapsedSec{};
		const int m_SecInterval{ 1 };

		std::shared_ptr<TextComponent> m_TextComponent;
	};
}