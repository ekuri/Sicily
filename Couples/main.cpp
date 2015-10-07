#include <iostream>
#include <deque>

using namespace std;

void scanAndRemoveCoupleTogether(deque<int> &coupleDeque);

int main()
{
    int couplesCount = 0;
    cin >> couplesCount;
    while (couplesCount != 0) {
        deque<int> couplesDeque(couplesCount * 2);
        for (int currentCouplesCount = 0; currentCouplesCount < couplesCount; currentCouplesCount++) {
            int tempPostion = 0;
            cin >> tempPostion;
            couplesDeque[tempPostion - 1] = currentCouplesCount;
            cin >> tempPostion;
            couplesDeque[tempPostion - 1] = currentCouplesCount;
        }

        scanAndRemoveCoupleTogether(couplesDeque);
        cin >> couplesCount;
    }

    return 0;
}

void scanAndRemoveCoupleTogether(deque<int> &coupleDeque) {
    if (coupleDeque.size() <= 1) {
        cout << "No" << endl;
        return;
    }

    bool hasRemoved = false;
    while (coupleDeque.front() == coupleDeque.back()) {
        coupleDeque.pop_back();
        coupleDeque.pop_front();
        hasRemoved = true;
        if (coupleDeque.size() == 0) {
            cout << "Yes" << endl;
            return;
        } else if (coupleDeque.size() <= 1) {
            cout << "No" << endl;
            return;
        }
    }

    for (deque<int>::iterator it = coupleDeque.begin() + 1; it != coupleDeque.end();) {
        if (*it == *(it - 1)) {
            coupleDeque.erase(it - 1);
            it = coupleDeque.erase(it);
            hasRemoved = true;
        } else {
            it++;
        }
    }

    if (coupleDeque.size() == 0) {
        cout << "Yes" << endl;
        return;
    }
    if (!hasRemoved) {
        cout << "No" << endl;
        return;
    }
    scanAndRemoveCoupleTogether(coupleDeque);
}
