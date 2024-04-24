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
			/*std::cout << " ";*/
		}
		std::cout << std::endl;
	}
}
void TicTacBoard::DelCell(int xpos, int ypos, CellType dct) {
	cells[ypos][xpos] = dct;
		
}

void TicTacBoard::SetCell(int xpos, int ypos, CellType ct) {
	cells[ypos][xpos] = ct;
}

TicTacBoard::~TicTacBoard() {
	for (unsigned i = 0; i < boardsize; i++)
		delete[] cells[i];
	delete[] cells;
}



bool TicTacBoard::CheckLegal(int xpos, int ypos, int dxpos, int dypos, CellType ct) {
	if ((xpos < 0) || (xpos > boardsize) || (ypos < 0) || (ypos > boardsize)){
		return false;
	}
	
	if (ct == CELLTYPE_PWHITE) {
		for (int i = -1; i < 2; i += 2) {
			if ((cells[dypos + 1][dxpos + i]) == CELLTYPE_PBLACK) {
				if ((cells[dypos + 2][dxpos + i + i]) == CELLTYPE_EBLACK) {
					if (cells[dypos][dxpos] != CELLTYPE_PWHITE) {
						std::cout << "1!" << std::endl;
						return false;
					}
					if (cells[ypos][xpos] != CELLTYPE_EBLACK) {
						return false;
					}
					if (cells[ypos - 1][xpos - i] != CELLTYPE_PBLACK) {
						std::cout << "ne tuda" << std::endl;
						return false;
					}
					if (std::abs(xpos - dxpos) != 2) {
						std::cout << "2!" << std::endl;
						return false;
					}
					if (ypos - dypos != 2) {
						std::cout << "3!" << std::endl;
						return false;
					}
					cells[dypos + 1][dxpos + i] = CELLTYPE_EBLACK;
					break;
				}
				if (i != 1)
					continue;
			}
			if (i != 1)
				continue;
			if (cells[dypos][dxpos] != CELLTYPE_PWHITE) {
				std::cout << "1" << std::endl;
				return false;
			}
			if (std::abs(xpos - dxpos) != 1) {
				std::cout << "2" << std::endl;
				return false;
			}
			if (ypos - dypos != 1) {
				std::cout << "3" << std::endl;
				return false;
			}
		}
	}
		
	if (ct == CELLTYPE_PBLACK) {
		for (int i = -1; i < 2; i += 2) {
			if ((cells[dypos - 1][dxpos + i]) == CELLTYPE_PWHITE) {
				if ((cells[dypos - 2][dxpos + i + i]) == CELLTYPE_EBLACK) {
					if (cells[dypos][dxpos] != CELLTYPE_PBLACK) {
						std::cout << "1!" << std::endl;
						return false;
					}
					if (cells[ypos][xpos] != CELLTYPE_EBLACK) {
						return false;
					}
					if (cells[ypos + 1][xpos - i] != CELLTYPE_PWHITE) {
						std::cout << "ne tuda" << std::endl;
						return false;
					}
					if (std::abs(xpos - dxpos) != 2) {
						std::cout << "2!" << std::endl;
						return false;
					}
					if (dypos - ypos != 2) {
						std::cout << "3!" << std::endl;
						return false;
					}
					cells[dypos - 1][dxpos + i] = CELLTYPE_EBLACK;
					break;
				}
				if (i != 1)
					continue;
			}
			if (i != 1)
				continue;
			if (cells[dypos][dxpos] != CELLTYPE_PBLACK) {
				std::cout << "1" << std::endl;
				return false;
			}
			if (std::abs(xpos - dxpos) != 1) {
				std::cout << "2" << std::endl;
				return false;
			}
			if (dypos - ypos != 1) {
				std::cout << "3" << std::endl;
				return false;
			}
		}
	}
	
	if (cells[dypos][dxpos] == CELLTYPE_EBLACK) {
		std::cout << "!!" << std::endl;
		return false;
	}
	return (cells[ypos][xpos] == CELLTYPE_EBLACK);
}

bool TicTacBoard::IsRowMade(unsigned row) {
	int numX = 0, numO = 0;
	for (unsigned i = 0; i < boardsize; i++) {
		if (cells[row][i] == CELLTYPE_PBLACK) numO++;
		if (cells[row][i] == CELLTYPE_PWHITE) numX++;
	}
	if ((numX == boardsize) || (numO == boardsize)) {
		bVictory = true;
		return true;
	}
	return false;
}

bool TicTacBoard::IsColumnMade(unsigned col) {
	int numX = 0, numO = 0;
	for (unsigned i = 0; i < boardsize; i++) {
		if (cells[i][col] == CELLTYPE_PBLACK) numO++;
		if (cells[i][col] == CELLTYPE_PWHITE) numX++;
	}

	if ((numX == boardsize) || (numO == boardsize)) {
		bVictory = true;
		return true;
	}
	return false;
}

bool TicTacBoard::IsDiagMade() {
	int numX = 0, numO = 0;
	for (unsigned i = 0; i < boardsize; i++) {
		if (cells[i][i] == CELLTYPE_PBLACK) numO++;
		if (cells[i][i] == CELLTYPE_PWHITE) numX++;
	}
	if ((numX == boardsize) || (numO == boardsize)) {
		bVictory = true;
		return true;
	}
	return false;
}

bool TicTacBoard::IsBoardFull() {
	int numX = 0, numO = 0;
	for (unsigned i = 0; i < boardsize; i++) {
		for (unsigned j = 0; j < boardsize; j++) {
			if (cells[i][j] == CELLTYPE_PBLACK) numO++;
			if (cells[i][j] == CELLTYPE_PWHITE) numX++;
		}
	}
	if ((numX + numO) == (boardsize * boardsize))
		return true;

	return false;
}

bool TicTacBoard::CheckEndCondition() {
	for (unsigned i = 0; i < boardsize; i++) {
		if (IsRowMade(i) || IsColumnMade(i))
			return true;
	}
	if (IsDiagMade() || IsBoardFull())
		return true;

	return false;
}

bool TicTacBoard::IsVictory() {
	return bVictory;
}