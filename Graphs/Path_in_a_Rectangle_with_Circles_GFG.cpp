int eight_x[8]={-1,-1,0,1,1,1,0,-1};
int eight_y[8]={0,1,1,1,0,-1,-1,-1};

bool isValidCordinate(int x,int y,int row, int col)
{
    if(x<0 or x>row or y<0 or y>col)
       return false;
    return true;   
}

bool isCircle(int x,int y,int noc,int r,vector<int> &x_cor, vector<int> &y_cor)
{
    //iterate ver every circle
    for(int i=0;i<noc;i++)
    {
        if((x-x_cor[i])*(x-x_cor[i])+(y-y_cor[i])*(y-y_cor[i])<=r*r)
          return true;
          
        
    }
     return false; 
}


string Solution::solve(int row, int col, int noc, int r, vector<int> &x_cor, vector<int> &y_cor) {
    
   bool vis[row+1][col+1];
   memset(vis,false,sizeof(vis));
   
   queue<pair<int,int>>q;
   if(isCircle(0,0,noc,r,x_cor,y_cor))
    {
        return "NO";
    } 
    
    q.push({0,0});
    vis[0][0];
    
    
    int x=0,y=0;
    while(!q.empty())
    {
        pair<int,int>source=q.front();
         q.pop();
           for(int i=0;i<8;i++)
           {
               x=source.first+eight_x[i];
               y=source.second+eight_y[i];
               
               if(isValidCordinate(x,y,row,col) and !vis[x][y] and !isCircle(x,y,noc,r,x_cor,y_cor))
                    {q.push({x,y});
                       vis[x][y]=true;
                    }
               
           }
           
         
    }
    
    if(vis[row][col]==true)
    return "YES";
    
    return "NO";
      
   
   
    
}
