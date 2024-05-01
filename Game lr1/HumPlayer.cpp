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
	std::cout << "Èãðîê " << "\033[42m" << name << "\033[0m" << ", âàø õîä..." << std::endl;
	std::cout << "Êàêîé ôèãóðîé ïîéä¸òå? ";
	std::cout << "Ââåäèòå êîîðäèíàòû(A1-B2): ";
	std::cin >> dletter >> dcol >> letter >> col;

	drow = dletter - '@';
	zrow = letter - '@';
	
	//if (this->board->Woman(col, zrow, dcol, drow, this->cellType, this->wcellType)) {
	//	std::cout << "woma" << std::endl;
	//	/*if (this->board->OneMore(col, row, dcol, drow, this->cellType)) {
	//		if (this->board->CheckLegal(col, row, dcol, drow, this->cellType)) {
	//			this->board->SetCell(col, row, this->cellType, dcol, drow, this->dcellType);
	//			std::cout << "À äàëüøå?" << std::endl;
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
	

	//if (this->board->OneMore(col, zrow, dcol, drow, this->cellType)) {
	//	std::cout << "tut1" << std::endl;
	//	/*if (this->board->CheckLegal(col, zrow, dcol, drow, this->cellType)) {
	//		if (this->board->Woman(zrow, this->cellType)) {
	//			this->board->WSetCell(col, zrow, this->wcellType, dcol, drow, this->dcellType);
	//		}
	//		else {
	//			this->board->SetCell(col, zrow, this->cellType, dcol, drow, this->dcellType);
	//			std::cout << "À äàëüøå?" << std::endl;
	//		}
	//	}*/
	//	if (this->board->onlyFight(this->cellType)) {
	//		if (this->board->onlyFightRule(col, zrow, dcol, drow, this->cellType)) {
	//			this->board->SetCell(col, zrow, this->cellType, dcol, drow, this->dcellType);
	//			if (this->board->onlyFight(this->cellType)) {
	//				board->Show();
	//				return MakeMove();
	//			}
	//			else
	//			{
	//				return true;
	//			}
	//		}
	//		else {
	//			std::cout << "\033[37;42mÂÛ ÎÁßÇÀÍÛ ÑÚÅÑÒÜ ØÀØÊÓ\033[0m" << std::endl;
	//			return false;
	//		}
	//	}
	//	board->Show();
	//	return MakeMove();
	//}
	if (this->board->onlyFight(this->cellType)) {
		std::cout << "tut2" << std::endl;
		if (this->board->onlyFightRule(col, zrow, dcol, drow, this->cellType)) { //ÏÐÎÁËÅÌÛ ÑÎ ÑÒÎÐÎÍÀÌÈ
			this->board->SetCell(col, zrow, this->cellType, dcol, drow, this->dcellType);
			if (this->board->onlyFight(this->cellType)) { //ÍÅ ÏÐÀÂÈËÜÍÎ, ÍÓÆÍÎ ÒÎËÜÊÎ ÏÎÑËÅ ÕÎÄÀ ÏÐÎÂÅÐßÒÜ
				board->Show();
				return MakeMove();
			}
			else
			{
				return true;
			}
		}
		else {
			std::cout << "\033[37;42mÂÛ ÎÁßÇÀÍÛ ÑÚÅÑÒÜ ØÀØÊÓ\033[0m" << std::endl;
			return false;
		}
	}
	if (this->board->iisWoman(dcol, drow)) {
		if (this->board->WomanLegal(col, zrow, dcol, drow, this->cellType)) {
			std::cout << "WOMKA" << std::endl;
			this->board->WSetCell(col, zrow, this->wcellType, dcol, drow, this->dcellType);
			return true;
		}
		return false;
	}
	if (this->board->CheckLegal(col, zrow, dcol, drow, this->cellType)) {
		if (this->board->Woman(zrow, this->cellType)) {
			std::cout << "CHECKSS" << std::endl;
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