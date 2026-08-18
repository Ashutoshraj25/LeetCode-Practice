class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int maxlen = 0;
        int maxfreq = 0;
        unordered_map<char, int> freq;

        for (int r = 0; r < s.size(); r++) {
            freq[s[r]]++;
            maxfreq = max(maxfreq, freq[s[r]]);

            while ((r - l + 1) - maxfreq > k) {
                freq[s[l]]--;
                if (freq[s[l]] == 0)
                    freq.erase(s[l]);
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};