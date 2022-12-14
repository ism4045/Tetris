#pragma once
#ifndef _SCREEN_H
#define _SCREEN_H

#include <Windows.h>
#include <ctime>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include "BackGround.h"
#include "Tetris.h"
using namespace std;

class Screen {
public:
	Screen(Tetris& t);
	void ScreenFlipping();
	void ScreenClear();

	void DrawIntro();

	void DrawBackGround();
	void DrawManual();
	void DrawPause();
	void DrawPlayBoard();
	void DrawNextBlock();
	void DrawPlayerInfo();

	void Draw2DVector(vector<vector<string>> arr, pair<short, short> startPos);
	void Draw1DVector(vector<string> arr, pair<short, short> startPos);
	void DrawROE(bool endMenu);

	void RecieveHandle(int stage, bool endMenu);

	void TextColor(int foreGround, int backGround);
	void DecisionBlockColor(int blockType);
	void ResetColor();

private:
	BackGround BG;
	Tetris* tetris;

	bool screenIndex;
	HANDLE doubleBuffer[2];
	DWORD dw;

	clock_t introStart;
	clock_t introCurrent;
	bool blink;
};

#endif // !_SCREEN_H