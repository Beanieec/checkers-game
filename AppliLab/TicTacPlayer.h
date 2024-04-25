#pragma once

#ifndef _TICTACPLAYER_H_

#define _TICTACPLAYER_H_

#include "TicTacBoard.h"
#include "CellType.h"

class TicTacPlayer {
	TicTacBoard* board;
	CellType cellType;
	CellType dcellType;
	std::string name;
	char dletter, letter;
	int row, col, drow, dcol;
public:
	TicTacPlayer();
	virtual ~TicTacPlayer();
	void SetupPlayer(std::string name, CellType cellType, CellType dcellType);
	void SetBoard(TicTacBoard* board);
	bool MakeMove();
	std::string GetName();
};

#endif