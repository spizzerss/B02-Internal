#include <includes.h>
#include <Inventory.h>

CInventory::CInventory(uintptr_t addr)
{
	m_inventory = reinterpret_cast<Inventory*>(addr);
}


void CInventory::isFiringRight(bool state)
{
	*(bool*)(0x02342978) = state;
	return;
}

void CInventory::isFiringLeft(bool state)
{
	*(bool*)(0x0234297C) = state;
	return;
}

void CInventory::setAmmoPrimary(int amnt)
{
	m_inventory->AmmoPrimary = amnt;
	return;
}

void CInventory::setAmmoSecondary(int amnt)
{
	m_inventory->AmmoSecondary = amnt;
		return;
}

void CInventory::setAmmoPrimaryStock(int amnt)
{
	m_inventory->AmmoPrimaryStock = amnt;
		return;
}

void CInventory::setAmmoSecondaryStock(int amnt)
{
	m_inventory->AmmoSecondaryStock = amnt;
		return;
}

void CInventory::setEquipmentMain(int amnt)
{
	m_inventory->EquipmentMain = amnt;
		return;
}

void CInventory::setEquipmentSecondary(int amnt)
{
		return;
}

void CInventory::setPrimaryAmmoIfDuelWield(int amnt) 
{
	m_inventory->primaryAmmoIfDuelWield = amnt;
	return;
}