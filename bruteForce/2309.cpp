#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    int num=9;
    int dwarfs[9];

    int sum=0;
    for(int i=0; i<num; i++){
        cin >> dwarfs[i];
        sum += dwarfs[i];
    }

    sort(dwarfs, dwarfs+num);
    
   for(int i=0; i<num; i++){
       for(int j=i+1; j<num; j++){
           if(sum-dwarfs[i]-dwarfs[j] == 100){
               for(int k=0; k<9; k++){
                   if(k == i || k == j) continue;
                    cout << dwarfs[k] << endl;
               }
               return 0;
           }
       }
   }

   return 0;
}