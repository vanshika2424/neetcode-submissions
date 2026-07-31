class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        // vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            int target=-nums[i];
            int l=i+1;
            int r=n-1;
            while(l<r){
                int sum=nums[l]+nums[r];
                if(sum==target){
                    s.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                else if(sum<target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
        
        
    }

};
