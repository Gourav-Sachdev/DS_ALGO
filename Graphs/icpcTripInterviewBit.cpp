
//https://www.interviewbit.com/problems/useful-extra-edges/


#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

 void callDijkstra(int source,vector<pii> adj[],vector<int>& dist)
 {
            
           // cout<<"abc";
            priority_queue<pii,vector<pii>,greater<pii>>pq;

            pq.push({0,source});
            dist[source]=0;

            while(!pq.empty())
            {
                auto pr=pq.top();
                int source_node=pr.second;
                int source_dist=pr.first;
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

 }





int main()
{
    int A;
    cin>>A;

    int R,C;      // no of rows and col  3 col
    cin>>R>>C;

    vector<vector<int>>B;
    int a,b,c;
    
     for(int i=0;i<R;i++)
     {
          cin>>a>>b>>c; 

         B.push_back({a,b,c});
          B.push_back({b,a,c});
     }

    //   for(int i=0;i<R;i++)
    //  {
    //       cout<<B[i][0]<<"  "<<B[i][1]<<"  "<<B[i][2]<<endl;
    //  }
       int source,dest;
       cin>>source>>dest;


       int er,ec;      // no of rows and col  3 col
       cin>>er>>ec;

//(R,vector<int>(C))
//(er,vector<int>(ec))
    vector<vector<int>>extra;
    
     for(int i=0;i<er;i++)
     {
          cin>>a>>b>>c;   
         extra.push_back({a,b,c});
         extra.push_back({b,a,c});
     }

  

     for(int i=0;i<extra.size();i++)
     {
          cout<<extra[i][0]<<"  "<<extra[i][1]<<"  "<<extra[i][2]<<endl;
     }

         vector<pii>adj[A+1];
        
           vector<int>dist_from_source(A+1,INT_MAX);
      vector<int>dist_from_destination(A+1,INT_MAX);


      
      for(int i=0;i<B.size();i++)
      {
          adj[B[i][0]].push_back({B[i][1],B[i][2]});
      }

      

    //   for(int i=1;i<=B.size();i++)
    //  {
    //       //cout<<extra[i][0]<<"  "<<extra[i][1]<<"  "<<extra[i][2]<<endl;
    //        cout<<i<<" --> ";
    //       for(auto nbr:adj[i])
    //       {
    //           cout<<nbr.first<<"  ";
    //           cout<<nbr.second<<"||";
    //       }
    //       cout<<endl;
         
    //  }



     
          callDijkstra(source,adj,dist_from_source);
          callDijkstra(dest,adj,dist_from_destination);

          for(int i=1;i<dist_from_source.size();i++)
          {
              cout<<dist_from_source[i]<<" ";
          }
             cout<<endl;
          for(int i=1;i<dist_from_destination.size();i++)
          {
              cout<<dist_from_destination[i]<<" ";
          }

                 int ans=dist_from_source[dest];
for(int i=0;i<extra.size();i++)
{
    
    int dist=dist_from_source[extra[i][0]]+dist_from_destination[extra[i][1]]+extra[i][2];
    int dist1=dist_from_source[extra[i][1]]+dist_from_destination[extra[i][0]]+extra[i][2];
    ans=min(ans,min(dist,dist1));
} 
          
cout<<endl;

if(dist_from_source[dest]==INT_MAX)
  cout<<"-1";
          cout<<"smallest dist from "<<source<<" to Destination is"<<ans;


    return 0;
}



/* cout<<"bdfbdfbd";


      
      vector<pii>adj[A+1];
      
    //   vector<int>dist_from_source(A+1,INT_MAX);
    //   vector<int>dist_from_destination(A+1,INT_MAX);

     
      for(int i=0;B.size();i++)
      {
          adj[B[i][0]].push_back({B[i][1],B[i][2]});
      }

         
     for(int i=0;i<R;i++)
     {
          //cout<<extra[i][0]<<"  "<<extra[i][1]<<"  "<<extra[i][2]<<endl;
           cout<<i<<" --> ";
          for(auto nbr:adj[i])
          {
              cout<<nbr.first<<"  ";
              cout<<nbr.second<<"||";
          }
         
     }

 */






// for(int i=0;i<extra.size();i++)
//           {
//               int source_to=extra[i][0];
//               int to_destination=extra[i][1];
//               int wt=extra[i][2];
//                 cout<<endl;
//                cout<<dist_from_source[source_to]<<"+ "<<wt<<"+"<<dist_from_destination[to_destination]<<"<"<<dist_from_source[dest]<<endl;
//             if(dist_from_source[source_to]+dist_from_destination[to_destination]+wt<dist_from_source[dest])
//             {
                
//                 dist_from_source[dest]=dist_from_source[source_to]+dist_from_destination[to_destination]+wt;
//             }

//           }