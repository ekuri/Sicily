#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    int inputCount = 0;
    cin >> inputCount;

    while (inputCount != 0) {

        map<string, string> portMapName;
        map<string, string> MJMapMainID;
        string tempNameInputString;
        string tempPortInputString;

        for (int currentInputCount = 0; currentInputCount < inputCount; currentInputCount++) {
            cin >> tempNameInputString;
            cin >> tempPortInputString;

            map<string, string>::iterator foundIterator = portMapName.find(tempPortInputString);
            if (foundIterator == portMapName.end()) {
                portMapName[tempPortInputString] = tempNameInputString;
            } else {
                MJMapMainID[tempNameInputString] = foundIterator->second;
                portMapName.erase(foundIterator);
            }

        }
        /*nameMapToPort["inkfish"] = "192.168.29.24";
        nameMapToPort["zhi"] = "192.168.29.235";
        nameMapToPort["magicpig"] = "192.168.50.170";
        nameMapToPort["pegasus"] = "192.168.29.235";
        nameMapToPort["iamcs"] = "202.116.77.131";
        nameMapToPort["finalBob"] = "192.168.29.24";
        nameMapToPort["tomek"] = "202.116.77.131";
        nameMapToPort["magicduck"] = "192.168.50.170";*/


        /*while (portMapName.size() >= 2) {
            map<string, string>::iterator it = portMapName.begin();
            it++;
            for (; it != portMapName.end(); it++) {
                if (it->second == portMapName.begin()->second) {
                    MJMapMainID[portMapName.begin()->first] = it->first;
                    cout << portMapName.begin()->first << " -----> " << it->first << endl;
                    portMapName.erase(it);
                    portMapName.erase(portMapName.begin());
                    break;
                }
            }
        }*/

        while (!MJMapMainID.empty()) {
            map<string, string>::iterator it = MJMapMainID.begin();
            map<string, string>::iterator result = MJMapMainID.begin();
            it++;
            for (; it != MJMapMainID.end(); it++) {
                if (result->second > it->second) {
                    result = it;
                }
            }
            cout << result->first << " is the MaJia of " << result->second << endl;
            MJMapMainID.erase(result);
        }
        cout << endl;

        cin >> inputCount;
    }
    return 0;
}

