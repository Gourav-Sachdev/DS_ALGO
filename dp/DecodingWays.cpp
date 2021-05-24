
#define mod 1000000007
int calldfs(string s,int i,vector<int>& dp)
    {
        if(i==s.size())
            return 1;
        
        if(i>s.size())
            return 0;
        
        if(s[i]=='0')
              return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int op1=0,op2=0;
        
        op1=calldfs(s,i+1,dp);
        
        if(i<s.size()-1 and (s[i]=='1' or (s[i]=='2' and s[i+1]<'7')))
            op2=calldfs(s,i+2,dp);
        
        return dp[i]=(op1+op2)%mod;
    
    }

int Solution::numDecodings(string s) {
    
     
        if(s[0]=='0')
            return 0;
        
        vector<int>dp(s.size(),-1);
        
        return calldfs(s,0,dp);
}
