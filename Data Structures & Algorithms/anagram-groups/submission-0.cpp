class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        int freq[26]={0};
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']--;
            freq[t[i]-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(freq[s[i]-'a']!=0) return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<bool> vis(strs.size());
        for(int i=0;i<strs.size();i++){
            vector<string> s;
            s.push_back(strs[i]);
            if(vis[i]!=false){
                continue;
            }
            for(int j=i+1;j<strs.size();j++){
    
                if(isAnagram(strs[i],strs[j])){
                    s.push_back(strs[j]);
                    vis[j]=true;
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};
