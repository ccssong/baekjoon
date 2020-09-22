#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int p,q,r,n,m;
int alphaMin = 160000, betaMin = 160000, unionMin = 160000;
pair<int,int> alphaVisit[40000];
pair<int,int> betaVisit[40000];

typedef struct _node{
    int data;
    struct _node *next;
}node;

node* path[40000];

void createNode(node *a, int _data){
    node* head = a;
    while(head->next != NULL){
        head = head->next;
    }
    node* newNode = (node *)malloc(sizeof(node));
    newNode->next = NULL;
    newNode->data = _data;
    head->next = newNode;
}

void findEachPath(int start, int cost, int firstCity){
    if(firstCity == 1){
        if(start == n){
            alphaMin = cost < alphaMin ? cost : alphaMin;
            return;
        }
        node* curr = path[start]->next;
        //cout << curr->data << endl;
        while(curr!= NULL){
            alphaVisit[curr->data].first = 1;
            alphaVisit[curr->data].second = cost+p;
            findEachPath(curr->data, cost+p, firstCity);
            curr = curr->next;
        }
    }else{
        if(start == n){
            betaMin = cost < betaMin ? cost : betaMin;
            return;
        }
        node* curr = path[start]->next;
        //cout << curr->data << endl;
        while(curr!= NULL){
            betaVisit[curr->data].first = 1;
            betaVisit[curr->data].second = cost + q;
            findEachPath(curr->data, cost+p, firstCity);
            curr = curr->next;
        }
    }
}

void checkMinUnion(int start, int cost){
    //cout << "start: " << start << "cost: " << cost << endl;
    if(start == n){
        unionMin = cost < unionMin ? cost : unionMin;
        return;
    }
    node* curr = path[start]->next;
    while(curr != NULL){
        checkMinUnion(curr->data, cost+r);
        curr = curr->next;
    }
}

void findUnionPath(){
     for(int i=1; i<n; i++){
        if(alphaVisit[i].first == 1 && betaVisit[i].first == 1){
            //cout << i << endl;
            checkMinUnion(i, alphaVisit[i].second + betaVisit[i].second);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> p >> q >> r >> n >> m;

    for(int i=1; i<n; i++){
        path[i] = (node*)malloc(sizeof(node));
        path[i]->next = NULL;
        path[i]->data = -1;
    }

    for(int i=1; i<=m ;i++){
        int start, end;
        cin >> start >> end;
        createNode(path[start], end);
    }
    findEachPath(1, 0, 1);
    findEachPath(2, 0, 2);
    findUnionPath();
    
    if(alphaMin + betaMin < unionMin)
        cout << alphaMin + betaMin << endl;
    else
        cout << unionMin << endl;
    
    return 0;
}