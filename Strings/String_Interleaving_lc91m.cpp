class Solution {
public:
    
   unordered_map<string,int> ump;
    
    bool callFunc(string s1, string s2, string s3,int i, int j, int k)
    {
        if(i+j==k and k==s3.size())
            return true;
        
        if(s1[i]!=s3[k] and s2[j]!=s3[k])
            return false;
        
        
         string token=to_string(i)+"#"+to_string(j);
        if(ump.find(token)!=ump.end())
            return ump[token];
        
        
         if(s2[j]==s3[k] and s1[i]==s3[k])
              return ump[token]=callFunc(s1,s2,s3,i,j+1,k+1) or callFunc(s1,s2,s3,i+1,j,k+1);
           
            
        
        if(s1[i]==s3[k])
            
            return ump[token]=callFunc(s1,s2,s3,i+1,j,k+1);
        
       // if(s2[j]==s3[k])
          //  return callFunc(s1,s2,s3,i,j+1,k+1);
        
        
        return ump[token]=callFunc(s1,s2,s3,i,j+1,k+1);
            
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s1.length()+s2.length()!=s3.length())
            return false;
        
       // vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        
      //  unordered_map<string,bool>ump;
        
        return callFunc(s1,s2,s3,0,0,0);
    }
};



// "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa"
// "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab"
// "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab"
// "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa"
// "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab"
// "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab"