#include<bits/stdc++.h>
using namespace std;


bool canCutMidLength(vector<int>& arr,int mid,int B)
{     int sum=0;
    for(int i=0;i<arr.size();i++)
    {
       if(mid<arr[i])
        {
         sum=sum+arr[i]-mid;
         }
         if(sum>=B)
           return true;
    }
    return false;
    
}


int callBinarySearch(vector<int>&arr,int B)
{
    int max_val=0;
    for(int i=0;i<arr.size();i++)
    {
        max_val=max(max_val,arr[i]);
    }


    int low=max_val-B;
    if(low<0)
      low=0;
    int high=max_val;
    int ans=0;

    while(low<=high)
    {
        int mid=(low+high)>>1;
         bool checkHeight=canCutMidLength(arr,mid,B);
         if(checkHeight)
         {
             ans=mid;
             low=mid+1;
         }
         else{
             high=mid-1;
         }

    }
    return ans;
}



int main()
{
    vector<int>arr{5};
    int B=4;
    cout<<callBinarySearch(arr,B);

    return 0;
}