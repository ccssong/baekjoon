#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;
int n, v;
vector<int> num;

void find()
{
    int cnt = 0;
    bool flag = true;
    while (1)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (num[i] > num[i + 1])
            {
                int temp = num[i];
                num.erase(num.begin() + i);
                num.push_back(temp);
                cnt++;
            }
            if (num[i + 1] < num[i])
            {
                int temp = num[i + 1];
                num.erase(num.begin() + i + 1);
                num.insert(num.begin(), temp);
                cnt++;
            }
        }
    }

    printf("\n");

    for (int i = 0; i < n; i++)
        cout << num[i] << endl;
}

int main()
{
    cin >> n;
    num.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    find();
    return 0;
}