class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int N, int k) 
    { 
        // Complete the function
        
        int i=0;int j=1;
       int  max_len=0,sum=0;
        unordered_map<int,int>mp;
        
        for(int i=0;i<N;i++)
        {
            sum=sum+arr[i];
            
            if(sum==k)
             max_len=max(max_len,i+1);
             
             
           if(mp.find(sum)==mp.end())
           {
               mp.insert({sum,i});
           }
           
           
           if(mp.find(sum-k)!=mp.end())
           {
               max_len=max(max_len,i-mp[sum-k]);
           }
        }
        
        
        
        return max_len;
    } 

};