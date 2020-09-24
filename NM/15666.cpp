#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 8;
vector<int> arr;
int result[MAX] = {0,};
int n,m;

void find(int index, int curr){
    if(index == m){
        for(int i=0; i<m; i++)
            printf("%d ",result[i]);
        printf("\n");
        return;
    }
    bool used[10001] = {false, };
    for(int i=curr; i<n; i++){
        if(!used[arr[i]]){
            used[arr[i]] = true;
            result[index] = arr[i];
            find(index+1, i);
        }
    }
}

int main(){
    cin >> n >> m;
    arr.resize(n);

    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    find(0,0);

    return 0;
}