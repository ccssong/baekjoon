#include <iostream>

using namespace std;

const int MAX = 8;
int n,m;
bool visited[MAX];
int arr[MAX];
int result[MAX];

void find(int index, int curr){
    if(index == m){
        for(int i=0; i<m; i++)
            cout << result[i] << " ";
        cout << endl;
    }
    for(int i=curr; i<n; i++){
        if(!visited[i]) continue;
        result[index] = arr[i];
        visited[i] = false;
        find(index+1, i);
        visited[i] = true;
    }
}

int main(){
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        arr[i] = i+1;
        visited[i] = true;
    }
    find(0,0);

    return 0;
}