#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;
const int MAX = 20001;
const int RED = 0;
const int BLUE = 1;

int k;
bool check[MAX] = {false, };
int color[MAX]; 
vector< vector<int> > edge;
queue<int> q;


int bfs(int start){
    q.push(start);
    color[start] = RED;
    check[start] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
       // printf("node: %d, color: %d\n",node, color[node]);
        if(color[node] == RED){
            for(int i=0; i<edge[node].size(); i++){
                if(!check[edge[node][i]]){
                    check[edge[node][i]] = true;
                    color[edge[node][i]] = BLUE;
                    q.push(edge[node][i]);
                }
                else{
                    if(color[edge[node][i]] == RED){
                        return 0;
                    }
                }
            }
        }else if(color[node] == BLUE){
            for(int i=0; i<edge[node].size(); i++){
                if(!check[edge[node][i]]){
                    check[edge[node][i]] = true;
                    color[edge[node][i]] = RED;
                    q.push(edge[node][i]);
                }
                else
                {   
                    if(color[edge[node][i]] == BLUE){
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int main(){
    cin >> k;
    for(int i=0; i<k; i++){
        int n,m;
        cin >> n >> m;
        edge.resize(n+1);

        for(int j=0; j<m; j++){
            int start, end;
            cin >> start >> end;
            edge[start].push_back(end);
            edge[end].push_back(start);
        }

        int result = bfs(1);
        if(result == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        

        for(int j=1; j<n+1; j++)
            edge[i].clear();
        edge.clear();
        memset(check, false, MAX);
        queue<int> empty;
        swap(q, empty);

    }

    return 0;
}
