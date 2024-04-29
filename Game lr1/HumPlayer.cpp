#include "HumPlayer.h"

HumPlayer::HumPlayer() {}

HumPlayer::~HumPlayer() {}

void HumPlayer::SetupPlayer(std::string name, CellType cellType, CellType dcellType, CellType wcellType) {
	this->name = name;
	this->cellType = cellType;
	this->dcellType = dcellType;
	this->wcellType = wcellType;

}

void HumPlayer::SetBoard(ChekersBoard* board) {
	this->board = board;
}

//bool HumPlayer::

bool HumPlayer::MakeMove() {
	std::cout << "Игрок " << "\033[42m" << name << "\033[0m" << ", ваш ход..." << std::endl;
	std::cout << "Какой фигурой пойдёте? ";
	std::cout << "Введите координаты(A1-B2): ";
	std::cin >> dletter >> dcol >> letter >> col;

	drow = dletter - '@';
	zrow = letter - '@';
	
	//if (this->board->Woman(col, zrow, dcol, drow, this->cellType, this->wcellType)) {
	//	std::cout << "woma" << std::endl;
	//	/*if (this->board->OneMore(col, row, dcol, drow, this->cellType)) {
	//		if (this->board->CheckLegal(col, row, dcol, drow, this->cellType)) {
	//			this->board->SetCell(col, row, this->cellType, dcol, drow, this->dcellType);
	//			std::cout << "А дальше?" << std::endl;
	//		}
	//		board->Show();
	//		return MakeMove();
	//	}*/
	//	/*if (this->board->CheckLegal(col, row, dcol, drow, this->cellType)) {*/
	//		this->board->WSetCell(col, zrow, this->wcellType, dcol, drow, this->dcellType);
	//		std::cout << "womasasa" << std::endl;
	//		return true;
	//	//}
	//}
	
	if (this->board->OneMore(col, zrow, dcol, drow, this->cellType)) {
		if (this->board->CheckLegal(col, zrow, dcol, drow, this->cellType)) {
			if (this->board->Woman(col, zrow, dcol, drow, this->cellType, this->wcellType)) {
				this->board->WSetCell(col, zrow, this->wcellType, dcol, drow, this->dcellType);
			}
			else {
				this->board->SetCell(col, zrow, this->cellType, dcol, drow, this->dcellType);
				std::cout << "А дальше?" << std::endl;
			}
		}
		board->Show();
		return MakeMove();
	}
	if (this->board->CheckLegal(col, zrow, dcol, drow, this->cellType)) {
		if (this->board->Woman(col, zrow, dcol, drow, this->cellType, this->wcellType)) {
			this->board->WSetCell(col, zrow, this->wcellType, dcol, drow, this->dcellType);
		}
		else {
			this->board->SetCell(col, zrow, this->cellType, dcol, drow, this->dcellType);

		}
		return true;
	}
	
	return false;
}

std::string HumPlayer::GetName() {
	return this->name;
}