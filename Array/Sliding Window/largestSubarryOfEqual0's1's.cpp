class Solution{
  public:
    int maxLen(int arr[], int N)
    {
        int max_len=0;int sum=0;
        unordered_map<int,int>mp;
        
        
        for(int i=0;i<N;i++)
        {
            if(arr[i]==1)
              sum++;
              else{
                  sum--;
              }
              
              if(sum==0)
              max_len=max(max_len,i+1);
              
              else if(mp.find(sum)!=mp.end())
              {
                   max_len=max(max_len,i-mp[sum]);
              }
              else{
                  mp.insert({sum,i});
              }
        }
        return max_len;
    }
};
