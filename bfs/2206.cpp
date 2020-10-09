#include <iostream>
#include <queue>
#include <stdio.h>
#include <cstring>

using namespace std;
int a[1000][1000];
int visited[1000][1000];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m;

struct component{
    int y;
    int x;
    int cnt;
};

bool isInside(int y, int x){
    if( 0 <= y && y < n && 0 <= x && x < m)
        return true;
    return false;
}

int bfs(){
    queue<component> q;
    component c = {0,0,1};
    q.push(c);
    visited[0][0] = 1;

    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int cnt = q.front().cnt;
        q.pop();

        if(y == n-1 && x == m-1)
            return visited[n-1][m-1];
        
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(isInside(ny,nx) && a[ny][nx] == 1 && cnt == 1){
                visited[ny][nx] = visited[y][x] + 1;
                component c = {ny,nx,cnt-1};
                q.push(c);
            }

            if(isInside(ny,nx) && a[ny][nx] == 0 && visited[ny][nx] == 0){
                visited[ny][nx] = visited[y][x] + 1;
                component c = {ny,nx,cnt};
                q.push(c);
            }
        }
    }
    return -1;
}

int main(){
    memset(visited, 0, sizeof(visited[0][0])*n*m);

    cin >> n >> m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%1d", &a[i][j]);
    
    cout << bfs() << endl;
    

    return 0;
}