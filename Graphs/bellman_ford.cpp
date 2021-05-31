//  Bellman ford algo 
//   test case (directed graph)
//     3 3    vertices and edges
//     1 2 3
//     3 1 -10
//     2 3 4

#include<bits/stdc++.h>
using namespace std;


   void runBallmanFord(int V,int src,vector<vector<int>>edges,vector<int>& dist)
   {

           // for V-1 times relax all the edges
           dist[src]=0;
           for(int i=0;i<V-1;i++)
           {
               for(auto edge:edges)
               {
                   int u=edge[0];
                   int v=edge[1];
                   int wt=edge[2];

                   if(dist[u]!=INT_MAX and dist[u]+wt<dist[v])
                     dist[v] =dist[u]+wt;
                     
               }
           }


           // Run for Vth time to check cycle

           for(auto edge:edges)
               {
                   int u=edge[0];
                   int v=edge[1];
                   int wt=edge[2];

                   if(dist[u]!=INT_MAX and dist[u]+wt<dist[v])
                     {
                         cout<<"negative cycle found";
                         exit(0) ;
                     }  
               }

               cout<<"NO negative cycle found";
               return ;
       

   }

int main()
{
    int V,e;
    cin>>V>>e;

    vector<vector<int>>edges;   //(2-->3,weight=5)

    int a,b,c;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }

      vector<int>dist(V+1,INT_MAX);

       int src=1;
       dist[src]=0;
       runBallmanFord(V,src,edges,dist);

       for(int i=1;i<=V;i++)
       {
           cout<<"dist of "<<i<<"== "<<dist[i];
       }


}


