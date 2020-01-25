#include "Monster.h"
#include "Debug.h"


void Monster::Awake()
{
	navAgent = gameObject->GetComponent<MinNetNavMeshAgent>();
}

void Monster::Update()
{
	//Debug::Log(gameObject->position);
	auto player = gameObject->GetNowRoom()->GetGameObject("Knight");
	if (player == nullptr || navAgent == nullptr) return;

	navAgent->SetDestination(player->position);

}

Monster::Monster()
{
}


Monster::~Monster()
{
}
