#include <stdlib.h>
#include <iostream>

using namespace std;

void test(int index){
    if(index == 2)
        exit(1);
    
    cout << "index: " << index << endl;
    for(int i=index; i > 0; i--){
        cout << i << endl;
        test(i-1);
    }
}

int main(){
    cout << "?" << endl;
    test(4);

    return 0;
}

void find(int index, int** square,  int total){
    printf("### index: %d, total:%d\n",index,total);
    if(total == (int)pow(size,2)){
        printf("total = %d\n",total);
        for(int i=0; i<size; i++)
            for(int j=0; j<size; j++)
                result[i][j] = square[i][j];

        squarePossible = true;
        return;
    }

    int x,y;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(square[i][j] == 0){
                y = i;
                x = j;
                printf("index: %d availiable y: %d, x: %d\n", index, y, x);
                bool polyInside = true;
                for(int k=0; k<poly[index].size(); k++){
                    int ny = y+poly[index][k].first;
                    int nx = x+poly[index][k].second;
                    printf("ny: %d, nx:%d \n",ny,nx);
                    if(!isInside(ny, nx) || visited[ny][nx]){
                        polyInside = false;
                    }
                }
                if(!polyInside)
                    continue;
                else{
                    printf("is polyInside\n");
                    for(int k=0; k<poly[index].size(); k++){
                        int ny = y+poly[index][k].first;
                        int nx = x+poly[index][k].second;
                        square[ny][nx] = index+1;
                        visited[ny][nx] = true;
                        total++;
                        printf("------%d: ny: %d nx: %d\n",index,ny,nx);
                    }
                    find(++index, square, total);
                    for(int k=0; k<poly[index].size(); k++){
                        int ny = y+poly[index][k].first;
                        int nx = x+poly[index][k].second;
                        visited[ny][nx] = false;
                    }
                }
                int temp;
                cin >> temp;
            }
        }
    }
}
