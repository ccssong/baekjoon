#include <iostream>
#include <stdio.h>

using namespace std;
#define mod 1000000000
int d[101][11] = {0,};


int main(){
    int N;
    cin >> N;

    for(int i=1; i<=9; i++){
        d[1][i] = 1;
    }

    for(int n=2; n<=N; n++){
        for(int l=0; l<10; l++){
            if(l == 0)
                d[n][0] = d[n-1][1] % mod;
            else if(l == 9)
                d[n][9] = d[n-1][8] % mod;
            else
                d[n][l] = (d[n-1][l-1] + d[n-1][l+1]) % mod;
        }
    }

    int ans=0;
    for(int i=0; i<10; i++){
       // printf("d[%d][%d] = %d\n",N,i,d[N][i]);
        ans = (ans + d[N][i]) % mod;
    }
    cout << ans << endl;
    
    return 0;
}