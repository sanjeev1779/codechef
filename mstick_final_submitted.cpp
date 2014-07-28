#include <iostream>
#include <cstdio>
using namespace std;
#define SIZ 101010
int array[SIZ];
class node
{
public :
        int maxi,mini,left_r,right_r;
        node *left ,*right;
        node() {
                maxi=mini=left_r=right_r=-1;
                left=right='\0';
        }
};
void maketree(int leftt,int rightt,node *nod)
{
        node *left=new node();
        node *right=new node();
        if(leftt<rightt) {
                nod->left=left;
                nod->right=right;
                nod->left_r=leftt;
                nod->right_r=rightt;
                maketree(leftt,(leftt+rightt)/2,nod->left);
                maketree(1+(leftt+rightt)/2,rightt,nod->right);
                nod->maxi=max(nod->left->maxi,nod->right->maxi);
                nod->mini=min(nod->left->mini,nod->right->mini);
        } else {
                nod->left_r=nod->right_r=leftt;
                left->left_r=left->right_r=leftt;
                left->maxi=left->mini=array[leftt];
                left->left=left->right=NULL;

                nod->left=nod->right=left;
                nod->maxi=nod->mini=array[leftt];
        }
}
void preprocess(int N,node *top)
{
        maketree(0,N-1,top);
}
int maxRMQ(int leftt,int rightt,node *nod)
{
        int val=(nod->left_r+nod->right_r)/2;
        if(leftt==nod->left_r&&rightt==nod->right_r)return nod->maxi;
        if(val<leftt) {
                return maxRMQ(leftt,rightt,nod->right);
        } else if(val>=rightt) {
                return maxRMQ(leftt,rightt,nod->left);
        } else {
                return max(maxRMQ(leftt,val,nod->left),maxRMQ(val+1,rightt,nod->right));
        }
}

int minRMQ(int leftt,int rightt,node *nod)
{
        int val=(nod->left_r+nod->right_r)/2;
        if(leftt==nod->left_r&&rightt==nod->right_r)return nod->mini;
        if(val<leftt) {
                return minRMQ(leftt,rightt,nod->right);
        } else if(val>=rightt) {
                return minRMQ(leftt,rightt,nod->left);
        } else {
                return min(minRMQ(leftt,val,nod->left),minRMQ(val+1,rightt,nod->right));
        }
}
int main()
{
   int N,i=0;
        scanf("%d",&N);
        while(i<N) {
                scanf("%d",&array[i++]);
        }
        node *top=new node();
        preprocess(N,top);
        int q;
        scanf("%d",&q);
        while(q--) {
                int leftt,rightt;
                scanf("%d%d",&leftt,&rightt);
                int leftt_r=leftt-1,rightt_r=rightt+1;
                int left_max=0,right_max=0,mid_max=0,mid_min=0;
                if(leftt_r>=0)left_max=maxRMQ(0,leftt_r,top);
                if(rightt_r<=N-1)right_max=maxRMQ(rightt_r,N-1,top);
                mid_max=maxRMQ(leftt,rightt,top);
                mid_min=minRMQ(leftt,rightt,top);
                float mid_result=(float)(mid_min+mid_max)/2;

                left_max=max(left_max+mid_min,mid_min+right_max);
                if(mid_result>=left_max)printf("%.1f\n",mid_result);
                else printf("%d.0\n",left_max);
        }
        return 0;
}
