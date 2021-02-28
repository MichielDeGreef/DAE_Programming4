#include "MiniginPCH.h"
#include "Command.h"

void dae::DieCommand::Execute()
{
	Die();
}

void dae::DieCommand::Die()
{
	// execute death of object.
}

void dae::ScoredCommand::Execute()
{
	Scored();
}

void dae::ScoredCommand::Scored()
{
	// execute scoring of points.
}