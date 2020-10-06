#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main(){
    int N = 697;
    int n;

    if(N < 0)  n = abs(N);
    else    n = N;

    cout << n << endl;

    vector<int> num;
    int count=0;
    if(n == 0)
        num.push_back(0);
    while(n != 0){
        int temp = n % 10;
        n /= 10;
        num.push_back(temp);
    }
    reverse(num.begin(), num.end());
   
    
    vector<int>::iterator it;
    bool flag = false;
    if(N >= 0){
        for(it =num.begin(); it<num.end(); it++){
            if(*it < 5){
                flag = true;
                num.insert( it, 5);
                break;
            }
        }
        if(!flag){
            num.push_back(5);
        }
    }else{
        for(it = num.begin(); it < num.end(); it++){
            if(*it > 5){
                flag = true;
                num.insert(it, 5);
                break;
            }
        }
        if(!flag){
            num.push_back(5);
        }
    }

    
    reverse(num.begin(), num.end());
    int decimal = 1;
    int result=0;
    for(it = num.begin(); it < num.end(); it++){
        result += (*it) * decimal;
        decimal *= 10;
    }
    if(N  < 0)
        result *= -1;
    cout << result << endl;

    return 0;
}