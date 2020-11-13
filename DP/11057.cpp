#include <iostream>
#include <stdio.h>

using namespace std;
#define mod 10007
int d[10001][10] = {0,};

int main(){
    int N;
    cin >> N;

    for(int i=0; i<10; i++)
        d[1][i] = 1;
    
    for(int n=2; n<=N; n++){
        for(int i=0; i<10; i++){
           for(int k=0; k<=i; k++){
               d[n][i] = (d[n][i] + d[n-1][k]) % mod;
           }
        }
    }

    int sum=0;
    for(int i=0; i<10; i++)
        sum = (sum + d[N][i]) % mod;
    cout << sum << endl; 76y4rhr

    return 0;
}