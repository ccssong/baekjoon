#include <iostream>
#include <stdio.h>

using namespace std;
#define MAX 100000
#define mod 1000000009
long long dp[MAX+1][4];

void solve(){
    dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
    for(int n=4; n<= MAX; n++){
        if(n-1>= 0){
            dp[n][1] = (dp[n-1][2] + dp[n-1][3]) % mod;
        }
        if(n-2>=0){
            dp[n][2] = (dp[n-2][1] + dp[n-2][3]) % mod;
        }
        if(n-3 >= 0){
            dp[n][3] = (dp[n-3][1] + dp[n-3][2]) % mod;
        }
    }
}

int main(){
    int t;
    cin >> t;

    solve();
    while(t--){
        int n;
        cin >> n;
        cout << (dp[n][1] + dp[n][2] + dp[n][3]) % mod << endl;
    }

    return 0;
}