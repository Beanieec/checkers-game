#pragma once

#ifndef _TICTACBOARD_H_

#define _TICTACBOARD_H_

#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
#include "CellType.h"

class ChekersBoard {
	int boardsize;
	CellType** cells;
	bool bVictory = false;
	bool side = false;
public:
	ChekersBoard(int size);
	virtual ~ChekersBoard();
	void Show();
	void SetCell(int xpos, int ypos, CellType ct, int dxpos, int dypos, CellType dct);
	void WSetCell(int xpos, int ypos, CellType wct, int dxpos, int dypos, CellType dct);
	bool CanFight(int dypos, int dxpos, CellType ct);
	bool iisWoman(int dxpos, int dypos);
	bool Woman(int ypos, CellType ct);
	bool OneMore(int xpos, int ypos, int dxpos, int dypos, CellType ct);
	bool MovesRule(int xpos, int ypos, int dxpos, int dypos, CellType ct);
	bool CheckLegal(int xpos, int ypos, int dxpos, int dypos, CellType ct);
	bool WomanLegal(int xpos, int ypos, int dxpos, int dypos, CellType ct);
	bool onlyFight(CellType ct);
	void onlyFightcheck(CellType ct, std::vector<std::pair<std::pair<int, int>, bool>>* validCoords);
	bool onlyFightRule(int xpos, int ypos, int dxpos, int dypos, CellType ct);
	//void pairs([](int y, int x));
	bool CheckEndConditionScorecounter();
	bool IsVictory();
};

#endif