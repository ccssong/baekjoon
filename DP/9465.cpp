#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
int d[2][100001], arr[2][100001];

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        for(int r=0; r<2; r++)
            for(int c=1; c<=n; c++)
                scanf("%d",&arr[r][c]);
        
        d[0][1] = arr[0][1], d[1][1] = arr[1][1];
        for(int i=2; i<=n; i++){
            d[0][i] = max(d[1][i-1], d[1][i-2]) + arr[0][i];
            d[1][i] = max(d[0][i-1], d[0][i-2]) + arr[1][i];
          //  printf("d[0][%d]: %d, d[1][%d]: %d\n", i,d[0][i],i,d[1][i]);
        }
        cout << max(d[0][n], d[1][n]) << endl;
    }

    return 0;
}