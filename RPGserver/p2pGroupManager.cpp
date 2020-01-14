#include "p2pGroupManager.h"
#include <MinNetGameObject.h>
#include <MinNetp2pGroup.h>
#include <Debug.h>

void p2pGroupManager::Awake()
{
	group = gameObject->GetNowRoom()->Createp2pGroup();
}

p2pGroupManager::p2pGroupManager()
{
}

p2pGroupManager::~p2pGroupManager()
{
}

void p2pGroupManager::JoinGroup(MinNetUser * user)
{
	group->AddMember(user);
}

void p2pGroupManager::LeaveGroup(MinNetUser * user)
{
	group->DelMember(user);
}
