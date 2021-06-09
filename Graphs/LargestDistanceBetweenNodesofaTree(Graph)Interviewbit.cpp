#include<bits/stdc++.h>
using namespace std;

 //vector<int>*adj;

void callDFS(int source,int parent,vector<int>& dist,vector<int> adj[])
{
    
      for(int nbr:adj[source])
      {
          //cout<<nbr;
                if(nbr!=parent)
                {
                    dist[nbr]=dist[source]+1;
                    callDFS(nbr,source,dist,adj);
                }
      }
}




int main()
{
    int len;
    cin>>len;

    vector<int>arr(len);
    int a;
    for(int i=0;i<len;i++)
    {
        cin>>a;
        arr[i]=a;
    }

    vector<int>adj[len];
    //adj=new vector<int>[len];
    vector<int>dist(len,0);
    int parent=-1;
    int root=0;

    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==-1)
         {
             root=i;
         }
         else{
        adj[i].push_back(arr[i]);
        adj[arr[i]].push_back(i);
         }
        
    }
            for(int i=0;i<len;i++)
            {
                cout<<i<<"  -> ";
                for(int x:adj[i])
                {
                    cout<<x<<"  ";
                }
                cout<<endl;
            }

           
        callDFS(root,parent,dist,adj);

        int max_dist=0;
        int max_i=-2;

        //  for(int i=0;i<dist.size();i++)
        //     {
        //          cout<<dist[i]<<"  ";
                
        //     }
        for(int i=0;i<dist.size();i++)
        {
            if(dist[i]>max_dist)
            {
                max_dist=dist[i];
                max_i=i;
            }         
            
        }

 // to handle when there is only one node that is root
         if(max_dist==0)
          { cout<<"max dist=0";
             return 0;
          }


          for(int i=0;i<dist.size();i++)
            {
                dist[i]=0;
                
            }
         callDFS(max_i,parent,dist,adj);

         for(int i=0;i<dist.size();i++)
        {
            if(dist[i]>max_dist)
            {
                max_dist=dist[i];
                max_i=i;
            }         
            
        }

        cout<<max_dist;
        cout<<max_i;

        return 0;

}