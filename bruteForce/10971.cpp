#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> path(N);
    int** arr = new int*[N];
    for(int i=0; i<N; i++){
        arr[i] = new int[N];
        path[i] = i+1;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    int min=10000000;
    do{
        int sum=0;
        int a=0, b=0;
        bool ok = true;
        for(int i=0; i<N-1; i++){
            a=path[i];      b=path[i+1];
            if(arr[a-1][b-1] != 0){
                sum += arr[a-1][b-1];
            }else{
                ok = false;
            }
        }  
        a=path[N-1];    b=path[0];
        if(ok && arr[a-1][b-1] != 0){
            sum += arr[a-1][b-1];
            min = sum<=min ? sum : min;
        }
    }while(next_permutation(path.begin(), path.end()));

    cout << min << endl;

    return 0;
}