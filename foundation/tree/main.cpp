#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int val): val(val), left(NULL), right(NULL) {}
};


class BinaryTree {
public:
    BinaryTree(vector<int*> & values): m_visited({false}) {
        for (int i = 0; i < values.size(); ++i) {
            int * each = values[i];
            if (each) {
                Node * node = new Node((*each);
                insertNode_levelOrder(node);
            }
        }
    }

    ~BinaryTree() {

    }

private:
    vector<bool> m_visited;
    Node * m_root;

    Node* insertNode_levelOrder(Node* root) {
        if(root == NULL) {
            return root;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp->left != NULL) {
                q.push(temp->left);
            } else {
                temp->left = new Node(val);
                return root;
            };

            if (temp->right != NULL) {
                q.push(temp->right);
            } else {
                temp->right = new Node(val);
                return root;
            }
        }
    }

             1
        2       3
    null 4  null null

    int dfs(TreeNode* node) {
        if(node==NULL) return 0;

        int l = dfs(node->left);
        int r = def(node->right);

        cout << l << r << endl;
        return node->val;
    }
};