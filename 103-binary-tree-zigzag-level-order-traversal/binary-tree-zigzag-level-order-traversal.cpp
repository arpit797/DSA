class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> result;

        if (root == NULL) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {

            int size = q.size();

            vector<int> row(size);

            for (int i = 0; i < size; i++) {

                TreeNode* curr = q.front();
                q.pop();

                // Zigzag position
                int index;

                if (leftToRight)
                    index = i;
                else
                    index = size - 1 - i;

                row[index] = curr->val;

                // Push children
                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }

            result.push_back(row);

            // Direction change
            leftToRight = !leftToRight;
        }

        return result;
    }
};