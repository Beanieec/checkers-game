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

//bool TicTacPlayer::

bool TicTacPlayer::MakeMove() {
	std::cout << "����� " << "\033[42m" << name << "\033[0m" << ", ��� ���..." << std::endl;
	std::cout << "����� ������� ������? ";
	std::cout << "������� ����������(A1-B2): ";
	std::cin >> dletter >> dcol >> letter >> col;

	drow = dletter - '@';
	row = letter - '@';

	if (this->board->OneMore(col, row, dcol, drow, this->cellType)) {
		if (this->board->CheckLegal(col, row, dcol, drow, this->cellType)) {
			this->board->SetCell(col, row, this->cellType, dcol, drow, this->dcellType);
			std::cout << "� ������?" << std::endl;
		}
		board->Show();
		return MakeMove();
	}
	if (this->board->CheckLegal(col, row, dcol, drow, this->cellType)) {
		this->board->SetCell(col, row, this->cellType, dcol, drow, this->dcellType);
		return true;
	}
	return false;
}

std::string TicTacPlayer::GetName() {
	return this->name;
}