#pragma once

#ifndef _TICTACBOARD_H_

#define _TICTACBOARD_H_

#include <iostream>
#include <cmath>
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
	bool Woman(int xpos, int ypos, int dxpos, int dypos, CellType ct, CellType wct);
	bool OneMore(int xpos, int ypos, int dxpos, int dypos, CellType ct);
	bool MovesRule(int xpos, int ypos, int dxpos, int dypos, CellType ct);
	bool CheckLegal(int xpos, int ypos, int dxpos, int dypos, CellType ct);
	bool CheckEndCondition();
	bool IsVictory();
};

#endif