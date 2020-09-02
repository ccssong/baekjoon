#include <iostream>
#include <vector>

using namespace std;

int primeNumber(vector<int> vect)
{
    int result = 0;

    for (int i = 0; i < vect.size(); i++)
    {
        int count = 0;
        for (int j = 1; j <= vect[i]; j++)
        {   
           if(vect[i] % j == 0)
                count += 1;
        }
        if (count == 2)
        {
            result += 1;
        }
    }
    return result;
}

int main()
{
    int test_case;
    cin >> test_case;

    vector<int> box(test_case);
    for (int i = 0; i < test_case; i++)
    {
        cin >> box[i];
    }

    int result = 0;
    result = primeNumber(box);
    cout << result << endl;
}