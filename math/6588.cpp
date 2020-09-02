#include <iostream>

#define MAX 1000000
using namespace std;

int prime[MAX] = {0,};
bool check[MAX] = {false,};
int pn = 0;

void findPrime()
{
    for (int i = 2; i <= MAX; i++)
    {
        if (check[i] == false)
        {
            prime[pn++] = i;
            for (int j = i * 2; j <= MAX; j += i)
            {
                check[j] = true;
            }
        }
    }
}

int main()
{
    check[0] = check[1] = true;
    findPrime();

    while (true)
    {
        int num;
        cin >> num;
        if (num == 0)
            break;

        bool is_find = false;
        for (int i=0; prime[i] < num; i++)
        {
            int a = prime[i];
            int b = num - a;
            if (check[b] == false)
            {
                cout << num << " = " << a << " + " << b << endl;
                is_find = true;
                break;
            }
        }
        if (!is_find)
            cout << "Goldbach's conjecture is wrong." << endl;
    }
}