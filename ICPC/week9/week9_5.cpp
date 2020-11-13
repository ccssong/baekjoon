#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;
#define N 500


int dp[N][N];
bool v[N][N];

int minMergeCost(int i, int j, int* arr){
    if(i == j)
        return 0;
    
    if(v[i][j]){
        return dp[i][j];
    }
    
    v[i][j] = 1;
    int &x = dp[i][j];

    x = INT_MAX;

    int tot = 0;
    for(int k = i; k <= j; k++){
        tot += arr[k];
    }
    for(int k = i+1; k <= j; k++){
        x = min(x, tot + minMergeCost(i, k-1, arr) + minMergeCost(k, j, arr));
    }
    return x;
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[500];
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);

    cout << minMergeCost(0, n-1, arr);
    return 0;
}
