#include <Windows.h>
#include <includes.h>
#include <SDK.h>
bool autofire = false;
DWORD base = (DWORD)GetModuleHandle(nullptr);

typedef void(__stdcall* Truncmd)(int a1, const char* msg);
Truncmd runcmd = reinterpret_cast<Truncmd>(0x6B9D20);

typedef DWORD(__cdecl* CGetsv)(const char* a1, int a2, int a3, int* szProxyBypass);
CGetsv getsv = reinterpret_cast<CGetsv>(0x5FBCC0);

typedef DWORD(__cdecl* CGetcg)(const char* a1, int a2, int a3, int a4, int* szProxyBypass);
CGetcg getcg = reinterpret_cast<CGetcg>(0x6FA930);

typedef DWORD(__cdecl* CGetCamera)(const char* a1, int a2, int a3, int a4, int* szProxyBypass);
CGetCamera getcamera = reinterpret_cast<CGetCamera>(0x4D0480);

DWORD WINAPI Main(HMODULE hm)
{
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);

    SDK sdk(base);
    CLocalPlayer* localplayer = sdk.GetLocalPlayer();
    CInventory* inventory = sdk.GetInventory();


    // just got bored and found other ways to turn on big fps and sv_cheats lolz \\ 
    static int szProxyBypass = 4;
    uintptr_t sv_cheats = getsv("sv_cheats", 0, 24, &szProxyBypass);
    bool* cheats_allowed = reinterpret_cast<bool*>(sv_cheats + 0x18);
    *cheats_allowed = 1;

    uintptr_t cg_states = getcg("cg_drawBigFps", 0xD3A9F8, 0, 0x20000, &szProxyBypass);
    bool* bigfps = reinterpret_cast<bool*>(cg_states + 0x18);

    
    uintptr_t cg_camera = getcamera("cg_fov", 0, 0x42B4000042820000LL, 540672, &szProxyBypass);
    printf("cg_camera -> %x", cg_camera);
    *(float*)(cg_camera + 0x18) = 150;
    while (true) {
        if (GetAsyncKeyState(VK_F1)) {
            runcmd(0, "cmd god");
            Sleep(500);
        }               
        if (GetAsyncKeyState(VK_F2)) {
            autofire = !autofire;
            Sleep(500);
        } 
        if (GetAsyncKeyState(VK_F3)) {
            inventory->setAmmoPrimary(999);
            inventory->setAmmoPrimaryStock(999);
            inventory->setAmmoSecondary(999);
            inventory->setAmmoSecondaryStock(999);
            inventory->setEquipmentMain(999);
            inventory->setEquipmentSecondary(999);
            inventory->setPrimaryAmmoIfDuelWield(999);
            localplayer->SetPoints(999999);
        }
        if (GetAsyncKeyState(VK_F4)) {
            *bigfps = !*bigfps;
            Sleep(500);
        }
        if (autofire) {
            inventory->isFiringLeft(false);
            inventory->isFiringRight(false);
        }
    }
    return 0;
}

BOOL WINAPI DllMain(HMODULE hm, DWORD reason, LPVOID lp)
{
    switch (reason) {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Main, hm, 0, 0);
    }
    return true;
}
