/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    struct check{

            bool operator()(pair<int,string>a, pair<int,string>b){

                    if(a.first == b.first) return a.second > b.second;

                     return a.first < b.first;
         
            }

    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        
        priority_queue<pair<int,string>, vector<pair<int,string>>,check>pq;

        unordered_map<string,int> map;

        int n= words.size();

        for(int i=0;i<n;i++){
            map[words[i]]++;
        }

        for(auto & i: map){

                int freq  = i.second;
                string val   = i.first;

         //       cout<<val<<" "<<freq<<endl;

                pq.push({freq,val});



        }

        vector<string> ans;

        while(k>0 && pq.size()>0){

            ans.push_back(pq.top().second);
            k--;
            pq.pop();
        }

        return ans;
    }
};
// @lc code=end

