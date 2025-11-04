#include "../header/solution_interface.h"
using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        return hasPathSumRecursive(root, targetSum, 0);
    }

private:
    bool hasPathSumRecursive(TreeNode* root, int targetSum, int currentSum){
        if (!root) return false;

        currentSum += root->val;

        if (!root->left && !root->right) {  // leaf node
            if (targetSum == currentSum)  return true;
            else return false;
        }

        if (root->left && hasPathSumRecursive(root->left, targetSum, currentSum)) {
            return true;
        }
        else if (root->right) {
            if (hasPathSumRecursive(root->right, targetSum, currentSum)) return true;
        }

        return false;
    }

};
