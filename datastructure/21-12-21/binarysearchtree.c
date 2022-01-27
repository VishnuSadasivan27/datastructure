#include <stdio.h>
#include <stdlib.h>

struct node* insertion(struct node*,int);
struct node* deleteItem(struct node*, int);
void inorder(struct node *);
void inorder(struct node *);
void inorder(struct node *);
struct node* minValueNode(struct node*);
struct node* deleteNode(struct node*, int);

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* root= NULL;

struct node* createNode(int data){
    struct node* temp= (struct node*) malloc(sizeof(struct node));
    temp->left= temp->right=NULL;
    temp->data= data;
    return temp;
}

void main(){
    int size,choice;
    printf("BST Operations\n");

    while(1){
        printf("\n\n");
        printf("1. Insertion\n2. Deletion\n3. Traversal\n4. Search\n5. Exit\n\n");
        printf("Enter the option number to perform operation : ");
        scanf("%d",&choice);
        fflush(stdin);

        switch(choice){
            case 1: {
                        int keyval;
                        printf("Enter the value to insert into the BST : ");
                        scanf("%d",&keyval);
                        if(root==NULL){
                            root= insertion(root, keyval);
                        }
                        else{
                            insertion(root,keyval);
                        }
                        break;
                    }

            case 2: {
                        int keyval;
                        printf("Enter the value to delete from the BST : ");
                        scanf("%d",&keyval);
                        deleteNode(root,keyval);
                        break;
                    }

            case 3: {
                        int dis_choice, dis_switch_error=1;
                        while(dis_switch_error==1){
                            printf("\n1. In-Order Traversal.\n2. Pre-Order Traversal.\n3. Post-Order Traversal.");
                            printf("\n\nChoose type of traversal - ");
                            scanf("%d",&dis_choice);
                            fflush(stdin);

                            dis_switch_error=0;
                            switch(dis_choice){
                                case 1: {
                                            inorder(root);
                                            break;
                                        }

                                case 2: {
                                            preorder(root);
                                            break;
                                        }

                                case 3: {
                                            postorder(root);
                                            break;
                                        }

                                default:{
                                            printf("Invalid Operation !!!");
                                            dis_switch_error=1;
                                        }
                            }
                        }
                        break;
                    }

            case 4: {
                        int search_val;
                        printf("Enter the number that you want to search : ");
                        scanf("%d",&search_val);
                        search(root, search_val);
                        break;
                    }

            case 5: {
                        exit(0);
                        break;
                    }
        }

    }
}

struct node* minValueNode(struct node* node){
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct node* deleteNode(struct node* root, int key){
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        if (root->left==NULL && root->right==NULL)
            return NULL;

        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

struct node* insertion(struct node* node, int item){

    if(node==NULL){
        return createNode(item);
    }
    else{
//        printf("Node is : %d\n", node->data);
        if(item < node->data){
            node->left= insertion(node->left, item);
        }
        else if(item > node->data){
            node->right= insertion(node->right, item);
        }
        return node;
    }
}

void inorder(struct node *temp){
    if (temp != NULL) {
        inorder(temp->left);
        printf("%d \n", temp->data);
        inorder(temp->right);
    }
}

void postorder(struct node *temp){
    if (temp != NULL) {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d \n", temp->data);
    }
}

void preorder(struct node *temp){
    if (temp != NULL) {
        printf("%d \n", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void search(struct node *temp, int val){
    if(temp==NULL){
        printf("Element not found !! or List empty !!\n");
    }
    else if(val==temp->data){
        printf("Element %d found\n", val);
    }
    else if(val > temp->data){
        return search(temp->right, val);
    }
    else if(val < temp->data){
        return search(temp->left, val);
    }
}

