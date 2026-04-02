class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> m;
        priority_queue<pair<int, int>> pq;
        for(int i:nums) m[i]++;
        for(auto& i:m){
            pq.push({i.second,i.first});
        }
        while(!pq.empty()){
            pair x=pq.top();
            pq.pop();
            ans.push_back(x.second);
            if(ans.size()==k) return ans;
        }
        return ans;
    }
};
