class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> numbers;
       for(int num : nums){
        numbers.insert(num);
       }

       int longest = 0;
       int current = 0;
       for(int num : numbers){
        if(!numbers.count(num - 1)){
            int length = 1;
            current = num;

            while(numbers.count(current + 1)){
                length++;
                current++;
            }
            longest = max(longest, length);
        }
       }
       return longest;
    }
};
