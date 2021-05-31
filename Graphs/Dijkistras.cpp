
#include <bits/stdc++.h>
using namespace std;


class Graph{

   int V;
    vector<pair<int,int>>*adj;

    public:

    Graph(int V)
    {
        this->V=V;
        adj=new vector<pair<int,int>>[V+1];
    }

    void addEdge(int x,int y,int weight)
    {
       // adj[x].push_back({y,weight});
         adj[x].push_back(make_pair(y,weight));
    }

    void callDijkistras()
    {
               vector<int>dist(V+1,INT_MAX);
            //priority_queue<pair<int,int>>pq;


            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

            pq.push({0,1});
            dist[1]=0;


            while(!pq.empty())
            {
                auto node=pq.top();
                int source_node=node.second;
                int source_dist= node.first;

                pq.pop();

                for(auto nbr:adj[source_node])
                {
                     int nbr_node=nbr.first;
                     int nbr_dist=nbr.second;

                     if(source_dist+nbr_dist<dist[nbr_node])
                     {
                         dist[nbr_node]=source_dist+nbr_dist;
                         pq.push({dist[nbr_node],nbr_node});
                     }
                }

            }

            for(int i=0;i<dist.size();i++)
            {
                cout<<"shortest distance of "<<1<<" to "<<i<<" is "<<dist[i]<<endl;
            }


    }

};

    

int main() {
      Graph g(5);
      g.addEdge(1,2,2);
       g.addEdge(1,4,1);
        g.addEdge(2,1,2);
         g.addEdge(2,5,5);
          g.addEdge(2,4,3);
           g.addEdge(3,2,4);
            g.addEdge(3,4,3);
             g.addEdge(3,5,1);
             g.addEdge(4,1,1);
             g.addEdge(4,3,3);
             g.addEdge(5,2,5);
             g.addEdge(5,3,1);

            g.callDijkistras();
 
return 0;


}
