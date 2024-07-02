double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }
    
    int x = nums1.size();
    int y = nums2.size();
    int low = 0;
    int high = x;
    
    while(low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;
        
        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];
        
        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];
        
        if(maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if((x + y) % 2 == 0) {
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
            } else {
                return max(maxLeftX, maxLeftY);
            }
        } else if(maxLeftX > minRightY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }
    
    throw "Input arrays are not sorted";
}

/*class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int i=0, j=0;
        double result=0.0;
        vector<int> merged_vector;

        while(i!=nums1.size() && j!=nums2.size()){

            if(nums1[i]<nums2[j]){
                merged_vector.push_back(nums1[i]);
                if(i<nums1.size()){
                    i++;
                }
            }else{
                merged_vector.push_back(nums2[j]);
                if(j<nums2.size()){
                    j++;
                }
            }
        }

        if(i==nums1.size()){
            merged_vector.insert(merged_vector.end(),nums2.begin()+j,nums2.end());
        }else{
            merged_vector.insert(merged_vector.end(),nums1.begin()+i,nums1.end());
        }

        double mvs = merged_vector.size();

        if(mvs/2!=floor(mvs/2)){
            result = merged_vector[floor(mvs/2)];
        }else{
            result = (merged_vector[int(mvs/2)-1]+merged_vector[int(mvs/2)])/2.0;
        }

        return result;
    }
};%/


