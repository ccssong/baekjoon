#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<int> a;
vector<int> num;
vector<pair<int,int> > ans;
int total=0;

int main(){
    cin >> n;
    a.resize(2*n);
    num.resize(2*n);
    

    for(int i=0; i<2*n; i++){
        cin >> num[i];
        total += num[i];
    }   
   sort(num.begin(), num.end());
   int min = 20999001;
   for(int i=0; i < n; i++){
       int sum = num[i] + num[2*n-i-1];
       if(sum < min)
            min = sum;
   }
   cout << min;
    
   

    return 0;
}