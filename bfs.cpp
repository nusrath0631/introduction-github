#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,m,x,y;
    cin >> n >> m;
    int am[n][n];
    memset(am,0,sizeof(am));
    for(i=0;i<m;i++){
        cin>>x>>y;
        am[x][y] = 1;
        am[y][x] = 1;
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cout<< am[i][j]<<" ";
        }
        cout<<endl;
    }

    queue<int> q;
    int parent[n], visited[n];
    int source;

    cin>> source;
    q.push(source);
    visited[source] = 1;
    parent[source] = -1;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(i=0; i<n; i++){
            if(am[v][i] == 1 && visited[i] != 1){
                q.push(i);
                parent[i] = v;
                visited[i] = 1;
            }
        }
    }
    for(i=0; i<n; i++){
        cout<< parent[i]<< " ";
    }
}
