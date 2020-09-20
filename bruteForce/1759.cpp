#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//vector<char> vowels = {'a','e','i','e','o'};

bool mycomp(char a, char b){
    if(a < b)
        return true;
    else 
        return false;
}

bool check(string &code){
    int vow=0; 
    int cons=0;
    for(char x : code){
        if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'){
            vow++;
        }
        else{
            cons++;
        }
    }
    if(vow >=1 && cons >=2)
        return true;
    else
    {
        return false;
    }
    
}

void select(int L, vector<char> &a, string code, int i){
    if(code.length() == L){
        if(check(code))
            cout << code << endl;
        return;
    }
    if(i >= a.size()){
        return;
    }
    select(L, a, code+a[i], i+1);
    select(L, a, code, i+1);
}

int main(){
    int L, C;
    cin >> L >> C;

    vector<char> a(C);
    for(int i=0; i<C; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end(), mycomp);

    string code="";
    select(L, a, code, 0);



    return 0;
}