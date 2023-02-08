#pragma once
#include"Lists.h"
#include<string>
#include<exception>
template<typename E>
class node{
public:
	E element;
	node* next;
	node(E element,node* next):element(element),next(next){}
	std::string toString() {
		std::string buffer;
		buffer.append(std::to_string(element)).append("->").append((next == nullptr ? "null" : std::to_string(next->element)));
		return buffer;
	}
};
template <typename E>
class LinkedLists:public Lists<E>
{
private:
	int lenght = 0;
	node<E>* first = nullptr;
	node<E>* Fnode(int index) {
		rangeCheckIndex(index);
		auto temp = this->first;
		while (index)
		{
			index--;
			temp = temp->next;
		}
		return temp;
	}
	node<E>* Fnode(int index) const {
		rangeCheckIndex(index);
		auto temp = this->first;
		while (index)
		{
			index--;
			temp = temp->next;
		}
		return temp;
	}
public:
	static int const ELEMENT_NOT_EXISTS = -1;
	virtual int size()const {
		return this->lenght;
	}
	virtual bool isEmpty()const {
		return this->lenght==0;
	}
	virtual void clear() {
		this->lenght = 0;
		auto temp = this->first;
		while (temp)
		{
			auto temp2 = temp->next;
			delete temp;
			temp = temp2;
		}
		this->first = nullptr;
	}

	virtual void add(E element) {
		this->add(this->lenght, element);
	}
	virtual void add(int index, E element) {
		if (index == 0) {
			this->first = new node<E>(element, this->first);
		}
		else {
			auto temp = Fnode(index - 1);
			temp->next = new node<E>(element, temp->next);
		}
		this->lenght++;
	}
	virtual E remove() {
		return remove(this->lenght - 1);
	}
	virtual E remove(int index) {
		E old = get(index);
		if (index==0)
		{
			auto temp = this->first;
			this->first = this->first->next;
			delete temp;
		}
		else {
			auto temp = Fnode(index - 1);
			auto re = temp->next;
			temp->next = re->next;
			delete re;
		}
		this->lenght--;
		return old;
	}
	virtual E get(int index)const {
		return Fnode(index)->element;
	}
	virtual void set(int index, E element) {
		Fnode(index)->element = element;
	}
	virtual int indexOf(E element)const {
		auto temp = this->first;
		for (int i = 0; i < this->lenght; i++) {
			if (temp->element == element)
				return i;
			temp = temp->next;
		}
		return ELEMENT_NOT_EXISTS;
	}
	virtual bool contains(E element)const {
		return indexOf(element) != ELEMENT_NOT_EXISTS;
	}
	virtual std::string toString()const {
		std::string temp;
		temp.append("size:").append(std::to_string(this->lenght)).append("[");
		auto p = this->first;
		for (int i = 0; i < this->lenght; i++) {
			if (i != 0) {
				temp.append(",");
			}
			temp.append(p->toString());
			p = p->next;
		}
		temp.append("]");
		return temp;
	}
protected:
	virtual void rangeCheckIndex(int index)const {
		if (index<0||index>this->lenght)
		{
			throw std::out_of_range("‘ΩΩÁ¡À");
		}
	}
};
template<typename E>
std::ostream& operator<<(std::ostream& os, const LinkedLists<E>& arr) {
	os << arr.toString();
	return os;
}