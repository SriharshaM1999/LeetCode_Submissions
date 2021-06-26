/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq;

        for(auto &i:stones){
            pq.push(i);
        }

        while(pq.size()>1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();

            if(first==second){
                continue;
            }
            else{
                pq.push(first-second);
            }

        }

        if(pq.size()==0) return 0;

        return pq.top();
        
    }
};
// @lc code=end

