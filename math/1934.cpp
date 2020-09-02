#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcm(int a, int b)
{   
    int _a = a, _b = b;
    int gcd = 0;
    while (true)
    {
        gcd = a % b;
        if (gcd == 0)
        {
            gcd = b;
            break;
        }
        else{
            a = b;
            b = gcd;
        }
    }

    int result = gcd * (_a / gcd) * (_b / gcd);
    return result;
}

int main()
{
    int num = 0;
    cin >> num;
    vector<pair<int, int> > box;
    for (int i = 0; i < num; i++)
    {
        int a, b;
        cin >> a >> b;
        box.push_back(make_pair(a, b));
    }

    for (int i = 0; i < num; i++)
    {
        cout << lcm(box[i].first, box[i].second) << endl;
    }
}