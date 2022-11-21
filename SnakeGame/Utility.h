#pragma once

wchar_t* CharToWChar(const char* pstrSrc);

char* ConvertWCtoC(const wchar_t* str);

void gotoxy(int x, int y);

void ScreenInit();

void ScreenFlipping();

void ScreenClear(int width = 120, int height = 80);

void ScreenRelease();

void ScreenPrint(int x, int y, const wchar_t* string);

void SetColor(unsigned short color);
