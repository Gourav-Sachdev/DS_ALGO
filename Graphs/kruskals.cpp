#include<bits/stdc++.h>
using namespace std;

class DSU{

public:
       int V;
    //    vector<int>* parent;
    //    vector<int>* rank;

    int* parent;
    int* rank;


       DSU(int V)
       {
           // parent=new vector<int>(V,-1);
           // rank=new vector<int>(V,1);
            
            parent=new int[V];
            rank=new int[V];

            fill(parent,parent+V,-1);
            fill(rank,rank+V,1);
           
       }
       

       int find(int i)
       {
           if(parent[i]==-1)
              return i;
             return parent[i]= find(parent[i]);
       }

       void union_set(int x,int y)
       {
           int s1=find(x);
           int s2=find(y);

           if(s1!=s2)
           {
               if(rank[s1]<rank[s2])
               {
                   parent[s1]=s2;
                   rank[s2]+=rank[s1];
               }
               else{
                    parent[s2]=s1;
                   rank[s1]+=rank[s2];
               }
           }

       }


};
class Graph
{
    public:
            int V;
            vector<vector<int>> edges;

            Graph(int V)
            {
                this->V=V;
               
            }

            void addEdge(int x,int y,int w)
            {
                edges.push_back({w,x,y});
            }



        int kruskal()
       {
           sort(edges.begin(),edges.end());
           DSU s(4);
           int sum=0;

           for(auto edge_vector:edges)
           {
               int w=edge_vector[0];
               int x=edge_vector[1];
               int y=edge_vector[2];

               if(s.find(x)!=s.find(y))
               {
                   s.union_set(x,y);
                   sum=sum+w;
               }
           }

           return sum;

       }




};

int main()
{
       Graph g(4);
       

       g.addEdge(0,1,1);
       g.addEdge(1,3,3);
       g.addEdge(3,2,4);
       g.addEdge(2,0,2);
       g.addEdge(0,3,2);
       g.addEdge(1,2,2);


       cout<<"the max spanning tree cost is"<<g.kruskal();

       return 0;


      
}
