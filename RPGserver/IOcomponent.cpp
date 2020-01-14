#include "IOcomponent.h"
#include <MinNetMySQL.h>
#include <Debug.h>
#include "p2pGroupManager.h"

IOcomponent::IOcomponent()
{
}


IOcomponent::~IOcomponent()
{
}

void IOcomponent::InitRPC()
{
	DefRPC("SetQuery", [this](MinNetPacket * packet) 
	{
		auto query = packet->pop_string();
		this->SetQuery(query);
	});

	DefRPC("UDPtest", [this](MinNetPacket * packet)
	{
		auto message = packet->pop_string();
		this->UDPtest(message);
	});
}

void IOcomponent::Awake()
{
	manager = gameObject->GetNowRoom()->GetGameObject("P2PTestRoomManager")->GetComponent<p2pGroupManager>();
	manager->JoinGroup(gameObject->owner);
}

void IOcomponent::Update()
{
}

void IOcomponent::OnDestroy()
{
	Debug::Log(gameObject->owner, " 를 그룹에서 제외시켰음");
	manager->LeaveGroup(gameObject->owner);
}

void IOcomponent::SetQuery(std::string query)
{
	auto asdf = shared_from_this();
	MinNetMySQL::AddQuery(query, [asdf](int errorNumber, std::vector<MYSQL_ROW> * rows, int rowCount, int fieldCount)
	{
		if (errorNumber != 0)
		{
			Debug::Log("query error");
		}
		else
		{
			asdf->RPC("QueryEnd", asdf->gameObject->owner);
		}
	});
}

void IOcomponent::UDPtest(std::string message)
{
	Debug::Log("Message", message);
}