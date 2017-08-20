/*
116. Populating Next Right Pointers in Each Node

Given a binary tree
    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }



Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.


Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).




For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7



After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    struct TreeLinkNode *v, *h;
    if (!root || !root->left) return;
    v = root;
    while (v->left) {
        h = v;
        do {
            h->left->next = h->right;
            if (h->next) {
                h->right->next = h->next->left;
            }
            h = h->next;
        } while (h);
        v = v->left;
    }
}


/*
Difficulty:Medium
Total Accepted:138.8K
Total Submissions:375.8K


Companies Microsoft
Related Topics Tree Depth-first Search
Similar Questions 
                
                  
                    Populating Next Right Pointers in Each Node II
                  
                    Binary Tree Right Side View
*/
