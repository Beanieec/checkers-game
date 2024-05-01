#include "GameManager.h"

GameManager::GameManager() {}

bool GameManager::Init() {
	unsigned int boardsize = 9;
	std::string playerName;
	this->board = new ChekersBoard(boardsize);
	this->player1 = new HumPlayer();
	this->player2 = new HumPlayer();
	//cin.ignore();
	std::cout << "Введите имя игрока, играющего \033[47m \033[0m: ";
	std::getline(std::cin, playerName);
	player1->SetupPlayer(playerName, CELLTYPE_PWHITE, CELLTYPE_EBLACK, CELLTYPE_WOMWHITE);
	std::cout << "Введите имя игрока, играющего \033[41m \033[0m: ";
	std::getline(std::cin, playerName);
	player2->SetupPlayer(playerName, CELLTYPE_PBLACK, CELLTYPE_EBLACK, CELLTYPE_WOMBLACK);
	player2->SetBoard(this->board);
	player1->SetBoard(this->board);
	currentPlayer = player1;
	std::cout << "Обычные пешки имеют вид - " << wh << " ; " << bk << std::endl;
	std::cout << "Дамки имеют вид - " << kwh << " ; " << kbk << std::endl;

	return true;
}

GameManager::~GameManager() {
	delete this->player2;
	delete this->player1;
	delete this->board;
}

void GameManager::ShowBoard() {
	this->board->Show();
}

void GameManager::MakeMove() {
	ShowBoard();
	while (!currentPlayer->MakeMove()) {
		std::cout << "\033[41mНедопустимый ход, попробуйте ещё раз!\033[0m" << std::endl;
		ShowBoard();
	}
	if (this->board->CheckEndConditionScorecounter()) {
		if (this->board->CheckEndConditionScorecounter())
			std::cout << "  \033[42m" << "Игрок " << currentPlayer->GetName() << " победил!" << "\033[0m" << std::endl;
		else
			std::cout << "Ничья!" << std::endl;
		this->bGameFinished = true;
		ShowBoard();
		std::cout << "      \033[41mКоНеЦ!!!\033[0m" << std::endl;
		return;
	}
	currentPlayer = (currentPlayer == player1) ? player2 : player1;
}

bool GameManager::IsGameFinished() {
	return bGameFinished;
}