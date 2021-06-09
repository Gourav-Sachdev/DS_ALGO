
#include<bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int nums[], long long int n, long long int k) 
{
    
        
        // create a maxSUm array  ith index of it will hold the max sum till ith index
        
        long long int maxSumTillNow[n];
        maxSumTillNow[0]=nums[0];  
        long long int curr_sum=nums[0],max_sum=0;
        
        for(long long int i=1;i<n;i++)
        {                          
            curr_sum=max(curr_sum+nums[i],nums[i]);  // khudki train banau ya piche wale ki train me baithu in dono ka max
          
            maxSumTillNow[i]=curr_sum;
        }
        
        
       
        
        
        // start slinding window concept from here
        long long int window_sum=0;
        
        for(long long int i=0;i<k;i++)
        {
            window_sum=window_sum+nums[i];
        }
        
        long long int max_windowSum=window_sum;
        

        for(long long int i=k;i<n;i++)
        {
            window_sum=window_sum+nums[i]-nums[i-k];
            // new created window choose karna hai ya old window rehne du
            max_windowSum=max(max_windowSum,window_sum); // if this not written it will fail on {-1 2 -3 4} k=3
            
            //window length ki window theek hai ya usme previous maxSUm bhi add kare toh achha hoga
            max_windowSum=max(max_windowSum,window_sum+maxSumTillNow[i-k]);
        }
        
        return max_windowSum;
        
}