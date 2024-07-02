class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
/*        // Idea is start with the first position and find the longest substring
        // then move on to the next position and repeat
        // print string with largest string length

        // Maximum length
        int max_length = 0;

        // Start to find the largest substring from every position in the substring
        for(int i=0; i<s.size(); i++){

            // Setup a hash map
            unordered_map<string, string> map;

            string ss = s.substr(i,1);
            map[s.substr(i,1)] = ss;    
            map_ss[ss] = ss.size();



            for(int j=i+1; j<s.size(); j++){

                if(map.find(s.substr(j,1))==map.end()){
                    ss.push_back(s[j]);
                    map[s.substr(j,1)] = ss;
                }else{
                    break;
                }
            }

            if(ss.size()>max_length){
                max_length = ss.size();
            }            

        }

        return max_length;

    }*/

    unordered_map<char, int> charMap;
    int start = 0;
    int maxLength = 0;
    
    for(int end = 0; end < s.length(); end++) {
        char endChar = s[end];
        
        if(charMap.count(endChar) == 1) {
            start = max(start, charMap[endChar] + 1);
        }
        
        charMap[endChar] = end;
        maxLength = max(maxLength, end - start + 1);
    }
    
    return maxLength;

};
