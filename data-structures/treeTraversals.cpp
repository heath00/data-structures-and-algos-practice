#include <iostream>
#include <vector>

using namespace std;
class TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    public:
    TreeNode() : val(0),left(nullptr),right(nullptr) {};
    TreeNode(int v) : val(v),left(nullptr),right(nullptr) {};
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(v),left(l),right(r) {};
    
    vector<int> preorderTraversal(TreeNode* node);
    vector<int> postorderTraversal(TreeNode* node);
    vector<int> inorderTraversal();
};

vector<int> TreeNode::preorderTraversal(TreeNode* node) {
    vector<int> visited;
    vector<int> left;
    vector<int> right;
    if (node) {
        visited.push_back(node->val);
        left = preorderTraversal(node->left);
        right = preorderTraversal(node->right);
        for (int i = 0; i < left.size(); i++) {
            visited.push_back(left[i]);
        }
        for (int i = 0; i < right.size(); i++) {
            visited.push_back(right[i]);
        }
    }

    return visited;

}

vector<int> TreeNode::postorderTraversal(TreeNode* node) {

}

int main() {
    TreeNode* left2 = new TreeNode(4);
    TreeNode* left1Right1 = new TreeNode(5);
    TreeNode* left1 = new TreeNode(2,left2,left1Right1);
    TreeNode* right1 = new TreeNode(3);
    TreeNode* root = new TreeNode(1, left1, right1);


    vector<int> vals = root->preorderTraversal(root);
    for (auto v : vals) {
        cout << v << endl;
    }
}