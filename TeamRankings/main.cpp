#include <iostream>
#include <string>
#include <deque>

#define RANK_LENGTH 5

using namespace std;

void makeAllPossibleRanks(deque<string> &processDeque) {
    for (char count = 0; count < RANK_LENGTH; count++) {
        string temp;
        temp += 'A' + count;
        processDeque.push_back(temp);
    }

    while (true) {
        string currentProcessString = processDeque.front();
        if (currentProcessString.length() >= RANK_LENGTH)
            return;
        processDeque.pop_front();

        for (char count = 0; count < RANK_LENGTH; count++) {
            if (currentProcessString.find('A' + count) != string::npos)
                continue;

            processDeque.push_back(currentProcessString + (char) ('A' + count));
        }
    }
}

int measureDistance(const string &inputRank, const string &currentRank) {
    int result = 0;
    for (size_t count = 0; count < inputRank.length(); count++) {
        char currentChar = inputRank[count];
        for (size_t next = count + 1; next < inputRank.length(); next++) {
            char tempChar = inputRank[next];
            size_t currentCharPosition = currentRank.find(currentChar);
            size_t tempCharPosition = currentRank.find(tempChar);

            if (tempCharPosition < currentCharPosition)
                result++;
        }
    }
    if (result == 0) {
        //cout << "distance between: " << inputRank << " and " << currentRank << " is 0" << endl;
    }
    return result;
}

int measureDistance(const deque<string> &inputRanks, const string &currentRank) {
    int result = 0;
    for (size_t count = 0; count < inputRanks.size(); count++) {
        result += measureDistance(inputRanks[count], currentRank);
    }
    return result;
}

int main()
{
    int ranksCount;
    deque<string> allPossibleRanks;
    makeAllPossibleRanks(allPossibleRanks);

    while (true) {
        cin >> ranksCount;
        if (ranksCount <= 0)
            return 0;

        deque<string> inputRanks(ranksCount);

        for (int count = 0; count < ranksCount; count++) {
            cin >> inputRanks[count];
        }

        deque<string> result;
        int medianDistance = -1;

        for (size_t count = 0; count < allPossibleRanks.size(); count++) {
            int distance = measureDistance(inputRanks, allPossibleRanks[count]);

            if (medianDistance == -1) {
                medianDistance = distance;
            }

            if (medianDistance == distance) {
                result.push_back(allPossibleRanks[count]);
            } else if (medianDistance > distance) {
                result.clear();
                result.push_back(allPossibleRanks[count]);
                medianDistance = distance;
            }
        }

        /*while (result.size()) {
            // print with alphabet order
            deque<string>::iterator minIt = result.begin();
            for (deque<string>::iterator it = minIt + 1; it != result.end(); it++) {
                if (it->compare(*minIt) < 0) {
                    minIt = it;
                }
            }
            cout << *minIt << " is the median ranking with value " << medianDistance << "." << endl;
            result.erase(minIt);
        }*/

        // shoud only the first one
        cout << result.front() << " is the median ranking with value " << medianDistance << "." << endl;
    }
    return 0;
}

