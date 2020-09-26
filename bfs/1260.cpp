#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n,m,v;
vector< vector<int> > edge;
bool check_b[1001] = {false, };
bool check_d[1001] = {false, };
queue<int> q;

void bfs(){
    while(!q.empty()){
        int node = q.front();
        q.pop();
        printf("%d ", node);
        for(int i=0; i< edge[node].size(); i++){
            if(!check_b[edge[node][i]]){
                check_b[edge[node][i]] = true;
                q.push(edge[node][i]);
            }
        }
    }
}

void dfs(int node){
    printf("%d ",node);
    for(int i=0; i<edge[node].size(); i++){
        if(!check_d[edge[node][i]]){
            check_d[edge[node][i]] = true;
            dfs(edge[node][i]);
        }
    }
}

int main(){
    cin >> n >> m >> v;
    edge.resize(n+1);
    q.push(v);
    check_b[v] = true;
    check_d[v] = true;

    for(int i=0; i<m; i++){
        int start, end;
        cin >> start >> end;
        edge[start].push_back(end);
        edge[end].push_back(start);
    }
    for(int i=0; i<n; i++)
        sort(edge[i].begin(), edge[i].end());

    dfs(v);
    printf("\n");
    bfs();
    printf("\n");

    return 0;
}
