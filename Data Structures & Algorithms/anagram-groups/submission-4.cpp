class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        int n=strs.size();
        for(int i=0;i<n;i++){
            vector<int> freq(26);
            for(char c:strs[i]){
                freq[c-'a']++;
            }
            string key = to_string(freq[0]);
            for (int j=1;j<26;j++){
                key+=','+to_string(freq[j]);
            }
            m[key].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto& s:m){
            ans.push_back(s.second);
        }
        return ans;
    }
};
