class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        int n=nums.size();
        int maxseq=0;
        for(int i=0;i<n;i++){
            if(s.find(nums[i]-1)==s.end()){
                int curr=nums[i];
                int count=1;
                
                while(s.find(curr+1)!=s.end()){
                    curr++;
                    count++;

                }
                maxseq=max(maxseq,count);
            }
        }
        return maxseq;
        
    }
};
