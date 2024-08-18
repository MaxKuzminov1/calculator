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
