#include <stdio.h>
#include <algorithm>

using namespace std;

int a[100000];
int dp[100000];

int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)  
        scanf("%d", &a[i]);

    dp[0]= a[0];
    int ans  = dp[0];
    for(int i=1; i<n; i++){
        dp[i] = max(dp[i-1] + a[i], a[i]);
        ans = max(ans, dp[i]);
    }

    printf("%d\n",ans);


    return 0;
}