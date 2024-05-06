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

bool HumPlayer::MakeMove(int bufdcol, int bufdrow) {
	std::cout << "\033[32m====================================\033[0m" << std::endl;
	std::cout << "����� " << "\033[42m" << name << "\033[0m" << ", ��� ���..." << std::endl;
	std::cout << "����� ������� ������? " << std::endl;
	std::cout << "������� ����������(A1-B2): ";
	std::cin >> dletter >> dcol >> letter >> col;
	std::cout << "\033[32m====================================\033[0m" << std::endl;

	drow = dletter - '@';
	zrow = letter - '@';
	//������ �����
	if (onlyfightcount != onmorecount) {
		std::cout << "tut1" << std::endl;
		if (this->board->CheckLegal(col, zrow, bufdcol, bufdrow, dcol, drow, this->cellType)) {
			if (this->board->onlyFightRule(col, zrow, dcol, drow, this->cellType)) {
				if (this->board->Woman(zrow, this->cellType)) {
					this->board->WSetCell(col, zrow, this->wcellType, dcol, drow, this->dcellType);
				}
				else {
					this->board->SetCell(col, zrow, this->cellType, dcol, drow, this->dcellType);
				}
				if (this->board->OneMore(col, zrow, dcol, drow, this->cellType)) {
					board->Show();
					return MakeMove(col, zrow);
				}
				else
				{
					onlyfightcount++;
					return true;
				}
			}
			else {
				std::cout << "       \033[37;42m�� ������� ������ �����\033[0m" << std::endl;
				board->Show();
				return MakeMove(bufdcol, bufdrow);
			}
		}
		else {
			std::cout << "       \033[37;42m�� ������� ������ �����\033[0m" << std::endl;
			board->Show();
			return MakeMove(bufdcol, bufdrow);
		}
	}
	//������ ����
	if (this->board->onlyFight(this->cellType)) {
		std::cout << "tut2" << std::endl;
		if (this->board->onlyFightRule(col, zrow, dcol, drow, this->cellType)) { 
			if (this->board->Woman(zrow, this->cellType)) {
				this->board->WSetCell(col, zrow, this->wcellType, dcol, drow, this->dcellType);
			}
			else {
				this->board->SetCell(col, zrow, this->cellType, dcol, drow, this->dcellType);
			}
			if (this->board->OneMore(col, zrow, dcol, drow, this->cellType)) { 
				board->Show();
				onmorecount++;
				return MakeMove(col, zrow);
			}
			else
			{
				return true;
			}
		}
		else {
			std::cout << "       \033[37;42m�� ������� ������ �����\033[0m" << std::endl;
			return false;
		}
	}
	//����������� �����
	if (this->board->iisWoman(dcol, drow)) {
		if (this->board->WomanLegal(col, zrow, dcol, drow, this->cellType)) {
			this->board->WSetCell(col, zrow, this->wcellType, dcol, drow, this->dcellType);
			return true;
		}
		return false;
	}
	//������� ����
	if (this->board->CheckLegal(col, zrow, dcol, drow, this->cellType)) {
		if (this->board->Woman(zrow, this->cellType)) {
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