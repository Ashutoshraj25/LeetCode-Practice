class Solution {
    static final long LIMIT = 1000000L;

    long countWays(int[] cnt) {
        int total = 0;
        for (int x : cnt) total += x;

        long ans = 1;

        for (int i = 0; i < 26; i++) {
            int c = cnt[i];
            if (c == 0) continue;

            ans *= comb(total, c);
            if (ans > LIMIT) ans = LIMIT + 1;
            total -= c;
        }

        return ans;
    }

    long comb(int n, int r) {
        if (r > n - r) r = n - r;

        long res = 1;

        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
            if (res > LIMIT) return LIMIT + 1;
        }

        return res;
    }

    public String smallestPalindrome(String s, int k) {
        int[] freq = new int[26];
        for (char c : s.toCharArray()) freq[c - 'a']++;

        int[] half = new int[26];
        String mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if ((freq[i] & 1) == 1)
                mid = String.valueOf((char) ('a' + i));
        }

        if (countWays(half) < k) return "";

        StringBuilder first = new StringBuilder();
        int len = s.length() / 2;

        for (int pos = 0; pos < len; pos++) {
            for (int ch = 0; ch < 26; ch++) {
                if (half[ch] == 0) continue;

                half[ch]--;

                long ways = countWays(half);

                if (ways >= k) {
                    first.append((char) ('a' + ch));
                    break;
                } else {
                    k -= ways;
                    half[ch]++;
                }
            }
        }

        StringBuilder ans = new StringBuilder();
        ans.append(first);
        ans.append(mid);
        ans.append(first.reverse());

        return ans.toString();
    }
}