class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> s;
        vector<pair<int, int>> temps;

        for(int i = 0; i < temperatures.size(); i++){
            temps.push_back({i, temperatures[i]});
        }
        vector<int> result(temps.size(), 0);
        s.push(temps[0]);
        for(int i=0; i < temps.size(); i++){
                while(!s.empty() && temps[i].second > s.top().second){
                    result[s.top().first] = temps[i].first - s.top().first;
                    s.pop();
                }

            s.push(temps[i]);
        }

        return result;
    }
};
