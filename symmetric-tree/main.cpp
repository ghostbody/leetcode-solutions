#include <iostream>
#include <stack>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
          return true;
        }
        queue<TreeNode *> ql;
        queue<TreeNode *> qr;
        ql.push(root);
        qr.push(root);
        while (!ql.empty() && !qr.empty()) {
            TreeNode * topl = ql.front();
            ql.pop();
            TreeNode * topr = qr.front();
            qr.pop();
            if (topl->val != topr->val) {
                return false;
            }
            if (topl->left != NULL) {
                ql.push(topl->left);
            }
            if (topr->right != NULL) {
                qr.push(topr->right);
            }
            if (qr.size() != ql.size()) {
                return false;
            }
            if (topl->right != NULL) {
                ql.push(topl->right);
            }
            if (topr->left != NULL) {
                qr.push(topr->left);
            }
            if (qr.size() != ql.size()) {
                return false;
            }
        }
        return true;
    }
};

void test_case1 () {
    Solution s;

    TreeNode n1 = TreeNode(0);
    TreeNode n2 = TreeNode(2);
    TreeNode n3 = TreeNode(2);
    TreeNode n4 = TreeNode(3);
    TreeNode n5 = TreeNode(4);
    TreeNode n6 = TreeNode(4);
    TreeNode n7 = TreeNode(3);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;

    cout << s.isSymmetric(&n1) << endl;
}

void test_case2 () {
    Solution s;

    TreeNode n1 = TreeNode(0);
    TreeNode n2 = TreeNode(2);
    TreeNode n3 = TreeNode(2);
    TreeNode n4 = TreeNode(3);
    TreeNode n5 = TreeNode(3);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = NULL;
    n2.right = &n4;
    n3.left = NULL;
    n3.right = &n5;

    cout << s.isSymmetric(&n1) << endl;
}

void test_case3 () {
    Solution s;

    TreeNode n1 = TreeNode(1);
    TreeNode n2 = TreeNode(2);

    n1.left = &n2;

    cout << s.isSymmetric(&n1) << endl;
}


int main() {
    test_case1();
    test_case2();
    test_case3();
}