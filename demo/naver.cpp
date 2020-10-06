#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
vector<vector<int>> v;
int cnt[51] = {
    0,
};
bool check[51] = {
    false,
};

void dfs(int node)
{
    queue<int> q;
    for (int i = 0; i < v[node].size(); i++)
    {
        if (!check[v[node][i]])
        {
            check[v[node][i]] = true;
            q.push(v[node][i]);
            dfs(v[node][i]);
        }
    }
    if (q.empty())
    {
        cnt[node] = 1;
        // printf("node: %d cnt: %d\n" ,node,cnt[node]);
    }
    else
    {
        cnt[node] += 1;
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            cnt[node] += cnt[now];
        }
        // printf("node: %d cnt: %d\n" ,node,cnt[node]);
    }
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first > b.first;
    return a.second < b.second;
}

int main()
{
    int n = 19;
    vector<vector<int>> a{{0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 5}, {4, 11}, {4, 12}, {5, 13}, {2, 6}, {6, 14}, {6, 15}, {6, 16}, {3, 7}, {3, 8}, {3, 9}, {8, 17}, {8, 18}};
    v.resize(19);
    for (int i = 0; i < a.size(); i++)
    {
        v[a[i][0]].push_back(a[i][1]);
        v[a[i][1]].push_back(a[i][0]);
    }

    check[0] = true;
    dfs(0);

    bool visited[51] = {
        false,
    };
    int cut = 0;
    vector<pair<int, int>> next;
    queue<int> head;
    head.push(0);
    while(!head.empty()){
        while (!head.empty())
        {
            int parent = head.front();
            head.pop();
            cout <<"head size: " <<  head.size() << endl;
            cout << parent << endl;
            for (int j = 0; j < v[parent].size(); j++)
            {
                if (!visited[v[parent][j]])
                {
                    visited[v[parent][j]] = true;
                    next.push_back(make_pair(v[parent][j], cnt[v[parent][j]]));
                    printf("v: %d cnt: %d\n", v[parent][j], cnt[v[parent][j]]);
                }
            }
        }
        sort(next.begin(), next.end(), cmp);
        cout << "end: " << next.back().first << " " << next.back().second << endl;
        next.pop_back();
        for(int i=0; i<next.size(); i++){
            head.push(next[i].first);
        }
        cut++;
    }

return 0;
}