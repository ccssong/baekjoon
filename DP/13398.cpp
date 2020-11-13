#include <stdio.h>
#include <algorithm>

using namespace std;

int a[100000];
int dp[100000][2];

int  main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    
    int ans = a[0];
    dp[0][0]= a[0];
    dp[0][1] = 0;
    for(int i=1; i<n; i++){
        dp[i][0] = max(dp[i-1][0] + a[i], a[i]);
        dp[i][1] = max(dp[i-1][0], dp[i-1][1] + a[i]);
        ans = max(max(ans, dp[i][0]) , dp[i][1]);
    }

    printf("%d\n", ans);

    return 0;
}