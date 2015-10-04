/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <map>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::map;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
    	map<TreeNode*, int> treeDepth;
        if(root == NULL){
        	return true;
        } else{
        	return depth(root, treeDepth);
        }
    }

    bool depth(TreeNode *node, map<TreeNode*, int> &treeDepth){
    	bool result = true;
    	int leftdepth = 0;
    	int rightdepth = 0;
    	if(node -> left != NULL){
    		if(treeDepth.find(node -> left) == treeDepth.end()){
    			result = result && depth(node -> left, treeDepth);
    		}
    		leftdepth = treeDepth.find(node -> left) -> second;
    	}

    	if(node -> right != NULL){
    		if(treeDepth.find(node -> right) == treeDepth.end()){
    			result = result && depth(node -> right, treeDepth);
    		}
    		rightdepth = treeDepth.find(node -> right) -> second;
    	}

    	treeDepth[node] = (leftdepth > rightdepth ? leftdepth : rightdepth) + 1;

    	if(abs(leftdepth - rightdepth) > 1){
    		return false;
    	} else{
    		return result;
    	}
    }
};

int main(int argc, char const *argv[])
{
	Solution test;
	TreeNode *first = new TreeNode(1);
	TreeNode *second = new TreeNode(2);
	TreeNode *third = new TreeNode(3);
	first -> right = second;
	first -> left = third;

	bool result = test.isBalanced(first);
	if(result){
		cout << "true" << endl;
	} else{
		cout << "false" << endl;
	}

	return 0;
}