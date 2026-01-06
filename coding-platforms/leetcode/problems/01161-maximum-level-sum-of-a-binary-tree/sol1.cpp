#include "../header/solution_interface.h"
using namespace std;

int maxLevelSum(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    int level = 1;
    int bestLevel = 1;
    long long maxSum = LLONG_MIN;

    while (!q.empty()) {
        int size = q.size();
        long long currSum = 0;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            currSum += node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        if (currSum > maxSum) {
            maxSum = currSum;
            bestLevel = level;
        }
        level++;
    }

    return bestLevel;
}
