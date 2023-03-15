#pragma once
#include <iostream>
using namespace std;
class Test
{
	
public:
	static int nCount;
	Test() {
		nCount++;
		cout << "Creating object" << " " << nCount<< endl;
		
	}
	Test(const Test& other) {
		nCount++;
		cout << "Copy constructor" << " " << nCount << endl;	
	}

	~Test() {
		nCount--;
		cout << "Deleting object" << " " << nCount << endl;

	}
};
class Child :public Test {
public:
	Child() {
		nCount++;
		cout << "Creating child object" << " " << nCount << endl;
	}
	~Child() {
		nCount--;
		cout << "Deleting child object" << " " << nCount << endl;
	}
};
class Aggregate {
public:
	Test m_objTest;

	Aggregate() {
		Test::nCount++;
		cout << "Creating Aggregate object" << " " << Test::nCount << endl;
	}

	~Aggregate() {
		Test::nCount--;
		cout << "Deleting Aggregate object" << " " << Test::nCount << endl;
	}
};
template <typename T>
class AggregateT {
public:
	T m_obj;

	AggregateT() {
		Test::nCount++;
		cout << "Creating AggregateT object" << " " << Test::nCount << endl;
	}

	~AggregateT() {
		Test::nCount--;
		cout << "Deleting AggregateT object" << " " << Test::nCount << endl;
	}
};
