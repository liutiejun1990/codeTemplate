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

void insert(node_s** root,int value){
	if(*root==NULL){
		*root=(node_s*)malloc(sizeof(node_s));
		(*root)->value=value;
		(*root)->left=NULL;
		(*root)->right=NULL;
		return;
	}
	if(value<(*root)->value){
		return insert(&((*root)->left),value);
	}
	else{
		return insert(&((*root)->right),value);
	}
}

void print(node_s* root){
	if(root==NULL){
		return;
	}
	print(root->left);
	printf("%d\n",root->value);
	print(root->right);
}

void deleteNode(node_s* root, int value){
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
	print(root);
	freeTree(root);
	return 0;
}