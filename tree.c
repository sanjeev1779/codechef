#include<stdio.h>
#include<stack>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node *newnode(int val)
{
        struct node* newnode= (struct node*)malloc(sizeof(struct node));
        newnode->data= val;
        newnode->left= NULL;
        newnode->right= NULL;
        return newnode;
}

void preorder(struct node* head)
{

}
main()
{
    struct node* root= NULL;
    root= newnode(1);
    root->left= newnode(2);
    root->right= newnode(3);
    root->left->left= newnode(4);
    root->left->right= newnode(5);
    root->right->left= newnode(6);
    root->right->right= newnode(7);
    struct node* head= root;
    preorder(head);
}
