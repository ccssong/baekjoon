#include <iostream>

using namespace std;
int num[10];

int Sum(int a){
    if(a < 0)
        return 0;
    else if(a == 1 || a == 0)
        return 1;
    return Sum(a-1) + Sum(a-2) + Sum(a-3);

}

int main(){
    int T;
    cin >> T;
    
    for(int i=0; i<T; i++){
        cin >> num[i];
    }

    for(int i=0; i<T; i++){
        int result = Sum(num[i]);
        cout << result << endl;
    }


    return 0;
}