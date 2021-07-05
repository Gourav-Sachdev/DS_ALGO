#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        
        //1234 is the 0th index so we basically need to find out k-1 th index pe jo permutation hai
        // step1 --store numbers 1234 in case of n=4 in array and store n-1! factorial in variable 
        
        vector<int>numbers;
        int fact=1;
        for(int i=1;i<n;i++)
        {
            fact=fact*(i);               //1*2*3  in case of n=4
            numbers.push_back(i);
        }
         numbers.push_back(n);
        
        
        k=k-1;                         // basically need to find out k-1 th index pe jo permutation hai
        string ans="";
        
        while(true)
        {
            ans=ans+to_string(numbers[k/fact]);
            numbers.erase(numbers.begin()+(k/fact));
            
            if(numbers.size()==0)
                break;
            
            k=k%fact;                                      
            fact=fact/numbers.size();                    // pehle 3! se divide kara tha ab 2 se karna hai
        }
        return ans;
        
    }
};