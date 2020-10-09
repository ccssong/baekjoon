#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;
#define WATER 0
#define HEDGEHOG 1

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};

int R,C;
char a[50][50] = {'0',};
int visited[50][50] = {0,};
queue <pair<pair<int,int>, int> > q;

bool isInside(int y,int x){
    if (0<=y && y<R && 0<=x && x < C)
        return true;
    return false; 
}

int bfs(){
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int division = q.front().second;
        q.pop();

        for (int i=0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(isInside(ny, nx)){
                if(division == HEDGEHOG){
                    if(a[ny][nx] == '.' && visited[ny][nx] == 0){
                        a[ny][nx] == 'S';
                        visited[ny][nx] = visited[y][x] + 1;
                        q.push(make_pair(make_pair(ny,nx),HEDGEHOG));
                    }
                    if(a[ny][nx] == 'D'){
                        visited[ny][nx] = visited[y][x] + 1;
                        return visited[ny][nx] - 1;
                    }
                }else{
                    if(a[ny][nx] == '.' ){
                        a[ny][nx] = '*';
                        visited[ny][nx] = visited[y][x] + 1;
                        q.push(make_pair(make_pair(ny,nx),WATER));
                    }
                }
            }
        }
        
    }
    return -1;
}

int main(){
    cin >> R >> C;

    int y; int x;
    for(int i=0; i<R; i++){
        scanf("%s",&a[i]);
        for(int j=0; j<C; j++){
            if(a[i][j] == '*')
                q.push(make_pair(make_pair(i,j),WATER));
            if(a[i][j] == 'S'){
                y = i;
                x = j;
            }
        }
    }

    q.push(make_pair(make_pair(y,x),HEDGEHOG));
    visited[y][x] = 1;
    
    int result = bfs();
    if(result == -1){
        cout << "KAKTUS" << endl;
    }
    else{
        cout << result << endl;
    }
    return 0;
}