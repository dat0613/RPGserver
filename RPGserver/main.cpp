#include <MinNetIOCP.h>
#include <MinNetCache.h>
#include <MinNetGameObject.h>
#include <MinNetMySQL.h>
#include "Auth.h"
#include "p2pGroupManager.h"

#pragma comment(lib, "MinNetIOCP.lib")

#include "IOcomponent.h"

void main()
{
	//MinNetCache::SetComponentCache("P2PTestRoomManager", [](MinNetGameObject * object) 
	//{
	//	object->isSyncingObject = false;
	//	object->AddComponent<p2pGroupManager>();
	//});

	//MinNetCache::SetComponentCache("DataBaseIOTestObject", [](MinNetGameObject * object) 
	//{
	//	object->AddComponent<IOcomponent>();
	//});

	//MinNetCache::SetRoomCache("Main", [](MinNetRoom * room, MinNetPacket * packet) 
	//{
	//	room->Instantiate("P2PTestRoomManager");
	//});

	MinNetCache::SetComponentCache("Knight", [](MinNetGameObject * object) 
	{

	});

	MinNetIOCP::SetTickrate(20);
	MinNetIOCP::StartServer(8200, 8201);
	MinNetMySQL::ConnectToMySQL(Auth::host, Auth::port, Auth::user, Auth::password, Auth::databaseName);
	MinNetIOCP::ServerLoop();
}