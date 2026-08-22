class Solution {
public:
    string minWindow(string s, string t) {

        if (s.size() < t.size())
            return "";

        unordered_map<char, int> mp;

        // Store required frequency
        for (char c : t) {
            mp[c]++;
        }

        int left = 0;
        int count = 0;

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            // If s[right] is required
            if (mp.count(s[right])) {

                // We still need this character
                if (mp[s[right]] > 0) {
                    count++;
                }

                mp[s[right]]--;
            }

            // Window is valid
            while (count == t.size()) {

                // Check if this is the smallest window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove left character
                if (mp.count(s[left])) {

                    mp[s[left]]++;

                    // We removed a needed character
                    if (mp[s[left]] > 0) {
                        count--;
                    }
                }

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};