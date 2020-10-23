#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <cmath>
#include <stdlib.h>

using namespace std;
#define MAX 5
int n;
int sqrSize;
int totalNumber;

vector<vector<pair<int, int> > > poly;
int** result;
bool squarePossible = false;
bool endCondition = false;

bool isInside(int y, int x)
{
    if (0 <= y && y < sqrSize && 0 <= x && x < sqrSize)
        return true;
    return false;
}

void find(int index, int **square, int total)
{
    printf("\n### index: %d, total:%d\n", index, total);
    if (total == totalNumber)
    {
        printf("total = %d\n", total);
        for (int i = 0; i < sqrSize; i++)
            for (int j = 0; j < sqrSize; j++)
                result[i][j] = square[i][j];
        
        for (int i = 0; i < sqrSize; i++){
            for (int j = 0; j < sqrSize; j++){
                printf("%d ",square[i][j]);
            }
            printf("\n");
        }
        squarePossible = true;
        endCondition = true;
        return;
    }

    for (int i = 0; i < sqrSize; i++)
    {
        for (int j = 0; j < sqrSize; j++)
        {
            if (!endCondition)
            {
                if(square[i][j] == 0){
                    int y = i;
                    int x = j;

                    printf("index: %d availiable y: %d, x: %d,, total: %d\n", index, y, x,total);
                    bool isPolyInside = true;
                    for(int k = 0; k < poly[index].size(); k++){
                        int ny = y + poly[index][k].first;
                        int nx = x + poly[index][k].second;

                        if(!isInside(ny,nx) || square[ny][nx] != 0){
                            printf("is not inside:((((( ny: %d nx: %d\n",ny,nx);
                            isPolyInside = false;
                        }
                    }
                    if(!isPolyInside){
                        // 조각이 square 범위를 벗어나거나 다른 조각과 겹칠 때
                        continue;
                    }
                    else{
                        printf("in polynomina!!!\n");
                        for(int k=0; k<poly[index].size(); k++){
                            int ny = y + poly[index][k].first;
                            int nx = x + poly[index][k].second;
                            square[ny][nx] = index + 1;
                            total++;
                            printf("------%d: ny: %d nx: %d\n",index,ny,nx);
                        }

                        find(index+1, square, total);
                        total -= poly[index].size();
                        for(int k=0; k<poly[index].size(); k++){
                            int ny = y + poly[index][k].first;
                            int nx = x + poly[index][k].second;
                            square[ny][nx] =0;
                        }
                    }
                    int temp;
                    cin >> temp;
                }
            }
        }
    }


    printf("~~~~~~~search end index: %d, total: %d\n\n", index, total);
    return;
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int h, w;
        scanf("%d %d", &h, &w);

        int a[h][w];
        vector<pair<int, int> > b;
        int colStart=-1;
        for (int row = 0; row < h; row++)
        {
            for (int col = 0; col < w; col++)
            {
                scanf("%d", &a[row][col]);
                if (row == 0 && a[row][col] == 1 && colStart == -1)
                {
                    colStart = col;
                }
                if(a[row][col] == 1){
                    totalNumber += a[row][col];
                    b.push_back(make_pair(row, col-colStart));
                }
            }
        }
        poly.push_back(b);
    }

    sqrSize = (int)sqrt((double)totalNumber);
    cout << "sqrt sqrSizeL " << pow(sqrSize,2) << endl;

    int **square;
    square = new int *[sqrSize];
    result = new int *[sqrSize];

    for (int i = 0; i < sqrSize; i++)
    {
        square[i] = new int[sqrSize];
        result[i] = new int [sqrSize];
        memset(square[i], 0, sizeof(int) * sqrSize);
        memset(result[i], 0, sizeof(int) * sqrSize);
    }

    // for(int i=0; i<poly.size(); i++){
    //     for(int j=0; j<poly[i].size(); j++){
    //         printf("index: %d: %d %d\n", i, poly[i][j].first, poly[i][j].second);
    //     }
    //     cout << endl;
    // }

    find(0, square, 0);
    if (squarePossible)
    {
        for (int i = 0; i < sqrSize; i++)
        {
            for (int j = 0; j < sqrSize; j++)
                cout << result[i][j] << " ";
            cout << endl;
        }
    }
    else
    {
        cout << "No solution possible";
    }

    return 0;
}

/*
4 
2 3 1 1 1 1 0 1 4 2 0 1 0 1 1 1 0 1 2 1 1 1 3 2 1 0 1 0 1 1

2
4 4 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1

4
4 1 1 1 1 1 1 1 1 1 1 1 1 1 1

2
3 3 0 1 1 1 1 1 1 1 0 1 1 1

2
3 3 0 1 1 1 1 1 1 1 1 1 1 1


**/