#include "TicTacPlayer.h"

TicTacPlayer::TicTacPlayer() {}

TicTacPlayer::~TicTacPlayer() {}

void TicTacPlayer::SetupPlayer(std::string name, CellType cellType, CellType dcellType) {
	this->name = name;
	this->cellType = cellType;
	this->dcellType = dcellType;

}

void TicTacPlayer::SetBoard(TicTacBoard* board) {
	this->board = board;
}

bool TicTacPlayer::MakeMove() {
	char dletter, letter;
	int drow, dcol;
	int row, col;
	std::cout << "Игрок " << "\033[42m" << name << "\033[0m" << ", ваш ход..." << std::endl;
	std::cout << "Какой фигурой пойдёте? ";
	std::cout << "Введите координаты(A1-B2): ";
	std::cin >> dletter >> dcol >> letter >> col;

//admin panel	
	/*if (dletter == '$') {
		this->board->
	}*/
//
	drow = dletter - '@';
	row = letter - '@';

	if (this->board->CheckLegal(col, row, dcol, drow, this->cellType)) {
		this->board->DelCell(dcol, drow, this->dcellType);
		this->board->SetCell(col, row, this->cellType);
		return true;
	}
	return false;
}

std::string TicTacPlayer::GetName() {
	return this->name;
}