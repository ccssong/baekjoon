#include <iostream>
#include <stdio.h>

using namespace std;

int d[1001] = {0,};
int a[1001] = {0,};
int v[1001]= {0,};

int main(){
    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> a[i];
    
    int max=0;
    int maxIndex=0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            if(a[j] < a[i] && d[i] < d[j] + 1){
               d[i] = d[j] + 1;
               v[i] = j;
            }
        }
        if(max < d[i]){
            max = d[i];
            maxIndex = i;
        }
    }

    int result[1001]= {0,};
    for(int i=0; i<max; i++){
        result[i] = a[maxIndex];
        maxIndex = v[maxIndex];
    }

    cout << max << endl;
    for(int i=1; i<=max; i++){
        printf("%d ",result[max-i]);
    }
    cout << endl;

    return 0;
}