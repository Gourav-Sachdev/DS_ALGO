#include<bits/stdc++.h>
using namespace std;

int main()
{
    int v;
    int e;
    cin>>v>>e;

    vector<pair<int,int>>adj[v];

     int x,y,wt;
    for(int i=0;i<e;i++)
    {
        cin>>x>>y>>wt;
        adj[x].push_back({y,wt});
        adj[y].push_back({x,wt});
    }

        vector<int>parent(v,-1);
        vector<int>vis(v,0);
        vector<int>dist(v,INT_MAX);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,0});
        parent[0]=-1;
         

         while(!pq.empty())
         {
               int source_dist=pq.top().first;
               int source_node=pq.top().second;
               vis[source_node]=1;
               pq.pop();

               for(auto nbr_pair:adj[source_node] )
               {
                   int nbr_node=nbr_pair.second;
                   int nbr_dist=nbr_pair.first;

                   if(vis[nbr_node]==false and dist[nbr_node]<source_dist)
                   {
                        parent[nbr_node]=source_node;
                        dist[nbr_node]=source_dist;
                        pq.push({source_dist,nbr_node});
                   }

               }


         }


         for (int i = 1; i < v; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	     return 0;

}