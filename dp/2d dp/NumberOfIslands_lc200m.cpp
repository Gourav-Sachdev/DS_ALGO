class Solution {
public:
    
    int dfs(int i,int j,vector<vector<char>>& grid)
    {
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]=='0')
             return 0;
        
         grid[i][j]='0';
        dfs(i+1,j,grid);
       dfs(i-1,j,grid);
       dfs(i,j+1,grid);
       dfs(i,j-1,grid);
        
        return 1;
    }
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {

                
                    count=count+dfs(i,j,grid);
                     
            }
        }
    }
            
            return count;
    }
};