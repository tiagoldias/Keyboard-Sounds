#include <stdio.h>
#include <windows.h>

HHOOK keyboardHook;

void PlaySoundFrequency(DWORD frequency) {
    Beep(frequency, 100); // 100 ms de duração do som
}

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION && (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)) {
        KBDLLHOOKSTRUCT* kbStruct = (KBDLLHOOKSTRUCT*)lParam;
        switch (kbStruct->vkCode) {
            case 'A':
                PlaySoundFrequency(261.63);
                break;
            case 'B':
                PlaySoundFrequency(275.39);
                break;
            case 'C':
                PlaySoundFrequency(289.15);
                break;
            case 'D':
                PlaySoundFrequency(302.91);
                break;
            case 'E':
                PlaySoundFrequency(316.67);
                break;
            case 'F':
                PlaySoundFrequency(330.43);
                break;
            case 'G':
                PlaySoundFrequency(344.19);
                break;
            case 'H':
                PlaySoundFrequency(357.95);
                break;
            case 'I':
                PlaySoundFrequency(371.71);
                break;
            case 'J':
                PlaySoundFrequency(385.47);
                break;
            case 'K':
                PlaySoundFrequency(399.23);
                break;
            case 'L':
                PlaySoundFrequency(412.99);
                break;
            case 'M':
                PlaySoundFrequency(426.75);
                break;
            case 'N':
                PlaySoundFrequency(440.51);
                break;
            case 'O':
                PlaySoundFrequency(454.27);
                break;
            case 'P':
                PlaySoundFrequency(468.03);
                break;
            case 'Q':
                PlaySoundFrequency(481.79);
                break;
            case 'R':
                PlaySoundFrequency(495.55);
                break;
            case 'S':
                PlaySoundFrequency(509.31);
                break;
            case 'T':
                PlaySoundFrequency(523.07);
                break;
            case 'U':
                PlaySoundFrequency(536.83);
                break;
            case 'V':
                PlaySoundFrequency(550.59);
                break;
            case 'W':
                PlaySoundFrequency(564.35);
                break;
            case 'X':
                PlaySoundFrequency(578.11);
                break;
            case 'Y':
                PlaySoundFrequency(591.87);
                break;
            case 'Z':
                PlaySoundFrequency(605.63);
                break;
            case VK_ESCAPE:
                UnhookWindowsHookEx(keyboardHook);
                PostQuitMessage(0);
                break;
        }
    }

    return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}

int main() {
    keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    if (keyboardHook == NULL) {
        printf("Error installing the keyboard hook.\n");
        return 1;
    }

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(keyboardHook);

    return 0;
}
