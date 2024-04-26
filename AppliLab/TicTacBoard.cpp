#include "TicTacBoard.h"

TicTacBoard::TicTacBoard(int size) {
	this->boardsize = size;
	this->cells = new CellType * [size];
	for (unsigned i = 0; i < size; i++) {
			cells[i] = new CellType[size];
		for (unsigned j = 1; j < boardsize; j ++){
			if ((i + j) % 2 == 0) {
				cells[i][j] = CELLTYPE_EWHITE;
			}
			else
				cells[i][j] = CELLTYPE_EBLACK;
		}
		if (boardsize > 8) {
			if (i % 2 == 1 && i <= 3) {
				for (unsigned j = 2; j <= 8; j += 2) {
					cells[i][j] = CELLTYPE_PWHITE;
				}
			}
			if (i == 2) {
				for (unsigned j = 1; j <= 8; j += 2) {
					cells[i][j] = CELLTYPE_PWHITE;
				}
			}

			if (i % 2 == 0 && i == 6 || i == 8) {
				for (unsigned j = 1; j <= 8; j += 2) {
					cells[i][j] = CELLTYPE_PBLACK;
				}
			}
			if (i == 7) {
				for (unsigned j = 2; j <= 8; j += 2) {
					cells[i][j] = CELLTYPE_PBLACK;
				}
			}
		}
	}
	/*cells[3][2] = CELLTYPE_PWHITE;
	cells[4][3] = CELLTYPE_PWHITE;
	cells[7][6] = CELLTYPE_PWHITE;
	cells[6][5] = CELLTYPE_PBLACK;
	cells[1][8] = CELLTYPE_PWHITE;*/
}

void TicTacBoard::Show() {
	std::cout << "  ";
	for (unsigned j = 1; j < boardsize; j++) {
		if (j > 9) {
			std::cout << j;
		}
		else
			std::cout << " " << j;
	}
	std::cout << std::endl;
	for (unsigned i = 1; i < boardsize; i++) {
		char abc[27];
		abc[i] = '@' + i;
		std::cout << abc[i] << " ";
		for (unsigned j = 0; j < boardsize; j++) {
			switch (cells[i][j]) {
			case CELLTYPE_PBLACK:
				std::cout << "\033[31;42m()\033[0m";
				break;
			case CELLTYPE_PWHITE:
				std::cout << "\033[37;42m()\033[0m";
				break;
			case CELLTYPE_EBLACK:
				std::cout << "\033[42m  \033[0m";
				break;
			case CELLTYPE_EWHITE:
				std::cout << "\033[47m  \033[0m";
				break;
			}
		}
		std::cout << std::endl;
	}
}

void TicTacBoard::SetCell(int xpos, int ypos, CellType ct, int dxpos, int dypos, CellType dct) {
	cells[ypos][xpos] = ct;
	cells[dypos][dxpos] = dct;
}

TicTacBoard::~TicTacBoard() {
	for (unsigned i = 0; i < boardsize; i++)
		delete[] cells[i];
	delete[] cells;
}


bool TicTacBoard::CanFight(int dypos, int dxpos, CellType ct) {

	if (ct == CELLTYPE_PWHITE) {
		if ((cells[dypos + 1][dxpos + 1]) == CELLTYPE_PBLACK) {
			if ((cells[dypos + 2][dxpos + 2]) == CELLTYPE_EBLACK) {
				side = false;
				return true;
			}
		}
		if ((cells[dypos + 1][dxpos - 1]) == CELLTYPE_PBLACK) {
			if ((cells[dypos + 2][dxpos - 2]) == CELLTYPE_EBLACK) {
				side = true;
				return true;
			}
		}
	}
	if (ct == CELLTYPE_PBLACK) {
		if ((cells[dypos - 1][dxpos + 1]) == CELLTYPE_PWHITE) {
			if ((cells[dypos - 2][dxpos + 2]) == CELLTYPE_EBLACK) {
				side = false;
				return true;
			}
		}
		if ((cells[dypos - 1][dxpos - 1]) == CELLTYPE_PWHITE) {
			if ((cells[dypos - 2][dxpos - 2]) == CELLTYPE_EBLACK) {
				side = true;
				return true;
			}
		}
	}
	return false;
}

bool TicTacBoard::OneMore(int xpos, int ypos, int dxpos, int dypos, CellType ct) {
	if (CanFight(dypos, dxpos, ct)) {
		if (ypos + 2 >= boardsize || xpos + 2 >= boardsize || ypos - 2 < 0 || xpos - 2 < 0) {
			return false;
		}
		else{
			if (CanFight(ypos, xpos, ct))
				return true;
		}
	}
	return false;
}

bool TicTacBoard::MovesRule(int xpos, int ypos, int dxpos, int dypos, CellType ct) {
	
	if (cells[dypos][dxpos] != ct) {
		return false;
	}

	if (CanFight(dypos, dxpos, ct)) {
		switch (ct)
		{
		case CELLTYPE_PWHITE:
			switch (side)
			{
			case true:
				if (ypos - dypos != 2 || std::abs(xpos - dxpos) != 2 || cells[ypos - 1][xpos + 1] != CELLTYPE_PBLACK)
					return false;
				cells[dypos + 1][dxpos - 1] = CELLTYPE_EBLACK;
				return true;
				break;
			case false:
				if (ypos - dypos != 2 || std::abs(xpos - dxpos) != 2 || cells[ypos - 1][xpos - 1] != CELLTYPE_PBLACK)
					return false;
				cells[dypos + 1][dxpos + 1] = CELLTYPE_EBLACK;
				return true;
				break;
			}
			break;
		case CELLTYPE_PBLACK:
			switch (side)
			{
			case true:
				if (dypos - ypos != 2 || std::abs(xpos - dxpos) != 2 || cells[ypos + 1][xpos + 1] != CELLTYPE_PWHITE)
					return false;
				cells[dypos - 1][dxpos - 1] = CELLTYPE_EBLACK;
				return true;
				break;
			case false:
				if (dypos - ypos != 2 || std::abs(xpos - dxpos) != 2 || cells[ypos + 1][xpos - 1] != CELLTYPE_PWHITE)
					return false;
				cells[dypos - 1][dxpos + 1] = CELLTYPE_EBLACK;
				return true;
				break;
			}
			break;
		}	
	}
	else {
		switch (ct)
		{
		case CELLTYPE_PWHITE:
			if (std::abs(xpos - dxpos) != 1 || ypos - dypos != 1) {
				return false;
			}
			return true;
			break;
		case CELLTYPE_PBLACK:
			if (std::abs(dxpos - xpos) != 1 || dypos - ypos != 1) {
				return false;
			}
			return true;
			break;
		}
	}
}

bool TicTacBoard::CheckLegal(int xpos, int ypos, int dxpos, int dypos, CellType ct) {
	
	if ((xpos < 0) || (xpos >= boardsize) || (ypos < 0) || (ypos >= boardsize)){
		return false;
	}

	if (cells[dypos][dxpos] == CELLTYPE_EBLACK) {
		return false;
	}
	
	if (MovesRule(xpos, ypos, dxpos, dypos, ct) != true) {
		return false;
	}
	return (cells[ypos][xpos] == CELLTYPE_EBLACK);
}


bool TicTacBoard::CheckEndCondition() {
	unsigned blackcount = 0;
	unsigned whitecount = 0;

	for (unsigned i = 1; i < boardsize; i++) {
		for (unsigned j = 0; j < boardsize; j++) {
			if (cells[i][j] == CELLTYPE_PBLACK) 
				blackcount++;
			if (cells[i][j] == CELLTYPE_PWHITE)
				whitecount++;
		}
	}
	if (blackcount < 1 || whitecount < 1)
		return true;
	return false;
}

bool TicTacBoard::IsVictory() {
	return bVictory;
}