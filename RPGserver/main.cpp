#include <MinNetIOCP.h>
#include <MinNetPrefab.h>
#include <MinNetGameObject.h>
#include <MinNetMySQL.h>
#include "Auth.h"
#include "p2pGroupManager.h"
#include "Monster.h"

#include <MinNetNavMeshAgent.h>
#include <MinNetTransform.h>

#pragma comment(lib, "MinNetIOCP.lib")

#include "IOcomponent.h"

void main()
{
	MinNetPrefab::SetGameObjectPrefab("Knight", [](MinNetGameObject * object)
	{
		object->AddComponent<MinNetTransform>();
	});

	MinNetPrefab::SetGameObjectPrefab("BoximonRed", [](MinNetGameObject * object)
	{
		object->AddComponent<Monster>();
		auto transform = object->AddComponent<MinNetTransform>();
		transform->serverIsOriginal = true;
		transform->syncPerSecond = 10;
		auto nav = object->AddComponent<MinNetNavMeshAgent>();
		//nav->halfExtends.y = 10.0f;
		nav->SetDefaultParameter();
		nav->addtion.y = -0.5f;
		//nav->agentParams.height = 100.0f;
	});

	MinNetPrefab::SetRoomPrefab("Main", [](MinNetRoom * room, MinNetPacket * packet)
	{
		MinNetPrefab::SetNavMeshPrefab(room, "MapMesh.bin");
		room->Instantiate("BoximonRed", Vector3(95.0f, 22.0f, 35.0f), Vector3::zero);
	});

	MinNetIOCP::SetTickrate(20);
	MinNetIOCP::StartServer(8200, 8201);
	MinNetMySQL::ConnectToMySQL(Auth::host, Auth::port, Auth::user, Auth::password, Auth::databaseName);
	MinNetIOCP::ServerLoop();
}