/*************************************************************************
	> File Name: SmartPointer.cpp
	> Author: 刘铁俊
	> Mail: liutiejun@xiaomi.com
	> Created Time: 2014年12月26日 星期五 21时06分56秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
using namespace std;
class _counter{  
	template<class T> friend class SmartPointer;  
	_counter(int u):use(u){}  
	~_counter(){}  
	int use;  
};

template<class T>  
class SmartPointer{  
	public:  
		SmartPointer(T *t):pc(new _counter(1)){  
			cout<<"SmartPointer::SmartPointer() invoded use is: "<<pc->use<<endl;  
			this->pt = t;  
		}  
    
    T& operator*(){
			return *pt;
		}

		T* operator->(){
			return pt;
		}

		SmartPointer(SmartPointer<T> &rhs){  
			this->pc = rhs.pc;  
			this->pt = rhs.pt;  
			this->pc->use++;  
			cout<<"SmartPointer copy invoked use is: "<<pc->use<<endl;  
		}  

		~SmartPointer(){  
			pc->use--;  
			cout<<"SmartPointer::~SmartPointer() invoded use is: "<<pc->use<<endl;  
			if(pc->use == 0)  
			{  
				delete pt;  
				delete pc;  
			}  
		}  

		SmartPointer<T>& operator=(SmartPointer<T>& rhs){  
			if(&rhs == this){  
				return *this;  
			}  

			this->pt = rhs.pt;  
			this->pc = rhs.pc;  
			this->pc->use++;  
			cout<<"SmartPointer::operator=() invoked  use is: "<<pc->use<<endl;  
			return *this;  
		}  

	private:  
		T *pt;  
		_counter* pc;  
};

class HasPtr{  
	public:  
		HasPtr(int val):value(val),p(new int(3)){  
			cout<<"HasPtr::HasPtr() invoked"<<endl;  
		}  
		~HasPtr(){ delete p; cout<<"HasPtr::~HasPtr() invoded"<<endl;}  

	private:  
		int *p;  
		int value;  
};

int main(){
	HasPtr *php = new HasPtr(3);  
	SmartPointer<HasPtr> psp(php);  
	SmartPointer<HasPtr> npsp(psp);  
	SmartPointer<HasPtr> nnpsp = npsp;//careful,call copy function,not operator= 
	nnpsp=npsp;
	return 0;
}
