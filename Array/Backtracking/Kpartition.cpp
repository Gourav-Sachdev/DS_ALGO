
#include<bits/stdc++.h>
using namespace std;

 void callKPartition(int index,int n,int k,int nos,vector<vector<int>>&ans)
{
    if(index>n)
    {
        
        if(nos==k)
        {
              for(vector<int>arr:ans)
              {
                   for(int x:arr)
                   {
                        cout<<x;
                   }
                   cout<<"|";
              }
                cout<<endl;
        }
      
        return ;
       
    }
    
    for(int j=0;j<ans.size();j++)
    {
       
      
        if(ans[j].size()>0)    //already present subset me apna element dalo
        {
           
            ans[j].push_back(index);
            // cout<<"not empty"<<index<<endl;
            callKPartition(index+1,n,k,nos,ans);
            ans[j].pop_back();
            
        }
        else{
            ans[j].push_back(index);
           // cout<<" empty"<<index<<endl;
            callKPartition(index+1,n,k,nos+1,ans);
            ans[j].pop_back();
            break;
        }
    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    
      vector<vector<int>>ans;

    vector<int>v;
    for(int i=0;i<k;i++)
    {
        ans.push_back(v);
    }
  //  cout<<ans.size();
    callKPartition(1,n,k,0,ans);
    
    

    
    
    return 0;
}





/* // cout<<"Inside printing";
             for(int i=0;i<ans.size();i++)
                {
                    cout<<"[";
                    for(int j=0;j<ans[i].size();i++)
                    {
                       cout<<ans[i][j]<<", ";   
                    }
                    cout<<"]";
                }
                
                cout<<endl; */