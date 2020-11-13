#include <stdio.h>
#include <iostream>

using namespace std;
int a[1001] = {0,};
int dp1[1001] = {0,};
int dp2[1001] = {0,};

int main(){
    int n;
    cin >> n;

    for(int i=1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++){
        dp1[i] = 1; 
        for(int j = 1; j <= i; j++){
            if(a[j] < a[i] && dp1[i] < dp1[j] + 1){
                dp1[i] = dp1[j] + 1;
            }   
        }
    }

    for(int i = n; i >=1; i--){
        dp2[i] = 1;
        for(int j = n; j >= i; j--){
            if(a[j] < a[i] && dp2[j] + 1 > dp2[i]){
                dp2[i] = dp2[j] + 1;
            }
        }
    }


    int ans = 0;
    for(int i=1; i<=n; i++){
        if(dp1[i] + dp2[i] > ans){
            ans = dp1[i] + dp2[i];
        }
    }
    printf("%d\n",ans-1);
    return 0;
}