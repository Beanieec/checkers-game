#pragma once

#ifndef _TICTACMANAGER_H_

#define _TICTACMANAGER_H_

#include <iostream>
#include <string>
#include "TicTacBoard.h"
#include "TicTacPlayer.h"
#include "CellType.h"

using namespace std;

class TicTacManager {
	TicTacBoard* board;
	TicTacPlayer* player1;
	TicTacPlayer* player2;
	TicTacPlayer* currentPlayer;
	bool bGameFinished = false;
public:
	TicTacManager();
	virtual ~TicTacManager();
	bool Init();
	void ShowBoard();
	void MakeMove();
	bool IsGameFinished();
private:
	string wh = "\033[31;42m()\033[0m";
	string bk = "\033[37;42m()\033[0m";
	string kwh = "\033[31;42m[]\033[0m";
	string kbk = "\033[37;42m[]\033[0m";
};

#endif