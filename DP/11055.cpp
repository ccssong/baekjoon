#include <iostream>
#include <stdio.h>

using namespace std;
int a[1001] = {0,};
int sum[1001] = {0,};

int main(){
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    int max = 0;

    for(int i=1; i<=n; i++){
        sum[i] = a[i];
        for(int j=0; j<i; j++){
            if(a[j] < a[i] && sum[i] < sum[j] + a[i]){
                sum[i] = sum[j] + a[i];
            }
        }
        if(max < sum[i])
            max = sum[i];

    }
    cout << max << endl;

    return 0;
}