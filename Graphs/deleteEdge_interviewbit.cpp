

#include<bits/stdc++.h>;
using namespace std;

#define mod (1e9+7)
vector<int>*adj;
long long int ans;
long long res=0;



   int  callDFS(int source,int parent,vector<int> A,long long int total_sum)
   {
           int x=0;
           x=x+A[source-1];
         // long long int y=0;
          
          for(int nbr:adj[source])
          {
              if(nbr==parent)
              {
                  continue;
                  
              }
              x=x+callDFS(nbr,source,A,total_sum);
          }
         
           ans=max(ans,((x%int(mod))*(total_sum-x)%int(mod)));
         
          return x;
   }
int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    
    
 adj=new vector<int>[A.size()+1];
    int parent=-1;
     
     ans=0;
     long long int total_sum=0;
    
     
     for(int i=0;i<B.size();i++)
     {
         adj[B[i][0]].push_back(B[i][1]);
         adj[B[i][1]].push_back(B[i][0]);
     }
     
     for(int a:A)
       total_sum+=a;
      
       
      callDFS(1,parent,A,total_sum);
      
     return int(ans)%int(mod);
}
