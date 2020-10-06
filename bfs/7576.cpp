#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n,m;
int a[1000][1000];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void bfs(vector<pair<int, int> > tomatos){
    queue< pair<int, int> > q;
    for(int i=0; i<tomatos.size(); i++){      
        int x = tomatos[i].first;
        int y = tomatos[i].second;
        q.push(make_pair(x, y));
    }

    while(!q.empty()){
        int x = q.front().first; int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x+dx[i]; int ny = y+dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m){
                if(a[nx][ny] == 0){
                    a[nx][ny] = a[x][y] + 1;
                    
                    //printf("nx: %d, ny: %d days: %d,\n",nx,ny, a[nx][ny]);
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
}

int main(){
    cin >> m >> n;

    vector<pair<int, int> > tomatos;

    int cnt1=0, cnt2=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d",&a[i][j]);
            if(a[i][j] == -1)
                cnt1++;
            if(a[i][j] == 1){
                cnt2++;
                tomatos.push_back(make_pair(i, j));
            }
        }
    }

    //토마토가 미리 다 익은 경우
    if(cnt1+cnt2 == n*m){
        cout << "0" << endl;
        return 0;
    }

    bfs(tomatos);

    int result=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == 0){
                cout << "-1" << endl;
                return 0;
            }
            if(a[i][j] > result)
                result = a[i][j];
        }
    }

    cout << result-1 << endl;
    return 0;
}