class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>s;
        int maxarea=0;
        for(int i=0;i<=n;i++){
            while(!s.empty() && (i==n || heights[s.top()]>=heights[i])){
                int h=heights[s.top()];
                s.pop();
                int l=s.empty()? -1:s.top();
                int w=i-l-1;
                int area= w*h;
                maxarea=max(area,maxarea);
            }
            s.push(i);
        }
        return maxarea;

        
    }
};
