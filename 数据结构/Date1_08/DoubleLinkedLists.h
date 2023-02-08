#pragma once
#include"Lists.h"
#include<string>
#include<exception>
template<typename E>
struct Base_Node {
	E element;
	Base_Node* prev;
	Base_Node* next;
	Base_Node(Base_Node* prev, E element, Base_Node* next) :prev(prev), element(element), next(next){}
	std::string toString() {
		std::string buffer;
		buffer.append((prev == nullptr ? "null" : std::to_string(prev->element))).append("<-").append(std::to_string(element)).append("->").append((next == nullptr ? "null" : std::to_string(next->element)));
		return buffer;
	}
};

template <typename E >
class DoubleLinkedLists :public Lists<E> {
public:
	using DateType = Base_Node<E>;
private:
	DateType* first=nullptr;
	DateType* last=nullptr;
	size_t lenght=0;
public:
	virtual int size()const {
		return this->lenght;
	}
	virtual bool isEmpty()const {
		return this->lenght == 0;
	}
	virtual void clear() {
		auto p = this->first;
		while (p)
		{
			auto q = p->next;
			delete p;
			p = q;
		}
		this->first = nullptr;
		this->last = nullptr;
		this->lenght = 0;
	}

	virtual void add(E element) {
		this->add(this->lenght, element);
	}
	virtual void add(int index, E element) {
		if (this->lenght == 0) {
			this->first = new DateType(nullptr, element, nullptr);
			this->last = this->first;
		}
		else if (index == 0) {
			this->first->prev = new DateType(nullptr, element, this->first);
			this->first = this->first->prev;
		}
		else if (index == this->lenght) {
			this->last->next = new DateType(this->last, element, nullptr);
			this->last = this->last->next;
		}
		else {
			auto p = node(index);
			auto prev = p->prev;
			prev->next = new DateType(prev, element, p);
			p->prev = prev->next;
		}
		this->lenght++;
	}
	virtual E remove() {
		return this->remove(this->lenght - 1);
	}
	virtual E remove(int index){
		E old = get(index);
		if (index == 0) {
			auto p = this->first;
			first = first->next;
			first->prev = nullptr;
			delete p;
		}
		else if (index == this->lenght - 1) {
			auto p = this->last;
			last = last->prev;
			last->next = nullptr;
			delete p;
		}
		else {
			auto p = node(index);
			auto prev = p->prev;
			auto next = p->next;
			prev->next = next;
			next->prev = prev;
			delete p;
		}
		this->lenght--;
		return old;
	}
	virtual E get(int index)const {
		return node(index)->element;
	}
	virtual void set(int index, E element) {
		node(index)->element = element;
	}
	virtual int indexOf(E element)const {
		auto p = this->first;
		int i = 0;
		while (p)
		{
			if (p->element==element)
			{
				return i;
			}
			i++;
		}
		return Lists<E>::ELEMENT_NOT_EXISTS;
	}
	virtual bool contains(E element)const {
		return indexOf(element)!= Lists<E>::ELEMENT_NOT_EXISTS;
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
		if (index<0 || index>this->lenght) {
			throw std::out_of_range("Ô½½çÁË");
		}
	}
	DateType* node(int index) const{
		this->rangeCheckIndex(index);
		if (index <= (this->lenght >> 1))
		{
			auto p = this->first;
			while (index)
			{
				index--;
				p = p->next;
			}
			return p;
		}
		else {
			auto p = this->last;
			index = this->lenght - 1 - index;
			while (index)
			{
				index--;
				p = p->prev;
			}
			return p;
		}
	}
};
template<typename E>
std::ostream& operator<<(std::ostream& os, const DoubleLinkedLists<E>& arr) {
	os << arr.toString();
	return os;
}