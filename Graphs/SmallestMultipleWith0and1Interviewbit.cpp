#include<bits/stdc++.h>
using namespace std;



int main()
{
    int n;
    cin>>n;


     queue<int>q;
    vector<int>vis(n,0);
    vector<string>dp(n);

    q.push({1});
    vis[1]=true;
    dp[1]="1";


    while(!q.empty())
    {
        
            auto front=q.front();
            int num=front;
           
           
            q.pop();

            if(num==0)
            {
                cout<<dp[front];
                break;
            }



            int insert_num=((num*10)+1)%n;
            //  if(insert_num==5)
            //    cout<<endl<<dp[num]<<endl;
               
            string insert_string=dp[num]+"1";
            if(vis[insert_num]==false)
            {
                 vis[insert_num]=true;
                q.push(insert_num);
                dp[insert_num]=insert_string;

            }

            insert_num=(num*10)%n;
            insert_string=dp[num]+"0";
           

            if(vis[insert_num]==false)
            {
                 vis[insert_num]=true;
                q.push(insert_num);
                dp[insert_num]=insert_string;
            }

            // inserting right subtree
             


       // }
    }

    
    cout<<endl;
    for(int i=0;i<dp.size();i++)
    {
        cout<<i<<"-->"<<dp[i];
        cout<<endl;
    }
    return 0;
}




/* int main()
{
    int n;
    cin>>n;


     queue<pair<int,string>>q;
    vector<int>vis(n,0);

    q.push({1,"1"});
    vis[1]=true;


    while(!q.empty())
    {
        int count=q.size();
        // while(n--)
        // {
            auto front=q.front();
            int num=front.first;
            string temp=front.second;
            q.pop();

            if(num==0)
            {
                cout<<temp;
                return 0;
            }

           int insert_num=(num*10)%n;
           string insert_string=temp+"0";
            if(vis[insert_num]==false)
            {
                q.push({insert_num,insert_string});
            }

            // inserting right subtree
             insert_num=((num*10)+1)%n;
            insert_string=temp+"1";
            if(vis[insert_num]==false)
            {
                q.push({insert_num,insert_string});
            }


       // }
    }

    
    return 0;
} */