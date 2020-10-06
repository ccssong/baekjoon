#include <iostream>
#include <queue>

using namespace std;
#define MAX 100001
bool visited[MAX] = {false, };
int n,k;
int result;


int bfs(){
    priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int, int> > > q;
   //priority_queue에서 pair로 정의했을 때, first 먼저 비교 -> second 비교
    q.push(make_pair(0, n));
    visited[n] = true;

    while(!q.empty()){
        int time = q.top().first;
        int x = q.top().second;
        q.pop();

        if(x == k){
            return time;
        }

        //x*2 코드가 먼저 와야 하는 이유 --> visited때문에 그렇다.
        if(x*2 < MAX && !visited[x*2]){
            visited[x*2] = true;
            q.push(make_pair(time, x*2));   
        }
        if(0 <= x-1 && !visited[x-1]){
            visited[x-1] = true;
            q.push(make_pair(time+1, x-1));
        }
        if(x+1 < MAX && !visited[x+1]){           
            visited[x+1] = true;
            q.push(make_pair(time+1, x+1));
        
        }
    }
   // return result;
}

int main(){
    cin >> n >> k;
    
    cout << bfs() << endl;
    return 0;
}