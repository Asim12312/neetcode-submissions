class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int var : nums){
            if(s.count(var)){
                return true;
            }
            s.insert(var);
        }
        return false;    
    }
};