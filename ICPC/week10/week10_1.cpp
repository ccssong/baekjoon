#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> s;

int n, d, m;
int k = 0;

int find()
{
    while(true)
    {
        bool plus_k = false;
        int i = 1;
        k++;
        printf("----k is: %d\n",k);
        for (int day = 1; day <= n; day++)
        {   
            printf("\ncurrent day: %d\n",day);
            bool notyet = false;
            for (int j=0; j < k; j++)
            {   
                printf("i+j: %d, s[i+j]: %d\n", i+j, s[i+j]);
                //이 경우일땐 continue
                if(s[i+j] > day){
                    notyet = true;
                    printf("not yet: %d : %d\n",i+j,s[i+j]);
                    break;
                }
                //이 경우일떈 k++
                if (s[i+j] + d < day)
                {
                    plus_k = true;
                    printf("time is over, s[%d]: %d k:%d\n",i+j, s[i + j], k);
                    break;
                }
                //종료조건
                else if(i+j == m){
                    printf("~~~~~~~finish i+j == m , return %d\n", k);
                    return k;
                }
            }
            if(notyet){
                continue;
            }
            if (!plus_k)
            {
                i += k;
                printf("next i, i: %d\n",i);
            }
            else
            {
                printf("break\n\n\n");
                break;
            }
        }
        int temp;
        cin >> temp;
    }
    printf("k is : %d\n",k);
    return k;
}

int main()
{
    cin >> n >> d >> m;
    s.resize(m + 1);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &s[i]);
    }
    sort(s.begin(), s.end());
    if(m > n)
        k++;

    cout << find() << endl;
}

/**
8 2 12
1 2 4 2 1 3 5 6 2 3 6 4 

8 2 12
1 2 2 2 1 3 5 6 2 3 6 2

8 2 12
1 2 4 2 1 3 5 6 2 3 8 8

5 2 12
1 1 2 2 3 3 4 4 5 5 5 5

6 2 7
1 2 3 4 5 5 5

8 2 8
1 1 1 1 8 8 8 8
*/