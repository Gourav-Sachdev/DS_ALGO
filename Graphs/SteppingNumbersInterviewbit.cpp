#include<bits/stdc++.h>
using namespace std;

vector<int>ans;

void  bfs(int last,int first)
      {
          vector<int> vis(last+1,0);
         
          queue<int>q;
          //cout<<"0"<<"  ";
          if(first==0)
          {
              ans.push_back(0);
          }
            vis[0]=true;
           for(int i=1;i<=9 and i<=last ;i++)
            {
               q.push(i);
            }
           
           
            while(!q.empty())
            {
                int front=q.front();
                q.pop();

                if(front<=last and vis[front]==false)
                {
                     vis[front]=true;

                     if(front>=first and front<=last)
                       {
                        
                        ans.push_back(front);
                       }
                   
                   int last_digit=front%10;

                   if(last_digit==9)
                   {
                       q.push((front*10)+(last_digit-1));
                   }

                   else if(last_digit==0 )
                   {
                       q.push((front*10)+(last_digit+1));
                   } 

                  
                   else{
                          q.push((front*10)+(last_digit-1));
                        q.push((front*10)+(last_digit+1));
                        
                   } 

                }

                      
            }

            
      }

     

int main()
{
    int first,last;
    cin>>first>>last;

    

    
       

   bfs(last,first); 
   

   for(int i=0;i<ans.size();i++)
   {
       cout<<ans[i]<<"  ";
   }


 //cout<<"the  count is"<<cnt;
   return 0;
}












/*  int  bfs(int last,int first)
      {
          vector<int> vis(last+1,0);
          int cnt=0;
            queue<int>q;
            cout<<"0"<<"  ";
            vis[0]=true;
           for(int i=1;i<=9 and i<=last ;i++)
            {
               q.push(i);
            }
           
           
            while(!q.empty())
            {
                int front=q.front();
                q.pop();

                if(front<=last and vis[front]==false)
                {
                     vis[front]=true;

                     if(front>=first and front<=last)
                   {cout<<front<<"  ";
                  
                    cnt++;
                   }
                   
                   int last_digit=front%10;

                   if(last_digit==9)
                   {
                       q.push((front*10)+(last_digit-1));
                   }

                   else if(last_digit==0 )
                   {
                       q.push((front*10)+(last_digit+1));
                   } 

                  
                   else{
                          q.push((front*10)+(last_digit-1));
                        q.push((front*10)+(last_digit+1));
                        
                   } 
                }

                      
            }

            return cnt;

      } */