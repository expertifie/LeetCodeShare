class Solution {
public:
    
    int binarySearch(vector<int>& nums, int m, int lo, int hi)  {
        
        if(lo >= hi) return hi;
        int mid = (lo + hi)/2;
        

        int ans = partition(nums, m, mid);
        
        cout<<lo<< " "<<hi<<" "<<mid<<" "<<ans<<endl;
        if(ans == 0)  return binarySearch(nums, m, lo, mid);
        if(ans == -1) return binarySearch(nums, m, mid+1, hi);
        return binarySearch(nums, m, lo, mid-1);
        
    }
        
    int partition(vector<int>& nums, int m, int target)  {
        
        int sum = 0;
        int sol = 0;
        int cnt = 1;
        for(int i=0; i<nums.size(); i++)  {
            sum += nums[i];
            if(target < sum && cnt < m)  {
                
                // empty subarray not allowed;
                if(sum - nums[i] == 0)  {
                    return -1;
                }
                sol = max(sol, sum-nums[i]);
                sum = nums[i];
                cnt++;
            }
        }
        sol = max(sol, sum);
        
        if(target > sol) return 1;
        if(target < sol) return -1;
        
        return 0;
        
    }
    
    int splitArray(vector<int>& nums, int m) {
        
        int sum = 0;
        for(int i=0; i<nums.size(); i++)  {
            sum += nums[i];
        }
        return binarySearch(nums, m, 0, sum);
        
    }
};
