int Solution::longestSubsequenceLength(const vector<int> &arr) {
    int n =arr.size();
    
    
    if(arr.size()==0)
    return 0;
    
    vector<int>inc(n,1);
     vector<int>dec(n,1);
     int len=1;
                   // making ic and dec part taken from bitonic question
				   // filling array done in LIS manner
     
     for(int i=1;i<n;i++)                    // Do what we do in Longest increasing subsequence
     {
         for(int j=i-1;j>=0;j--)
         {
             if(arr[i]<=arr[j])
              continue;
            
            inc[i]=max(inc[i],inc[j]+1); 
             
         }
     }
     
     for(int i=n-2;i>=0;i--)
     {
         for(int j=i+1;j<n;j++)
         {
             if(arr[i]<=arr[j])
              continue;
            
            dec[i]=max(dec[i],dec[j]+1); 
             
         }
     }
     
    //  for(int i=0;i<n;i++)
    //  {
    //      cout<<inc[i];
    //  }
    //  cout<<endl;
    //  for(int i=0;i<n;i++)
    //  {
    //      cout<<dec[i];
    //  }
    //   cout<<endl;
     
     for(int i=0;i<n;i++)
     {
         len=max(len,inc[i]+dec[i]-1);
     }
     
     return len;
    
}
