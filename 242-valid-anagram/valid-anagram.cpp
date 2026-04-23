class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char,int> mp1;

        for(int i =0;i<s.length();i++){
            mp1[s[i]]++;
        }
        for(int i =0;i<t.size();i++){
            char ch = t[i];
            if(mp1.find(ch)!=mp1.end()){
                mp1[ch]--;
                if(mp1[ch] == 0) mp1.erase(ch);
            }
            else return false;
        }
        if(mp1.size()>0) return false;
        else return true;
    }
};