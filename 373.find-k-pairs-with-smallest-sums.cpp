/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start


// for this problem  i took help from discussion

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

   // time complexity is m*n*logK;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums2.empty() || nums1.empty()) return {};
        priority_queue<pair<int, vector<int>>> maxheap;
        vector<vector<int>> result;
        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                if(maxheap.size() < k)
                    maxheap.push({nums1[i]+nums2[j], vector<int>({nums1[i],nums2[j]})});
                else if(maxheap.size() == k && maxheap.top().first > nums1[i]+nums2[j]) {
                    maxheap.pop();
                    maxheap.push({nums1[i]+nums2[j], vector<int>({nums1[i],nums2[j]})});
                }
           }
        }
        while(!maxheap.empty()) {
            result.insert(result.begin(),maxheap.top().second);
            maxheap.pop();
        }
         //sort(result.begin(), result.end(), check);
         return result;
    }
    };
    
// @lc code=end

