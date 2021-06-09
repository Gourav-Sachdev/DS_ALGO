

//Max Area of island lc651M



class Solution {
public:
    
    int dfs(int i,int j,vector<vector<int>>& grid)
    {
        if(i<0 or i>=grid.size() or  j<0 or j>=grid[0].size() or grid[i][j]==0)
        {
            return 0;
            
        }
             grid[i][j]=0;
             int op1=dfs(i+1,j,grid);
             int op2=dfs(i-1,j,grid);
             int op3=dfs(i,j+1,grid);
             int op4=dfs(i,j-1,grid);
            
            return 1+op1+op2+op3+op4;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int max_area=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    max_area=max(max_area,dfs(i,j,grid));
                }
            }
        }
        
        return max_area;
    }
    
    
    
//     int dfs(int i,int j,vector<vector<int>>& grid)
//     {
//         if(i>=0 and i<grid.size()and  j>=0 and j<grid[0].size() and grid[i][j]==1)
//         {
//             grid[i][j]=0;
//             int op1=dfs(i+1,j,grid);
//              int op2=dfs(i-1,j,grid);
//              int op3=dfs(i,j+1,grid);
//              int op4=dfs(i,j-1,grid);
            
//             return 1+op1+op2+op3+op4;
//         }
//         return 0;
//     }
};