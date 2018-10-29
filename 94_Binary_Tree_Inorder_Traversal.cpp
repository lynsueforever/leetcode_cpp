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
    vector<int> inorderTraversal(TreeNode* root) {
	std::vector<int> res;

        if (root != NULL) {
		res.push_back(root->val);
		std::vector<int> left_res = inorderTraversal(root->left);
		std::vector<int> right_res = inorderTraversal(root->right);
		res.insert(res.end(), left_res.begin(), left_res.end());
		res.insert(res.end(), right_res.begin(), right_res.end());
	}
	return res;
    }
};
