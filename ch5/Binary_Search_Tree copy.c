#include <stdio.h>
#include <stdlib.h>

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
        // ���n�R�����`�I
        // case 1: �p�G�n�R����node�Oleaf�A���N�����R���C
		// case 2: �p�G�n�R����node���Oleaf�A���O�u���@��child�A�h������child���W�ӡC
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

        // case 3: �p�G�n�R����node���Oleaf�A�ӥB�����child!
        // �ϥΥk�l��̤p�ȩΥ��l��̤j�ȥN���쥻���R����node
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

int height(struct Node * node) {
	if (node == NULL)
		return 0;
  	else {
    	int lheight = height(node -> left);
    	int rheight = height(node -> right);
    	if (lheight > rheight)
    		return (lheight + 1);
    	else return (rheight + 1);
  	}
}

void CurrentLevel(struct Node * root, int level) {
	if (root == NULL)
		return;
	if (level == 1)
    	printf("%d ", root -> val);
  	else if (level > 1) {
    	CurrentLevel(root -> left, level - 1);
    	CurrentLevel(root -> right, level - 1);
  	}
}

void levelorder(struct Node *root){
	
	int h = height(root);
	
	for (int i = 1; i <= h; i++)
		CurrentLevel(root, i);
}

int main(){
	
	FILE *fp;
	fp=fopen("test1.txt","r");	
	
	struct Node *root = NULL; // ���ͤ@�Ӫ�root 
	int ins;      //  �x�s�y��Ū���쪺���O�s�� 
	int element;  // �x�s�y��Ū���쪺�� 
		
	if(fp!=NULL){
		while(fscanf(fp,"%d",&ins)!=EOF){
			printf("\nThe instruction:%d",ins);
			
			switch(ins)
			{
				case 1: // Insert node
					fscanf(fp," %d",&element);
					printf("\nInsert %d.",element);
					if (root==NULL) // root�S����l�ƹL�A����l�� 
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
					printf("\nWrong instruction!"); // case 1~6 �H�~�����p  
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
