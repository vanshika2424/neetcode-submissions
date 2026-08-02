class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        int l=0;
        vector<int>ans;
        
        for(int r=0;r<n;r++){
            
            while(!dq.empty() && dq.front()<l){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]<nums[r]){
                dq.pop_back();
            }
            dq.push_back(r);
            if(r-l+1==k){
                ans.push_back(nums[dq.front()]);
                l++;
            }
            


        }
        return ans;
        
    }
};
