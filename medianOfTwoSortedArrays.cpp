
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int INF = 1000006;
    int findPartition(vector<int>& nums1, vector<int>& nums2, int lo, int hi, int median)  {
        
        if(lo > hi) return -1;
        
        int N = nums1.size();
        int M = nums2.size();
        
        int mid = (int)(lo+hi)/2;
        int l1 = -INF, l2 = -INF;
        int r1 = INF, r2 = INF;
        
        l1 = nums1[mid];
        if(mid+1<N) r1 = nums1[mid+1];
        if(median - mid - 2 >= M) return findPartition(nums1, nums2, mid + 1, hi, median);
        if(median - mid - 1 < 0) return findPartition(nums1, nums2, lo, mid - 1, median);
        
        if(median - mid - 2 >= 0 && median - mid - 2 < M) l2 = nums2[median - mid - 2];
        if(median - mid - 1 >= 0 && median - mid - 1 < M) r2 = nums2[median - mid - 1];
        
        if(l1<=r2 && l2 <= r1)  {
            return mid;
        } else if(l1>r2)  {
            return findPartition(nums1, nums2, lo, mid - 1, median);
        } else {
            return findPartition(nums1, nums2, mid + 1, hi, median);
        }
        
        
    }
    
    double getMedianWithPartition(vector<int>& nums1, int idx1, vector<int>& nums2, int idx2)  {
        
        int r1 = INF;
        int r2 = INF;
        int l1 = -INF;
        int l2 = -INF;
        if(idx1 >= 0) l1 = nums1[idx1];
        if(idx2 >= 0) l2 = nums2[idx2];
        if(idx1 + 1 < nums1.size()) r1 = nums1[idx1 + 1];
        if(idx2 + 1 < nums2.size()) r2 = nums2[idx2 + 1];
        
        int l = max(l1, l2);
        int r = min(r1, r2);
        
        if((nums1.size() + nums2.size()) % 2 == 0)  {
            return (double)(l+r)/2.0;
        }
        
        return l;
        
        
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int median_idx = (nums1.size() + nums2.size()) % 2 == 0 ? 
                                (int)(nums1.size() + nums2.size())/2 :
                                (int)(nums1.size() + nums2.size())/2 + 1;
        int res = findPartition(nums1, nums2, 0, nums1.size() -1, median_idx);
        return getMedianWithPartition(nums1, res, nums2, median_idx - res - 2);
    }
};
