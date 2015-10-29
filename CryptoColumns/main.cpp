#include <iostream>
#include <string>

#define VISITED_WORD '.'

using namespace std;

inline size_t findMinAlphabetPosition(const string &target) {
    char min = 'Z' + 1;
    size_t result = -1;
    for (size_t count = 0; count < target.length(); count++) {
        if (target[count] == VISITED_WORD)
            continue;
        if (target[count] < min) {
            result = count;
            min = target[count];
        }
    }

    return result;
}

int main()
{
    string keywords;
    string cipherText;
    while (true) {
        cin >> keywords;
        if (keywords == "THEEND")
            break;

        cin >> cipherText;
        string result = cipherText;

        size_t minAlphabetPosition;
        size_t columnsCount = keywords.length();
        size_t rowsCount = cipherText.length() / columnsCount;
        for (size_t count = 0; count < keywords.length(); count++) {
            minAlphabetPosition = findMinAlphabetPosition(keywords);
            keywords[minAlphabetPosition] = VISITED_WORD;

            // build one column for result
            size_t currentPosition = count * rowsCount;
            for (size_t alphabetCount = 0; alphabetCount < rowsCount; alphabetCount++) {
                result[minAlphabetPosition + alphabetCount * columnsCount] = cipherText[currentPosition + alphabetCount];
            }
        }

        cout << result << endl;
    }
    return 0;
}

