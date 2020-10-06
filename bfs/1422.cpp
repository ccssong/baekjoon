#include <iostream>
#include <queue>
#include <stdio.h>
#include <cstring>

using namespace std;
#define MAX 1001
int s;
bool check[1001][1001];

struct component{
    int display; 
    int clip;
    int time;
};

int bfs(){
    queue<component> q;
    component c = {1,0,0};
    q.push(c);
    check[1][0] = true;
    int result=0;

    while(!q.empty()){
        int display = q.front().display;
        int clip = q.front().clip;
        int time = q.front().time;
        q.pop();

        if(display == s){
            result = time;
            break;
        }

        if(0<= display && display < MAX){
            if(!check[display][display]){
                check[display][display] = true;
                component c = {display, display, time+1};
                q.push(c);
            }
        }

        if(0 < clip && clip+display < MAX){
            if(!check[display+clip][clip]){
                check[display+clip][clip] = true;
                component c = {display+clip, clip, time+1};
                q.push(c);
            }
        }

        if(0<= display-1){
            if(!check[display-1][clip]){
                check[display-1][clip] = true;
                component c = {display-1,clip, time+1};
                q.push(c);
            }
        }
    }
    return result;
}

int main(){
    memset(check, false, sizeof(check[0][0]) * 1001 * 1001);
    cin >> s;

    cout <<  bfs() << endl;
   
    return 0;
}