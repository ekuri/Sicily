#include <iostream>
#include <string>
#include <deque>

#define MATRIX_SIZE 8

using namespace std;

inline void swap(char &left, char &right) {
    char temp = left;
    left = right;
    right = temp;
}

inline int factor(int number) {
    int result = 1;
    while (number > 1) {
        result *= number;
        number--;
    }
    return result;
}

inline int mapValue(const string &target) {
    if (target.length() != MATRIX_SIZE)
        throw "map value error";
    int result = 0;
    for (int count = 0; count < MATRIX_SIZE; count++) {
        int newFactor = 1;
        for (int i = 0; i < count; i++) {
            if (target[i] < target[count])
                newFactor++;
        }
        result += (target[count] - '0' - newFactor) * factor(MATRIX_SIZE - 1 - count);
    }

    return result;
}

inline void AOperation(deque<string> &operationDeque, bool visitedMap[], string currentMatrix, int maxDepth) {
    swap(currentMatrix[0], currentMatrix[2]);
    swap(currentMatrix[1], currentMatrix[3]);
    swap(currentMatrix[4], currentMatrix[6]);
    swap(currentMatrix[5], currentMatrix[7]);

    // test reach max depth
    if (currentMatrix.length() >= maxDepth + MATRIX_SIZE) {
        return;
    }

    // test whether visited
    string currentState = currentMatrix.substr(0, MATRIX_SIZE);
    if (visitedMap[mapValue(currentState)]) {
        return;
    }
    visitedMap[mapValue(currentState)] = true;

    operationDeque.push_back(currentMatrix + 'A');
}
inline void BOperation(deque<string> &operationDeque, bool visitedMap[], string currentMatrix, int maxDepth) {

    for (int count = 0; count < MATRIX_SIZE / 2 - 1; count++) {
        swap(currentMatrix[count], currentMatrix[count + 1]);
    }

    for (int count = MATRIX_SIZE / 2; count < MATRIX_SIZE - 1; count++) {
        swap(currentMatrix[count], currentMatrix[count + 1]);
    }

    // test reach max depth
    if (currentMatrix.length() >= maxDepth + MATRIX_SIZE) {
        return;
    }

    // test whether visited
    string currentState = currentMatrix.substr(0, MATRIX_SIZE);
    if (visitedMap[mapValue(currentState)]) {
        return;
    }
    visitedMap[mapValue(currentState)] = true;

    operationDeque.push_back(currentMatrix + 'B');
}
inline void COperation(deque<string> &operationDeque, bool visitedMap[], string currentMatrix, int maxDepth) {
    char temp1 = currentMatrix[1];
    char temp2 = currentMatrix[5];
    char temp6 = currentMatrix[6];

    currentMatrix[1] = currentMatrix[2];
    currentMatrix[5] = temp1;
    currentMatrix[6] = temp2;
    currentMatrix[2] = temp6;

    // test reach max depth
    if (currentMatrix.length() >= maxDepth + MATRIX_SIZE) {
        return;
    }

    // test whether visited
    string currentState = currentMatrix.substr(0, MATRIX_SIZE);
    if (visitedMap[mapValue(currentState)]) {
        return;
    }
    visitedMap[mapValue(currentState)] = true;

    operationDeque.push_back(currentMatrix + 'C');
}

inline void operation(deque<string> &operationDeque, bool visitedMap[], string &goalMatrix, int maxDepth) {

    while (operationDeque.size()) {
        string currentMatrix = operationDeque.front();
        operationDeque.pop_front();

        if (currentMatrix.find(goalMatrix) != string::npos) {
            if (currentMatrix.length() == MATRIX_SIZE) {
                cout << "0" << endl;
                return;
            }

            string answer = currentMatrix.substr(MATRIX_SIZE);
            cout << answer.length() << " " << answer << endl;
            return;
        }

        if (maxDepth == 0) {
            cout << "-1" << endl;
            return;
        }

        AOperation(operationDeque, visitedMap, currentMatrix, maxDepth);
        BOperation(operationDeque, visitedMap, currentMatrix, maxDepth);
        COperation(operationDeque, visitedMap, currentMatrix, maxDepth);
    }

    cout << "-1" << endl;
}

int main()
{
    while (true) {
        int maxDepth;
        cin >> maxDepth;

        if (maxDepth < 0) {
            return 0;
        }

        deque<string> operationDeque;
        operationDeque.push_back("12345678");

        const int visitableCount = factor(MATRIX_SIZE);
        bool visitedMap[visitableCount];
        for (int count = 0; count < visitableCount; count++) {
            visitedMap[count] = false;
        }

        visitedMap[mapValue("12345678")] = true;
        string goalMatrix = "12345678";
        for (int count = 0; count < MATRIX_SIZE; count++) {
            cin >> goalMatrix[count];
        }

        operation(operationDeque, visitedMap, goalMatrix, maxDepth);
    }
    return 0;
}

