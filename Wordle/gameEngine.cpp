#include "gameEngine.h"

gameEngine::gameEngine()
{
	this->_wordToGuess = db.getRandomWord();
}

gameEngine::~gameEngine() { 
}

void gameEngine::startGame()
{	
	int column = 0;
	std::string userGuess;
	std::cout << this->_wordToGuess << std::endl;
	std::cout << "Hello and welcome to my wordle prototype\n";

	while ( (userGuess != this->_wordToGuess) && (column != 5) ){
		std::cout << "Enter your guess:\n";
		std::cin >> userGuess;
		std::cout << "\n";
		checkIfExist(&userGuess);
		fillBoard(column, userGuess);
		printBoard();
		column++;
	}
	
	(column == 5) ? std::cout << "\n0You run out of tries :(\n" : std::cout << "Good Job!\n";
}

void gameEngine::checkIfExist(std::string* word)
{
	while (db.checkIfWordExist(word)) {
		std::cout << "This word doesn't exist pick anther one:\n";
		std::cin >> *word;
	}
	std::cout << "\n";
}

void gameEngine::fillBoard(uint32_t col, const std::string guessWord)
{
	for (int i = 0; i < ROW; i++)
	{
		if (guessWord[i] == this->_wordToGuess[i]) {
			this->_board[col][i] = guessWord[i];
			this->_board[col][i] += "g";
		}
		else if (this->_wordToGuess.find(guessWord[i]) != std::string::npos) {
			this->_board[col][i] = guessWord[i];
			this->_board[col][i] += "y";
		}
		else {
			this->_board[col][i] = guessWord[i];
		}
	}

}

void gameEngine::printBoard()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (this->_board[i][j].length() >= 1) {
				if ((this->_board[i][j])[1] == 'g') {
					std::cout << textColor(2, this->_board[i][j][0]);
					textColor(7, ' ');
				}
				else if ((this->_board[i][j])[1] == 'y') {
					std::cout << textColor(6, this->_board[i][j][0]);
					textColor(7, ' ');
				}
				else {
					std::cout << this->_board[i][j];
				}
			}

		}
		std::cout << "\n";
	}
}
