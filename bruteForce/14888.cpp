#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector<int> num(N);
    for(int i=0; i<N; i++){
        cin >> num[i];
    }
        
    vector<int> opers(4);
    for(int i=0; i<4; i++){
        cin >> opers[i];
    }
    vector<int> op;
    for(int i=0; i<4; i++){
        int size = opers[i];
        for(int j=0; j<size; j++)
            op.push_back(i);
    }

    long long min= 1000000000;
    long long max = -1000000000;
    do{
        int temp=num[0];
        for(int i=0; i<op.size(); i++){
            switch(op[i]){
                case 0: temp += num[i+1]; break;
                case 1: temp -= num[i+1]; break;
                case 2: temp *= num[i+1]; break;
                case 3: temp /= num[i+1]; break;
                default: break;
            }
        }
        //cout << temp << endl;
        min = temp <= min ? temp : min;
        max = temp >= max ? temp : max;
    }while(next_permutation(op.begin(), op.end()));
    
    cout << max << endl;
    cout << min << endl;
    return 0;
}