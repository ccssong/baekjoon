#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>

#define MAXSIZE 500000

using namespace std;

int readInt();

int IsCycle(int root);

int n, m;
vector<int> link[MAXSIZE];

void Input(){
    n = readInt();
    m = readInt();
}

void Solve(){
    for(int i=1; i<=m; i++){
        int u, v;
        u = readInt(); v = readInt();
        link[u].push_back(v);
        link[v].push_back(u);

        if(IsCycle(u)){
            cout << i;
            return;
        }
    }

    cout << 0;
    return;


}

int IsCycle(int root){
    int visited[MAXSIZE] = {0,};
    stack<int> s;

    s.push(root);

    while (!s.empty()){
        int u = s.top(); s.pop();

        for(int i=0; i < link[u].size(); i++){
            int v = link[u][i];
            if(visited[v] == 0){
                visited[v] = visited[u]+1;
                s.push(v);
            }
            if(abs(visited[u] - visited[v]) >= 2) return 1;


        }
    }
    return 0;
}

int main(){
    Input();
    Solve();

}

int readInt(){
    int temp;
    scanf("%d", &temp);
    return temp;
}