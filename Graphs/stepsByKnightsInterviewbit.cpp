    #include<bits/stdc++.h>
     using namespace std;


    
    
    
    
	
    int main()
	{
                  int x_direc[]={2,2,1,-1,-2,-2,-1,1};
                  int y_direc[]={1,-1,2,2,1,-1,-2,-2};

               vector<int>nightPos;
              vector<int>targetPos;

              int a;
              for(int i=0;i<2;i++)
              {
                  cin>>a;
                  nightPos.push_back(a);

              }
                     //  cout<<nightPos[0]<<"  "<<nightPos[1];
              for(int i=0;i<2;i++)
              {
                  cin>>a;
                  targetPos.push_back(a);

              }
             
              int n;
              cin>>n;
             

              

          
             
	    // Code here
	    int steps=0;
	    vector<vector<int>>vis(n,vector<int>(n,0));
	    queue<pair<int,int>>q;
	    q.push({nightPos[0],nightPos[1]});
	    
	    while(!q.empty())
	    {
	        int size=q.size();
	        while(size--)
	        {
	            auto pr=q.front();
	            int source_x=pr.first;
	             int source_y=pr.second;
                   cout<<"{"<<source_x<<","<<source_y<<"}"<<endl;
                 
	             q.pop();
	             
	             if(source_x==targetPos[0] and source_y==targetPos[1])
	               {
                       cout<<steps;
                         return 0;
                   } 
	                
	           for(int i=0;i<8;i++)
	           {
	               int new_x=source_x+x_direc[i];
	               int new_y=source_y+y_direc[i];
	               
	               if((new_x>=1 and new_x<n and new_y>=1 and new_y<n) and vis[new_x][new_y]==false)
	               {
	                   vis[new_x][new_y]=true;
	                   q.push({new_x,new_y});
	               }
	           }
	             
	        }
	        steps++;
	    }

        cout<<"-1";
         return 0;
	}
	
	
    /*  int x_direc[]={2,2,1,-1,-2,-2,-1,1};
                  int y_direc[]={1,-1,2,2,1,-1,-2,-2};
        
              vector<int>KnightPos;
              vector<int>TargetPos;
             

              int a;
             for(int i=0;i<2;i++)
             {
                 cin>>a;
                 KnightPos.push_back(a);

             }
                 cout<<KnightPos[0]<<"  "<<KnightPos[1];
                 int b;
              for(int i=0;i<2;i++)
             {
                 cin>>b;
                 TargetPos.push_back(b);

             }
              cout<<TargetPos[0]<<"  "<<TargetPos[1];
                
                 int n;
                cin>>n;

          cout<<n;
        cout<<"dbvdf";
 */