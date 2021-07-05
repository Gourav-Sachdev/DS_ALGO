#include<bits/stdc++.h>
using namespace std;

int solve( vector<int> &needed_capacity,  vector<int> &dish_capacity,  vector<int> &cost_ofdish) {
    
    // step1 find ki table me kitne coloumns hoge // max needed capacity
    

     // step1 find ki table me kitne coloumns hoge // max needed capacity
     int col=*max_element(needed_capacity.begin(),needed_capacity.end());
     int row=dish_capacity.size();

    int dp[row+1][col+1];
    
     for(int i=0;i<=row;i++)
        dp[i][0]=0;
        
        for(int i=1;i<=col;i++)
        dp[0][i]=100000001;
        
    
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
           
              
              if(j<dish_capacity[i-1])    //when person can eat 5 kg but i have only 3 kgs dish_capacity
                   dp[i][j]=dp[i-1][j];
                   
            else if(j>=dish_capacity[i-1])
            {
                int op1=dp[i-1][j];
                int op2=cost_ofdish[i-1]+dp[i][j-dish_capacity[i-1]];
                dp[i][j]=min(op1,op2);
            }       
               
               
        }
    }

    for(int i=0;i<=row;i++)
    {
        for(int j=0;j<=col;j++)
        {
            cout<<dp[i][j]<<" ";
               
               
        }
        cout<<endl;
    }

    int total_cost=0;
    for(int i=0;i<needed_capacity.size();i++)
    {
        total_cost+=dp[row][needed_capacity[i]];
    }
    
    return total_cost;
    
   
    
}


int main()
{
    vector<int>needed_capacity{2, 3, 1, 5, 4 }; 
    vector<int>dish_capacity{3, 2, 4, 1};
    vector<int>cost_ofdish{ 1, 2, 5, 10};


    cout<<solve(needed_capacity,dish_capacity,cost_ofdish);
    return 0;
}