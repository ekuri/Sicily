#include <stdio.h>
#include <memory.h>

#define MAX_ARRAY_SIZE 1000
int storage[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];

int dynamicProgram(const int numbersCount, int storage[][MAX_ARRAY_SIZE]);
void dealNext(const int currentNumber, const int currentRunLength, const int numbersCount, int storage[][MAX_ARRAY_SIZE]);
void greedySelect(const int currentStartNumber, const int currentEndNumber, const int numberCount, int storage[][MAX_ARRAY_SIZE]);
int max(int left, int right);

int main() {
    int testCount = 0;

    while (true) {
        testCount++;

        int numbersCount = 0;
        scanf("%d", &numbersCount);
        if (numbersCount <= 0) {
            break;
        }

        memset(storage, 0, sizeof(storage));

        int scoreSum = 0;
        for (int currentNumbersCount = 0; currentNumbersCount < numbersCount; currentNumbersCount++) {
            scanf("%d", &storage[currentNumbersCount][currentNumbersCount]);
            scoreSum += storage[currentNumbersCount][currentNumbersCount];
        }

        printf("In game %d, the greedy strategy might lose by as many as %d points.\n",
               testCount, 2 * dynamicProgram(numbersCount, storage) - scoreSum);
    }
    return 0;
}

int dynamicProgram(const int numbersCount, int storage[][MAX_ARRAY_SIZE]) {
    for (int currentRunLength = 1; currentRunLength < numbersCount; currentRunLength += 2) {

        printf("Matrix:\n");
        for (int count = 0; count < numbersCount; count++) {

            for (int temp = 0; temp < numbersCount; temp++) {
                printf("%d ", storage[count][temp]);
            }
            printf("\n");
        }

        for (int currentNumber = 0; currentNumber + currentRunLength - 1 < numbersCount; currentNumber++) {
            dealNext(currentNumber, currentRunLength, numbersCount, storage);
        }
    }

    printf("Matrix:\n");
    for (int count = 0; count < numbersCount; count++) {

        for (int temp = 0; temp < numbersCount; temp++) {
            printf("%d ", storage[count][temp]);
        }
        printf("\n");
    }

    return storage[0][numbersCount - 1];
}

void dealNext(const int currentNumber, const int currentRunLength, const int numbersCount, int storage[][MAX_ARRAY_SIZE]) {
    if (currentNumber - 1 >= 0) {

        const int currentStartNumber = currentNumber - 1;
        const int currentEndNumber = currentNumber + currentRunLength - 1;
        const int previousScore = (currentRunLength == 1)?0:storage[currentNumber][currentEndNumber];
        storage[currentStartNumber][currentEndNumber] = max(
                    storage[currentStartNumber][currentStartNumber] + previousScore,
                    storage[currentStartNumber][currentEndNumber]);

        printf("Free select number in position: %d   current run length: %d\n", currentStartNumber, currentRunLength);
        greedySelect(currentStartNumber, currentEndNumber, numbersCount, storage);

    }

    if (currentNumber + currentRunLength < numbersCount) {

        const int currentEndNumber = currentNumber + currentRunLength;
        const int previousScore = (currentRunLength == 1)?0:storage[currentNumber][currentEndNumber - 1];
        storage[currentNumber][currentEndNumber] = max(
                    storage[currentEndNumber][currentEndNumber] + previousScore,
                    storage[currentNumber][currentEndNumber]);

        printf("Free select number in position: %d   current run length: %d\n", currentEndNumber, currentRunLength);
        greedySelect(currentNumber, currentEndNumber, numbersCount, storage);

    }
}

void greedySelect(const int currentStartNumber, const int currentEndNumber, const int numberCount, int storage[][MAX_ARRAY_SIZE]) {
    {
        if (currentEndNumber - currentStartNumber + 1 == numberCount) {
            printf("Reached end\n");
            return;
        }
        int leftScore = 0;
        int rightScore = 0;

        if (currentStartNumber - 1 >= 0) {
            leftScore = storage[currentStartNumber - 1][currentStartNumber - 1];
        }
        if (currentEndNumber + 1 < numberCount) {
            rightScore = storage[currentEndNumber + 1][currentEndNumber + 1];
        }

        if (leftScore >= rightScore && leftScore != 0) {

            if (leftScore + storage[currentStartNumber][currentEndNumber] > storage[currentStartNumber - 1][currentEndNumber]) {
                storage[currentStartNumber - 1][currentEndNumber] = max(
                            storage[currentStartNumber][currentEndNumber],
                            storage[currentStartNumber - 1][currentEndNumber]);
            }

        } else {

            if (rightScore + storage[currentStartNumber][currentEndNumber] > storage[currentStartNumber][currentEndNumber + 1]) {
                storage[currentStartNumber][currentEndNumber + 1] = max(
                            storage[currentStartNumber][currentEndNumber],
                            storage[currentStartNumber][currentEndNumber + 1]);
            }

        }
    }
}

int max(int left, int right) {
    return (left > right)?left:right;
}

/*#include <iostream>
#include <deque>

using namespace std;

// return score
int freeStrategy(deque<int> &numbers);

// return score
int greedyStrategy(deque<int> &numbers);

int testGreedyStrategy(deque<int> &numbers);

int main()
{
    int testCount = 0;
    while (true) {
        testCount++;
        int numberCount;
        cin >> numberCount;

        if (numberCount <= 0) {
            break;
        }

        deque<int> numbers;
        int tempNumber;

        for (int currentNumberCount = 0; currentNumberCount < numberCount; currentNumberCount++) {
            cin >> tempNumber;

            numbers.push_back(tempNumber);
        }

        int greedyScore = 0;
        int freeScore = 0;

        while (numbers.size() >= 2) {
            freeScore += freeStrategy(numbers);
            greedyScore += greedyStrategy(numbers);
        }

        cout << "In game " << testCount << ", the greedy strategy might lose by as many as "
                                           << freeScore - greedyScore << " points." << endl;
    }
    return 0;
}

int freeStrategy(deque<int> &numbers) {
    if (numbers.size() == 2) {
        return greedyStrategy(numbers);
    }

    const int frontElement = numbers.front();
    numbers.pop_front();
    const int leftFirstScore = testGreedyStrategy(numbers);
    numbers.push_front(frontElement);

    const int backElement = numbers.back();
    numbers.pop_back();
    const int rightFirstScore = testGreedyStrategy(numbers);
    numbers.push_back(backElement);

    const int greedyScoreDifference = (leftFirstScore >= rightFirstScore)?
                (leftFirstScore - rightFirstScore):(rightFirstScore - leftFirstScore);
    const int freeScoreDifference = (backElement >= frontElement)?
                (backElement - frontElement):(frontElement - backElement);
    if (freeScoreDifference >= greedyScoreDifference) {
        return greedyStrategy(numbers);
    }

    if (leftFirstScore <= rightFirstScore) {
        numbers.pop_front();
        cout << "freeStrategy Peek: " << frontElement << endl;
        return frontElement;
    }
    numbers.pop_back();
    cout << "freeStrategy Peek: " << backElement << endl;
    return backElement;
}

int greedyStrategy(deque<int> &numbers) {
    int score = 0;

    if (numbers.front() >= numbers.back()) {
        score = numbers.front();
        numbers.pop_front();
    } else {
        score = numbers.back();
        numbers.pop_back();
    }

    cout << "greedyStrategy Peek: " << score << endl;
    return score;
}

int testGreedyStrategy(deque<int> &numbers) {
    return (numbers.front() >= numbers.back())?numbers.front():numbers.back();
}
*/
