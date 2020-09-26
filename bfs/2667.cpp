#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int a[26][26];
int n;
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};
bool visit[25][25] = {false, };
vector<int> result;
int group=0;

void bfs(int x, int y, int cnt){
    group=1;
    queue< pair<int,int> > q;
    q.push(make_pair(x,y));
    visit[x][y] = true;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx=x+dx[i]; int ny=y+dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<n){
                if(!visit[nx][ny] && a[nx][ny] == 1){
                    visit[nx][ny] = true;
                    //a[nx][ny] = cnt;
                    q.push(make_pair(nx,ny));
                    group++;
                }
            }
        }
    }
    result.push_back(group);
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%1d",&a[i][j]);

    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visit[i][j] && a[i][j] != 0){
                visit[i][j] = true;
                bfs(i,j,cnt++);
            }
        }
    }
    cout << cnt << endl;
    for(int i=0; i<result.size(); i++)
        cout << result[i] << endl;

    return 0;
}