class Solution {
public:
    
    
    bool isValid(int i,int j, vector<vector<int>> rooms)
    {
        return i>=0 and i<rooms.size() and j>=0  and j<rooms[0].size();
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        
        //queue<pair<int,pair<int,int>>>q;
        queue<pair<int,int>>q;
         vector<vector<int>>vis(rooms.size(),vector<int>(rooms[0].size(),0));
        
        for(int i=0;i<rooms.size();i++)
        {
            for(int j=0;j<rooms[0].size();j++)
            {
                if(rooms[i][j]==0 )
                     q.push({i,j});
                // vis[i][j]=true;
            }
        }
        
       
        int i_cor[]={1,-1,0,0};
        int j_cor[]={0,0,1,-1};
          // APPLY BFS
        
        while(!q.empty())
        {
           // int distance=q.front().first;
             int source_i=q.front().first;
             int source_j=q.front().second;
             q.pop();
            
           
            
            for(int i=0;i<4;i++)
            {
                int x=source_i +  i_cor[i];
                 int y=source_j + j_cor[i];
                
                if((x>=0 and x<rooms.size() and y>=0  and y<rooms[0].size()) and rooms[x][y]==INT_MAX )
                {
                    rooms[x][y]=rooms[source_i][source_j]+1;
                    q.push({x,y});
                   // vis[x][y]=true;
                }
            }
            
            
            
        }
        
    }
};




/*  
    bool callDFS(int i,int j,vector<string> &board,string word,int index)
    {
       if(index==word.size())
        return true;
       
         if(i<0 or i>=board.size() or j<0 or j>=board[0].size() or word[index]!=board[i][j]  )
         {
             return false;
         }
        
       
        
         
        
        // if(board[i][j]==word[index] )//and vis[i][j]==false)
        // {
           //cout<<board[i][j]<<"  ";
           
               //vis[i][j]=true;
            
              bool op1=callDFS(i+1,j,board,word,index+1);
              bool op2=callDFS(i-1,j,board,word,index+1);
              bool op3=callDFS(i,j+1,board,word,index+1);
              bool op4=callDFS(i,j-1,board,word,index+1);
            
           
           
           return op1 or op2 or op3 or op4;
             
        //      if(op1 or op2 or op3 or op4)
        //      {
                  
        //           return true;
        //      }
        //     // else{
        //     //      vis[i][j]=false;     // backtrack kardo  nahi mila toh
        //     // }
                
        // }
                          
        // return false;
        
        
       
        
    }




int Solution::exist(vector<string> &board, string word) {
    
    bool result=false;
        //vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0] )//and vis[i][j]==false)
                {
                    result=callDFS(i,j,board,word,0);
                    // cout<<endl;
                    //  cout<<endl;
                    // for(int i=0;i<board.size();i++)
                    // {
                    //     for(int j=0;j<board[i].size();j++)
                    //     {
                    //         cout<<board[i][j]<<"  ";
                    //     }
                    //     cout<<endl;
                    // }
                            
                    
                }
                if(result==true)
                    return true;
            }
        }
        
        return result;

}
 */