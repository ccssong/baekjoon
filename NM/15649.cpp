#include <iostream>

using namespace std;
bool c[9];
int a[9]; int num[9];

void find(int index, int n, int m){
    if(index == m){
        for(int i=0; i<m; i++)
            cout << a[i] << " ";
        cout << endl;
        return;
    }
    for(int i=0; i<n; i++){
        if(c[i] == false){ 
            continue;
        }
        a[index] = num[i];
        c[i] = false;
        find(index+1, n, m);
        c[i] = true;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        num[i] = i+1;
        c[i] = true;
    }
    find(0, n, m);

    return 0;
}