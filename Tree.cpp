#include<iostream>
#include<cstdlib>/*<cstdlib>�O malloc �ݭn�ޤJ�����(27��) */ 
#include <fstream> /*<fstream>�OŪ�ɻݭn�ޤJ�����(27��)*/ 
//�Ѧ�:https://blog.csdn.net/gyysmall/article/details/38455935 

using namespace std;

class Node{
	public:
		Node *new_node(int);
		Node *insert_node(Node *,int);
		Node *min_value_node(Node *);
		Node *delete_node(Node *,int);
		void inorder(Node *);
		void preorder(Node *);
		void postorder(Node *);
		int height(Node *);
		void CurrentLevel(Node *,int);
		void levelorder(Node *);
		
		
	private:
		int val;
		Node *left,*right;
		
};

Node *Node::new_node(int element){
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->val = element;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node *Node::insert_node(Node *root, int element){
	if (root == NULL)	
    	return new_node(element);
    else if (element < root->val)
        root->left = insert_node(root->left, element);
    else if (element > root->val)
        root->right = insert_node(root->right, element);
    
	return root;
}

Node *Node::min_value_node(Node *root){
	Node *curent = root;

    while (curent && curent->left != NULL)
        curent = curent->left;

    return curent;
}

Node *Node::delete_node(Node *root, int val){
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
            Node *temp = root->right;
            delete(root);
            cout<<" Delete successfully.";
			return temp;
        }
        else if (root->right == NULL){	
            struct Node *temp = root->left;
            delete(root);
            cout<<" Delete successfully.";
            return temp;
        }

        // case 3: �p�G�n�R����node���Oleaf�A�ӥB�����child!
        // �ϥΥk�l��̤p�ȩΥ��l��̤j�ȥN���쥻���R����node
        Node *temp = min_value_node(root->right);
        root->val = temp->val;
        root->right = delete_node(root->right, temp->val);
    }
    
    return root;
}

void Node::inorder(Node *root){
	if (root != NULL){
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}

void Node::preorder(Node *root){
	if (root != NULL){	
		cout<<root->val<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

void Node::postorder(Node *root){
	 if (root != NULL){
		postorder(root->left);
		postorder(root->right);
		cout<<root->val<<" ";
	}
}

int Node::height(Node * node){
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

void Node::CurrentLevel(Node * root, int level){
		if (root == NULL)
		return;
	if (level == 1)
    	cout<<root -> val<<" ";
  	else if (level > 1) {
    	CurrentLevel(root -> left, level - 1);
    	CurrentLevel(root -> right, level - 1);
  	}
}

void Node::levelorder(Node *root){
	int h = height(root);
	
	for (int i = 1; i <= h; i++)
		CurrentLevel(root, i);
}

int main(){
	
	ifstream file;
    file.open("test1.txt");
    
	Node *root = NULL; // ���ͤ@�Ӫ�root 
	int ins;      //  �x�s�y��Ū���쪺���O�s�� 
	int element;  // �x�s�y��Ū���쪺�� 
		
	if(file != NULL){
		 while (!file.eof()){
		 	file >> ins;
			cout<<"\nThe instruction:"<<ins;
			
			switch(ins)
			{
				case 1: // Insert node
					file >> element;
					cout<<"\nInsert "<<element<<".";
					if (root==NULL) // root�S����l�ƹL�A����l�� 
						root = root->insert_node(root,element);
					else 
						root->insert_node(root,element);
					cout<<" Insert successfully.";
					break;
				case 2: // Delete node
					file >> element;
					cout<<"\nDelete "<<element<<".";
					root->delete_node(root,element);
					break;
				case 3: // Inorder traversal
					cout<<"\nInorder: ";
					root->inorder(root);
					break;
				case 4: // Preorder traversal
					cout<<"\nPreorder: ";
					root->preorder(root);
					break;
				case 5: // Postorder traversal
					cout<<"\nPostorder: ";
					root->postorder(root);
					break;
				case 6: // level-order traversal
					cout<<"\nLevel-order: ";
					root->levelorder(root);
					break;
				default:
					cout<<"\nWrong instruction!"; // case 1~6 �H�~�����p  
					break;
			}
		}
	}
	else{
		cout<<"No such file.\n";
	}
	file.close();       //�����ɮ�
	return 0;
}
