class Solution {
public:
    
    
    bool callKSumPartiton(int index,int currsum,int targetsum,int bucket,vector<int>& nums,vector<bool>& visited)
  {       
        
        if(bucket==1)
             return true;                // only one suset to form
        
        if(currsum==targetsum)             // yhe subset full ho gaya now fill next subset
            return callKSumPartiton(0,0,targetsum,bucket-1,nums,visited); 
        
        // check for all the numbers that can we fill subset by this number
        for(int start=index;start<nums.size();start++)
        {
              //cout<<nums[start]<<"  ";
               if(visited[start]==false and currsum+nums[start]<=targetsum)
               {
                   visited[start]=true;
                   
                   // now check using this number can we fill the subset if not try next unvisited number 
                   if(callKSumPartiton(start+1,currsum+nums[start],targetsum,bucket,nums,visited)==true)
                         return true;
                   
                   visited[start]=false;                        // backtrack
                   
               }
        }
        
        return false;
        
  }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
       
    
    

      int targetsum=0;
      for(int i=0;i<nums.size();i++)
      {
          targetsum+=nums[i];
      }
     
      if(k>nums.size() or targetsum%k!=0)
         {return false;}
        else{
            targetsum=targetsum/k;
        }
       

     int currsum=0;
        vector<bool>visited(nums.size(),false);
  return callKSumPartiton(0,currsum,targetsum,k,nums,visited);     // index,currsumnums,targetsum,bucket,nums
         
        
        
    
    }
};