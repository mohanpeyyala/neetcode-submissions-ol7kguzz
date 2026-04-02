class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> m;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i:nums) m[i]++;
        for(auto& i:m){
            pq.push({i.second,i.first});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            pair x=pq.top();
            pq.pop();
            ans.push_back(x.second);
        }
        return ans;
    }
};
