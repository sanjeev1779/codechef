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
        int query;
        scanf("%d",&query);
        while(query--) {
                int leftt,rightt;
                scanf("%d%d",&leftt,&rightt);
                int leftt_r=leftt-1,rightt_r=rightt+1;
                int res1=0,res2=0,res_max=0,res_min=0;
                if(leftt_r>=0)res1=maxRMQ(0,leftt_r,top);
                if(rightt_r<=N-1)res2=maxRMQ(rightt_r,N-1,top);
                res_max=maxRMQ(leftt,rightt,top);
                res_min=minRMQ(leftt,rightt,top);
                //cout<<res_max<<""<<res_min<<endl;
                float result=(float)(res_min+res_max)/2;
                //cout<<result<<endl;
                res1=max(res1+res_min,res_min+res2);
                if(result>=res1)printf("%.1f\n",result);
                else printf("%d.0\n",res1);
        }
        return 0;
}
