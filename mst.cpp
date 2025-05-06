#include<iostream>
#define Max 100
#define INF 999
using namespace std;
int cost[Max][Max];
int visited[Max];


void prim(int n){
    int totalcost=0;
    visited[0]=1;
    for(int edges=1;edges<n ; edges++){
        int min=INF;
        int u=-1;
        int v=-1;
        for(int i=0;i<n;i++){
            if(visited[i]){
                for(int j=0;j<n;j++){
                    if(cost[i][j]&&!visited[j]&&cost[i][j]<min){
                        min=cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        if(u!=-1&&v!=-1){
            cout<<"edge "<<u<<"- "<<v<<"| cost- "<<min<<endl;
            totalcost+=min;
            visited[v]=1;
        }
    }
    cout<<"total minimum cost"<<totalcost<<endl;
}
int main(){
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter cost matrix (0 for no edge):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    prim(n);
    return 0;
}
