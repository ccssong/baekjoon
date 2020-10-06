#include <iostream>

using namespace std;
int d[1000001] = {0,};

int find(int n){
    if(n == 1){
        return 0;
    }
    if(d[n] > 0)
        return d[n];
    d[n] = find(n-1)+1;
    if(n%2 == 0){
        int temp = find(n/2)+1;
        if(d[n] > temp) d[n] = temp;
    }
    if(n%3 == 0){
        int temp =  find(n/3)+1;
        if(d[n] > temp) d[n] = temp;
    }
    return d[n];
}


int main(){
    int n;
    cin >> n;

    int result = find(n);

    cout << result << endl;
    return 0;
}