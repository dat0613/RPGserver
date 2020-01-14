#pragma once

#include <MinNetComponent.h>

class p2pGroupManager;
class IOcomponent :
	public MinNetComponent
{
public:
	
	IOcomponent();
	~IOcomponent();

	void InitRPC() override;
	void Awake() override;
	void Update() override;
	void OnDestroy() override;
	void SetQuery(std::string query);
	void UDPtest(std::string message);

private:

	p2pGroupManager * manager = nullptr;
};