#include<iostream>
#include<string>
using namespace std;
int data[1024000];
bool usedata[1024000];
int dostr(int p, string t, int len)
{
    int count = 1;

    if (t[p] == '0') return 0;

    if (p == len - 1)return 1;
    if (p == len) return 1;
    if (usedata[p])return data[p];


    if (t[p] == '1')
    {
        //1 or 1x
        if (t[p + 1] == '0')
        {
            count *= dostr(p + 2, t, len);
        }
        else
            count *= (dostr(p + 1, t, len) + dostr(p + 2, t, len));
    }
    else
    {
        if (t[p] == '2')
        {
            if (t[p + 1] == '0')
            {
                count *= dostr(p + 2, t, len);
            }
            else
            {
                int count2 = 0;
                //2511
                count2 += dostr(p + 1, t, len);//2
                if (t[p + 1] <= '6')count2 += dostr(p + 2, t, len);//2
                //if(p==0)cout <<endl<< dostr(p + 1, t, len), dostr(p + 2, t, len);
                count *= count2;
            }
        }
        else
        {
            return dostr(p + 1, t, len);
        }
    }
    usedata[p] = 1;
    data[p] = count;
    return count;
}

int main()
{
    string t;
    int len = 0;
    while (1)
    {
        t = "";
        cin >> t;
        if (t == "0")break;
        for (int i = 0; i < len; i++)usedata[i] = 0;
        len = t.length();
        //memset(usedata, 0, sizeof(usedata));
        cout << dostr(0, t, len) << endl;//point go!
    }
    //cout << endl;
    return 0;
}
