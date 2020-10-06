#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n;
    cin >> n;

    int d[1001];
    d[2] = 2;
    d[1] = 1;
    for(int i=3; i<=n; i++){
        d[i] = (d[i-2] + d[i-1]) % 10007;
    }
   cout << d[n] << endl;

    return 0;
}