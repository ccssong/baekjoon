#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int temp = (n-1)/2 + 1;
    int ans = 1;
    for(int i=0; i<temp; i++){
        ans = (ans << 1) % 16769023;
    }
    
    cout << ans;
    return 0;
}