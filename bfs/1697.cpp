#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int MAX = 100001;
int n,k;
int visited[100001] = {0,};

void bfs(){
    queue<int> q;
    q.push(n);
    visited[n] = 1;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(x == k)
            return;

        for(int i=0; i<3; i++){
            int nx;
            if(i==0)        nx = x+1;
            else if(i==1)   nx = x-1;
            else if(i==2)   nx = x*2;

            if(0 <= nx && nx < MAX && visited[nx] == 0){
                visited[nx] = visited[x]+1;
                q.push(nx);
               // printf("nx: %d, visit count: %d\n",nx, visited[nx]);
            }
        }
    }
}

int main(){
    cin >> n >> k;

    bfs();
    cout << visited[k]-1 << endl;

    return 0;
}