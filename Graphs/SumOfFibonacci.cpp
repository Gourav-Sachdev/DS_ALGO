
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int A=3;
    int count=0;
    while(A>0)
    {
        int temp1=1;
        int temp2=1;
        int temp3=0;
        
        while(temp1<=A)
        {
           // cout<<temp1<<"<="<<A<<endl;
           temp3=temp1;
            
            temp1=temp1+temp2;
            temp2=temp3;

            
        }//cout<<temp2;

        A=A-temp2;
       // cout<<A<<endl;
        count++;
    }
    cout<< count;

    return 0;
}