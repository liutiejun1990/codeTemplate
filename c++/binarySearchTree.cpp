/*************************************************************************
	> File Name: binarySearchTree.cpp
	> Author: 刘铁俊
	> Mail: liutiejun@xiaomi.com
	> Created Time: 2014年11月10日 星期一 16时02分45秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<error.h>
#include<unistd.h>
#include<sys/stat.h>
using namespace std;
struct node_s{
	int value;
	node_s* left;
	node_s* right;
};

//void insert(node_s* &root,int value)//或者用引用,但是c语言不支持
void insert(node_s** root,int value){
	if(*root==NULL){
		*root=(node_s*)malloc(sizeof(node_s));
		(*root)->value=value;
		(*root)->left=NULL;
		(*root)->right=NULL;
		printf("begin insert node,value is %d\n",value);
		return;
	}
	if(value<(*root)->value){
		return insert(&((*root)->left),value);
	}
	else{
		return insert(&((*root)->right),value);
	}
}

//递归方式
node_s* findNode(node_s* root, int value){
	if(root==NULL||root->value==value){
		return root;
	}
	if(value<root->value){
		return findNode(root->left,value);
	}
	else{
		return findNode(root->right,value);
	}
}

//非递归方式
node_s* findNode2(node_s* root, int value){
	while(root!=NULL){
		if(root->value==value){
			return root;
		}
		if(value<root->value){
			root=root->left;
		}
		else{
			root=root->right;
		}
	}
	return NULL;
}


void print(node_s* root){
	if(root==NULL){
		return;
	}
	print(root->left);
	printf("%d\n",root->value);
	print(root->right);
}

//注意引用的使用
void freeNode(node_s* &node){
	if(node==NULL){
		return;
	}
	node_s* tmp=NULL;
	if(node->left==NULL&&node->right==NULL){
		printf("left and right is NULL\n");
		free(node);
		node=NULL;
		return;
	}
	else if(node->left==NULL){
		tmp=node;
		node=node->right;
		free(tmp);
		return;
	}
	else if(node->right==NULL){
		tmp=node;
		node=node->left;
		free(tmp);
		return;
	}
	else{
		node_s* next=node->left;
		while(next->right!=NULL){
			next=next->right;
		}
		tmp=node;
		node=next;
		node->left=tmp->left;
		node->right=tmp->right;
		free(tmp);
		return;
	}
}

//注意**的使用
void freeNode2(node_s** node){
}

//注意引用的使用
void deleteNode(node_s* &root,int value){
	if(root==NULL||root->value==value){
		return freeNode(root);
	}
	else if(value<root->value){
		deleteNode(root->left,value);
	}
	else{
		deleteNode(root->right,value);
	}
}

void buildTree(){
}

void freeTree(node_s* root){
	if(root==NULL){
		return;
	}
	freeTree(root->left);
	freeTree(root->right);
	printf("begin free node %d\n", root->value);
	free(root);
	root=NULL;
}

int main(){
	int array[5]={2,4,1,5,3};
	node_s* root=NULL;
	for(int i=0;i<5;i++){
		insert(&root,array[i]);
	}
	printf("begin print tree\n");
	print(root);
	printf("begin find 3\n");
	node_s* ans=NULL;
	ans=findNode(root,3);
	if(ans!=NULL){
		printf("find it, value is %d\n",ans->value);
	}
	printf("begin delete node,value is 1\n");
	deleteNode(root,3);
	print(root);
	freeTree(root);
	return 0;
}
