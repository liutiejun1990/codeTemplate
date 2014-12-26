/*************************************************************************
	> File Name: String.cpp
	> Author: 刘铁俊
	> Mail: liutiejun@xiaomi.com
	> Created Time: 2014年12月26日 星期五 19时24分24秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
using namespace std;

class String{
	public:
		String(const char*);
		String(const String&);
		~String();
		String& operator=(const String&);
    const char* c_str() const;
	private:
		char* m_data;
};

const char* String::c_str() const{
	return m_data;
}

String::String(const char* s){
	if(s==NULL){
		m_data=new char[1]; *m_data='\0';
	}
	else{
		int len=strlen(s);
		m_data=new char[len+1];
		if(m_data==NULL){
		}
		strcpy(m_data,s);
	}
	printf("String::String char\n");
}

String::String(const String& s){
	int len=strlen(s.m_data);
	m_data=new char[len+1];
	if(m_data==NULL){
	}
	strcpy(m_data,s.m_data);
	printf("String::String String\n");
}

String::~String(){
	delete[] m_data;
}

String& String::operator=(const String& s){
	if(this==&s){
		return *this;
	}
	delete[] m_data;
	m_data=new char[strlen(s.m_data)+1];
	if(m_data==NULL){
	}
	strcpy(m_data,s.m_data);
	printf("String::operator=\n");
	return *this;
}

void fun(const String& s){
	printf("fun, string is %s\n",s.c_str());
}
void fun1(String s){
	printf("fun1, string is %s\n",s.c_str());
}

int main(){
	String s("aa");
	String ss=s;//call String::String(const String&)
	ss=s;//call String::operator=(const String&)
	fun(s);//careful to see default copy function
	return 0;
}
