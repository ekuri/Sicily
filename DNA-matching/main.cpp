#include <iostream>
#include <string>
#include <deque>

using namespace std;

bool formByDNADeque(deque<string> &DNADeque, const string &rightDNA);
bool canMatchDNA(const string &leftDNA, const string &rightDNA);
bool isBasePair(const char &left, const char &right);

int main()
{
    int testCaseCount;
    cin >> testCaseCount;

    for (int currentTestCount = 0; currentTestCount < testCaseCount; currentTestCount++) {
        int DNACount;
        cin >> DNACount;

        string tempDNA;
        deque<string> DNADeque;
        int matchCount = 0;
        for (int currentDNACount = 0; currentDNACount < DNACount; currentDNACount++) {
            cin >> tempDNA;
            if (formByDNADeque(DNADeque, tempDNA)) {
                matchCount++;
            } else {
                DNADeque.push_back(tempDNA);
            }
        }

        cout << matchCount << endl;
    }
    return 0;
}

bool formByDNADeque(deque<string> &DNADeque, const string &rightDNA) {
    if (DNADeque.empty()) {
        return false;
    }

    for (deque<string>::iterator it = DNADeque.begin(); it != DNADeque.end(); it++) {
        if (canMatchDNA(*it, rightDNA)) {
            DNADeque.erase(it);
            return true;
        }
    }

    return false;
}

bool canMatchDNA(const string &leftDNA, const string &rightDNA) {
    if (leftDNA.length() != rightDNA.length()) {
        return false;
    }

    int count = 0;
    // 正向顺序比较
    for (; count < leftDNA.length(); count++) {
        if (!isBasePair(leftDNA[count], rightDNA[count])) {
            break;
        }
    }

    if (count == leftDNA.length()) {
        return true;
    }

    /*// 逆向顺序比较
    int DNALength = leftDNA.length();
    for (; count < leftDNA.length(); count++) {
        if (!isBasePair(leftDNA[count], rightDNA[DNALength - 1 - count])) {
            break;
        }
    }

    if (count == leftDNA.length()) {
        return true;
    }*/

    return false;
}

bool isBasePair(const char &left, const char &right) {
    if (left == 'A' && right == 'T') {
        return true;
    }
    if (left == 'T' && right == 'A') {
        return true;
    }
    if (left == 'C' && right == 'G') {
        return true;
    }
    if (left == 'G' && right == 'C') {
        return true;
    }

    return false;
}
