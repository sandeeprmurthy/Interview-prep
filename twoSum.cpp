class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Create a unordered map
        std::unordered_map<int, int> map;

        // Create a loop to go through the vector nums and fidn the TwoSum
        for(int i=0; i<nums.size(); i++){

            // Compute the complementary number
            int complement = target - nums[i];

            // Check if the complement has already been added to the map
            if(map.find(complement) != map.end()){
                return {map[complement], i};
            }

            // Else add the nums[i] value to the unordered_map
            map[nums[i]] = i;
        }

        return {};
        
    }
};
