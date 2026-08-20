class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        int count1[26] = {0};
        int count2[26] = {0};

        // Frequency of characters in s1
        for (char c : s1) {
            count1[c - 'a']++;
        }

        int windowSize = s1.size();

        // First window
        for (int i = 0; i < windowSize; i++) {
            count2[s2[i] - 'a']++;
        }

        // Check first window
        if (equal(begin(count1), end(count1), begin(count2)))
            return true;

        // Slide the window
        for (int right = windowSize; right < s2.size(); right++) {
            count2[s2[right] - 'a']++;              // add right character
            count2[s2[right - windowSize] - 'a']--; // remove left character

            if (equal(begin(count1), end(count1), begin(count2)))
                return true;
        }

        return false;
    }
};