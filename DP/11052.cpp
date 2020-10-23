#include <iostream>
#include <stdio.h>
#include <algorithm>
int n;

using namespace std;

int main(){
    cin >> n;
    int p[1000] = {0,};
    for(int i=1; i<=n; i++){
        cin >> p[i];
    }
    int* dp = new int[n+1];
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i] = max(dp[i], dp[i-j] + p[j] );
        }
    }
    
    cout << dp[n] << endl;

    return 0;
}