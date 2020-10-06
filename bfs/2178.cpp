#include <iostream>
#include <queue>

using namespace std;
int n,m;
int maze[100][100];
int check[100][100] = {0, };
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int bfs(int x, int y){
    queue< pair<int, int> > q;
    q.push(make_pair(x,y));
    check[x][y] = 1;
    while(!q.empty()){
        x = q.front().first; y = q.front().second;
        q.pop();

        int cnt = check[x][y];
        for(int i=0; i<4; i++){
            int nx = x+dx[i]; int ny=y+dy[i];
            if(0 <= nx && nx < n && 0<= ny && ny < m){
                if(check[nx][ny] == 0 && maze[nx][ny] == 1){
                    check[nx][ny] = cnt+1;
                    q.push(make_pair(nx, ny));
                   // printf("current x, y: %d %d\t cnt: %d\n", nx, ny, check[nx][ny]);
                }
            }
        }
    }
    return check[n-1][m-1];
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%1d", &maze[i][j]);
    
    int result = bfs(0,0);
    cout << result << endl;

    
    return 0;
}