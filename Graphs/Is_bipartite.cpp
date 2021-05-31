// Find if the graph is bipartite or not
// will use adjacency list bcz nbr info needed

// 5 6
// 0 1
// 0 2
// 1 3
// 2 4
// 2 3
// 3 4


#include<bits/stdc++.h>
using namespace std;



   // in visited  array 0= not visited ,1=visited and color no1 , 2=visited and color no2

   bool callDFS(int source,int parent,int color,vector<int>& vis,vector<int> adj[])
   {
                 vis[source]=color;

                 for(auto nbr:adj[source])
                 {
                     if(vis[nbr]==0)     // visiteing first tme
                     {
                         bool isBipartite=callDFS(nbr,source,3-color,vis,adj);
                         if(isBipartite==false)
                            return false;
                     }

                     else if(nbr!=parent and color==vis[nbr])
                           return false;

                 }

                 return true;

   }
int main()
{
   int v,e;
   cin>>v>>e;

   vector<int>adj[v];

   int a,b;
   for(int i=0;i<e;i++)
   {
       cin>>a>>b;
         adj[a].push_back(b);
         adj[b].push_back(a);
   }
   


       vector<int>vis(v,0);
       bool res=callDFS(0,-1,1,vis,adj);

       if(res)
         cout<<"Graph is bipartite";
         else{
             cout<<"NOT bipartite";
         }
         cout<<endl;

         for(int i=0;i<vis.size();i++)
         {
             cout<<i<<" vertx"<<vis[i]<<"color"<<endl;
         }

       return 0;

}
