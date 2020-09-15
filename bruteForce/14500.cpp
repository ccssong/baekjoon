#include <iostream>

using namespace std;

int **arr;

int main(){
    int n,m;
    cin >> n >> m;

    arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[m];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    int sum=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            //1
            if(j+3 < m){
                int temp = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i][j+3];
                if(temp > sum)  sum = temp;
            }
            //2
            if(i+3 < n){
                int temp = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+3][j];
                if(temp > sum) sum=temp;
            }
            //3
            if(i+1 < n && j+1 < m){
                int temp = arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1];
                if(temp > sum) sum=temp;
            }
            //4
            if(i+2 < n && j+1 < m){
                int temp = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+2][j+1];
                if(temp > sum) sum=temp;
            }
            //5
            if(i+2 < n && j-1 >= 0){
                int temp = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+2][j-1];
                if(temp > sum) sum=temp;
            }
            //6
            if(i+2 < n && j+1 < m){
                int temp = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i][j+1];
                if(temp > sum) sum=temp;
            }
            //7
           if(i+2 < n && j-1 >= 0){
                int temp = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i][j-1];
                if(temp > sum) sum=temp;
            }
            //8
            if(i+1 < n && j+2 <m){
                int temp = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j];
                if(temp > sum) sum=temp;
            }
            //9
            if(i+1 < n && j+2 <m){
                int temp = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+2];
                if(temp > sum) sum=temp;
            }
            //10
            if(i-1 >= 0 && j+2 <m){
                int temp = arr[i-1][j] + arr[i][j] + arr[i][j+1] + arr[i][j+2];
                if(temp > sum) sum=temp;
            }
            //11
            if(i-1 >= 0 && j+2 <m){
                int temp = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i-1][j+2];
                if(temp > sum) sum=temp;
            }
            //12
            if(i+2 < n && j+1 <m){
                int temp = arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j+1];
                if(temp > sum) sum=temp;
            }
            //13
            if(i+2 < n && j-1 >=0){
                int temp = arr[i][j] + arr[i+1][j] + arr[i+1][j-1] + arr[i+2][j-1];
                if(temp > sum) sum=temp;
            }
            //14
            if(i+1 < n && j+2 <m){
                int temp = arr[i+1][j] + arr[i+1][j+1] + arr[i][j+1] + arr[i][j+2];
                if(temp > sum) sum=temp;
            }
            //15
            if(i+1 < n && j+2 <m){
                int temp = arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+1][j+2];
                if(temp > sum) sum=temp;
            }
            //16
            if(i+1 < n && j+2 < m){
                int temp = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1];
                if(temp > sum) sum=temp;
            }
            //17
            if(i-1 >= 0 && j+2 < m){
                int temp = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i-1][j+1];
                if(temp > sum) sum=temp;
            }
            //18
            if(i+2 < n && j-1 >= 0){
                int temp = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+1][j-1];
                if(temp > sum) sum=temp;
            }
            //19
            if(i+2 < n && j+1 < m){
                int temp = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+1][j+1];
                if(temp > sum) sum=temp;
            }
        }
    }
    cout << sum << endl;

    return 0;
}