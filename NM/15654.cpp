#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 10;

vector<int> arr;
bool visited[MAX];
int result[MAX] = {0,};

void find(int n, int m, int index){
    if(index == m){
        for(int i=0; i<m; i++){
            printf("%d ", result[i]);
            //cout << result[i] << " ";
        }
        printf("\n");
        //cout << endl;
        return;
    }
    for(int i=0; i<n; i++){
        if(visited[i])
            continue;
        result[index] = arr[i];
        visited[i] = true;
        find(n, m, index+1);
        visited[i] = false;
    }
}

int main(){

    int n,m;
    cin >> n >> m; 


    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
        visited[i] = false;
    }
    sort(arr.begin(), arr.end());

    find(n, m, 0);

    return 0;
}