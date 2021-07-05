#include<bits/stdc++.h>
using namespace std;



int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
         
        int arr[n];
       
       int a;
          for(int i=0;i<n;i++)
          {   cin>>a;
             // cout<<i;
              arr[i]=a;
          }
       
        
        vector<vector<int>>matrix(n,vector<int>(n,0));

        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=gap; j<n; i++,j++)
            {
                   if(gap==0)
                    matrix[i][j]=1;
                  else if(gap==1)
                  matrix[i][j]= (arr[i]==arr[j]) ? 2 : 1;  

                  else{
                      if(arr[i]==arr[j])
                         matrix[i][j]=matrix[i+1][j-1]+2;
                       else{
                            matrix[i][j]=max(matrix[i+1][j],matrix[i][j-1]);
                       }

                  }
            }
        }

        //cout<<matrix[0][n-1];
        if(matrix[0][n-1]>=3)
           cout<<"YES"<<endl;
         else{
             cout<<"NO"<<endl;
         }  
    }

    return 0;
}

