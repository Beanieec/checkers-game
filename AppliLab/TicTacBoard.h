#pragma once

#ifndef _TICTACBOARD_H_

#define _TICTACBOARD_H_

#include <iostream>
#include <cmath>
#include "CellType.h"

class TicTacBoard {
	int boardsize;
	CellType** cells;
	bool bVictory = false;
	bool IsRowMade(unsigned row);
	bool IsColumnMade(unsigned col);
	bool IsDiagMade();
	bool IsBoardFull();
public:
	TicTacBoard(int size);
	virtual ~TicTacBoard();
	void Show();
	void DelCell(int xpos, int ypos, CellType dct);
	void SetCell(int xpos, int ypos, CellType ct);
	bool CheckLegal(int xpos, int ypos, int dxpos, int dypos, CellType ct);
	bool CheckEndCondition();
	bool IsVictory();
};

#endif