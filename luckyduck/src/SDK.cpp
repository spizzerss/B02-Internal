#include <SDK.h>

SDK::SDK(uintptr_t base) : m_addr(base)
{
    m_localPlayer = new CLocalPlayer(base + 0x1F47D68 - 0x1C0);
    m_inventory = new CInventory(base + 0x1F42BCC - 0x50);
}

CLocalPlayer* SDK::GetLocalPlayer()
{
    return m_localPlayer;
}

CInventory* SDK::GetInventory()
{
    return m_inventory;
}