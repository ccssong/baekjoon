#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool next_permutation(vector<int> &arr, int n)
{
    int i = n - 1;

    while (i > 0 && arr[i - 1] >= arr[i])
    {
        i--;
    }
    if (i <= 0)
        return false;
    int j = n - 1;
    while (arr[i - 1] >= arr[j])
    {
        j--;
    }
    swap(arr[i - 1], arr[j]);
    j = n-1;
    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    return true;
}

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }

    do
    {
        for (int i = 0; i < N; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    } while (next_permutation(arr, N));

    // do{
    //     for(int i=0; i<N; i++){
    //         cout << arr[i] << " ";
    //     }
    //     cout << endl;
    // }while(next_permutation(arr.begin(), arr.end()));

    return 0;
}