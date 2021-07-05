#include<bits/stdc++.h>
using namespace std;
 
 int findBitonicPoint(vector<int>& arr)
 {
     int n=arr.size();
     int s=0; int e=n-1;
        int ans=-1;
     while(s<=e)
     {
      
          int mid = s+ (e - s) / 2;
                //cout<<mid<<"  ";
 
        if(mid <n and arr[mid]>arr[mid+1])
             {
                ans=mid;
                return ans ;  
             }
         if(mid>=s and arr[mid] < arr[mid - 1])
             {
                ans=mid-1;
                return ans ;  
             }
             
             if (arr[s] >= arr[mid]) 
                 e=mid-1;
            else{
                s=mid+1;
            } 


       }
           return ans;     
               
     }

 int applyBinarySearch(vector<int> arr,int low,int high,int target)
 {
     int ans=-1;
     while(low<=high)
     {
         int mid=(low+high)/2;

         if(arr[mid]==target)
            {
                // cout<<"element found";
                 return 1;
            }

            else if(arr[mid]<target)
            {
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

vector<int>arr{4,5,6,7,7,7,7,8,0,1,2,3};
    int target=5;

    int bitonic_index=findBitonicPoint(arr);
    cout<<bitonic_index;

    
         if(target<=arr[bitonic_index] and target>=arr[0])
              cout<< applyBinarySearch(arr,0,bitonic_index,target);

            else
              cout<< applyBinarySearch(arr,bitonic_index+1,arr.size()-1,target);
                           

return 0;

}
