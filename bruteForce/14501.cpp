#include <iostream>
#include <vector>

using namespace std;
int T;
vector<int> day;
vector<int> pay;

int _max=0;
void check(int sum, int i){
    if(i == T){
        //cout << i << " " << sum << endl;
        if(sum >= _max){
            _max=sum;
            //cout << "max: " << _max <<  ", sum: " << sum << endl;
        }
        return;
    } 
     if(i > T)
        return;
    
    check(sum+pay[i], i+day[i]);
    check(sum, i+1);
}

int main(){
    cin >> T;

    for(int i=0; i<T; i++){
        int d,p;
        cin >> d >> p;
        day.push_back(d);
        pay.push_back(p);
    }
    
    
    check(0,0);
    cout <<  _max << endl;

    return 0;
}