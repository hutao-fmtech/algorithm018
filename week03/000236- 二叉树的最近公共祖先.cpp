//题目地址：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
//题目地址：https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
	TreeNode *lowestCommondAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		if (!root || root == p || root == q)
			return root;

		TreeNode *left = lowestCommondAncestor(root->left, p, q);
		TreeNode *right = lowestCommondAncestor(root->right, p, q);
		if (left && right)
			return root;
		return left ? left : right;
	}
}