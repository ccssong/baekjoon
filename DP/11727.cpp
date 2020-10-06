#include <iostream>

using namespace std;

int main(){
    int n, d[1001];
    cin >> n;

    d[1] = 1;
    d[2] = 3;

    for(int i=3; i<=n; i++){
        d[i] = (d[i-1] + d[i-2] * 2) % 10007;
    }

    printf("%d\n",d[n]);

    return 0;
}