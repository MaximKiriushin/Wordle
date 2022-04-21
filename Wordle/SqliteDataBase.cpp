#include "SqliteDataBase.h"



SqliteDataBase::SqliteDataBase() {
    std::string dbFileName = "wordleList";
    char* errmsg = 0;
    int fileExist = _access(dbFileName.c_str(), 0);

    int res = sqlite3_open(dbFileName.c_str(), &this->db);
    if (res != SQLITE_OK) {
        this->db = nullptr;
        std::cout << "Failed to open wordleList" << std::endl;
    }
}

SqliteDataBase::~SqliteDataBase() {
    sqlite3_close(this->db);
}

void SqliteDataBase::clear() {
    remove("wordleList");
}

const std::string SqliteDataBase::getRandomWord()
{
    std::string randomWord;

    std::string randomWordRequest = "SELECT WORD from WORDS where ROWID=" + std::to_string(randomNumber()) + ";";
    int res = 0;
    char* errorMsg = nullptr;

    auto callback = [](void* data, int argc, char** argv, char** colName)
    {
        *((std::string*)data) = argv[0];
        return 0;
    };


    res = sqlite3_exec(db, randomWordRequest.c_str(), callback, &randomWord, &errorMsg);

    return randomWord;

}

bool SqliteDataBase::checkIfWordExist(const std::string* word)
{

    std::string wordCheckd;

    std::string wordRequest = "SELECT WORD from WORDS where ID=" + convertWordToAscii(word) + ";";
    int res = 0;
    char* errorMsg = nullptr;

    auto callback = [](void* data, int argc, char** argv, char** colName)
    {
        *((std::string*)data) = argv[0];
        return 0;
    };


    res = sqlite3_exec(db, wordRequest.c_str(), callback, &wordCheckd, &errorMsg);

    return wordCheckd == "";
}


