/*************************************************************************
    > File Name: heap.cpp
    > Author: 刘铁俊
    > Mail: liutiejun@xiaomi.com
    > Created Time: 2014年11月12日 星期三 21时14分10秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<error.h>
#include<unistd.h>
#include<sys/stat.h>
using namespace std;

const int len=10;
int heap[len]={3,4,1,6,7,0,2,9,5,8};

void swap(int& a, int& b){
	a=a^b;
	b=a^b;
	a=a^b;
}

void down(int index){
	int p=index<<1;
	int tmp=heap[index];
	while(p+2<len){
		if(heap[p+1]>heap[p+2]){
			p=p+2;
		}
		while(tmp>heap[p]){
			swap(tmp,heap[p]);
		}
	}
	if(p+1>=len){
	}
}

int main(){
	return 0;
}

