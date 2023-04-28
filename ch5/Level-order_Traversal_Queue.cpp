#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Node{
    int val;
    struct Node *left, *right;
};

struct Node *new_node(int element){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->val = element;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct Node *insert_node(struct Node *root, int element){
    if (root == NULL)	
    	return new_node(element);
    else if (element < root->val)
        root->left = insert_node(root->left, element);
    else if (element > root->val)
        root->right = insert_node(root->right, element);
    
	return root;
}

struct Node *min_value_node(struct Node *root){
    struct Node *curent = root;

    while (curent && curent->left != NULL)
        curent = curent->left;

    return curent;
}

struct Node *delete_node(struct Node *root, int val){
    if (root == NULL){
        return root;
    }

    if (val < root->val)
        root->left = delete_node(root->left, val);
    else if (val > root->val)
        root->right = delete_node(root->right, val);
    else{
        // 找到要刪除的節點
        // case 1: 如果要刪除的node是leaf，那就直接刪除。
		// case 2: 如果要刪除的node不是leaf，但是只有一個child，則直接把child接上來。
        if (root->left == NULL){	
            struct Node *temp = root->right;
            free(root);
            printf(" Delete successfully.");
			return temp;
        }
        else if (root->right == NULL){	
            struct Node *temp = root->left;
            free(root);
            printf(" Delete successfully.");
            return temp;
        }

        // case 3: 如果要刪除的node不是leaf，而且有兩個child!
        // 使用右子樹最小值或左子樹最大值代替原本欲刪除的node
        struct Node *temp = min_value_node(root->right);
        root->val = temp->val;
        root->right = delete_node(root->right, temp->val);
    }
    
    return root;
}

void inorder(struct Node *root){
    if (root != NULL){
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

void preorder(struct Node *root){
    if (root != NULL){	
		printf("%d ",root->val);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct Node *root){
    if (root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->val);
	}
}
 
/* frunction prototypes */
struct Node** createQueue(int*, int*);
void enQueue(struct Node**, int*, struct Node*);
struct Node* deQueue(struct Node**, int*);
 
/* Given a binary tree, print its nodes in level order
   using array for implementing queue */
void levelorder(struct Node* root)
{
    int rear, front;
    struct Node** queue = createQueue(&front, &rear);
    struct Node* temp_node = root;
 
    while (temp_node) {
        printf("%d ", temp_node->val);
 
        /*Enqueue left child */
        if (temp_node->left)
            enQueue(queue, &rear, temp_node->left);
 
        /*Enqueue right child */
        if (temp_node->right)
            enQueue(queue, &rear, temp_node->right);
 
        /*Dequeue node and make it temp_node*/
        temp_node = deQueue(queue, &front);
    }
}

/*UTILITY FUNCTIONS*/
struct Node** createQueue(int* front, int* rear)
{
    struct Node** queue = (struct Node**)malloc(
        sizeof(struct Node*) * MAX);
 
    *front = *rear = 0;
    return queue;
}
 
void enQueue(struct Node** queue, int* rear,
             struct Node* new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}
 
struct Node* deQueue(struct Node** queue, int* front)
{
    (*front)++;
    return queue[*front - 1];
}
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
    struct Node* node
        = (struct Node*)malloc(sizeof(struct Node));
    node->val = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
int main(){
	
	FILE *fp;
	fp=fopen("test1.txt","r");	
	
	struct Node *root = NULL; // 產生一個空root 
	int ins;      //  儲存稍後讀取到的指令編號 
	int element;  // 儲存稍後讀取到的值 
		
	if(fp!=NULL){
		while(fscanf(fp,"%d",&ins)!=EOF){
			printf("\nThe instruction:%d",ins);
			
			switch(ins)
			{
				case 1: // Insert node
					fscanf(fp," %d",&element);
					printf("\nInsert %d.",element);
					if (root==NULL) // root沒有初始化過，先初始化 
						root = insert_node(root,element);
					else 
						insert_node(root,element);
					printf(" Insert successfully.");
					break;
				case 2: // Delete node
					fscanf(fp," %d",&element);
					printf("\nDelete %d.",element);
					delete_node(root,element);
					break;
				case 3: // Inorder traversal
					printf("\nInorder: ");
					inorder(root);
					break;
				case 4: // Preorder traversal
					printf("\nPreorder: ");
					preorder(root);
					break;
				case 5: // Postorder traversal
					printf("\nPostorder: ");
					postorder(root);
					break;
				case 6: // level-order traversal
					printf("\nLevel-order: ");
					levelorder(root);
					break;
				default:
					printf("\nWrong instruction!"); // case 1~6 以外的狀況  
					break;
			}
		}
	}
	else{
		printf("No such file.\n");
	}
	fclose(fp);
	return 0;
}