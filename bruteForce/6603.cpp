#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){     
    int T;
    vector<int> arr;
    vector<int> check;

    while(true){
        cin >> T;
        if(T == 0){
            break;
        }else{
            for(int i=0; i<T; i++){
                int temp;
                cin >> temp;
                arr.push_back(temp);
            }
            for(int i=0; i<6; i++)
                check.push_back(0);
            for(int i=0; i<T-6; i++)
                check.push_back(1);
            
            do{
                for(int i=0; i<T; i++){
                    if(check[i] == 0)
                        cout << arr[i] << " ";
                }
                cout << endl;
            }while(next_permutation(check.begin(), check.end()));
            cout << endl;
            
            check.clear();
            arr.clear();
        }
    }

    return 0;
}