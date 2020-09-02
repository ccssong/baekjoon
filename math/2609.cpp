#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    int result = 1;
    for(int i = 1; i <= min(a,b); i++){
        if(a%i==0 && b%i == 0){
            result = i;
        }
    }
    return result;
}

int main(){
    int a, b;
    cin >> a >> b;

    int g = gcd(a,b);
    cout << g << endl;
    int l = g*(a/g)*(b/g);
    cout << l << endl;

}