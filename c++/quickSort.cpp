/*************************************************************************
	> File Name: quickSort.cpp
	> Author: 刘铁俊
	> Mail: liutiejun@xiaomi.com
	> Created Time: 2014年12月26日 星期五 20时10分17秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
using namespace std;
void swap(volatile int &a, volatile int &b){//be careful to use volatile
	a=a^b;
	b=a^b;
	a=a^b;
}

void quickSort(int arr[], int left, int right){
	int i=left,j=right;
	int pivot=arr[(left+right)/2];
	/*partition*/
	while(i<=j){
		while(arr[i]<pivot){
			i++;
		}
		while(arr[j]>pivot){
			j--;
		}
		if(i<=j){
			swap(arr[i],arr[j]);
			//int tmp = arr[i];
			//arr[i] = arr[j];
			//arr[j] = tmp;
			i++;
			j--;
		}
	}
	if(left<j){
		quickSort(arr,left,j);
	}
	if(right>i){
		quickSort(arr,i,right);
	}
}

int main(){
	int arr[10]={10,5,2,1,8,4,2,5,9,6};
	quickSort(arr,0,9);
	for(int i=0;i<10;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
