class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        int n=nums.size();
        int maxseq=0;
        for(int i=0;i<n;i++){
            if(s.find(nums[i]-1)==s.end()){
                int x=0;
                int count=0;
                
                while(s.find(nums[i]+x)!=s.end()){
                    count++;
                    x++;

                }
                maxseq=max(maxseq,count);
            }
        }
        return maxseq;
        
    }
};
