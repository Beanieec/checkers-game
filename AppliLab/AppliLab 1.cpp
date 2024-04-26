#include <iostream>
#include <Windows.h>
#include "TicTacBoard.h"
#include "TicTacManager.h"
#include "TicTacPlayer.h"
#include "CellType.h"

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	TicTacManager manager;
	if (!manager.Init()) {
		std::cout << "Неверные данные, выходим...";
		return 0;
	}
	while (!manager.IsGameFinished()) {
		manager.MakeMove();
	}
	
	SetConsoleCP(866);
	return 0;
}