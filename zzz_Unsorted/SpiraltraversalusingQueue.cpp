#include<iostream>
#include<queue>
using namespace std;

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *newNode(int a)
{
    struct node *temp = new struct node();
    temp->left = NULL;
    temp->data = a;
    temp->right = NULL;
    return temp;
}

void createTree(struct node **root,int a)
{
    if(*root==NULL)
        *root = newNode(a);
    else
    {
        if(a < (*root)->data)
            createTree(&(*root)->left,a);
        else
            createTree(&(*root)->right,a);
    }
}

void Inorder(struct node *tree)
{
    if(tree==NULL)
        return;
    Inorder(tree->left);
    cout<<tree->data<<" ";
    Inorder(tree->right);
}

void SpiralOrder(struct node *tree)
{
    bool flip = true;
    queue<struct node *> Q;
    Q.push(tree);
    
    int qsize = 0;
    while(!Q.empty())
    {
        qsize = Q.size();

        
        while(qsize)
        {
            struct node *top = Q.front();
            cout<<top->data<<" ";
            Q.pop();
            if(flip)
            {
                if(top->left)
                    Q.push(top->left);
                if(top->right)
                    Q.push(top->right);
            }
            else
            {
                if(top->right)
                    Q.push(top->right); 
                if(top->left)
                    Q.push(top->left);                
                
            }
            qsize--;
        }
        cout<<endl;
        flip = !flip;
    }
}

int main()
{
   int arr[] = {10,5,1,7,20,15,30,25,40};
   int n=sizeof(arr)/sizeof(arr[0]);
   
   struct node *tree = NULL;
   for(int i=0 ; i<=n-1 ; i++)
        createTree(&tree,arr[i]);
   
    Inorder(tree);
    cout<<endl;
    SpiralOrder(tree);
   
   cin.get();
   cin.get();
   return 0;
}