

int x_eight[8]={-1,-1,0,1,1,1,0,-1};
      int y_eight[8]={0,1,1,1,0,-1,-1,-1};
      
  int dfs(int x,int y,vector<vector<int>>&grid)
  {
      if(x<0 or x>=grid.size() or y<0 or y>=grid[0].size() or grid[x][y]==0)
         return 0;
         
         grid[x][y]=0;
         int count=1;
         
     for(int i=0;i<8;i++)
     {
         int x_cor=x+x_eight[i];
         int y_cor=y+y_eight[i];
         
         count=count+dfs(x_cor,y_cor,grid);
     }
     return count;
      
  }



int Solution::solve(vector<vector<int> > &grid) {
    
    
    int max_len=0;
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[0].size();j++)
        {
            if(grid[i][j]==1)
            max_len=max(max_len,dfs(i,j,grid));
        }
    }
    
    return max_len;
}
