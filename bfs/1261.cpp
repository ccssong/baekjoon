#include <iostream>
#include <deque>
#include <cstring>
#include <stdio.h>

using namespace std;
#define MAX 100
int visited[100][100];
int a[100][100];
// 우, 하, 좌, 상
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m;

bool isInside(int y, int x){
    if(0 <= y && y < n && 0 <= x && x < m)
        return true;
    return false;
}

int bfs(){
    deque<pair<int, int> > dq;
    dq.push_back(make_pair(0,0));
    visited[0][0] = 1;

     while(!dq.empty()){
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();
       // printf("dfdfdfsdfsdfs y: %d, x: %d, visited: %d\n", y,x,visited[y][x]);

        if(y == n-1 && x == m-1)
            return visited[n-1][m-1]-1;

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(isInside(ny,nx) && a[ny][nx] == 0 && visited[ny][nx] == 0){
                visited[ny][nx] = visited[y][x];
                dq.push_front(make_pair(ny,nx));
            }
            if(isInside(ny,nx) && a[ny][nx] == 1 && visited[ny][nx] == 0){
                visited[ny][nx] = visited[y][x] + 1;
                dq.push_back(make_pair(ny,nx));
            }
        }
    }
}

int main(){
    memset(visited, 0, sizeof(visited[0][0]) * n * m);
    cin >> m >> n;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%1d", &a[i][j]);

  
    cout << bfs() << endl;

    return 0;
}