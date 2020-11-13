#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
int N;
vector<int> a;
vector<int> result;

void removeOrigin(int min, int i){
    a.erase(a.begin()+i, a.begin()+i+2);
    a.insert(a.begin()+i, min);
    // for(int i=0; i<a.size(); i++)
    //     printf("%d ",a[i]);
    // printf("\n");
}

int main(){
    cin >> N;
    a.resize(N);

    for(int i=0; i<N; i++)
        cin >> a[i];

    int i = 1;
    while(a.size() != 1){
       // printf("while start\n");
        if(i >= a.size()-1){
          //  printf("i over size: %d\n",i);
            i = 1;
        }
        int size = a.size();
        int min = 0;
        if(i+2 < size){
            if(a[i-1] + a[i] < a[i] + a[i+1]){
                if(a[i-1] + a[i] < a[i+1] + a[i+2]){
                    min = a[i-1] + a[i];
                    removeOrigin(min, i-1);
                    i--;
                //    printf("1111 - previous: min: %d\n",min);
                }else{
                    min = a[i+1] + a[i+2];
                    removeOrigin(min, i+1);
                 //   printf("1111 - skip one: min: %d\n",min);
                }
            }else if(a[i] + a[i+1] < a[i+1] + a[i+2]){
                min = a[i] + a[i+1];
                removeOrigin(min, i);
                i--;
              //  printf("1111 - current one: min: %d\n",min);
            }else{
                min = a[i+1] + a[i+2];
                removeOrigin(min, i+1);
              //  printf("1111 - skip one: min: %d\n",min);
            }
        }
        else if(i+1 < size){
            if(a[i-1] + a[i] < a[i] + a[i+1]){
                min = a[i-1] + a[i];
                removeOrigin(min, i-1);
                i--;
               // printf("2222 - previous: min: %d\n",min);
            }
            else{
                min = a[i] + a[i+1]; 
                removeOrigin(min, i);
               // printf("2222 - current one: min: %d\n",min);
            }
        }
        else{
           // printf("last one\n");
            min = a[i-1] + a[i];
            a.clear();
            a.push_back(min);
            // for(int i=0; i<a.size(); i++)
            //     printf("%d ",a[i]);
            // cout << endl;
            // printf("3333 - min: %d\n",min);
        }
        result.push_back(min);
        i++;
       // printf("result.push_back: %d result size: %lu, i: %d\n",min,result.size(), i);
        fflush(stdin);
        // int temp;
        // scanf("%d",&temp);
        // cout << endl;
    }

    int sum=0;
     for(int i=0; i<result.size(); i++){
    //     printf("%d ",result[i]);
        sum += result[i];
    }
    cout <<  sum;
    return 0;
}

/*
4 3 4 4 2

12
1 20 35 5 4 3 5 92 23 14 32 18

5
4 1000 2 8 7
*/