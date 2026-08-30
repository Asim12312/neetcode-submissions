//Time complexity: O(N)
//Space complexity: O(N)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> s;
        vector<pair<int, int>> temps;
        vector<int> result(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); i++){
            temps.push_back({i, temperatures[i]});
        }

        for(int i = 0; i < temps.size(); i++){
            
            while(!s.empty() && temps[i].second > s.top().second){
                result[s.top().first] = temps[i].first - s.top().first;
                s.pop();
            }

            s.push(temps[i]);
        }

        return result;
    }
};