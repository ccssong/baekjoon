#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int d[1001] = {0,};
int arr[1001] = {0,};

int main(){
    int n;
    cin >>n;

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    
    int max=0;
    for(int i=1; i<=n; i++){
        int min = 0;
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i]){
                if(d[j] > min)
                    min = d[j];
            }
        }
        d[i] = min + 1;
        if(max < d[i])
            max = d[i];
    }
    cout << max << endl;

    return 0;
}