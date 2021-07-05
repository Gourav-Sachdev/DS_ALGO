#include<bits/stdc++.h>
using namespace std;
int callLastOccurenceofMid(vector<int>arr,int target)
 {
    
     int start=0;int end=arr.size()-1;
        int ans=-1;

     while(start<=end)
     {
         int mid=(start+end)/2;

         
          if(arr[mid]<=target)
         {
            ans=mid;
            start=mid+1;
            
         }
         else{
             end=mid-1;
         }
     }
      

     return ans;
 }


 int main()
{
   vector<vector<int>>arr{
        { 10, 20, 30, 40 },
        { 15, 25, 35, 45 },
        { 25, 29, 37, 48 },
        { 32, 33, 39, 50 },
    };
//     cout << "7th smallest element is "
//          << kthSmallest(matrix, 7);


cout<<callLastOccurenceofMid(arr[3],33);
    return 0;
}