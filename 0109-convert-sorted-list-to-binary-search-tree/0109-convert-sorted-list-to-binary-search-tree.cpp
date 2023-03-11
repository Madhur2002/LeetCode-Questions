/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* convertToBst(int i, int j, vector<int>& nums) {
        if(i > j) {
            return NULL;
        }

        int mid = (i+j) >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = convertToBst(i, mid-1, nums);
        root->right = convertToBst(mid+1, j, nums);

        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;

        while(head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }

        TreeNode* root = convertToBst(0, nums.size()-1, nums);
        return root;
    }
};