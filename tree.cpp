#include <iostream>

using namespace std;

class TreeNode
{
    public:
        int value;
        TreeNode * left;
        TreeNode * right;
        
    public:
        TreeNode(int n)
        {
            value = n;
            left = NULL;
            right = NULL;
        }
};

class Tree
{
    TreeNode * root;
    unsigned int size;
    
    public:
        Tree()
        {
            root = NULL;
            size = 0;
        }

        ~Tree()
        {
            cout << "Calling destructor" << endl;
            DeleteAllNodes(root);
        }

        void DeleteAllNodes(TreeNode * root)
        {
            if(root)
            {
                DeleteAllNodes(root->left);
                DeleteAllNodes(root->right);
                delete root;
                size = 0;
            }
        }

        void add(int numb)
        {
            if(root == NULL)
                root = new TreeNode(numb);
            else
                add_node(numb, root);
            size++;          
        }
        
        void traverse()
        {
            if(!root)
                cout << "Tree is empty";
            else
                in_order(root);
            cout << endl;
        }
        
        int find(int numb)
        {
            return find_in_tree(root, numb);   
        }
        
    private:    
        void add_node(int numb, TreeNode * node)
        {
            if(numb == node->value)
                return;
            if(numb < node->value)
                if(node->left)
                    add_node(numb, node->left);
                else
                {
                    TreeNode * fresh = new TreeNode(numb);
                    node->left = fresh;
                }
            else
                if(node->right)
                    add_node(numb, node->right);
                else
                {
                    TreeNode * fresh = new TreeNode(numb);
                    node->right = fresh;
                }
        }
        
        void in_order(TreeNode * node)
        {
            if(node->left)
                in_order(node->left);
            cout << node->value << " ";
            if(node->right)
                in_order(node->right);
        }

        int find_in_tree(TreeNode * node, int numb)
        {
            if(!node)
                return 0;
            if(numb == node->value)
                return 1;
            if(numb < node->value)
                return find_in_tree(node->left, numb);
            else
                return find_in_tree(node->right, numb);
            return 0;
        }            
};

int main()
{
    Tree tree;
    tree.traverse();
    cout << tree.find(11) << endl;
    tree.add(6);
    tree.traverse();
    tree.add(10);
    tree.add(15);
    tree.add(11);
    tree.add(2);
    tree.add(24);
    tree.traverse();
    cout << tree.find(11) << endl;
    cout << tree.find(8) << endl;
    
    return 0;
}
