#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<string> split(string command){
    vector<string> str;
    char *buffer = new char[1000];
    strcpy(buffer, command.c_str());
    char *tok = strtok(buffer, " ");
    
    if(tok == NULL)
        str.push_back(string(tok));
    else{
        while(tok != NULL){
            str.push_back(string(tok));
            tok = strtok(NULL, " ");
        }
    }

    return str;
}

int main(){
    int n;
    cin >> n;
    cin.get();

    vector<int> S;
    for(int i=0; i<n; i++){
        string command;
        getline(cin, command);
        
        vector<string> str = split(command);
        
        if(str[0] == "add"){
            int x = stoi(str[1]);
            S.push_back(x);
        }
        else if(str[0] == "remove"){
            int x = stoi(str[1]);
            vector<int>::iterator iter;
            iter = find(S.begin(), S.end(), x);
            if(iter != S.end()){
                S.erase(iter);
            }
        }
        else if(str[0] == "check"){
            int x = stoi(str[1]);
            vector<int>::iterator iter;
            iter = find(S.begin(), S.end(), x);
            if(iter != S.end()){
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
            }
        }
        else if(str[0] == "toggle"){
            int x = stoi(str[1]);
            vector<int>::iterator iter;
            iter = find(S.begin(), S.end(), x);
            if(iter != S.end()){
                S.erase(iter);
            }else{
                S.push_back(x);
            }
        }
        else if(str[0] == "all"){
            S.clear();
            for(int i=1; i<=20; i++){
                S.push_back(i);
            }
        }
        else if(str[0] == "empty"){
            S.clear();
        }

        
    }
    return 0;
}