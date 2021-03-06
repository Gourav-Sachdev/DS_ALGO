#include<bits/stdc++.h>
using namespace std;

   double findMedian(vector<int>&nums1,vector<int>&nums2)
   {
       if (nums1.size() > nums2.size()) {
            return findMedian(nums2, nums1);
        }
        int x = nums1.size();
        int y = nums2.size();

        int low = 0;
        int high = x;
        while (low <= high) {
            int partitionX = (low + high)/2;
            int partitionY = (x + y + 1)/2 - partitionX;

            //if partitionX is 0 it means nothing is there on left side. Use -INF for maxLeftX
            //if partitionX is length of input then there is nothing on right side. Use +INF for minRightX
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MIN : nums1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MAX: nums2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                //We have partitioned array at correct place
                // Now get max of left elements and min of right elements to get the median in case of even length combined array size
                // or get max of left for odd length combined array size.
                if ((x + y) % 2 == 0) {
                    return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2;
                } else {
                    return (double)max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) { //we are too far on right side for partitionX. Go on left side.
                high = partitionX - 1;
            } else { //we are too far on left side for partitionX. Go on right side.
                low = partitionX + 1;
            }
        }
        
        return 0.0;

   }



int main()
{

	vector<int>nums1{ 7 ,-50 ,-41, -40, -19 ,5 ,21, 28};
    vector<int>nums2{3 ,-50, -21, -10};
	
    double ans=findMedian(nums1,nums2);
    cout<<ans;

	return 0;
}

