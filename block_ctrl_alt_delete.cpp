// forty by croc100

#include <windows.h>

int main()
{
    // Set Windows Hook to block ctrl+alt+delete
    HHOOK hook = SetWindowsHookEx(WH_SHELL, [](int code, WPARAM wParam, LPARAM lParam) {
        if (code == HSHELL_SYSMENU && wParam == VK_ESCAPE)
        {
            return 1; // Block the event
        }
        return CallNextHookEx(NULL, code, wParam, lParam);
    }, NULL, GetCurrentThreadId());

    // Message loop to keep the application running
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Unhook the Windows Hook
    UnhookWindowsHookEx(hook);

    return 0;
}
