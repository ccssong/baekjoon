#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 8;

int n,m;
vector<int> arr;
int result[MAX] = {0,};

void find(int index, int curr){
    if(index == m){
        for(int i=0; i<m; i++)
            printf("%d ",result[i]);
        printf("\n");
        return;
    }
    for(int i=curr; i<n; i++){
        result[index] = arr[i];
        find(index+1, i+1);
    }
}

int main(){
    cin >> n >> m;

    arr.resize(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    find(0, 0);

    return 0;
}