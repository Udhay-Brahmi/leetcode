/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
#include "Tree.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start

//   Definition for a binary tree node.
 
 
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) //if tree is empty
            return 0;
        int result=1; // increase it from one
        queue<pair<TreeNode *,int>> q;
        q.push({root,0}); // push current first value of root at index 0
        while(!q.empty()){
            int n=q.size();
            int start=q.front().second;
            int end=q.back().second;
            result=max(result, end-start+1);

            for(int i=0;i<n;i++){
                pair<TreeNode*,int> p;
                p=q.front();
                int index=p.second-start;
                q.pop();

                if(p.first->left)
                    q.push({p.first->left,2*index+1});
                if(p.first->right)
                    q.push({p.first->right, 2*index+2});
            }
        }
        return result;
    }
};
// @lc code=end


int main(){
    Solution sol;
    string input= "[1,3,2,5,3,null,9]";
    TreeNode* root = stringToTreeNode(input);
    int result=sol.widthOfBinaryTree(root);
    cout<<result;
    return 0;
}