#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 9;

int result[MAX] = {0, };
vector<int> arr;
bool check[MAX];
int n,m;


void find(int index){
    if(index == m){
        for(int i=0; i<m; i++)
            printf("%d ", result[i]);
        printf("\n");
        return;
    }
    bool used[10001] = {false,};
    for(int i=0; i<n; i++){ 
        if(!used[arr[i]] && !check[i]){
            used[arr[i]] = true;
            check[i] = true;
            result[index] = arr[i];
            find(index+1);
            check[i] = false;
        }
    }
}
//2 4 4
int main(){
    cin >> n >> m;
    arr.resize(n);

    for(int i=0; i<n; i++){
        //printf("i: %d\n",i);
        cin >> arr[i];
        check[i] = false;
    }

    sort(arr.begin(), arr.end());

  
    find(0);

    return 0;
}