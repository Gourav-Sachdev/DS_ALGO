#include<bits/stdc++.h>
using namespace std;

bool canDistributeIntoKPersons(int mid,int k,vector<int> jobs)
{
    int curr_sum=0;
    int count_employe=1;
    for(int i=0;i<jobs.size();i++)
    {
        if(curr_sum+jobs[i]>mid)
        {
                 count_employe++;

                 curr_sum=jobs[i];
                 if(count_employe>k)
                    return false;
        }
        else{
            curr_sum+=jobs[i];
        }
    }

    return true;
}


int callfunc(vector<int> jobs,int k,int t)
{
    int max_val=INT_MIN;
    int sum=0;
    for(int i=0;i<jobs.size();i++)
    {
          max_val=max(max_val,jobs[i]);
          sum=sum+jobs[i];
    }

    int start=max_val;           //assign max_val to start 
    int end=sum;                // end=sum coz search space is max_val to total sum
    int ans=0;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
      
            bool canplace=canDistributeIntoKPersons(mid,k,jobs);
      if(canplace==true)
      {
          end=mid-1;   // if you can finish in mid amount of time usse jyada me bhi ho jaega 
          ans=mid  ;              //now try for 1st half of search space
      }
      else{
          start=mid+1;
      }

    }

    return ans;
}
 

int main()
{
    vector<int>jobs{10, 7, 8, 12, 6, 8};
    int k=4;
    int t=5;

    cout<<callfunc(jobs,k,t)*t;
    return 0;
    
}