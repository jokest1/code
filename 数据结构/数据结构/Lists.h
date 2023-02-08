#pragma once
#include<string>
template<typename E>
struct Lists
{
	static int const ELEMENT_NOT_EXISTS = -1;
	virtual int size()const = 0;
	virtual bool isEmpty()const = 0;
	virtual void clear() = 0;

	virtual void add(E element) = 0;
	virtual void add(int index,E element) = 0;
	virtual E remove() = 0;
	virtual E remove(int index) = 0;
	virtual E get(int index)const = 0;
	virtual void set(int index, E element) = 0;
	virtual int indexOf(E element)const = 0;
	virtual bool contains(E element)const = 0;
	virtual std::string toString()const = 0;
protected:
	virtual void rangeCheckIndex(int index)const = 0;
};
