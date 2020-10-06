#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 2000000000;
int f_num, g_num, p, q;
int cnt1 = 0, cnt2 = 0, ans = 0;
vector<pair<int, int> > f;
vector<pair<int, int> > g;

void initialize()
{
    while (cnt1 + 1 < f_num)
    {   
        if ((f[cnt1].first <= p && p < f[cnt1 + 1].first) || p < f[cnt1].first)
        {
            break;
        }
        else
        {
            cnt1++;
        }
    }
    while(cnt2 + 1 < g_num){
        if ((g[cnt2].first <= p && p < g[cnt2 + 1].first) || p < g[cnt2].first)
        {
            break;
        }
        else
        {
            cnt2++;
        }
    }
}

void find()
{
    initialize();
   // cout << cnt1 << "\t" << cnt2 << endl;
    int mul = 0;
    int end = MAX;
    while (p != q + 1)
    {
        int temp1 = cnt1, temp2 = cnt2;
        if(cnt1 >= f_num) 
        {
          temp1 = cnt1-1;
        }
        if(cnt2 >= g_num) 
        {
          temp2= cnt2-1;
        }      
        if (f[temp1].first <= p && g[temp2].first <= p)
        {
            if (f[temp1].second > g[temp2].second)
            {
                mul = f[temp1].second;
                cnt1++;
                temp1++;
               // cout << "f mul " << mul << ", cnt1: " << cnt1 << endl;
            }
            else
            {
                mul = g[temp2].second;
                cnt2++;
                temp2++;
               // cout << "g mul " << mul << ", cnt2: " << cnt2 << endl;
            }
        }
        else if (f[temp1].first <= p)
        {
            //cout << "f " << f[cnt1].first << endl;
            mul = f[temp1].second;
            cnt1++;
            temp1++;
        }
        else if (g[temp2].first <= p)
        {
            //cout << "g " << g[cnt2].first << endl;
            mul = g[temp2].second;
            cnt2++;
            temp2++;
        }

        if (temp1 == f_num)
        {
            end = MAX;
        }
        else
        {
            if (p < f[temp1].first)
                end = f[temp1].first;
        }
        if (temp2 == g_num)
        {
            end = end < MAX ? end : MAX;
        }
        else
        {
            if (p < g[temp2].first)
                end = end < g[temp2].first ? end : g[temp2].first;
        }

        if (end <= q)
        {
            ans += ((end - p) * mul);
            ans %= 10007;
            p = end;
           // printf("end < q -> ans: %d, p: %d, end: %d\n", ans, p, end);
        }
        else
        {
            ans += ((q - p + 1) * mul);
            ans %= 10007;
            p = q + 1;
           // printf("end > q -> ans: %d, p: %d, end: %d\n", ans, p, end);
        }

        end = MAX+1;
    }
}

int main()
{
    cin >> f_num;
    for (int i = 0; i < f_num; i++)
    {
        int a, b;
        cin >> a >> b;
        f.push_back(make_pair(a, b));
    }

    cin >> g_num;
    for (int i = 0; i < g_num; i++)
    {
        int a, b;
        cin >> a >> b;
        g.push_back(make_pair(a, b));
    }

    cin >> p >> q;
    find();
    cout << ans;

    return 0;
}