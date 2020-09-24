#include <iostream>

using namespace std;
const int MAX = 8;
int result[MAX] = {0,};

void find(int n, int m, int index){
    if(index == m){
        for(int i=0; i<m; i++)
            cout << result[i] << " ";
        cout << endl;
        return;
    }
    for(int i=0; i<n; i++){
        result[index] = i+1;
        find(n,m,index+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    
    find(n,m,0);


    return 0;
}