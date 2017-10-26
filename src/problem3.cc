/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int start = 0;
        int end = 0;

        int currentLen = 0;

        int index[26];
        for (int i = 0; i < 26; i++) {
        	index[i] = 0;
        }

    	while (start < s.size()) {
    		int idx = s[start] - 'a';
    		if (index[idx] > 0) {
    			for (int i = 0; i < 26; i++) {
    				index[i] = 0;
    			}
    			if (currentLen > maxLen) maxLen = currentLen;
    			currentLen = 1;
    			index[idx] = 1;
    		}
    		else {
    			index[idx]++;
    			currentLen++;
    			start++;
    		}
    	}
        

        if (currentLen > maxLen) maxLen = currentLen;

        return maxLen;
    }
};

int main()
{
	std::string s("abcabcbb");
	Solution solution;
	int maxLen = solution.lengthOfLongestSubstring(s);
	std::cout<<maxLen<<std::endl;
}