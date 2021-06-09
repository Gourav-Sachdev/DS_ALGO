#include<bits/stdc++.h>
using namespace std;

vector<int>*adj;

int ans=0;
void dfs(int source,vector<int>& vis,vector<int> &A,int good,int count_good)
{
    //int count=0;
   
    // if(good<0)
    //   return;
      
    
      
       vis[source]=true;
    for(auto nbr:adj[source]) 
    {
        if(vis[nbr]==false)
        {
            if(A[nbr-1])
            dfs(nbr,vis,A,good,count_good+1);
            else
                dfs(nbr,vis,A,good,count_good);
          
            
        }
    }
    
      if(adj[source].size()==1 and good>=count_good)
      {  ans++;
      
        // cout<<ans<<endl;
      }
      
    
}
  int solve(vector<int> &A, vector<vector<int> > &B, int good) {
    
    //cnt=new int;
    int count_good=0;
    int v=A.size()+1;
    adj=new vector<int>[v];
    vector<int>vis(v,false);
    
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
        
        adj[B[i][1]].push_back(B[i][0]);
    }
    
    // cout<<A.size()<<endl;
    // cout<<B.size()<<endl;
    // cout<<good;
    if(A[0]==1) dfs(1,vis,A,good,1);
    
    else dfs(1, vis,A, good,0);
     cout<<ans;
     return ans;
    
    
}

int main()
{
    int v;
    cin>>v;

    vector<int>A(v);
    for(int i=0;i<v;i++)
    {
        cin>>A[i];
    }

    int e;
    cin>>e;
    int g;
    cin>>g;
   vector<vector<int> >B;

   int c;
   int d;
   for(int i=0;i<e;i++)
   {
       cin>>c>>d;
       B.push_back({c,d});
   }

     int good;
     cin>>good;
        
        int res=solve(A,B,good);
         
     return 0;
}



