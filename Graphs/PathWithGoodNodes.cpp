#include<bits/stdc++.h>
using namespace std;

int result;
int num;
void dfs(int v, int count, vector<int> &A, vector<bool> vis, vector<vector<int>> &arr){
    vis[v]=1;
    
    for(int child: arr[v]){
        if(vis[child]==0){
            if(A[child-1]) dfs(child, count+1, A, vis, arr);
            else dfs(child, count, A, vis, arr);
        }
    }
    if(arr[v].size()==1 && count<=num) result++;
}

int solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int n=A.size();
    result=0;
    num=C;
    vector<bool> vis(n+1, false);
    vector<vector<int>> arr(n+1);
    
    for(int i=0; i<n-1; i++){
        arr[B[i][0]].push_back(B[i][1]);
        arr[B[i][1]].push_back(B[i][0]);
    }

    if(A[0]==1) dfs(1, 1, A, vis, arr);
    else dfs(1, 0, A, vis, arr);
    cout<<result;
    return result;
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
