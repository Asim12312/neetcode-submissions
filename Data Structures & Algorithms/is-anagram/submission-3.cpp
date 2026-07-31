class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> resultS;
        unordered_map<char, int> resultT;

        if(s.size() != t.size()){
            return false;
        }

        for (char c : s){
            resultS[c]++;
        }

        for (char c : t){
            resultT[c]++;
        }

        for (auto var : resultT){
           auto it = resultS.find(var.first);

           if(it == resultS.end()){
            return false;
           }

           if(it->second != var.second){
            return false;
           }
           
        }
        return true; 
    }
};
