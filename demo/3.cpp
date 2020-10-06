#include <iostream>
#include <vector>
#include <cstring>

using  namespace std;

int main(){
    // string S = "abccbd";
    // vector<int> C = {0,1,2,3,4,5};
    // string S = "aabbcc";
    // vector<int> C = {1,2,1,2,1,2};
     string S = "aaaa";
    vector<int> C = {3,4,5,6};
    
    int sum=0;
    int index=0;
    for(int i=0; i<S.length()-1; i++, index++){
        if(S[i] == S[i+1]){
            if(C[index] < C[index+1]){
                S.erase(i, 1);
               // cout << i << " " << C[index] << endl;
                sum+=C[index];
                i--;
            }else{
                sum+=C[index+1];
                //cout << i << " " << C[index] << endl;
                S.erase(i+1,1);
            }
        }
    }
    cout << S << " " << sum << endl;
    return 0;
}
