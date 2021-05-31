#include<bits/stdc++.h>
using namespace std;

class Graph{

       int V;
       vector<int>*adj;

  public:


       Graph(int V)
       {
           this->V=V;
           adj=new vector<int>[V+1];
       }


       void addEdge(int x,int y)
       {
           adj[x].push_back(y);
       }


         int findParent(int source,int parent[])
         {
             if(parent[source]==-1)
                  return source;

              return parent[source]=findParent(parent[source],parent);    
         }


         void Union(int node1,int node2,int parent[])
         {
             int s1=findParent(node1,parent);
             int s2=findParent(node2,parent);

             if(s1!=s2)
             {
                 parent[s1]=s2;
             }
         }

       bool findCycle()
       {
           int* parent=new int[V+1];
           fill(parent,parent+V+1,-1);


           for(int i=0;i<=V;i++)
           {
               for(auto edge:adj[i])
               {
                   int node1=i;
                   int node2=edge;

                   int s1=findParent( node1,parent);
                   int s2=findParent( node2,parent);
                   if(s1!=s2)
                   {
                       Union(s1,s2,parent);
                   }
                   else{
                       return true;
                   }
                  
               }
           }
           delete [] parent;
           return false;


       }


};


int main()
{
    Graph g(4);
    g.addEdge(1,2);
     g.addEdge(2,3);
      g.addEdge(3,4);
      // g.addEdge(4,1);

      if(g.findCycle())
       cout<<"there is a cycle";
       else{
           cout<<"No cycle found";
       }


}