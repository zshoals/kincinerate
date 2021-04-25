#pragma once

#include <kinc/input/keyboard.h>
#include <stdbool.h>

#define MAX_KEYS 256

typedef struct burn_keys_state burn_keys_state_t;

void burn_keys_start(void);

void burn_keys_enable_input(void);
void burn_keys_disable_input(void);
void burn_keys_disable_input_and_set_keys_up(void);

bool burn_keys_is_key_down(int keycode);
bool burn_keys_is_key_up(int keycode);
bool burn_keys_is_any_key_down(void);
bool burn_keys_was_key_just_pressed(int keycode, double threshold);
bool burn_keys_was_key_just_released(int keycode, double threshold);
bool burn_keys_did_key_just_transition(int keycode, double threshold);
bool burn_keys_has_key_been_held_for(int keycode, double threshold);
bool burn_keys_has_key_been_released_for(int keycode, double threshold);
double burn_keys_key_down_duration(int keycode);
double burn_keys_key_up_duration(int keycode);

void burn_internal_keys_time_update(double delta);
void burn_internal_keys_set_key_down(int keycode);
void burn_internal_keys_set_key_up(int keycode);
void burn_internal_keys_set_all_up(void);

//Kinc keys renamed for my brain
#define BURN_KEY_UNKNOWN 0
#define BURN_KEY_BACK 1 // Android
#define BURN_KEY_CANCEL 3
#define BURN_KEY_HELP 6
#define BURN_KEY_BACKSPACE 8
#define BURN_KEY_TAB 9
#define BURN_KEY_CLEAR 12
#define BURN_KEY_RETURN 13
#define BURN_KEY_SHIFT 16
#define BURN_KEY_CONTROL 17
#define BURN_KEY_ALT 18
#define BURN_KEY_PAUSE 19
#define BURN_KEY_CAPS_LOCK 20
#define BURN_KEY_KANA 21
#define BURN_KEY_HANGUL 21
#define BURN_KEY_EISU 22
#define BURN_KEY_JUNJA 23
#define BURN_KEY_FINAL 24
#define BURN_KEY_HANJA 25
#define BURN_KEY_KANJI 25
#define BURN_KEY_ESCAPE 27
#define BURN_KEY_CONVERT 28
#define BURN_KEY_NON_CONVERT 29
#define BURN_KEY_ACCEPT 30
#define BURN_KEY_MODE_CHANGE 31
#define BURN_KEY_SPACE 32
#define BURN_KEY_PAGE_UP 33
#define BURN_KEY_PAGE_DOWN 34
#define BURN_KEY_END 35
#define BURN_KEY_HOME 36
#define BURN_KEY_LEFT 37
#define BURN_KEY_UP 38
#define BURN_KEY_RIGHT 39
#define BURN_KEY_DOWN 40
#define BURN_KEY_SELECT 41
#define BURN_KEY_PRINT 42
#define BURN_KEY_EXECUTE 43
#define BURN_KEY_PRINT_SCREEN 44
#define BURN_KEY_INSERT 45
#define BURN_KEY_DELETE 46
#define BURN_KEY_0 48
#define BURN_KEY_1 49
#define BURN_KEY_2 50
#define BURN_KEY_3 51
#define BURN_KEY_4 52
#define BURN_KEY_5 53
#define BURN_KEY_6 54
#define BURN_KEY_7 55
#define BURN_KEY_8 56
#define BURN_KEY_9 57
#define BURN_KEY_COLON 58
#define BURN_KEY_SEMICOLON 59
#define BURN_KEY_LESS_THAN 60
#define BURN_KEY_EQUALS 61
#define BURN_KEY_GREATER_THAN 62
#define BURN_KEY_QUESTIONMARK 63
#define BURN_KEY_AT 64
#define BURN_KEY_A 65
#define BURN_KEY_B 66
#define BURN_KEY_C 67
#define BURN_KEY_D 68
#define BURN_KEY_E 69
#define BURN_KEY_F 70
#define BURN_KEY_G 71
#define BURN_KEY_H 72
#define BURN_KEY_I 73
#define BURN_KEY_J 74
#define BURN_KEY_K 75
#define BURN_KEY_L 76
#define BURN_KEY_M 77
#define BURN_KEY_N 78
#define BURN_KEY_O 79
#define BURN_KEY_P 80
#define BURN_KEY_Q 81
#define BURN_KEY_R 82
#define BURN_KEY_S 83
#define BURN_KEY_T 84
#define BURN_KEY_U 85
#define BURN_KEY_V 86
#define BURN_KEY_W 87
#define BURN_KEY_X 88
#define BURN_KEY_Y 89
#define BURN_KEY_Z 90
#define BURN_KEY_WIN 91
#define BURN_KEY_CONTEXT_MENU 93
#define BURN_KEY_SLEEP 95
#define BURN_KEY_NUMPAD_0 96
#define BURN_KEY_NUMPAD_1 97
#define BURN_KEY_NUMPAD_2 98
#define BURN_KEY_NUMPAD_3 99
#define BURN_KEY_NUMPAD_4 100
#define BURN_KEY_NUMPAD_5 101
#define BURN_KEY_NUMPAD_6 102
#define BURN_KEY_NUMPAD_7 103
#define BURN_KEY_NUMPAD_8 104
#define BURN_KEY_NUMPAD_9 105
#define BURN_KEY_MULTIPLY 106
#define BURN_KEY_ADD 107
#define BURN_KEY_SEPARATOR 108
#define BURN_KEY_SUBTRACT 109
#define BURN_KEY_DECIMAL 110
#define BURN_KEY_DIVIDE 111
#define BURN_KEY_F1 112
#define BURN_KEY_F2 113
#define BURN_KEY_F3 114
#define BURN_KEY_F4 115
#define BURN_KEY_F5 116
#define BURN_KEY_F6 117
#define BURN_KEY_F7 118
#define BURN_KEY_F8 119
#define BURN_KEY_F9 120
#define BURN_KEY_F10 121
#define BURN_KEY_F11 122
#define BURN_KEY_F12 123
#define BURN_KEY_F13 124
#define BURN_KEY_F14 125
#define BURN_KEY_F15 126
#define BURN_KEY_F16 127
#define BURN_KEY_F17 128
#define BURN_KEY_F18 129
#define BURN_KEY_F19 130
#define BURN_KEY_F20 131
#define BURN_KEY_F21 132
#define BURN_KEY_F22 133
#define BURN_KEY_F23 134
#define BURN_KEY_F24 135
#define BURN_KEY_NUM_LOCK 144
#define BURN_KEY_SCROLL_LOCK 145
#define BURN_KEY_WIN_OEM_FJ_JISHO 146
#define BURN_KEY_WIN_OEM_FJ_MASSHOU 147
#define BURN_KEY_WIN_OEM_FJ_TOUROKU 148
#define BURN_KEY_WIN_OEM_FJ_LOYA 149
#define BURN_KEY_WIN_OEM_FJ_ROYA 150
#define BURN_KEY_CIRCUMFLEX 160
#define BURN_KEY_EXCLAMATION 161
#define BURN_KEY_DOUBLE_QUOTE 162
#define BURN_KEY_HASH 163
#define BURN_KEY_DOLLAR 164
#define BURN_KEY_PERCENT 165
#define BURN_KEY_AMPERSAND 166
#define BURN_KEY_UNDERSCORE 167
#define BURN_KEY_OPEN_PAREN 168
#define BURN_KEY_CLOSE_PAREN 169
#define BURN_KEY_ASTERISK 170
#define BURN_KEY_PLUS 171
#define BURN_KEY_PIPE 172
#define BURN_KEY_HYPHEN_MINUS 173
#define BURN_KEY_OPEN_CURLY_BRACKET 174
#define BURN_KEY_CLOSE_CURLY_BRACKET 175
#define BURN_KEY_TILDE 176
#define BURN_KEY_VOLUME_MUTE 181
#define BURN_KEY_VOLUME_DOWN 182
#define BURN_KEY_VOLUME_UP 183
#define BURN_KEY_COMMA 188
#define BURN_KEY_PERIOD 190
#define BURN_KEY_SLASH 191
#define BURN_KEY_BACK_QUOTE 192
#define BURN_KEY_OPEN_BRACKET 219
#define BURN_KEY_BACK_SLASH 220
#define BURN_KEY_CLOSE_BRACKET 221
#define BURN_KEY_QUOTE 222
#define BURN_KEY_META 224
#define BURN_KEY_ALT_GR 225
#define BURN_KEY_WIN_ICO_HELP 227
#define BURN_KEY_WIN_ICO_00 228
#define BURN_KEY_WIN_ICO_CLEAR 230
#define BURN_KEY_WIN_OEM_RESET 233
#define BURN_KEY_WIN_OEM_JUMP 234
#define BURN_KEY_WIN_OEM_PA1 235
#define BURN_KEY_WIN_OEM_PA2 236
#define BURN_KEY_WIN_OEM_PA3 237
#define BURN_KEY_WIN_OEM_WSCTRL 238
#define BURN_KEY_WIN_OEM_CUSEL 239
#define BURN_KEY_WIN_OEM_ATTN 240
#define BURN_KEY_WIN_OEM_FINISH 241
#define BURN_KEY_WIN_OEM_COPY 242
#define BURN_KEY_WIN_OEM_AUTO 243
#define BURN_KEY_WIN_OEM_ENLW 244
#define BURN_KEY_WIN_OEM_BACK_TAB 245
#define BURN_KEY_ATTN 246
#define BURN_KEY_CRSEL 247
#define BURN_KEY_EXSEL 248
#define BURN_KEY_EREOF 249
#define BURN_KEY_PLAY 250
#define BURN_KEY_ZOOM 251
#define BURN_KEY_PA1 253
#define BURN_KEY_WIN_OEM_CLEAR 254