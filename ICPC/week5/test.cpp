#include <iostream>
#include <vector>

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
    cout << cnt1 << "\t" << cnt2 << endl;
    int mul = 0;
    int end = MAX;
    while (p != q + 1)
    {
      int temp1, temp2;
      if(cnt1 >= f_num) 
      {
        cout << "end of array" << endl;
        temp1 = f_num-1;
      }
      else
      {
        temp1 = f[cnt1].first;
      }
      if(cnt2 >= g_num) 
      {
        cout << "end of array" << endl;
        temp2 = g_num-1;
      }
      else
      {
        temp2 = g[cnt2].first;
      }
      if (temp1 <= p && temp2 <= p)
      {
          if (f[cnt1].second > g[cnt2].second)
          {
              mul = f[cnt1].second;
              cnt1++;
              cout << "f mul " << mul << ", cnt1: " << cnt1 << endl;
          }
          else
          {
              mul = g[cnt2].second;
              cnt2++;
              cout << "g mul " << mul << ", cnt2: " << cnt2 << endl;
          }
      }
      else if (temp1 <= p)
      {
          cout << "f " << f[cnt1].first  << "temp1: " << temp1 << endl;
          mul = f[cnt1].second;
          cnt1++;
      }
      else if (temp2 <= p)
      {
          cout << "g " << g[cnt2].first << endl;
          mul = g[cnt2].second;
          cnt2++;
      }

      if (cnt1 == f_num)
      {
          end = MAX + 1;
      }
      else
      {
          if (p < temp1)
              end = temp1;
      }
      if (cnt2 == g_num)
      {
          end = end < MAX + 1 ? end : MAX + 1;
      }
      else
      {
          if (p < temp2)
              end = end < temp2 ? end : temp2;
      }

      if (end <= q)
      {
          ans += ((end - p) * mul) % 10007;
          p = end;
          printf("end < q -> ans: %d, p: %d, end: %d, mul:%d\n", ans, p, end,mul);
      }
      else
      {
          ans += ((q - p + 1) * mul) % 10007;
          p = q + 1;
          printf("end > q -> ans: %d, p: %d, end: %d, mul:%d\n", ans, p, end,mul);
      }
      cout << "answer is " << ans << endl;
      end = MAX;
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