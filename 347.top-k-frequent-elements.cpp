/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        priority_queue<pair<int,int>>pq;

        unordered_map<int,int> map;

        int n= nums.size();

        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }

        for(auto & i: map){

                int freq  = i.second;
                int val   = i.first;

         //       cout<<val<<" "<<freq<<endl;

                pq.push({freq,val});



        }

        vector<int> ans;

        while(k>0 && pq.size()>0){

            ans.push_back(pq.top().second);
            k--;
            pq.pop();
        }

        return ans;
        
    }
};
// @lc code=end

