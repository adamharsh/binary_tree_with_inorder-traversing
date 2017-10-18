#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct node{
	int data;
	node* left;
	node* right;
};
node* root=NULL;
node* binary(node* head,int arr[],int m,int size){
	if(m>size){
		return head;
	}
	else{
		node *new_node=new(node);
		head=new_node;
		new_node->data=arr[m-1];
		
		new_node->left=new_node->right=NULL;
		head->left=binary(head->left,arr,2*m,size);
		head->right=binary(head->right,arr,2*m+1,size);
	}
	
}
void show(node* head){
	if(head!=NULL){
		show(head->left);
	cout<<head->data;
	show(head->right);
	}
	
}
int main(int argc, char** argv) {
	int size;
	cout<<"Welcome this is program to implement Binary Tree";
	cout<<"\nEnter the no of nodes:";
	cin>>size;
	int arr[size];
	for(int i=0;i<size;i++){
		cout<<"\nEnter data:";
		cin>>arr[i];
	}
	root=binary(root,arr,1,size);
	cout<<"\n";
	show(root);
	return 0;
}
