#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
vector<int> s;

int n, d, m;
int k=0;

int find()
{
    int *arr = new int[d];
    while(true)
    {
        bool plus_k = false;
        int i = 1;

       
        for (int day = 1; day <= n; day++)
        {   
            bool notyet = false;
            for (int j=0; j < k; j++)
            {   
                if(s[i+j] > day){
                    notyet = true;
                    break;
                }
                else if (s[i+j] + d < day)
                {
                    plus_k = true;
                    break;
                }
                else if(i+j == m){
                    return k;
                }
            }
            if(notyet){
                continue;
            }
            else if (!plus_k)
            {
                i += k;
            }
            else
            {
                break;
            }
        }
        k++;
    }
    return k;
}

int main()
{
    cin >> n >> d >> m;
    s.resize(m + 1);
    vector<int > ss[100001];
    for (int i = 1; i <= m; i++)
    {
        cin >> s[i];
        ss[s[i]].push_back(s[i]);
    }  
    sort(s.begin(), s.end());

    int max=0;
    for(int i=1; i<=m; i++){
        if(max < ss[i].size())
            max = ss[i].size();
    }
    k = (int)ceil(max / (double)d);

    printf("%d", find());
}

/**
8 2 12
1 2 4 2 1 3 5 6 2 3 6 4

8 2 12
1 2 4 2 1 3 5 6 2 3 8 8

5 2 12
1 1 2 2 3 3 4 4 5 5 5 5

6 2 7
1 2 3 4 5 5 5

8 2 8
1 1 1 1 8 8 8 8

8 1 12
1 2 4 2 1 3 5 6 2 6 8 7
*/