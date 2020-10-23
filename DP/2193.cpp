#include <iostream>

using namespace std;
long long d[91][2] = {0,};

int main(){
    d[1][1] = d[2][0] = 1;

    int n;
    cin >> n;

    for(int i=3; i<=n; i++){
        d[i][0] = d[i-1][0] + d[i-1][1];
        d[i][1] = d[i-1][0];
    }

    long long sum=0;
    sum = d[n][0] + d[n][1];
    cout << sum << endl;
    return 0;
}