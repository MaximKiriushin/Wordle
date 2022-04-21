#pragma once
#include <iostream>
#include <stdio.h>
#include <Windows.h>

#include "Helper.h"
#include "SqliteDataBase.h"

#define MAX_LEN 5
#define ROW 5
#define COL 5

class gameEngine
{
public:
	gameEngine();
	~gameEngine();
	
	void startGame();
	void checkIfExist(std::string* word);

	void fillBoard(uint32_t columNumber, const std::string guessWord);
	void printBoard();

private:
	std::string _wordToGuess;
	std::string _board[5][5];
	SqliteDataBase db;
};

