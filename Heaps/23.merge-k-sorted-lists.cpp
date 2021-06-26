/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start

//  Definition for singly-linked list.
#include<bits/stdc++.h>
using namespace std;

//   struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//   };
 

class Solution {
public:

 struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

    priority_queue<ListNode*, vector<ListNode*>,compare >pq;

        for(auto &i:lists){
            if(i!=nullptr)
            pq.push(i);
        }

        ListNode * ans = new ListNode(-1);
        ListNode *front= ans, *back= ans;

        if(pq.empty()) return nullptr;

        while(pq.empty()==false){

            ListNode *top = pq.top();
    //        cout<<top->val <<endl;
            pq.pop();

            back->next= top;
            back=top;

            if(top->next!=0){
                pq.push(top->next);
            }



        }

        return ans->next;
        
    }
};
// @lc code=end

