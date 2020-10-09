#include <iostream>
#include <queue>
#include <stdio.h>
#include <cstring>

using namespace std;
int a[1000][1000];
int visited[1000][1000][2];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m;

bool isInside(int y, int x){
    if( 0 <= y && y < n && 0 <= x && x < m)
        return true;
    return false;
}

int bfs(){
    queue<pair<pair<int, int>, int > > q;
    q.push(make_pair(make_pair(0,0),1));
    visited[0][0][1] = 1;

    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if(y == n-1 && x == m-1)
            return visited[n-1][m-1][cnt];
        
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(isInside(ny,nx)){
                if(a[ny][nx] == 1 && cnt == 1 && visited[ny][nx][cnt] == 0){
                    visited[ny][nx][cnt-1] = visited[y][x][cnt] + 1;
                    q.push(make_pair(make_pair(ny,nx),cnt-1));
                   // printf("1 -- ny: %d nx: %d cnt: %d\n",ny,nx,cnt);
                }

                if(a[ny][nx] == 0 && visited[ny][nx][cnt] == 0){
                    visited[ny][nx][cnt] = visited[y][x][cnt] + 1;
                    q.push(make_pair(make_pair(ny,nx),cnt));
                  //  printf("0 -- ny: %d nx: %d cnt: %d\n",ny,nx,cnt);
                }
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