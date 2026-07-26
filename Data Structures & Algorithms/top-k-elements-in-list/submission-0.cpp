struct compare{

    bool operator()(pair<int,int>a,pair<int,int>b){
        return a.second>b.second;
    }
    
};


class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>>res;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(auto &it:m){
            res.push_back({it.first,it.second});
        }
        sort(res.begin(),res.end(),compare());
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(res[i].first);
        }
        return ans;



        
    }
};
