#include <LocalPlayer.h>
#include <includes.h>

CLocalPlayer::CLocalPlayer(uintptr_t addr) {
	m_localPlayer = reinterpret_cast<LocalPlayer*>(addr);
}

int	CLocalPlayer::GetHealth() {
	return m_localPlayer->Health;
};

int CLocalPlayer::GetPoints()
{
	return m_localPlayer->Health;
}

void CLocalPlayer::SetPoints(int ammount)
{
	m_localPlayer->Points = ammount;
	return;
}

void CLocalPlayer::SetFov(float amnt)
{
	*(float*)((DWORD)GetModuleHandle(nullptr) + 0x26114A0) = amnt;
	return;
}

float CLocalPlayer::GetFov()
{
	return *(float*)((DWORD)GetModuleHandle(nullptr) + 0x26114A0);
}