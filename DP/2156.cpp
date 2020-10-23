#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
int d[10003] = {0,}, arr[10003] = {0,};

int main(){
    int n;
    cin >> n;

    for(int i=3; i<n+3; i++)
        scanf("%d",&arr[i]);

    for(int i=3; i<n+3; i++){
        d[i] = max(d[i-3] + arr[i-1] + arr[i], d[i-2] + arr[i]);
        d[i] = max(d[i], d[i-1]);
    }
    cout << d[n+2] << endl;

    return 0;
}