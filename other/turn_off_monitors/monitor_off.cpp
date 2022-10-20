#include <Windows.h>
extern "C" {
#include <Powrprof.h>

}
#pragma comment(lib, "Powrprof.lib")


int main(int argc, _TCHAR* argv[])
{
    ::PostMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);
    /* while(true)
    {
        SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED | ES_AWAYMODE_REQUIRED);
        Sleep(6000);
    } */
    return 0;
}