
class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        // vector<pair<int,int>>res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(auto &it:m){
            pq.push({it.second,it.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        // sort(res.begin(),res.end(),compare());
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;



        
    }
};
