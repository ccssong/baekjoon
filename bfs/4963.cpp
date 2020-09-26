#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int w,h;
int a[50][50];
bool visited[50][50] = {false, };
int dx[8] = {0,0,-1,1,-1,1,-1,1};
int dy[8] = {-1,1,0,0,-1,-1,1,1};
int cnt;

void dfs(int x, int y){
    for(int i=0; i<8; i++){
        int nx = x + dx[i]; int ny = y + dy[i];
        if(0 <= nx && nx <h && 0 <= ny && ny < w){
            if(!visited[nx][ny] && a[nx][ny] == 1){
                visited[nx][ny] = true;
                dfs(nx,ny);
            }
        }
    }
}

int main(){
    while(1){
        cin >> w >> h;
        if(w==0 && h==0)
            break;
        
        for(int i=0; i<50; i++){
            memset(visited[i], false, 50);
        }
        cnt = 0;
        
        for(int i=0; i<h; i++)
            for(int j=0; j<w; j++)
                cin >> a[i][j];

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(!visited[i][j] && a[i][j] == 1){
                    visited[i][j] = true;
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }   

    return 0;
}


