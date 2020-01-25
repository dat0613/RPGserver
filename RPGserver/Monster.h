#pragma once
#include <MinNetComponent.h>
#include <MinNetNavMeshAgent.h>

class Monster :
	public MinNetComponent
{
public:

	void Awake() override;
	void Update() override;

	Monster();
	~Monster();

private:

	MinNetNavMeshAgent * navAgent = nullptr;
};

