#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> arr(N); 
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    if(next_permutation(arr.begin(), arr.end())){
       for(int i=0; i<N; i++) {
           cout << arr[i] << " ";
       }
    }else{
        cout << "-1" << endl;
    }

    return 0;
}