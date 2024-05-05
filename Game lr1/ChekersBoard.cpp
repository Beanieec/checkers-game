#include "ChekersBoard.h"

ChekersBoard::ChekersBoard(int size) {
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
	/*cells[1][2] = CELLTYPE_PWHITE;
	cells[2][3] = CELLTYPE_PBLACK;*/
	//cells[6][3] = CELLTYPE_PWHITE;
	////cells[2][7] = CELLTYPE_PWHITE;
	////cells[3][2] = CELLTYPE_PBLACK;
	//cells[4][5] = CELLTYPE_PWHITE;
	////cells[3][6] = CELLTYPE_PBLACK;
	////cells[3][8] = CELLTYPE_PBLACK;
	//cells[5][6] = CELLTYPE_PBLACK;
	//cells[7][6] = CELLTYPE_PBLACK;
}
void ChekersBoard::Show() {
	std::cout << "        ";
	std::cout << "\033[30;43m  \033[0m";
	for (unsigned j = 1; j < boardsize; j++) {
		if (j > 9) {
			std::cout << j;
		}
		else
			std::cout << "\033[4;30;43m " << j << "\033[0m";
	}
	std::cout << "\033[30;43m  \033[0m" << std::endl;
	for (unsigned i = 1; i < boardsize; i++) {
		char abc[27];
		abc[i] = '@' + i;
		std::cout << "        \033[30;43m " << abc[i] << "\033[0m";
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
			case CELLTYPE_WOMBLACK:
				std::cout << "\033[31;42m[]\033[0m";
				break;
			case CELLTYPE_WOMWHITE:
				std::cout << "\033[37;42m[]\033[0m";
				break;
			}
		}
		std::cout << "\033[30;43m" << abc[i] << " \033[0m" << std::endl;
	}
	std::cout << "        \033[4;30;43m  \033[0m";
	for (unsigned j = 1; j < boardsize; j++) {
		if (j > 9) {
			std::cout << j;
		}
		else
			std::cout << "\033[4;30;43m" << j << " \033[0m";
	}
	std::cout << "\033[4;30;43m  \033[0m" << std::endl;
}

void ChekersBoard::WSetCell(int xpos, int ypos, CellType wct, int dxpos, int dypos, CellType dct) { //отрисовка дамки
		cells[ypos][xpos] = wct;
		cells[dypos][dxpos] = dct;
}

void ChekersBoard::SetCell(int xpos, int ypos, CellType ct, int dxpos, int dypos, CellType dct) { //отрисовка хода
		cells[ypos][xpos] = ct;
		cells[dypos][dxpos] = dct;
	
}

ChekersBoard::~ChekersBoard() {
	for (unsigned i = 0; i < boardsize; i++)
		delete[] cells[i];
	delete[] cells;
}

bool ChekersBoard::CanFight(int dypos, int dxpos, CellType ct) { //возможность нападения
	if (ct == CELLTYPE_PWHITE) {
		if (dypos + 2 >= boardsize) {
			return false;
		}
		if ((cells[dypos + 1][dxpos + 1]) == CELLTYPE_PBLACK) {
			if ((cells[dypos + 2][dxpos + 2]) == CELLTYPE_EBLACK) {
				if (cells[dypos][dxpos] == CELLTYPE_PWHITE) {
					side = false;
					return true;
				}
			}
		}
		if ((cells[dypos + 1][dxpos - 1]) == CELLTYPE_PBLACK) {
			if ((cells[dypos + 2][dxpos - 2]) == CELLTYPE_EBLACK) {
				if (cells[dypos][dxpos] == CELLTYPE_PWHITE) {
					side = true;
					return true;
				}
			}
		}
	}
	if (ct == CELLTYPE_PBLACK) {
		if (dypos - 2 <= 0) {
			return false;
		}
		if ((cells[dypos - 1][dxpos + 1]) == CELLTYPE_PWHITE) {
			if ((cells[dypos - 2][dxpos + 2]) == CELLTYPE_EBLACK) {
				if (cells[dypos][dxpos] == CELLTYPE_PBLACK) {
					side = false;
					return true;
				}
			}
		}
		if ((cells[dypos - 1][dxpos - 1]) == CELLTYPE_PWHITE) {
			if ((cells[dypos - 2][dxpos - 2]) == CELLTYPE_EBLACK) {
				if (cells[dypos][dxpos] == CELLTYPE_PBLACK) {
					side = true;
					return true;
				}
			}
		}
	}
	return false;
}

bool ChekersBoard::iisWoman(int dxpos, int dypos) {
	if (cells[dypos][dxpos] == CELLTYPE_WOMWHITE || cells[dypos][dxpos] == CELLTYPE_WOMBLACK) {
		return true;
	}
	return false;
}

bool ChekersBoard::WomanLegal(int xpos, int ypos, int dxpos, int dypos, CellType ct) {
	if ((xpos < 0) || (xpos >= boardsize) || (ypos < 0) || (ypos >= boardsize))
		return false;
	switch (ct)
	{
	case CELLTYPE_PWHITE:
		if (std::abs(xpos - dxpos) != 1 || std::abs(ypos - dypos) != 1) {
			return false;
		}
		return true;
		break;
	case CELLTYPE_PBLACK:
		if (std::abs(dxpos - xpos) != 1 || std::abs(dypos - ypos) != 1) {
			return false;
		}
		return true;
		break;
	}
}

bool ChekersBoard::Woman(int ypos, CellType ct) { //дамка
	for (unsigned i = 1; i < boardsize; i++) {
		if (ct == CELLTYPE_PWHITE) {
			if (ypos == 8)
				return true;
		}
		if (ct == CELLTYPE_PBLACK) {
			if (ypos == 1)
				return true;
		}
	}
	return false;
}

bool ChekersBoard::OneMore(int xpos, int ypos, int dxpos, int dypos, CellType ct) { // повторное нападение
	if (CanFight(ypos, xpos, ct)) {
		return true;
	}
	else
		return false;
}

bool ChekersBoard::MovesRule(int xpos, int ypos, int dxpos, int dypos, CellType ct) { //правила хода
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

bool ChekersBoard::CheckLegal(int xpos, int ypos, int dxpos, int dypos, CellType ct) { //базовые условия
	if ((xpos < 0) || (xpos >= boardsize) || (ypos < 0) || (ypos >= boardsize))
		return false;
	if (cells[dypos][dxpos] == CELLTYPE_EBLACK) 
		return false;
	if (cells[dypos][dxpos] == CELLTYPE_EWHITE) 
		return false;
	if (cells[ypos][xpos] == CELLTYPE_EWHITE)
		return false;
	if (!MovesRule(xpos, ypos, dxpos, dypos, ct)) 
		return false;
	return (cells[ypos][xpos] == CELLTYPE_EBLACK);
}

bool ChekersBoard::CheckLegal(int xpos, int ypos, int bufxpos, int bufypos, int dxpos, int dypos, CellType ct) {
	if (bufxpos != dxpos || bufypos != dypos) {
		return false;
	}
	return true;
}

bool ChekersBoard::onlyFightRule(int xpos, int ypos, int dxpos, int dypos, CellType ct) {
	std::vector<std::pair<std::pair<int, int>, bool>> coords;
	onlyFightcheck(ct, &coords);
	int count = 0;
	int total = coords.size();
	for (const auto& coord : coords) {
		count++;
		bool rule = false;
		int j = coord.first.first;
		int i = coord.first.second;
		bool sside = coord.second;
		if (i != dxpos || j != dypos) {
			if (count == total)
				return false;
			else
				continue;
		}
		switch (ct)
		{
		case CELLTYPE_PWHITE:
			switch (sside)
			{
			case true:
				if (ypos - j != 2 || std::abs(xpos - i) != 2 || cells[ypos - 1][xpos + 1] != CELLTYPE_PBLACK) {
					if (count == total)
						return false;
					else
						continue;
				}
				else {
					cells[ypos - 1][xpos + 1] = CELLTYPE_EBLACK;
					return true;
				}
				break;
			case false:
				if (ypos - j != 2 || std::abs(xpos - i) != 2 || cells[ypos - 1][xpos - 1] != CELLTYPE_PBLACK) {
					if (count == total)
						return false;
					else
						continue;
				}
				else {
					cells[ypos - 1][xpos - 1] = CELLTYPE_EBLACK;
					return true;
				}
				break;
			}
			break;
		case CELLTYPE_PBLACK:
			switch (sside)
			{
			case true:
				if (j - ypos != 2 || std::abs(xpos - i) != 2 || cells[ypos + 1][xpos + 1] != CELLTYPE_PWHITE) {
					if (count == total)
						return false;
					else
						continue;
				}
				else {
					cells[j - 1][i - 1] = CELLTYPE_EBLACK;
					return true;
				}
				break;
			case false:
				if (j - ypos != 2 || std::abs(xpos - i) != 2 || cells[ypos + 1][xpos - 1] != CELLTYPE_PWHITE) {
					if (count == total)
						return false;
					else
						continue;
				}
				else {
					cells[j - 1][i + 1] = CELLTYPE_EBLACK;
					return true;
				}
				break;
			}
			break;
		}
	}
}

bool ChekersBoard::onlyFight(CellType ct) {
	std::vector<std::pair<std::pair<int, int>, bool>> coords;
	onlyFightcheck(ct, &coords);
	for (const auto& coord : coords) {
		int j = coord.first.first;
		int i = coord.first.second;
		bool sside = coord.second;
	}
	return !coords.empty();
}

void ChekersBoard::onlyFightcheck(CellType ct, std::vector<std::pair<std::pair<int, int>, bool>>* validCoords) {
	for (int i = 1; i < boardsize; i++) {
		for (int j = 0; j < boardsize; j++) {
			if (CanFight(j, i, ct)) {
				validCoords->push_back(std::make_pair(std::make_pair(j, i), side));
			}
		}
	}
}

bool ChekersBoard::CheckEndConditionScorecounter() { //победа
	int blackcount = 0;
	int whitecount = 0;

	for (unsigned i = 1; i < boardsize; i++) {
		for (unsigned j = 0; j < boardsize; j++) {
			if (cells[i][j] == CELLTYPE_PBLACK || cells[i][j] == CELLTYPE_WOMBLACK)
				blackcount++;
			if (cells[i][j] == CELLTYPE_PWHITE || cells[i][j] == CELLTYPE_WOMWHITE)
				whitecount++;
		}
	}
	if ((whitecount > 0) && (blackcount > 0)) {
		if (whitecount > 9 && blackcount > 9)
			std::cout << "           " << "\033[37;42m" << whitecount << "/12\033[0m" << " -- " << "\033[31;42m" << blackcount << "/12\033[0m" << std::endl;
		else
			std::cout << "            " << "\033[37;42m" << whitecount << "/12\033[0m" << " -- " << "\033[31;42m" << blackcount << "/12\033[0m" << std::endl;
	}
	if (blackcount < 1 || whitecount < 1)
		return true;
	return false;
	
}

bool ChekersBoard::IsVictory() {
	return bVictory;
}