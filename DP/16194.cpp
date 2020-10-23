#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int p[1001] = {0,};
    int dp[1001] = {0,};
    dp[1] = p[1];

    for(int i=1; i<=n; i++)
        cin >> p[i];
    
    for(int i=1; i<=n; i++){
        dp[i] = p[i];
        for(int j=1; j <= i; j++){
            dp[i] = min(dp[i], dp[i-j] + p[j]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}