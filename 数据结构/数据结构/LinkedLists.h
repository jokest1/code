#pragma once
#include"Lists.h"
template <typename E>
class node{
public:
	E element;
	node* next;
	node(E element, node* next = nullptr) :element(element), next(next){}
};
template <typename E>
class LinkedLists :public Lists<E>{
public:
	virtual int size()const override {
		return this->lenght;
	}
	virtual bool isEmpty()const override {
		return this->lenght == 0;
	}
	virtual void clear() override {
		this->lenght = 0;
		auto p = this->first;
		auto q = p;
		this->first = nullptr;
		while (p)
		{
			q = p->next;
			delete p;
			p = q;
		}
	}

	virtual void add(E element) override {
		this->add(this->lenght, element);
	}
	virtual void add(int index, E element) {
		if (index==0){
			this->first = new node<E>(element, this->first);
		}
		else {
			auto p = nodeOf(index - 1);
			p->next = new node<E>(element, p->next);
		}
		this->lenght++;
	}
	virtual E remove() {
		return remove(this->lenght - 1);
	}
	virtual E remove(int index) {
		E old;
		if (index == 0) {
			old = this->first->element;
			auto p = this->first;
			this->first = this->first->next;
			delete p;
		}
		else {
			auto p = nodeOf(index - 1);
			auto q = p->next;
			p->next = q->next;
			old = q->element;
			delete q;
		}
		this->lenght--;
		return old;
	}
	virtual E get(int index)const {
		return nodeOf(index)->element;
	}
	virtual void set(int index, E element) {
		nodeOf(index)->element = element;
	}
	virtual int indexOf(E element)const {
		auto p = this->first;
		int i = 0;
		while (p)
		{
			if (p->element == element)
				return i;
			i++;
			p = p->next;
		}
		return Lists<E>::ELEMENT_NOT_EXISTS;
	}
	virtual bool contains(E element)const {
		return indexOf(element) != Lists<E>::ELEMENT_NOT_EXISTS;
	}
	virtual std::string toString()const {
		std::string sb;
		auto p = this->first;
		sb.append("size:").append(std::to_string(this->lenght)).append(" [");
		for (int i = 0; i < this->lenght; i++) {
			if (i != 0) {
				sb.append(",");
			}
			sb.append(std::to_string(p->element));
			p = p->next;
		}
		sb.append("]");
		return sb;
	}
	~LinkedLists()
	{
		this->clear();
	}
private:
	node<E>* first=nullptr;
	int lenght=0;
	virtual void rangeCheckIndex(int index)const override {
		if (index<0 || index>this->lenght)
		{
			throw std::out_of_range("索引不合法");
		}
	}
	node<E>* nodeOf(int index) const{
		rangeCheckIndex(index);
		auto p = this->first;
		while (index) {
			index--;
			p = p->next;
		}
		return p;
	}
};