#include<bits/stdc++.h>
using namespace std;



 
    void calldfs(int i,int j,vector<string>& arr,vector<vector<int>>& dp ,int dx,int dy)
    {
            if(i<0 or i>=arr.size() or j<0 or j>=arr[0].size())
            {
                return ;
            }
            dp[i][j]++;

            if(arr[i][j]=='0') // agar 0 mile toh hi aage jao warna return same direction me jaao jab tak boundry na mile
                 calldfs(i+dx,j+dy,arr,dp,dx,dy); 

    }

     vector<vector<int>> solution(vector<string>& arr)
    {
       // vector<vector<int>>res{{4,5,6}};
        int x_dir[8]={-1, 0, 1, 0, -1, -1, 1, 1};
        int y_dir[8]={0, 1, 0, -1, -1, 1, -1, 1};
        vector<vector<int>>dp(arr.size(),vector<int>(arr[0].size(),0));
       
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr[i].length();j++)
            {
                if(arr[i][j]=='1')  // jaha 1 dikha 8 direction me call kardo
                {
                    for(int q=0;q<8;q++)
                    {
                        int new_i=i+x_dir[q];
                        int new_j=j+y_dir[q];

                       // last 2 parameter shows kis direction me jaana hai
                         calldfs(new_i,new_j,arr,dp,x_dir[q],y_dir[q]);  


                    }
                   
                   
                }
            }
        }

             return dp;
    }




int main()
{
    int n;
    cin>>n;

    vector<string>arr(n);

     string a;
    for(int i=0;i<n;i++)
    {
       cin>>a;
       arr[i]=a;
    }


    

      vector<vector<int>>ans=solution(arr);

      for(int i=0;i<ans.size();i++)
      {
          for(int j=0;j<ans[0].size();j++)
          {
              cout<<ans[i][j]<<"  ";
          }
          cout<<endl;
      }

      return 0;
}