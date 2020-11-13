#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
int main(){
    vector<int> a(400);
    for(int i=0; i<400; i++){
        a[i] = rand()%10000;
    }

    for(int i=0; i<200; i++)
        printf("%d ",a[i]);
    printf("\n");
    for(int i=200; i<400; i++)
        printf("%d ",a[i]);
}