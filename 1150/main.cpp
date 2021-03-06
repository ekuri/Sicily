#include <iostream>
#include <string>
#include <deque>
#define MATRIX_SIZE 8

using namespace std;

inline void AOperation(deque<string> &operationDeque, string currentMatrix) {
    char temp;
    for (int count = 0; count < MATRIX_SIZE / 2; count++) {
        temp = currentMatrix[count];
        currentMatrix[count] = currentMatrix[count + (MATRIX_SIZE / 2)];
        currentMatrix[count + (MATRIX_SIZE / 2)] = temp;
    }
    operationDeque.push_back(currentMatrix + 'A');
}
inline void BOperation(deque<string> &operationDeque, string currentMatrix) {
    char row1temp1 = currentMatrix[MATRIX_SIZE / 2 - 1];
    char row2temp1 = currentMatrix[MATRIX_SIZE - 1];
    char row1temp2, row2temp2;
    for (int count = 0; count < MATRIX_SIZE / 2; count++) {
        row1temp2 = currentMatrix[count];
        row2temp2 = currentMatrix[count + (MATRIX_SIZE / 2)];
        currentMatrix[count] = row1temp1;
        currentMatrix[count + (MATRIX_SIZE / 2)] = row2temp1;
        row1temp1 = row1temp2;
        row2temp1 = row2temp2;
    }
    operationDeque.push_back(currentMatrix + 'B');
}
inline void COperation(deque<string> &operationDeque, string currentMatrix) {
    char temp1 = currentMatrix[1];
    char temp2 = currentMatrix[2];
    char temp6 = currentMatrix[6];

    currentMatrix[1] = currentMatrix[5];
    currentMatrix[2] = temp1;
    currentMatrix[6] = temp2;
    currentMatrix[5] = temp6;

    operationDeque.push_back(currentMatrix + 'C');
}

inline void operation(deque<string> &operationDeque, string &goalMatrix, int maxDepth) {

    while (true) {
        string currentMatrix = operationDeque.front();
        operationDeque.pop_front();
        if (currentMatrix.length() > MATRIX_SIZE + maxDepth) {
            cout << "-1" << endl;
            return;
        }

        if (currentMatrix.find(goalMatrix) != string::npos) {
            if (currentMatrix.length() == MATRIX_SIZE) {
                cout << "0 " << endl;
                return;
            }

            string answer = currentMatrix.substr(MATRIX_SIZE);
            cout << answer.length() << " " << answer << endl;
            return;
        }
        AOperation(operationDeque, currentMatrix);
        BOperation(operationDeque, currentMatrix);
        COperation(operationDeque, currentMatrix);
    }
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
        operationDeque.push_back("12348765");
        string goalMatrix = "12345678";
        for (int count = 0; count < MATRIX_SIZE; count++) {
            cin >> goalMatrix[count];
        }

        operation(operationDeque, goalMatrix, maxDepth);
    }
    return 0;
}
