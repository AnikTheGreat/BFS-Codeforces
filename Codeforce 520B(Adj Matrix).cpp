#include<bits/stdc++.h>
using namespace std;
int mat[10001][10001];
int n,m,visited[10001];

void MakingGraph(int maxm);
void BFS(int n, int maxm);

int main(){
    cin>>n>>m;
    int maxm = max(n,m);

    MakingGraph(maxm);
    BFS(n,maxm);
}

void MakingGraph(int maxm){
    for(int i=1;i<=maxm;i++){
        int a = i*2;
        int b = i-1;

        if(a<=maxm)
            mat[i][a] = 1;
        mat[i][b] = 1;
    }
}
void BFS(int n, int maxm){
    int steps = 0;
    queue<int> q;
    q.push(n);
    visited[n]=1;

    while(n!=m){
        n = q.front();
        q.pop();
        for(int i=1;i<=maxm;i++){
            if(mat[n][i]==1 && visited[i]==0){
                q.push(i);
                visited[i] = 1;

                if(i==m){
                    n = m;
                    break;
                }
            }
        }
        steps++;
    }
    cout<<steps;
}



