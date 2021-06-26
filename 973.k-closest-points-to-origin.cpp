/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {



public:

    struct Compare{

         bool operator()(pair<int,int>a, pair<int,int>b){

          
                int val1= sqrt((a.first*a.first)+(a.second*a.second));
                int val2= sqrt((b.first*b.first)+(b.second*b.second));

                return val1>val2;

        }
        
    };



    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
            int n= points.size();
            vector<vector<int>>ans(k);

   priority_queue<pair<int, int>,vector<pair<int, int>>,Compare>pq;

            for(int i=0; i<n; i++){


                    pair<int,int> p = {points[i][0],points[i][1]};

                    pq.push(p);


            }

            int index =0;
            while(k>0 && pq.size()>0){

              //  cout<<"I got called"<<endl;

                pair<int,int> top = pq.top();

                //cout<<top.first.first<<" "<< top.first.second<<endl;

                ans[index].push_back(top.first);
                ans[index].push_back(top.second);

                index++;

                pq.pop();
                
                k--;


            }

            // if(k>0) return -1;

            return ans;



    }
};
// @lc code=end

