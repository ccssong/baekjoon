#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1001;
vector< vector<int> > edge;
bool check[MAX] = {false, };
int n,m;
int _count=0;

void dfs(int node){
    for(int i=0; i<edge[node].size(); i++){
        if(!check[edge[node][i]]){
            check[edge[node][i]] = true;
            dfs(edge[node][i]);
        }
    }
}

int main(){
    cin >> n >> m;
    edge.resize(n+1); 

    for(int i=0; i<m; i++){
        int start, end;
        cin >> start >> end;
        edge[start].push_back(end);
        edge[end].push_back(start);
    }

    for(int i=1; i<=n; i++){
        if(!check[i]){
            check[i] = true;
            _count++;
            dfs(i);
        }
    }
    cout << _count << endl;

    return 0;
}