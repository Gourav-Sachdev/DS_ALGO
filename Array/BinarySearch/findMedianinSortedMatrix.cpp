#include<bits/stdc++.h>
using namespace std;


int main()
{
//    vector<vector<int>>matrix{
//         {1, 3, 5 },
//         {2, 6, 9 },
//         { 3, 6, 9},
        
//     };

    vector<vector<int>>arr{
        {1, 1, 3, 3, 3, 3, 3}
        
        
    };
     int row=arr.size();
     int col=arr[0].size();
     int min_val=INT_MAX;int max_val=INT_MIN;

     for(int i=0;i<row;i++)
     {
         min_val=min(min_val,arr[i][0]);
         max_val=max(max_val,arr[i][col-1]);
     }

     int low=min_val;  int high=max_val;  

     while(low<=high)
     {
         
         int mid=(low+high)/2;
         int count=0;
         for(int i=0;i<row;i++)
         {  // find upper bound of mid
             count=count+upper_bound(arr[i].begin(),arr[i].begin()+col,mid)-arr[i].begin();
         }

         if(count<=(row*col)/2)
             low=mid+1;
             else{  
                 high=mid-1;
             }
     }



    cout << "Median is "
         << low;
    return 0;
}
