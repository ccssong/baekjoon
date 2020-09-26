#include <iostream>
#include <vector>

using namespace std;
const int MAX = 2000;
int n,m;
vector< vector<int> > edge;
bool check[MAX]={false, };

void dfs(int x, int cnt){
    check[x] = true;
    if(cnt == 4){
        printf("%d\n",1);
        exit(0);
        
    }
    for(int i=0; i< edge[x].size(); i++){
        int next = edge[x][i];
        if(!check[next]){
            dfs(next, cnt+1);
        }
    }
    check[x] = false;
}

int main(){
    cin >> n >> m;
    edge.resize(n);

    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i=0; i<n; i++){
        dfs(i, 0);
    }
    cout << "0" << endl;
    return 0;
}