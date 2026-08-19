class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};

        int left = 0;
        int maxFreq = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++) {

            // Add current character
            count[s[right] - 'A']++;

            // Highest frequency in current window
            maxFreq = max(maxFreq, count[s[right] - 'A']);

            // Characters that need to be replaced
            int replacements = (right - left + 1) - maxFreq;

            // Window is invalid
            while(replacements > k) {
                count[s[left] - 'A']--;
                left++;
                replacements = (right - left + 1) - maxFreq;
            }

            // Current window is valid
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};