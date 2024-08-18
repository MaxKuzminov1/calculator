#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define bt_0_id 0
#define bt_1_id 1
#define bt_2_id 2
#define bt_3_id 3
#define bt_4_id 4
#define bt_5_id 5
#define bt_6_id 6
#define bt_7_id 7
#define bt_8_id 8
#define bt_9_id 9
#define bt_bracket1_id 10
#define bt_bracket2_id 11
#define bt_factorial_id 12
#define bt_sin_id 13
#define bt_cos_id 14
#define bt_bracketc2_id 15
#define bt_div_id 16
#define bt_mul_id 17
#define bt_plus_id 18
#define bt_minus_id 19
#define bt_pound_id 20
#define bt_ln_id 21
#define bt_exp_id 22
#define bt_tan_id 23
#define bt_del_id 24
#define bt_ansver_id 25
HWND cap1;

char* creature_window();
void button_press(WPARAM wparam);
LRESULT WINAPI WinProc (HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
void appendString(HWND cap1, const char* str);
char prevText[100] = "";

int main(){
    printf("%s",creature_window());
    return 0;
}
char* creature_window() {
    WNDCLASSA wcl;
    memset(&wcl, 0, sizeof(WNDCLASSA));
    wcl.lpszClassName = "my Window";
    wcl.lpfnWndProc = WinProc;
    RegisterClassA(&wcl);
    HWND hmnd;
    hmnd = CreateWindow("my Window", "Window Name", WS_OVERLAPPEDWINDOW, 10, 10, 640, 480, NULL, NULL, NULL,
                        NULL);
    ShowWindow(hmnd, SW_SHOWNORMAL);
    HWND bt_1 =
        CreateWindow("button", "1", WS_VISIBLE | WS_CHILD, 10, 110, 50, 50, hmnd, bt_1_id, NULL, NULL);
    HWND bt_2 =
        CreateWindow("button", "2", WS_VISIBLE | WS_CHILD, 60, 110, 50, 50, hmnd, bt_2_id, NULL, NULL);
    HWND bt_3 =
        CreateWindow("button", "3", WS_VISIBLE | WS_CHILD, 110, 110, 50, 50, hmnd, bt_3_id, NULL, NULL);
    HWND bt_4 =
        CreateWindow("button", "4", WS_VISIBLE | WS_CHILD, 10, 160, 50, 50, hmnd, bt_4_id, NULL, NULL);
    HWND bt_5 =
        CreateWindow("button", "5", WS_VISIBLE | WS_CHILD, 60, 160, 50, 50, hmnd, bt_5_id, NULL, NULL);
    HWND bt_6 =
        CreateWindow("button", "6", WS_VISIBLE | WS_CHILD, 110, 160, 50, 50, hmnd, bt_6_id, NULL, NULL);
    HWND bt_7 =
        CreateWindow("button", "7", WS_VISIBLE | WS_CHILD, 10, 210, 50, 50, hmnd, bt_7_id, NULL, NULL);
    HWND bt_8 =
        CreateWindow("button", "8", WS_VISIBLE | WS_CHILD, 60, 210, 50, 50, hmnd, bt_8_id, NULL, NULL);
    HWND bt_9 =
        CreateWindow("button", "9", WS_VISIBLE | WS_CHILD, 110, 210, 50, 50, hmnd, bt_9_id, NULL, NULL);
    HWND bt_0 =
        CreateWindow("button", "0", WS_VISIBLE | WS_CHILD, 10, 260, 100, 50, hmnd, bt_0_id, NULL, NULL);
    HWND bt_pound =
        CreateWindow("button", ".", WS_VISIBLE | WS_CHILD, 110, 260, 50, 50, hmnd, bt_pound_id, NULL, NULL);
    HWND bt_bracket1 =
        CreateWindow("button", "(", WS_VISIBLE | WS_CHILD, 10, 310, 50, 50, hmnd, bt_bracket1_id, NULL, NULL);
    HWND bt_bracket2 =
        CreateWindow("button", ")", WS_VISIBLE | WS_CHILD, 60, 310, 50, 50, hmnd, bt_bracket2_id, NULL, NULL);
    HWND bt_factorial = CreateWindow("button", "X!", WS_VISIBLE | WS_CHILD, 110, 310, 50, 50, hmnd,
                                     bt_factorial_id, NULL, NULL);
    HWND bt_sin =
        CreateWindow("button", "sin", WS_VISIBLE | WS_CHILD, 160, 310, 50, 50, hmnd, bt_sin_id, NULL, NULL);
    HWND bt_cos =
        CreateWindow("button", "cos", WS_VISIBLE | WS_CHILD, 210, 310, 50, 50, hmnd, bt_cos_id, NULL, NULL);
    HWND bt_plus =
        CreateWindow("button", "+", WS_VISIBLE | WS_CHILD, 160, 110, 50, 50, hmnd, bt_plus_id, NULL, NULL);
    HWND bt_minus =
        CreateWindow("button", "-", WS_VISIBLE | WS_CHILD, 160, 160, 50, 50, hmnd, bt_minus_id, NULL, NULL);
    HWND bt_mul =
        CreateWindow("button", "*", WS_VISIBLE | WS_CHILD, 160, 210, 50, 50, hmnd, bt_mul_id, NULL, NULL);
    HWND bt_div =
        CreateWindow("button", "/", WS_VISIBLE | WS_CHILD, 160, 260, 50, 50, hmnd, bt_div_id, NULL, NULL);
    HWND bt_ln =
        CreateWindow("button", "ln", WS_VISIBLE | WS_CHILD, 210, 260, 50, 50, hmnd, bt_ln_id, NULL, NULL);
    HWND bt_exp =
        CreateWindow("button", "X^Y", WS_VISIBLE | WS_CHILD, 210, 160, 50, 50, hmnd, bt_exp_id, NULL, NULL);
    HWND bt_tan =
        CreateWindow("button", "tan", WS_VISIBLE | WS_CHILD, 210, 210, 50, 50, hmnd, bt_tan_id, NULL, NULL);
    HWND bt_DEL =
        CreateWindow("button", "DEL", WS_VISIBLE | WS_CHILD, 210, 110, 50, 50, hmnd, bt_del_id, NULL, NULL);
    HWND bt_ansver =
        CreateWindow("button", "=", WS_VISIBLE | WS_CHILD, 10, 360, 250, 50, hmnd, bt_ansver_id, NULL, NULL);
    cap1 = CreateWindow("static", "", WS_VISIBLE | WS_CHILD, 10, 10, 610, 80, hmnd, NULL, NULL, NULL);
    HWND cap2 = CreateWindow("static", "", WS_VISIBLE | WS_CHILD, 270, 110, 300, 300, hmnd, NULL, NULL, NULL);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        if (msg.message == 161 && msg.wParam == 20) return;
        if (msg.wParam = bt_ansver_id) return prevText;
    }
    return;
}

void appendString(HWND cap1, const char* str) {
    char text[100];
    GetWindowTextA(cap1, text, 100);
    strcat(text, str);
    strcpy(prevText, text);
    SetWindowTextA(cap1, text);
}

void button_press(WPARAM wparam) {
    switch (LOWORD(wparam)) {
        case bt_bracket1_id:
            appendString(cap1, "(");
            break;
        case bt_bracket2_id:
            appendString(cap1, ")");
            break;
        case bt_factorial_id:
            appendString(cap1, "!");
            break;
        case bt_sin_id:
            appendString(cap1, "sin");
            break;
        case bt_cos_id:
            appendString(cap1, "cos");
            break;
        case bt_plus_id:
            appendString(cap1, "+");
            break;
        case bt_minus_id:
            appendString(cap1, "-");
            break;
        case bt_mul_id:
            appendString(cap1, "*");
            break;
        case bt_div_id:
            appendString(cap1, "/");
            break;
        case bt_pound_id:
            appendString(cap1, ".");
            break;
        case bt_ln_id:
            appendString(cap1, "ln");
            break;
        case bt_exp_id:
            appendString(cap1, "^");
            break;
        case bt_tan_id:
            appendString(cap1, "tan");
            break;
        case bt_del_id:
            prevText[strlen(prevText) - 1] = 0;
            // printf("%s\n",prevText);
            SetWindowTextA(cap1, prevText);
            break;
        case bt_0_id:
        case bt_1_id:
        case bt_2_id:
        case bt_3_id:
        case bt_4_id:
        case bt_5_id:
        case bt_6_id:
        case bt_7_id:
        case bt_8_id:
        case bt_9_id:
            appendString(cap1, (char[]){'0' + (LOWORD(wparam) - bt_0_id), '\0'});
            break;
    }
}

LRESULT WINAPI WinProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) {
    if (message == WM_DESTROY) PostQuitMessage(0);
    // else if (message == WM_KEYDOWN) printf("code = %d\n",wparam);
    // else if (message == WM_CHAR) printf("%c\n",wparam);
    //  else if (message == WM_MOUSEMOVE){
    //      int xPos =LOWORD(lparam);
    //      int yPos = HIWORD(lparam);
    //      printf("Mouse position: (%d, %d)\n",xPos, yPos);
    //  }
    // else if(message == WM_LBUTTONDOWN) printf("Left button clicked\n");
    // else if(message == WM_RBUTTONDOWN) printf("Right button clicked\n");
    else if (message == WM_COMMAND) {
        button_press(wparam);
    } else
        return DefWindowProcA(hwnd, message, wparam, lparam);
}