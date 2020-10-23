#include <deque>
#include <iostream>

using namespace std;
#define MAXSIZE 1000
int m,n;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int visited[1000][1000] = {0,};
int a[1000][1000] = {0,};

bool isInside(int y, int x){
    if(0<= y && y < m && 0<= x && x < n)
        return true;
    return false;
}

int bfs(){
    deque<pair<int, int> > q;
    q.push_back(make_pair(0,0));
    visited[0][0] = a[0][0] + 1;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop_front();
        printf("-------------pop: %d %d\n",y, x);

        if(y == m-1 && x == n-1){
                printf("cnt: %d\n", visited[m-1][n-1]);
                return visited[m-1][n-1] - 1;
            }

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(isInside(ny, nx)){
                if(a[ny][nx] == 0 && visited[ny][nx] == 0){
                    visited[ny][nx] = visited[y][x];
                    printf("a[ny][nx] = 0, ny: %d nx: %d\n",ny,nx);
                    printf("visit: %d\n", visited[ny][nx]);
                    q.push_front(make_pair(ny,nx));
                }
                if(a[ny][nx] == 1 && visited[ny][nx] == 0){
                    visited[ny][nx] = visited[y][x] + 1;
                    printf("a[ny][nx] = 1, ny: %d nx: %d\n",ny,nx);
                    printf("visit: %d\n", visited[ny][nx]);
                    q.push_back(make_pair(ny,nx));
                }
                if(a[ny][nx] == 2 && visited[ny][nx] == 0){
                    visited[ny][nx] = visited[y][x] + 2;
                    printf("a[ny][nx] = 2, ny: %d nx: %d\n",ny,nx);
                    printf("visit: %d\n", visited[ny][nx]);
                    q.push_back(make_pair(ny,nx));
                }
            }
        }
    }
    return -1;
}

int main(){
    cin >> m >> n;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin >> a[i][j];

 
    if(a[0][0] == -1 || a[m-1][n-1] == -1)
        cout << -1;
    else{
        cout << bfs() << endl;
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            cout << visited[i][j] << "\t";
        cout << endl;
    }
    return 0;
}

/*
2 3
1 -1 -1
1 -1 2

-1

2 3
-1 1 -1
1 1 -1

6 8
0 0 1 1 -1 1 0 1
1 0 1 1 1 1 1 1
1 0 0 -1 1 0 1 1
1 -1 1 1 1 0 1 1
1 0 1 0 0 0 1 1
1 0 0 0 1 1 1 0

4

6 8
2 0 1 1 -1 1 0 1
1 0 1 1 1 1 1 1
1 0 0 -1 1 0 1 1
1 -1 2 1 1 0 1 1
1 0 2 0 0 0 -1 1
1 0 0 0 1 2 2 0

8
//다익스트라 사용하는 듯
*/