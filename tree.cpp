#include<stdio.h>
#include<stack>
#include<stdlib.h>
#include<iostream>
using namespace std;
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
int pathlen=0;
int path[1000];
void path_finder(struct node* root,int path[],int pathlen)
{
   if(root==NULL) return;
    path[pathlen++]= root->data;
   if(root->left== NULL && root->right==NULL)
   {
       for(int i=0;i<pathlen;i++) printf("%d ",path[i]);
       printf("\n");
   }
   else
   {
       path_finder(root->left,path,pathlen);
       path_finder(root->right,path,pathlen);
   }

   return;
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

    path_finder(head,path,0);
}
