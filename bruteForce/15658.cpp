#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> num;
vector<int> oper(4);

int _max = -1000000000;
int _min = 1000000000;

void check(int i, int output, int plus, int minus, int mul, int div){
    //cout << i << "\t" << output << endl;
    if(plus < 0 || minus < 0 || mul <0 || div < 0)
        return;
    if(i == n-1){
        _max = output>=_max ? output : _max;
        _min = output<=_min ? output : _min;
        return;
    }
    check(i+1, output+num[i+1], plus-1, minus, mul, div);
    check(i+1, output-num[i+1], plus, minus-1, mul, div);
    check(i+1, (int)output*num[i+1], plus, minus, mul-1, div);
    check(i+1, (int)output/num[i+1], plus, minus, mul, div-1);
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        num.push_back(temp);
    }

    for(int i=0; i<4; i++){
        cin >> oper[i];
    }

    check(0, num[0], oper[0], oper[1], oper[2], oper[3]);

    cout << _max << endl;
    cout << _min << endl;

    return 0;
}