#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
string day[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
int num[] = {0,1,2,3,4,5,6};

int main(){
    string S = "Wed";
    int K = 2;
    int index=0;
    for(int i = index; i< 7; i++){
        if(day[i] == S){
            index = i;
            break;
        }
    }

    int temp = K%7;
    int result = (index + temp) % 7;
    cout << day[result] << endl;
    return 0;
}