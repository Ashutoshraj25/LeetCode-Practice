class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        vector<int> freq(10, 0);
        int ans = 0;

        // Count frequency
        for(auto x : digits) {
            freq[x]++;
        }

        // Hundreds digit: 1 to 9
        for(int a = 1; a <= 9; a++) {

            // Tens digit: 0 to 9
            for(int b = 0; b <= 9; b++) {

                // Units digit: even
                for(int c = 0; c <= 8; c += 2) {

                    // Take a, b, c
                    freq[a]--;
                    freq[b]--;
                    freq[c]--;

                    // If none became negative,
                    // we have enough digits
                    if(freq[a] >= 0 &&
                       freq[b] >= 0 &&
                       freq[c] >= 0) {

                        ans++;
                    }

                    // Restore
                    freq[a]++;
                    freq[b]++;
                    freq[c]++;
                }
            }
        }

        return ans;
    }
};