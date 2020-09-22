#include <iostream>
#include <string>
using namespace std;

int n, S, x;
string str;

int main(){     
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    while(n--){
        str.clear();
        cin >> str;

        if(str == "add"){
            cin >> x;
            S |= (1 << x);
        }
        else if(str == "remove"){
            cin >> x;
            S &= ~(1 << x);
        }
        else if(str == "check"){
            cin >> x;
            if(S & (1<<x))
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else if(str == "toggle"){
            cin >> x;
            S ^= (1<<x);
        }
        else if(str == "all"){
            S =  (1 << 21) - 1;
        }
        else if(str == "empty"){
           S = 0;
        }
    }
    
    return 0;
}


// #include <iostream>
// #include <string>
// using namespace std;
 
// int M, num, BIT;
// string input;
 
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
 
//     cin >> M;
//     while (M--)
//     {
//         input.clear();
//         cin >> input;
//         if (input == "add")
//         {
//             cin >> num;
//             BIT |= (1 << num);
//         }
//         else if (input == "remove")
//         {
//             cin >> num;
//             BIT &= ~(1 << num);
//         }
//         else if (input == "check")
//         {
//             cin >> num;
//             if (BIT & (1 << num))    cout << 1 << '\n';
//             else    cout << 0 << '\n';
//         }
//         else if (input == "toggle")
//         {
//             cin >> num;
//             BIT ^= (1 << num);
//         }
//         else if (input == "all")
//         {
//             BIT = (1 << 21) - 1;
//         }
//         else if (input == "empty")
//         {
//             BIT = 0;
//         }
//     }
//     return 0;
// }
