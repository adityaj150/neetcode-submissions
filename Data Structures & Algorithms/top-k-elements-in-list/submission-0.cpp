class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count the frequency of each element
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        // Step 2: Create a vector of pairs to store the element and its frequency
        vector<pair<int, int>> freqVec;
        for (auto& entry : freqMap) {
            freqVec.push_back(entry); // {element, frequency}
        }

        // Step 3: Sort the vector based on frequency in descending order
        sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second; // Sort by frequency
        });

        // Step 4: Extract the top K frequent elements
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(freqVec[i].first); // Get the element (not the frequency)
        }

        return result;
    }
};