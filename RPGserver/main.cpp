#include <MinNetIOCP.h>
#include <MinNetCache.h>
#include <MinNetGameObject.h>
#include <MinNetMySQL.h>
#include "Auth.h"
#include "p2pGroupManager.h"

#include "MinNetTransform.h"

#pragma comment(lib, "MinNetIOCP.lib")

#include "IOcomponent.h"

void main()
{
	MinNetCache::SetComponentCache("Knight", [](MinNetGameObject * object) 
	{
		object->AddComponent<MinNetTransform>();

	});

	MinNetCache::SetComponentCache("BoximonRed", [](MinNetGameObject * object)
	{
		object->AddComponent<MinNetTransform>();
	});

	MinNetCache::SetRoomCache("Main", [](MinNetRoom * room, MinNetPacket * packet)
	{
		room->Instantiate("BoximonRed", Vector3(0.0f, 2.384186e-07, 0.0f), Vector3::zero);
	});

	MinNetIOCP::SetTickrate(20);
	MinNetIOCP::StartServer(8200, 8201);
	MinNetMySQL::ConnectToMySQL(Auth::host, Auth::port, Auth::user, Auth::password, Auth::databaseName);
	MinNetIOCP::ServerLoop();
}