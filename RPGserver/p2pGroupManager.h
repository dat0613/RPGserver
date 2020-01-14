#pragma once
#include <MinNetComponent.h>

class MinNetp2pGroup;
class p2pGroupManager :
	public MinNetComponent
{
public:

	void Awake() override;

	p2pGroupManager();
	~p2pGroupManager();

	void JoinGroup(MinNetUser * user);
	void LeaveGroup(MinNetUser * user);

private:

	MinNetp2pGroup * group = nullptr;
};