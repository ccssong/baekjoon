#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> arr(N);
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int max=0;
    do{
        int sum=0;
        for(int i=0; i<N-1; i++){
            sum += abs(arr[i] - arr[i+1]);
        }
        if(sum >= max)
            max = sum;
    }while(next_permutation(arr.begin(), arr.end()));

    cout << max << endl;

    return 0;
}