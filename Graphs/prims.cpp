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

        
        vector<int>vis(v,0);
       
        int total_dist=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,0});
        
         

         while(!pq.empty())
         {
               int weight=pq.top().first;
               int source_node=pq.top().second;
               pq.pop();

                if(vis[source_node]==true)
                  continue;

                total_dist=total_dist+weight;
                
               vis[source_node]=true;
               
                 // 0--->{(1,2),(3,6)}  -- Ajacency list format
               for(auto nbr_pair:adj[source_node] )
               {
                     int nbr_node=nbr_pair.first;
                      int nbr_dist=nbr_pair.second;


                   if(vis[nbr_node]==false)
                   {
                        
                        pq.push({nbr_dist,nbr_node});
                       
                   }

               }


         }


         
        cout<<total_dist<<"\n";
	     return 0;

}




     
    