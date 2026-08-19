class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxStr = 0;
        int left = 0;
        set<char> st;

        for(int right = 0; right < s.size(); right++){
            //remove all the duplicates
            while(st.count(s[right])){
                st.erase(s[left]);
                left++;
            }
            //insert new char
            st.insert(s[right]);
            //calculate max
            maxStr = max(maxStr, right - left + 1);

        }

        return maxStr;
    }
};
