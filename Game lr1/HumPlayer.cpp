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

bool HumPlayer::MakeMove(int bufdcol, int bufdrow) {
	std::cout << "\033[32m====================================\033[0m" << std::endl;
	std::cout << "����� " << "\033[42m" << name << "\033[0m" << ", ��� ���..." << std::endl;
	std::cout << "����� ������� ������?" << std::endl;
	std::cout << "������� ����������(A1-B2): ";
	std::cin >> dletter >> dcol >> letter >> col;
	std::cout << "\033[32m====================================\033[0m" << std::endl;

	drow = dletter - '@';
	row = letter - '@';
	
	//������ �����
	if (onlyfightcount != onmorecount) {
		if (this->board->CheckLegal(col, row, bufdcol, bufdrow, dcol, drow, this->cellType)) {
			if (this->board->onlyFightRule(col, row, dcol, drow, this->cellType)) {
				if (this->board->Woman(row, this->cellType)) {
					this->board->SetCell(col, row, this->wcellType, dcol, drow, this->dcellType);
				}
				else if (this->board->iisWoman(dcol, drow)) {
					this->board->SetCell(col, row, this->wcellType, dcol, drow, this->dcellType); //��������� ���� �����
				}
				else {
					this->board->SetCell(this->cellType, col, row, dcol, drow, this->dcellType);
				}
				if (this->board->OneMore(col, row, dcol, drow, this->cellType)) {
					board->Show();
					return MakeMove(col, row);
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
	if (this->board->onlyFight(this->cellType)) { // ���� ����
		if (this->board->onlyFightRule(col, row, dcol, drow, this->cellType)) { //���� ���������� ��� �����
			if (this->board->Woman(row, this->cellType)) { //����������� ����� [8]
				this->board->SetCell(col, row, this->wcellType, dcol, drow, this->dcellType); //��������� ���� �����
			}
			else if (this->board->iisWoman(dcol, drow)) {
				this->board->SetCell(col, row, this->wcellType, dcol, drow, this->dcellType); //��������� ���� �����
			}
			else {
				this->board->SetCell(this->cellType, col, row, dcol, drow, this->dcellType); //��������� ���� �����
			}
			if (this->board->OneMore(col, row, dcol, drow, this->cellType)) { // ���� ��� ����
				board->Show();
				onmorecount++;
				return MakeMove(col, row);
			}
			else
			{
				return true; //���� �������� - ����� ����
			}
		}
		else {
			std::cout << "       \033[37;42m�� ������� ������ �����\033[0m" << std::endl;
			return false; // ���� ����, �� ����� �� ���
		}
	}
	//������� ����
	if (this->board->CheckLegal(col, row, dcol, drow, this->cellType, this->wcellType)) { //������� �������� ���� �����
		if (this->board->Woman(row, this->cellType)) { //����������� �����
			this->board->SetCell(col, row, this->wcellType, dcol, drow, this->dcellType); //��������� ���� �����
		}
		else if (this->board->iisWoman(dcol, drow)) { //�������� �� ����� ������
			this->board->SetCell(col, row, this->wcellType, dcol, drow, this->dcellType); //��������� ���� �����
		}
		else {
			this->board->SetCell(this->cellType, col, row, dcol, drow, this->dcellType); //��������� ���� �����
		}
		return true;
	}
	return false;
}

std::string HumPlayer::GetName() {
	return this->name;
}