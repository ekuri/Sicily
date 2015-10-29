#include <iostream>
#include <string>
#include <limits.h>
#include <stack>
#include <deque>

#define NUMBER_COUNT 5
#define COMPUTED_OPERRATION '.'

using namespace std;

inline void makeOperationSequece(deque<string> &operationSequenceQueue) {
    string operationSequenceString = "1234";
    operationSequenceQueue.push_back("");
    while (true) {
        string currentOperationString = operationSequenceQueue.front();
        if (currentOperationString.length() >= NUMBER_COUNT - 1)
            break;
        operationSequenceQueue.pop_front();

        for (size_t count = 0; count < operationSequenceString.length(); count++) {
            if (currentOperationString.find(operationSequenceString[count]) == string::npos) {
                operationSequenceQueue.push_back(currentOperationString + operationSequenceString[count]);
            }
        }
    }
}

inline int computeWithOrder(const int numbers[], const string &operation, const string &operationSequence) {
    deque<int> operationDeque;
    operationDeque.push_back(numbers[0]);
    for (size_t count = 0; count < operation.length(); count++) {
        operationDeque.push_back(operation[count]);
        operationDeque.push_back(numbers[count + 1]);
    }
    for (size_t count = 0; count < operationSequence.length(); count++) {
        size_t index = operationSequence.find((char) ('1' + count));
        size_t medianPosition = index * 2 + 1;
        int left = operationDeque[medianPosition - 1];
        int right = operationDeque[medianPosition + 1];
        int operant = operationDeque[medianPosition];
        int result;

        switch (operant) {
        case '/':
            operationDeque[medianPosition + 1] = left / right;
            break;
        case '*':
            operationDeque[medianPosition + 1] = left * right;
            break;
        case '+':
            operationDeque[medianPosition + 1] = left + right;
            break;
        case '-':
            operationDeque[medianPosition + 1] = left - right;
            break;
        default:
            throw "operant error";
            break;
        }
        operationSequence.erase(index * 2, 2);
    }
}

inline int compute(const int numbers[], const string &operation, const deque<string> &operationSequence) {
    //int result = 0;

    // compute using a stack
    /*stack<int> operationStack;
    operationStack.push(numbers[0]);

    // conpute all '*' and '/', store '+' and '-'
    for (int count = 0; count < NUMBER_COUNT - 1; count++) {
        if (operation[count] == '*') {
            int stackTop = operationStack.top();
            operationStack.pop();
            operationStack.push(stackTop * numbers[count + 1]);
            continue;
        } else if (operation[count] == '/') {
            int stackTop = operationStack.top();
            operationStack.pop();
            int value = stackTop / numbers[count + 1];

            // return INT_MAX if operation is invalid
            if (stackTop != value * numbers[count + 1])
                return INT_MAX;

            operationStack.push(value);
            continue;
        }
        operationStack.push(operation[count]);
        operationStack.push(numbers[count + 1]);
    }

    // conpute all '+' and '-'
    while (operationStack.size() > 2) {
        int stackTop = operationStack.top();
        operationStack.pop();
        int currentOperant = operationStack.top();
        operationStack.pop();
        int stackTopBelow = operationStack.top();
        operationStack.pop();
        if (currentOperant == '+') {
            operationStack.push(stackTop + stackTopBelow);
        } else if (currentOperant == '-') {
            operationStack.push(stackTopBelow - stackTop);
        } else {
            throw "invalid operant";
        }
    }

    result = operationStack.top();*/

    int result = INT_MAX;
    int tempResult;
    for (size_t count = 0; count < operationSequence.size(); count++) {
        tempResult = computeWithOrder(numbers, operation, operationSequence[count]);
        if (tempResult < result)
            result = tempResult;
    }

    // debug
    for (int count = 0; count < NUMBER_COUNT - 1; count++) {
        cout << numbers[count] << operation[count];
    }
    cout << numbers[NUMBER_COUNT - 1] << "=" << result << endl;

    return result;
}

inline int runWithNumbersAndTarget(int numbers[], int target, const deque<string> &allOperationQueue, const deque<string> &operationSequence) {
    int result = INT_MAX;
    int tempResult;
    for (size_t count = 0; count < allOperationQueue.size(); count++) {
        tempResult = compute(numbers, allOperationQueue[count], operationSequence);

        // invalid operarion
        if (tempResult == INT_MAX)
            continue;

        if (tempResult == target)
            return target;
        else if (tempResult < target && (tempResult > result  || result == INT_MAX))
            result = tempResult;
    }

    return result;
}

inline void makeAllOperation(deque<string> &allOperationQueue) {
    string allOperant = "+-*/";
    allOperationQueue.push_back("");
    while (true) {
        string currentOperation = allOperationQueue.front();
        if (currentOperation.length() >= NUMBER_COUNT - 1)
            break;
        allOperationQueue.pop_front();
        for (size_t operantCount = 0; operantCount < allOperant.length(); operantCount++) {
            allOperationQueue.push_back(currentOperation + allOperant[operantCount]);
        }
    }
}

int main()
{
    int testCount;
    cin >> testCount;
    int numbers[NUMBER_COUNT];
    int target;

    deque<string> allOperationQueue;
    makeAllOperation(allOperationQueue);
    // to debug print all operation
    /*while (allOperationQueue.size()) {
        cout << allOperationQueue.front() << endl;
        allOperationQueue.pop_front();
    }
    return 0;*/
    deque<string> operationSequence;
    makeOperationSequece(operationSequence);
    // to debug print all operation
    /*for (int count = 0; count < operationSequence.size(); count++) {
        cout << operationSequence[count] << endl;
    }
    return 0;*/

    while (testCount--) {
        // get numbers input
        for (int count = 0; count < NUMBER_COUNT; count++) {
            cin >> numbers[count];
        }

        // get target input
        cin >> target;

        // run and output result
        cout << runWithNumbersAndTarget(numbers, target, allOperationQueue, operationSequence) << endl;
    }
    return 0;
}

