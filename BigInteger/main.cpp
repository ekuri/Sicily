#include <iostream>
#include <string>
#include <stdlib.h>

#define FRAGMENT_LENGTH 6

using namespace std;

int computeRepresentation(const string &targetNumber, const int startPosition, const int basis, const int fowardRepresentation);

int main()
{
    int testCount = 0;
    cin >> testCount;
    for (int currentTestCount = 0; currentTestCount < testCount; currentTestCount++) {
        int digitsCount = 0;
        cin >> digitsCount;

        int digits[digitsCount];
        for (int currentDigitsCount = 0; currentDigitsCount < digitsCount; currentDigitsCount++) {
            cin >> digits[currentDigitsCount];
        }

        string targetNumber;
        cin >> targetNumber;

        cout << "(";
        for (int currentDigitsCount = 0; currentDigitsCount < digitsCount; currentDigitsCount++) {
            int fowardRepresentation = 0;
            for (int currentComputingPosition = 0; currentComputingPosition < targetNumber.length(); currentComputingPosition += FRAGMENT_LENGTH) {
                fowardRepresentation = computeRepresentation(targetNumber, currentComputingPosition, digits[currentDigitsCount], fowardRepresentation);
            }

            cout << fowardRepresentation;
            if (currentDigitsCount == digitsCount - 1) {
                cout << ")" << endl;
            } else {
                cout << ",";
            }
        }
    }
    return 0;
}

int computeRepresentation(const string &targetNumber, const int startPosition, const int basis, const int fowardRepresentation) {
    if (basis > 1000) {
        throw "error input";
    }

    int endPosition = startPosition + FRAGMENT_LENGTH - 1;
    if (endPosition >= targetNumber.length()) {
        endPosition = targetNumber.length() - 1;

    }
    int currentComputingNumber = fowardRepresentation;
    for (int powerCount = 0; powerCount < (endPosition - startPosition + 1); powerCount++) {
        currentComputingNumber *= 10;
    }

    currentComputingNumber += atoi(targetNumber.substr(startPosition, endPosition - startPosition + 1).c_str());

    return currentComputingNumber % basis;

    /*int currentComputingNumber = atoi(targetNumber.substr(startPosition, 1).c_str());
    currentComputingNumber += fowardRepresentation << 8;

    return currentComputingNumber % basis;*/
}
