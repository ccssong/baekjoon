#include <iostream>
#include <vector>

using namespace std;
const int MAX = 8;

void find(int n, int m, int result[], int index, int curr){
    if(index == m){
        for(int i=0; i<m; i++)
            cout << result[i] << " ";
        cout << endl;
        return;
    }
    for(int i=curr; i<n; i++){
        result[index] = i+1;
        find(n, m, result, index+1, i);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    int result[MAX] = {0,};

    cin >> n >> m;

    find(n, m, result, 0, 0);

    return 0;
}