#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
const int INF = 1e9;
vector<pair<int,int>> graph[N];
int dis[N];
int main()
{
    int n,e;
    cin >> n >> e;
    // memset(dis,INF,sizeof(dis));
    for(int i=1;i<=n;i++)
    {
        dis[i] = INF;
    }

    while(e--)
    {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});

    }

    int src = 1;

    dis[src] = 0;

    for(int i=0;i<n-1;i++)
    {
        for(int u = 1;u<=n;u++)
        {
            for(auto adj : graph[u])
            {
                int v = adj.first;
                int w = adj.second;
                if(dis[u] + w < dis[v])
                {
                    dis[v] = dis[u]+w;
                }
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout << i << " -> " << dis[i]<<endl;
    }
   
}

/*
4 4
1 3 5
1 2 10
2 3 -12
3 4 4

*/
