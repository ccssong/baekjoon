#include <iostream>
#include <queue>
#include <stdio.h>
#include <cstring>

#define INF 1001
int m,n;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int visited[1000][1000] = {0,};
int a[1000][1000] = {0,};
int d[1000][1000];

bool isInside(int y, int x){
    if(0<= y && y < m && 0<= x && x < n)
        return true;
    return false;
}



int dijkstra(){
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            d[i] = a
        }
    }
}

int main(){
    cin >> m >> n;

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++){
            cin >> a[i][j];
            d[i][j] = INF;
        }

 
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