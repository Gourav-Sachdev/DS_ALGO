#include<bits/stdc++.h>
using namespace std;




    int findLastPosition(vector<int>arr,int target)
 {
     int start=0;int end=arr.size()-1;
        int ans=-1;

     while(start<=end)
     {
         int mid=(start+end)/2;

         if(arr[mid]==target)
         {
            ans=mid;
            start=mid+1;
            
         }
         else if(arr[mid]<target)
         {
            
            start=mid+1;
            
         }
         else{
             end=mid-1;
         }
     }
      

     return ans;
 }


 int findFirstPosition(vector<int>arr,int target)
 {
     int start=0;int end=arr.size()-1;
     int ans=-1;

     while(start<=end)   //end<arr.size()-1 i added this bcz overflow was happening
     {
         int mid=(start+end)/2;

         if(arr[mid]==target)
         {
                 ans=mid;
                   end=mid-1;
         }
         else if(arr[mid]>target)
         {
            end=mid-1;
         }
         else{
             start=mid+1;
         }
     }
     

     return ans;
 }
int main()
{
    vector<int>arr{1,2,2,3,3,4,5,6};
    int target=5;
    if(arr.empty())
            cout<<" {-1,-1}";
        
         int x=findFirstPosition(arr,target);
        if(x==-1)
        {
           cout<<" {-1,-1}";
        }
        int y=findLastPosition(arr,target);
        
        cout<<x<<"  "<<y;
        return 0;
}