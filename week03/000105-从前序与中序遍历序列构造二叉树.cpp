//题目地址： https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

//题目地址：https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    private:
	unordered_map<int, int> index;

    private:
	TreeNode *myBuildTree(vector<int> &preorder, int preorder_left_index, int preorder_right_index,
			      vector<int> &inorder, int inorder_left_index, int inorder_right_index)
	{
		if (preorder_left_index > preorder_right_index) {
			return nullptr;
		}

		int preorder_root_index = preorder_left_index;
		int inorder_root_index = index[preorder[preorder_root_index]];

		TreeNode *root = new TreeNode(preorder[preorder_root_index]);

		int size_left_subtree = inorder_root_index - inorder_left_index;

		root->left = myBuildTree(preorder, preorder_left_index + 1, preorder_left_index + size_left_subtree,
					 inorder, inorder_left_index, inorder_root_index);

		root->right = myBuildTree(preorder, preorder_left_index + size_left_subtree + 1, preorder_right_index,
					  inorder, inorder_root_index + 1, inorder_right_index);
		return root;
	}

    public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
	{
		int len = inorder.size();
		for (int i = 0; i < len; i++) {
			index[inorder[i]] = i;
		}
		return myBuildTree(preorder, 0, len - 1, inorder, 0, len - 1);
	}
};