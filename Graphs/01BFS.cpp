#include<bits/stdc++.h>
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
         adj[y].push_back(make_pair(x,weight));
    }


    void bfs_01()
    {

        // visited array is not needed as dist vertex will do the job of it
               vector<int>dist(V+1,INT_MAX);
            //priority_queue<pair<int,int>>pq;


            //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            deque<pair<int,int>>dq;

            dq.push_back({0,1});
            dist[1]=0;


            while(!dq.empty())
            {
                pair<int,int> node=dq.front();
                int source_node=node.second;
                int source_dist= node.first;

                dq.pop_front();

                for(auto nbr:adj[source_node])
                {
                     int nbr_node=nbr.first;
                     int nbr_dist=nbr.second;

                     if(source_dist+nbr_dist<dist[nbr_node])
                     {

                         dist[nbr_node]=source_dist+nbr_dist;

                         if(nbr_dist==1)
                         {
                             dq.push_back({dist[nbr_node],nbr_node});
                         }else{
                              dq.push_front({dist[nbr_node],nbr_node});
                         }
                         
                     }
                }

            }

            for(int i=0;i<dist.size();i++)
            {
                cout<<"shortest distance of "<<1<<" to "<<i<<" is "<<dist[i]<<endl;
            }


    }

};


int main()
{
    Graph g(6);
  

    

       g.addEdge(1,2,0);
       g.addEdge(1,3,1);
       g.addEdge(2,4,0);
       g.addEdge(4,3,0);
       g.addEdge(3,5,1);
       g.addEdge(5,6,1);

       g.bfs_01();




    return 0;



}