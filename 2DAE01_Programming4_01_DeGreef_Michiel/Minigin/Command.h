#pragma once
namespace dae
{
	class Command
	{
	public:
		virtual ~Command() = default;
		virtual void Execute() = 0;
	};

	class DieCommand : public Command
	{
	public:
		virtual ~DieCommand() = default;
		void Execute() override;

	protected:
		void Die();
	};

	class ScoredCommand : public Command
	{
	public:
		virtual ~ScoredCommand() = default;
		void Execute() override;

	protected:
		void Scored();
	};
}