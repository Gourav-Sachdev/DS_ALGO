// C++ program to implement
// the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to search if element X
// is present in reverse sorted array
int findMax(int arr[], int N, int X)
{
	// Store the first index of the
	// subarray in which X lies
	int s = 0;

	// Store the last index of the
	// subarray in which X lies
	int e = N-1;

	while (s <= e) {

		
        if(s==e)
        {
            cout<<s;
           return s;
        } 
     
   
    if ((s == e + 1) && arr[s] >= arr[e])
         {
             return s;
        } 

      if ((s == e + 1) && arr[s] < arr[e])
         {
             return e;
        } 

		int mid = s+ (e - s) / 2;
				//cout<<mid<<"  ";
 
		int a=arr[mid-1];
        int b=arr[mid];
        int c=arr[mid+1];

        if(a<b and  b<c)
          s=mid+1;

          else if(a>b and  b>c)
            e=mid-1;

            else{
                return mid;
            }
        

		
		
	}

	// If X not found
	return -1;
}


int searchIncreasingSubarray(int arr[], int s,int e ,int X)
{

    
        
				//cout<<mid<<"  ";
                
 
	  while(s<=e)
      {

          int mid = s+ (e - s) / 2;
        if(arr[mid]==X)
          return mid;
        
        else if(arr[mid]>X)
          e=mid-1;

         else if(arr[mid]<X)
          s=mid+1;

            

		
		
	}

	// If X not found
	return -1;

}


int searchDecreasingSubarray(int arr[],int s,int e, int X)
{
    
      
				//cout<<mid<<"  ";
 
	  while(s<=e)
      {
             int mid = s+ (e - s) / 2;
        if(arr[mid]==X)
          return mid;
        
       else if(arr[mid]<X)
          e=mid-1;

         else {
                  s=mid+1;
         }
          

            

		
		
	}

	// If X not found
	return -1;
}

// Driver Code
int main()
{
	int arr[] = { 0,1,2,3,4,5, 4, -5, -6, -8 };
	int N = sizeof(arr) / sizeof(arr[0]);
	int X = -20;
	int max_index=findMax(arr, N, X);
  

       int inc=searchIncreasingSubarray(arr,0,max_index,X);
      // cout<<inc;
       if(inc!=-1)
       cout<< inc;
       else{
           int y= searchDecreasingSubarray(arr,max_index+1,N-1, X) ;
           cout<<y;
           exit(0);
       }

	return 0;
}







             