class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>>pq;
        int l=0;
        vector<int>ans;
        for(int i=0;i<k-1;i++){
            pq.push({nums[i],i});

        }
        for(int r=k-1;r<n;r++){
            pq.push({nums[r],r});
            
            int ind=pq.top().second;
            while(!pq.empty() && ind<l){
                pq.pop();
                ind=pq.top().second;

            }
            int maxi=pq.top().first;
            ans.push_back(maxi);
            l++;


        }
        return ans;
        
    }
};
