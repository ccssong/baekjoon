#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

int main(){
    int test_case;
    vector<int> box;

    cin >> test_case;
    int temp;

    for(int i=0; i<test_case; i++){
        int num = 0;
        cin >> num;

        for(int j=0; j<num; j++){
            int temp;
            cin >> temp;
            box.push_back(temp);
        }

        //자료형 주의!
        long long result=0;
        for(int n=0; n<box.size()-1; n++){
           // cout << box[n] << endl;
            for(int m=n+1; m<box.size();m++){
               // cout << box[m] << endl;
                result += gcd(box[n], box[m]);
            }
        }
        box.clear();
        cout << result << endl;
    }
}