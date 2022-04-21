#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <string>

#define STD_OUTPUT_HANDLE ((DWORD) - 11)
#define MAX_WORDS 12947


#pragma once

int randomNumber();
std::string convertWordToAscii(const std::string* word);
char textColor(int colorID, char textToColor);
