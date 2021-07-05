#include<bits/stdc++.h>
using namespace std;

// This contain the col index of last element in matrix less than of equal
        // to num means if element is not found it will return index of element
        // which just smaller from that element ans present in array
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
 
int callBinarySearch(vector<vector<int>>arr,int mid,int k)
{
    int n=arr.size();
    int ans=0;
     for(int i=0;i<arr.size();i++)
     {
         if(arr[i][0]>mid)
            return ans;  

            else if(arr[i][arr[0].size()-1]<=mid)  
           { ans=ans+arr.size(); 
            continue ; }  

        else{
            ans=ans+1+callLastOccurenceofMid(arr[i],mid);

            
        }

     }
            
    return ans;
}

int kthSmallest(vector<vector<int>>arr,int k)
{
    int n=arr.size();
    int m=arr[0].size();
    int low=arr[0][0];
    int high=arr[n-1][m-1];

    while(low<=high)

    {
        int mid=low+(high-low)/2;

        int x=callBinarySearch(arr,mid,k);
    
        if(x>=k)
        {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return low;
}
int main()
{
//    vector<vector<int>>matrix{
//         {1, 3, 5 },
//         {2, 6, 9 },
//         { 3, 6, 9},
        
//     };

    vector<vector<int>>matrix{
        {1, 1, 3, 3, 3, 3, 3}
        
        
    };
    cout << "7th smallest element is "
         << kthSmallest(matrix,4);
    return 0;
}


/* int greaterThan = 0;
        for (int jump = n / 2; jump >= 1; jump /= 2) {
            while (greaterThan + jump < n &&
                   arr[i][greaterThan + jump] <= mid) {
                greaterThan += jump;
            }
        }
 
        ans += greaterThan + 1;
    } */