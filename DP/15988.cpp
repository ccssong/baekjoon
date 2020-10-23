#include <iostream>

using namespace std;
#define MAX 1000001
int main(){
    int t;
    cin >> t;

    long long dp[MAX] = {0,};
    dp[1] = 1; 
    dp[2] = 2;
    dp[3] = 4;

    int n;
    while(t--){
        cin >> n;
        for(int i=4; i<=n; i++)
            dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 1000000009;
        cout << dp[n] << endl;
    }

    return 0;
}