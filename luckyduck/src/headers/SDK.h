#pragma once
#include <LocalPlayer.h>
#include <Inventory.h>

class SDK
{
public:
	SDK(uintptr_t addr);
	CLocalPlayer* GetLocalPlayer();
	CInventory* GetInventory();
private:
	uintptr_t m_addr;
	CLocalPlayer* m_localPlayer;
	CInventory* m_inventory;
};