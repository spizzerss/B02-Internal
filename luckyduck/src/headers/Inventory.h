#pragma once
#include <includes.h>


struct Inventory
{
	char pad_0000[20]; //0x0000
	int32_t AmmoPrimaryStock; //0x0014
	char pad_0018[4]; //0x0018
	int32_t AmmoSecondaryStock; //0x001C
	int32_t SecondaryAmmoStockIfDuelWield; //0x0020
	char pad_0024[44]; //0x0024
	int32_t AmmoPrimary; //0x0050
	int32_t EquipmentMain; //0x0054
	int32_t AmmoSecondary; //0x0058
	int32_t primaryAmmoIfDuelWield; //0x005C
	char pad_0060[2016]; //0x0060
}; //Size: 0x0840


class CInventory {
public:
    CInventory(uintptr_t addr);
    void isFiringRight(bool state);
    void isFiringLeft(bool state);
    void setAmmoPrimaryStock(int amnt);
    void setAmmoSecondaryStock(int amnt);
    void setAmmoPrimary(int amnt);
    void setEquipmentMain(int amnt);
    void setAmmoSecondary(int amnt);
    void setEquipmentSecondary(int amnt);
	void setPrimaryAmmoIfDuelWield(int amnt);
private:
    Inventory* m_inventory;
};