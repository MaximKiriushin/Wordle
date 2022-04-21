#include "Helper.h"


int randomNumber()
{
	srand(time(NULL));

	return rand() % MAX_WORDS + 1;
}

std::string convertWordToAscii(const std::string* word)
{
	std::string wordInAscii;

	for (char c : *word) wordInAscii += std::to_string((int)c);

	return wordInAscii;
}

char textColor(int colorID, char textToColor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
	return textToColor;
}
