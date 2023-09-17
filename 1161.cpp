
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        
        map<int,int> m; //Declare map.
        if(!root) return 0;

        queue<TreeNode*> q; // Declare queue.
        q.push(root);

        int lvl = 1; // Initialize level count by 1.
        // Run loop until the queue is empty.
        while(!q.empty()) {

            int sum = 0; //Initialize sum by 0 for each loop.
            int n = q.size();

            for(int i=0; i<n; i++) {

                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val; // Add the node -> val in sum.
                if(temp -> left!=NULL) q.push(temp->left); 
                if(temp -> right!=NULL) q.push(temp->right);

            }
            // Insert the sum of each level into the map m as an key if it is not present already and level will be it's value.
            if(m.find(sum) == m.end()) {
                m[sum] = lvl;
            }

            lvl++;
        }

        int max_sum = INT_MIN;
        int ans = 0;
        // Traverse through map and return the level having maximum sum.
        for(auto it: m) {
            if(max_sum < it.first) {
                max_sum = it.first;
                ans = it.second; 
            }
        }

        return ans;
    }
};