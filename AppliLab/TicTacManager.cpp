#include "TicTacManager.h"

TicTacManager::TicTacManager() {}

bool TicTacManager::Init() {
	unsigned int boardsize = 9;
	std::string playerName;
	this->board = new TicTacBoard(boardsize);
	this->player1 = new TicTacPlayer();
	this->player2 = new TicTacPlayer();
	//cin.ignore();
	std::cout << "������� ��� ������, ��������� \033[47m \033[0m: ";
	std::getline(std::cin, playerName);
	player1->SetupPlayer(playerName, CELLTYPE_PWHITE, CELLTYPE_EBLACK);
	std::cout << "������� ��� ������, ��������� \033[41m \033[0m: ";
	std::getline(std::cin, playerName);
	player2->SetupPlayer(playerName, CELLTYPE_PBLACK, CELLTYPE_EBLACK);
	player2->SetBoard(this->board);
	player1->SetBoard(this->board);
	currentPlayer = player1;
	std::cout << "������� ����� ����� ��� - " << wh << " ; " << bk << std::endl;
	std::cout << "����� ����� ��� - " << kwh << " ; " << kbk << std::endl;

	return true;
}

TicTacManager::~TicTacManager() {
	delete this->player2;
	delete this->player1;
	delete this->board;
}

void TicTacManager::ShowBoard() {
	this->board->Show();
}

void TicTacManager::MakeMove() {
	ShowBoard();
	while (!currentPlayer->MakeMove()) {
		std::cout << "������������ ���, ���������� ��� ���." << std::endl;
		ShowBoard();
	}
	/*if () {

	}*/
	if (this->board->CheckEndCondition()) {
		if (this->board->CheckEndCondition())
			std::cout << "����� " << currentPlayer->GetName() << " �������!" << std::endl;
		else
			std::cout << "�����!" << std::endl;
		this->bGameFinished = true;
		ShowBoard();
		return;
	}
	currentPlayer = (currentPlayer == player1) ? player2 : player1;
}

bool TicTacManager::IsGameFinished() {
	return bGameFinished;
}