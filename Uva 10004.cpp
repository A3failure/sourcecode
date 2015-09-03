#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

vector < int > edge[400];
int array[402],visited[402];
int bfs(int source){
    for(int i=0;i<402;i++){
        array[i]=-1;
        visited[i]=0;
    }
    queue< int > Q;
    Q.push(source);
    array[source]=0;
    while(!Q.empty()){
        int top=Q.front();
        Q.pop();
        for(int i=0;i<edge[top].size();i++){
            int v=edge[top][i];
            if(array[top]==0){
                if(array[v]!=0 && !visited[v]){
                    array[v]=1;
                    visited[v]=1;
                    Q.push(v);
                }
                else if(array[v]==0)return -1;
            }
            else if(array[top]==1){
                if(array[v]!=1 && !visited[v]){
                    array[v]=0;
                    visited[v]=1;
                    Q.push(v);
                }
                else if(array[v]==1)return -1;
            }
        }
    }
    return 1;
}
int main(void)
{
    int node,edges,x,y,src;
    while(scanf("%d%d",&node,&edges) && node){
        if(edges >  0){
            scanf("%d%d",&x,&y);
            edge[x].push_back(y);
             src=x;

             for(int i=0;i<edges-1;i++){
                scanf("%d%d",&x,&y);
                edge[x].push_back(y);
            }
            int color=bfs(src);
            if(color==-1)printf("NOT BICOLORABLE.\n");
            else printf("BICOLORABLE.\n");
            for(int i=0;i<400;i++){
                edge[i].clear();
            }
        }
        else printf("BICOLORABLE\n");
    }
    return 0;
}
