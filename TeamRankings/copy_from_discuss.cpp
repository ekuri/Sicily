#include<iostream>
#include<string>
using namespace std;

int position;
bool seq[120][10];
int tmp_position[5];

void StringGenerate(bool* avail,int* covered, int stage,string* names,int choice)//生成字符串，并且计算字符串内的10个bool值
{
    int i;
    if (stage == 0){
        int new_covered[5];
        new_covered[0] = choice;
        bool new_avail[5];

        for (i = 0; i < 5; ++i){
            new_avail[i] = true;
        }
        new_avail[choice] = false;
        for (i = 0; i < 5; ++i){
            if (new_avail[i]){
                StringGenerate(new_avail, new_covered, stage + 1, names, i);
            }
        }
    }
    else if (stage == 4){
        names[position] = "AAAAA";
        covered[4] = choice;
        for (i = 0; i < 5; ++i){
            names[position][i] = 'A' + covered[i];
        }
        //cout << position << " " << names[position] << endl;

        for (i = 0; i < 5; ++i){
            tmp_position[covered[i]] = i;//ABCDE to 01234, EDBCA to 42310
        }

        seq[position][0] = tmp_position[0] < tmp_position[1];
        seq[position][1] = tmp_position[0] < tmp_position[2];
        seq[position][2] = tmp_position[0] < tmp_position[3];
        seq[position][3] = tmp_position[0] < tmp_position[4];
        seq[position][4] = tmp_position[1] < tmp_position[2];
        seq[position][5] = tmp_position[1] < tmp_position[3];
        seq[position][6] = tmp_position[1] < tmp_position[4];
        seq[position][7] = tmp_position[2] < tmp_position[3];
        seq[position][8] = tmp_position[2] < tmp_position[4];
        seq[position][9] = tmp_position[3] < tmp_position[4];

        ++position;
    }
    else{
        int new_covered[5];
        bool new_avail[5];

        for (i = 0; i < 5; ++i){
            new_avail[i] = avail[i];
            new_covered[i] = covered[i];
        }
        new_avail[choice] = false;
        new_covered[stage] = choice;
        for (i = 0; i < 5; ++i){
            if (new_avail[i]){
                StringGenerate(new_avail, new_covered, stage + 1, names, i);
            }
        }
    }
}

int GetPosition(const string& name,string* names)//二分查找
{
    int left, right, target;
    left = 0;
    right = 120;
    target = right / 2;

    while (true){
        if (names[target] == name)
            return target;
        else if (right - left < 2)//not left - right
            break;

        if (names[target] < name)
            left = target;
        else
            right = target;
        target = (left + right) / 2;
    }

    return -1;
}

int main()
{
    string names[120];

    int i, j, k, l;

    position = 0;

    for (i = 0; i < 5; ++i){
        StringGenerate(NULL,NULL,0,names,i);
    }

    /*for (i = 1; i < position; ++i){
        if (names[i - 1] > names[i])
            cout << 0 << endl;
    }*/

    int distance[(120 + 1) * 120 / 2];

    int a, b=-1;

    for (i = 0; i < 120; ++i){
        for (j = i; j < 120; ++j){
            /*a = i*(120 + 120 - i + 1) / 2 + j - i;
            if (a != b + 1)
                cout << b << " " << a << endl;
            b = a;*/

            distance[i*(120 + 120 - i + 1) / 2 + j - i] = 0;
            for (k = 0; k < 10; ++k){
                if (seq[i][k] != seq[j][k]){
                    ++distance[i*(120 + 120 - i + 1) / 2 + j - i];
                }
            }

        }
    }

    int results[120];//120个可能性
    int team_count;
    int team_location;
    int place1, place2;
    int tmp_int;
    int min_position;

    string tmp_string;
    while (cin >> team_count&&team_count != 0){
        for (i = 0; i < 120; ++i){
            results[i] = 0;
        }
        for (i = 0; i < team_count; ++i){
            cin >> tmp_string;
            team_location = GetPosition(tmp_string, names);

            for (j = 0; j < 120; ++j){

                place1 = team_location;
                place2 = j;
                if (place1 > place2){
                    tmp_int = place1;
                    place1 = place2;
                    place2 = tmp_int;
                }
                //place1<=place2
                results[j] += distance[place1*(120 + 120 - place1 + 1) / 2 + place2 - place1];
            }

        }

        min_position = 0;
        for (i = 1; i < 120; ++i){
            if (results[i] < results[min_position])
                min_position = i;
        }

        cout << names[min_position] << " is the median ranking with value " << results[min_position] << "." << endl;
    }


    return 0;
}