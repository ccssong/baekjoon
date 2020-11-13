#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n, d, m;
int k=0;
vector<int > s[100001];

void find(){
    while(true){
        bool plus_k = false;
        int i=1;
        int *arr = new int[d];

        for(int day=1; day<=n; day++){
            //task 넣기
            arr[0] = s[day].size();
            //task 작업
            
            if(arr[0])
        }
    }
}


int main(){
    cin >> n >> d >> m;
     for (int i = 1; i <= m; i++)
    {
        int tmp;
        cin >> tmp;
        s[tmp].push_back(tmp);
    }
    int max=0;
    for(int i=1; i<=m; i++){
        if(max < s[i].size())
            max = s[i].size();
    }
    k = (int)ceil(max / (double)d);
    printf("max: %d %d\n",max, k);

    find();
    
    return 0;
}