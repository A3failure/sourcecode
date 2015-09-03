#include<cstdio>
#include<vector>
#include<map>
#include<queue>
using namespace std;
map < int,int > visited;
#define mem(n) memset(n,0,sizeof(n))
void bfs(int source,map< int, vector < int > > graph){
    queue < int > Q;
    Q.push(source);
    visited[source]=0;
    while(!Q.empty()){
        int top=Q.front();
        Q.pop();
        for(int i=0;i< graph[top].size();i++){
            int v=graph[top][i];
            if(!visited.count(v)){
                visited[v]=visited[top]+1;
                Q.push(v);
            }
        }
    }
}
int main(void)
{
    int node,cases=0;
    while(scanf("%d",&node) && node){
        map < int, vector<int> > graph;
        for(int i=0;i<node;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int source,ttl;
        while(scanf("%d%d",&source,&ttl) && (source!=0 || ttl !=0)){
            int result =0;
            visited.clear();
            bfs(source,graph);
            map <int,int>::const_iterator itr;
            for(itr=visited.begin();itr != visited.end();++itr){
                if((*itr).second > ttl)result++;
            }
            result+=graph.size()-visited.size();
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++cases,result,source,ttl);
        }
    }
    return 0;
}

