#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct food
{
   	char food_name[20];
	int price;
	int time;
};

typedef struct node
{
    struct node *left,*right;
    struct food f[10];
	int ht;
    char hotel[30];
	char street_name[30],dummy[2];
	char area[20];
}node;
 
node *insert(node *, char[] ,char[],char[]);
node *search(node *,char[]);
node *Delete(node *,char[]);
void preorder(node *);
void inorder(node *);
int height( node *);
node *rotateright(node *);
node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int BF(node *);
 
int main()
{
    node *root=NULL;
    int x,n,i,op;
    char hot[30], str[30], are[20], dummy[1];
    do
    {
     //   printf("\n1)Create:");
        printf("\n1)Insert Restaurant:");
        printf("\n2)Insert Food:");
        printf("\n3)Delete:");
        printf("\n4)Print:");
        printf("\n5)Quit:");
        printf("\n\nEnter Your Choice:");
        scanf("%d",&op);
        fstream file ("hotelavl.dat", ios::in | ios::out | ios::binary);
        switch(op)
        {

            case 1: 
            		cout<<"\tAdd Restaurant"<<endl;
         		    cin.getline(dummy,1,'\n');
					cout<<"Restaurant Name :"; 
					cin.getline(hot,30,'\n');
					cout<<"Street :"; cin.getline(str,30,'\n');
					cout<<"Area :";  cin.getline(are,20,'\n');;
                    root=insert(root,hot,str,are);
                    break;
        	
        	case 2:
        			cin.getline(dummy,1,'\n');
					cout<<"Restaurant Name:";
        			cin.getline(hot,30,'\n');
        			search(root,hot);
        			break;
        		/*	cout<<"\nAdd Food"<<endl;
         			cin.getline(dummy,1,'\n');
					cout<<"Food Name :"; 
					cin.getline(food_name,30,'\n');
					cout<<"Time :"; cin>>time;
					cout<<"Price :";  cin>>price;
					insert_food(food_name[],time,price)	
        		*/	
                    
            case 3: printf("\nEnter a data to delete:");
                    scanf("%s",hot);
                    root=Delete(root,hot);
                    break;
            
            case 4: printf("\nPreorder sequence:\n");
                    preorder(root);
                    printf("\n\nInorder sequence:\n");
                    inorder(root);
                    printf("\n");
                    break;   
            
        }
    }while(op!=5);
    
    return 0;
}
 
node * insert(node *T,char hot[],char str[],char are[])
{
    if(T==NULL)
    {
        T=(node*)malloc(sizeof(node));
        strcpy(T->hotel,hot);
        strcpy(T->street_name,str);
        strcpy(T->area,are);
        T->left=NULL;
        T->right=NULL;
    }
    else
        if(strcmp(hot,T->hotel) >= 0)        // insert in right subtree
        {
            T->right=insert(T->right, hot,str,are);
            if(BF(T)==-2)
                if(strcmp(hot,T->hotel) >= 0)
                    T=RR(T);
                else
                    T=RL(T);
        }
        else
            if(strcmp(hot,T->hotel) < 0)
            {
                T->left=insert(T->left,hot,str,are);
                if(BF(T)==2)
                    if(strcmp(hot,T->hotel) < 0)
                        T=LL(T);
                    else
                        T=LR(T);
            }
        
        T->ht=height(T);
        
        return(T);
}
 
struct node* search(struct node* root, char key[])
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || strcmp(root->hotel,key))
    {
    	   return root;
    	   cout<<"\nPresent";
	}
    // Key is greater than root's key
    if (strcmp(root->hotel,key) < 0)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}	

node * Delete(node *T,char hot[])
{
    node *p;
    
    if(T==NULL)
    {
        return NULL;
    }
    else
        if(strcmp(hot,T->hotel) >= 0)        // insert in right subtree
        {
            T->right=Delete(T->right,hot);
            if(BF(T)==2)
                if(BF(T->left)>=0)
                    T=LL(T);
                else
                    T=LR(T);
        }
        else
            if(strcmp(hot,T->hotel) < 0)
            {
                T->left=Delete(T->left,hot);
                if(BF(T)==-2)    //Rebalance during windup
                    if(BF(T->right)<=0)
                        T=RR(T);
                    else
                        T=RL(T);
            }
            else
            {
                //data to be deleted is found
                if(T->right!=NULL)
                {    //delete its inorder succesor
                    p=T->right;
                    
                    while(p->left!= NULL)
                        p=p->left;
                    
                    strcpy(T->hotel,p->hotel);
      			    strcpy(T->street_name,p->street_name);
        			strcpy(T->area,p->area);
                    T->right=Delete(T->right,p->hotel);
                    
                    if(BF(T)==2)//Rebalance during windup
                        if(BF(T->left)>=0)
                            T=LL(T);
                        else
                            T=LR(T);\
                }
                else
                    return(T->left);
            }
    T->ht=height(T);
    return(T);
}
 
int height(node *T)
{
    int lh,rh;
    if(T==NULL)
        return(0);
    
    if(T->left==NULL)
        lh=0;
    else
        lh=1+T->left->ht;
        
    if(T->right==NULL)
        rh=0;
    else
        rh=1+T->right->ht;
    
    if(lh>rh)
        return(lh);
    
    return(rh);
}
 
node * rotateright(node *x)
{
    node *y;
    y=x->left;
    x->left=y->right;
    y->right=x;
    x->ht=height(x);
    y->ht=height(y);
    return(y);
}
 
node * rotateleft(node *x)
{
    node *y;
    y=x->right;
    x->right=y->left;
    y->left=x;
    x->ht=height(x);
    y->ht=height(y);
    
    return(y);
}
 
node * RR(node *T)
{
    T=rotateleft(T);
    return(T);
}
 
node * LL(node *T)
{
    T=rotateright(T);
    return(T);
}
 
node * LR(node *T)
{
    T->left=rotateleft(T->left);
    T=rotateright(T);
    
    return(T);
}
 
node * RL(node *T)
{
    T->right=rotateright(T->right);
    T=rotateleft(T);
    return(T);
}
 
int BF(node *T)
{
    int lh,rh;
    if(T==NULL)
        return(0);
 
    if(T->left==NULL)
        lh=0;
    else
        lh=1+T->left->ht;
 
    if(T->right==NULL)
        rh=0;
    else
        rh=1+T->right->ht;
 
    return(lh-rh);
}
 
void preorder(node *T)
{
    if(T!=NULL)
    {
        printf("Hotel : %s(Bf=%d)\nStreet : %s\nArea : %s\n\n",T->hotel,BF(T),T->street_name,T->area);
        preorder(T->left);
        preorder(T->right);
    }
}
 
void inorder(node *T)
{
    if(T!=NULL)
    {
        inorder(T->left);
         printf("Hotel : %s(Bf=%d)\nStreet : %s\nArea : %s\n\n",T->hotel,BF(T),T->street_name,T->area);
        inorder(T->right);
    }
}
