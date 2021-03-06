#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>

using namespace std;
#define MAX 1000000000

vector<pair<int,double> > ballons;
int n;

void find(){
    pair<int, double> max;
    int maxIndex = 0;
    max.first = ballons[0].first;
    max.second = ballons[0].second;

    for(int i=1; i<ballons.size(); i++){
        double rmin = MAX;

        for(int j=maxIndex; j < i; j++){
            printf("??");
            int x2 = ballons[i].first;
            double y2 = ballons[i].second;
            int x1 = ballons[j].first;
            double y1 = ballons[j].second;
            double r;
            printf("%d %f, %d %f\n",x2,y2,x1,y1);
            printf("calculate result: %f, %f\n",4*y1*y2,  pow(x2-x1,2));
            if(4*y1*y2 <= pow(x2-x1,2)){
                r = y2;
                printf("r possible: %f\n",r);
            }
            else{
                r = pow(x2-x1,2) / (4*y1);
                printf("r impossible: %f\n",r);
            }            
            rmin = r < rmin ? r : rmin;
            printf("j: %d -- rmin: %f\n",j,rmin );
        }
        ballons[i].second = rmin;
        printf("ballon x: %d y: %f\n",ballons[i].first, ballons[i].second);
        if(rmin >= max.second){
            max.first = ballons[i].first;
            max.second = ballons[i].second;
            maxIndex = i;
            printf("max change -- %d: %f\n",max.first,max.second);
        }
        printf("\n");
    }
}

int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        int x; double r;
        scanf("%d %lf",&x,&r);
        ballons.push_back(make_pair(x,r));
    }

    find();

    for(int i=0; i<n; i++)
        printf("%.3f\n",ballons[i].second);

}

/*
3
0 9
8 1
13 7

3
1 9
10 5
20 10

3
1 1
5 3
11 4
*/