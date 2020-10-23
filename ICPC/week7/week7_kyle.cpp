#include <iostream>
#include <math.h>
using namespace std;
int main() {
  int toCheck= 0;
  int n;
  scanf("%d",&n);
  pair<int,float> *thePair = new pair<int,float>[n];
  
  for(int i = 0; i < n; i++)
  {
    scanf("%d %f",&thePair[i].first,&thePair[i].second);
    if(i>0)
    {
      for(int j = toCheck; j < i; j++)
      {
        float fTemp = pow(thePair[i].first - thePair[j].first, 2)/(4*thePair[j].second);
        thePair[i].second = thePair[i].second < fTemp ? thePair[i].second : fTemp;
      }
      toCheck = (thePair[i].second > thePair[toCheck].second) ? i : toCheck;
    }
  }
  cout.setf(ios::fixed,ios::floatfield);
  cout.precision(3);
  for( int i = 0; i < n; i++)
    cout << thePair[i].second << endl;
}