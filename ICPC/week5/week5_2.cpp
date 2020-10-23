#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
vector<pair<int,int> > f;
vector<pair<int,int> > g;
int p, q;
int index_f=0, index_g=0;
long long ans;

void preAdjust(){
    while(p < f[index_f].first){
        index_f++;
        printf("p: %d, index_f: %d, f: %d\n",p,index_f, f[index_f].first);
    }
     while(p < g[index_g].first){
        index_g++;
        printf("p: %d, index_g: %d, g: %d\n",p,index_g, g[index_g].first);
    }
}

void find(){
    preAdjust();
    // while(p == q+1){
    //     int mul = 0;
    //     if
    // }
}


int main(){
    for(int i=0; i<2; i++){
        int n;
        cin >> n;

        for(int k=0; k<n; k++){
            int a, v;
            cin >> a >> v;
            if(i == 0)
                f.push_back(make_pair(a,v));
            else
                g.push_back(make_pair(a,v));
        }
    }
    cin >> p >> q;
    find();
    return 0;
}

/*
3
-3 2
3 3
5 6
1
4 5
1 5
**/