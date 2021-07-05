class Solution {
public:
    
    vector<int>x_direc{1,-1,0,0};
     vector<int>y_direc{0,0,1,-1};
//          int x_direc[]={1,-1,0,0};
//          int y_direc[]={0,0,1,-1};
    
     void dfs(int i,int j,int prev,vector<vector<int>>& ocean_type,vector<vector<int>>& heights)
     {
         
         if(i<0 or i>=heights.size() or j<0 or j>=heights[0].size())
              return ;
         if(heights[i][j]<prev or ocean_type[i][j])
              return ;
         
         ocean_type[i][j]=true;
         for(int k=0;k<4;k++)
         {
             int new_x=i+x_direc[k];
              int new_y=j+y_direc[k];
             
             dfs(new_x,new_y,heights[i][j],ocean_type,heights);
         }
         
         
     }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n=heights.size();
        int m=heights[0].size();
        
         vector<vector<int>> intersection_result;
        vector<vector<int>>pacific(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));
        
       for(int j=0;j<m;j++)
       {
           // apply dfs on all coloums of 1st row(for pacific ocean) and last row(atlantic ocean)
           
           dfs(0,j,INT_MIN,pacific,heights);
            dfs(n-1,j,INT_MIN,atlantic,heights);
       }
        
        
        for(int i=0;i<n;i++)
       {
           // apply dfs on all rows of 1st coloum(for pacific ocean) and last coloumn(atlantic ocean)
           
           dfs(i,0,INT_MIN,pacific,heights);
            dfs(i,m-1,INT_MIN,atlantic,heights);
       }
           
    
         
         // to print the matrix
        
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                cout<<pacific[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        
//         cout<<endl;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                cout<<atlantic[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               
                if(atlantic[i][j]==true and pacific[i][j]==true)
                   intersection_result.push_back({i,j});
            }
           // cout<<endl;
        }
        
        
        return intersection_result;
    }
};