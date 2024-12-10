#pragma once
#include <includes.h>

struct LocalPlayer
{
    char pad_0000[196];
    int Health;
    char pad_00C8[248];
    int Points;
    char pad_01C4[1660];
};


class CLocalPlayer {
public:
    CLocalPlayer(uintptr_t addr);
    int GetHealth();
    int GetPoints();
    float GetFov();
    void SetPoints(int ammount);
    void SetFov(float amnt);

private:
    LocalPlayer* m_localPlayer;
};