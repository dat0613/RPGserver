#include "Monster.h"
#include "Debug.h"
#include <MinNetMath.h>

void Monster::Awake()
{
	navAgent = gameObject->GetComponent<MinNetNavMeshAgent>();
}

void Monster::Update()
{
	auto player = gameObject->GetNowRoom()->GetGameObjects("Knight");
	if (player.size() < 1 || navAgent == nullptr) return;

	navAgent->SetDestination(player->position);

	auto velocity = navAgent->velocity;

	gameObject->rotation.y = atan2(velocity.x, velocity.z) * MinNetMath::Rad2Deg;
}

Monster::Monster()
{
}


Monster::~Monster()
{
}
