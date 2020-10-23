#include <iostream>
#include <cstring>


using namespace std;

int main(){
    int n = 0, a,b;
    int std =0, find=0, index=0;
    cin >> n;

    string s, t;
    char c1, c2;

    cin >> s;
    cin >> t;

    cin >> a >> b;
//a,b인덱스값 제거

    c1 = s[a];
    c2 = s[b];     

    for(int i=b; i<s.length()-1; i++){
        s[i] = s[i+1];
    }
    for(int i=a; i<s.length()-2; i++){
        s[i] = s[i+1];
    }
    
    std  = n-2;

    for(int i=0; i<n; i++){
        if(s[index] == t[i]){
            index++;
            if(index == std){
                cout << "YES";
                return 0;  
            }
        }else{
            find++;
            if(find==1){
                if(t[i]!=c1){
                    cout << "NO";
                    return 0;   
                }   
            }
            if(find==2){
                if(t[i]!=c2){
                    cout << "NO";
                    return 0;   
                }    
            }
        }
        if(find>=3){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}