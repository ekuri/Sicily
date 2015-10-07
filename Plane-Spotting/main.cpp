#include <iostream>
#include <map>
#include <deque>

using namespace std;

struct QuarterPair {
    int from;
    int to;
    double planesPerQuarter;
    bool operator ==(struct QuarterPair &other) {
        return from == other.from && to == other.to && planesPerQuarter == other.planesPerQuarter;
    }

    QuarterPair(const QuarterPair &other) {
        from = other.from;
        to = other.to;
        planesPerQuarter = other.planesPerQuarter;
    }

    QuarterPair(int _from, int _to, double _planesPerQuarter) {
        from = _from;
        to = _to;
        planesPerQuarter =  _planesPerQuarter;
    }
};

void dealWith(map<int, int> &planesToQuarter, int resultCount, int miniumPeriodCount);
void quarterInsertOrdered(deque<QuarterPair> &quarterPairDeque, QuarterPair target);

int main()
{
    int testCaseCount;
    cin >> testCaseCount;

    for (int currentTestCaseCount = 0; currentTestCaseCount < testCaseCount; currentTestCaseCount++) {
        int quarterCount = 0;
        int resultCount;
        int miniumPeriodCount;
        cin >> quarterCount >> resultCount >> miniumPeriodCount;

        map<int, int> planesToQuarter;
        int tempPlanesCount = 0;
        int currentPlaneOfQuarter;
        for (int currentQuarterCount = 0; currentQuarterCount < quarterCount; currentQuarterCount++) {
            cin >> currentPlaneOfQuarter;

            // store the planes' number that from begin to current quarter
            tempPlanesCount += currentPlaneOfQuarter;
            planesToQuarter[currentQuarterCount + 1] = tempPlanesCount;
        }

        cout << "Result for run " << currentTestCaseCount + 1 << ":" << endl;
        dealWith(planesToQuarter, resultCount, miniumPeriodCount);
    }

    return 0;
}

void dealWith(map<int, int> &planesToQuarter, int resultCount, int miniumPeriodCount) {
    if (resultCount <= 0) {
        return;
    }

    if (planesToQuarter.size() <= miniumPeriodCount) {
        cout << "1-" << planesToQuarter.size() << endl;
        return;
    }

    deque<QuarterPair> quarterPairDeque;
    (miniumPeriodCount <= 0)?(miniumPeriodCount = 1):0;

    for (int currentPeriodCount = miniumPeriodCount - 1; currentPeriodCount < planesToQuarter.size(); currentPeriodCount++) {
        for (int currentQuarter = 1; currentQuarter + currentPeriodCount <= planesToQuarter.size(); currentQuarter++) {
            int endPlanesCount = planesToQuarter[currentQuarter + currentPeriodCount];
            int startPlanesCount = (currentQuarter == 1)?0:planesToQuarter[currentQuarter - 1];
            quarterInsertOrdered(quarterPairDeque, QuarterPair(currentQuarter,
                                               currentQuarter + currentPeriodCount,
                                               1.0 * (endPlanesCount - startPlanesCount) / (currentPeriodCount + 1)));
        }
    }

    /*cout << "All in deque:" << endl;
    for (deque<QuarterPair>::iterator it = quarterPairDeque.begin(); it != quarterPairDeque.end(); it++) {
        cout << it->from << "-" << it->to << " rate: " << it->planesPerQuarter << endl;
    }*/

    //cout << "Result: " << endl;
    for (int outputCount = 0; outputCount < resultCount && outputCount < quarterPairDeque.size(); outputCount++) {
        cout << quarterPairDeque.at(outputCount).from << "-" << quarterPairDeque.at(outputCount).to << endl;
    }
}

void quarterInsertOrdered(deque<QuarterPair> &quarterPairDeque, QuarterPair target) {
    for (deque<QuarterPair>::iterator it = quarterPairDeque.begin(); it != quarterPairDeque.end(); it++) {
        if (it->planesPerQuarter < target.planesPerQuarter) {
            // case 1: the number of planes per quarter is higher
            quarterPairDeque.insert(it, target);
            return;
        } else if (it->planesPerQuarter == target.planesPerQuarter) {
            if ((it->to - it->from) < (target.to - target.from)) {
                // case 2: the numbers are equal but P1 is a longer period (more quarters);
                quarterPairDeque.insert(it, target);
                return;
            } else if ((it->to - it->from) == (target.to - target.from)) {
                if (it->to >= target.to) {
                    // case 3: the numbers are equal and they are equally long, but period P1 ends earlier
                    quarterPairDeque.insert(it, target);
                    return;
                }
            }
        }
    }

    // worst period
    quarterPairDeque.push_back(target);
}
