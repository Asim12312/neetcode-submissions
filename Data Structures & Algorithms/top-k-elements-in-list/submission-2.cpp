class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> gr;
        for(int num : nums){
            if(gr.find(num) == gr.end()){
                gr[num] = 1;
            }
            else{
                gr[num]++;
            }
        }
        vector<int> result;

        for(int i=0; i<k; i++){
            auto max = gr.begin();
            for(auto itr = gr.begin(); itr!=gr.end(); ++itr){
                if(itr->second > max->second){
                    max = itr;
                }
            }
            result.push_back(max->first);
            gr.erase(max);
        }
        return result;
    }
};
