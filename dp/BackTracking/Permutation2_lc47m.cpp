
#include<bits/stdc++.h>
using namespace std;

/* Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]] */

class Solution {
public:
    
    vector<vector<int>> ans;
    void callRecursive(int index,vector<int>& v,vector<int>& count,vector<int>& result)
    {
        if(index==result.size())
        {
            ans.push_back(result);
            return ;
            
        } 
        
        for(int i=0;i<v.size();i++)
        {
            if(count[i] == 0) {
                continue;
            }
            result[index] = v[i];
            count[i]--;
            callRecursive(index + 1,v, count, result);
            count[i]++;
             
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        map<int,int>mp;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        vector<int>v;
        vector<int>count;
        vector<int>result(nums.size());
        
        for(auto it=mp.begin();it!=mp.end();it++)
        {
           v.push_back(it->first);
            count.push_back(it->second);
           
        }
        
        
//         for(auto it=mp.begin();it!=mp.end();it++)
//         {
//           cout<<it->first<<" "; 
           
//         }
//         cout<<endl;
//         for(auto it=mp.begin();it!=mp.end();it++)
//         {
//           cout<<it->second<<" "; 
           
//         }
        
      callRecursive(0,v,count,result);
          
          return ans;
        
    
    }
};