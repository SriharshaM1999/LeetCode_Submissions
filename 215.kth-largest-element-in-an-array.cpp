/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(auto& i:nums) pq.push(i);


        while(k>1 && pq.empty()==false){

           // cout<<pq.top()<<endl;

            pq.pop();

            k--;

        }

        if(pq.empty()) return -1;
        return pq.top();

    }
};
// @lc code=end

