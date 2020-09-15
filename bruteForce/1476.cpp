#include <iostream>

using namespace std;

int main(){
    int E=0, S=0, M=0;
    cin >> E >> S >> M;

    int sum=1, e=1, s=1, m=1;
    while(e !=E || s != S || m != M){
        sum++;
        e++;
        s++;
        m++;
        if(e == 16)
            e=1;
        if(s == 29)
            s=1;
        if(m == 20)
            m=1;
    }

    cout << sum << endl;

    return 0;
}