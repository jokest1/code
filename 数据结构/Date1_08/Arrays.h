#pragma once
#include"Lists.h"
#include<string>
#include<iostream>
#include<exception>
template<typename E>
class Arrays :public Lists<E> {
public:
	using  DateType =E;
public:
	Arrays(int capacity=10) :length(0), capacity(capacity >+ 10 ? capacity : 10) {
		this->dates = new DateType[this->capacity];
	}
	virtual int size()const {
		return this->length;
	}
	virtual bool isEmpty()const {
		return this->length == 0;
	}
	virtual void clear() {
		this->length = 0;
		this->capacity = 0;
		delete[] this->dates;
		this->dates = nullptr;
	}

	virtual void add(DateType element) {
		add(this->length, element);
	}
	virtual void add(int index, DateType element) {
		rangeCheckIndex(index);
		rangeCheckCapacity();
		for (int i = this->length; i > index; i--) {
			this->dates[i] = this->dates[i - 1];
		}
		this->dates[index] = element;
		this->length++;
	}
	virtual DateType remove() {
		return this->remove(this->length - 1);
	}
	virtual DateType remove(int index) {
		DateType old = get(index);
		this->length--;
		for (int i = index; i < this->length; i++)
		{
			this->dates[i] = this->dates[i + 1];
		}
		return old;
	}
	virtual DateType get(int index)const {
		return this->dates[index];
	}
	virtual void set(int index, DateType element) {
		this->dates[index] = element;
	}
	virtual int indexOf(DateType element)const {
		for (int i = 0; i < this->length; i++)
		{
			if (this->dates[i] == element) {
				return i;
			}
		}
		return Lists<E>::ELEMENT_NOT_EXISTS;
	}
	virtual bool contains(DateType element)const {
		return this->indexOf(element)!= Lists<E>::ELEMENT_NOT_EXISTS;
	}
	virtual std::string toString()const {
		std::string temp;
		temp.append("size:").append(std::to_string(this->length)).append(" [");
		for (int i = 0; i < this->length; i++)
		{
			if (i != 0) {
				temp.append(",");
			}
			temp.append(std::to_string(this->dates[i]));
		}
		temp.append("]");
		return temp;
	}
	~Arrays() {
		if (this->dates != nullptr) {
			this->clear();
		}
	}
protected:
	virtual void rangeCheckIndex(int index)const {
		if (index<0 || index>this->length) {
			throw std::out_of_range("Ô½½çÁË");
		}
	}
private:
	int length;
	int capacity;
	DateType* dates=nullptr;
	void rangeCheckCapacity() {
		if (this->length + 1 >= this->capacity) {
			this->capacity = ((this->capacity) + (this->capacity >> 1));
			DateType* temp = new DateType[this->capacity];
			for (int i = 0; i <this->length; i++)
			{
				temp[i] = this->dates[i];
			}
			delete[] this->dates;
			this->dates = temp;
		}
	}
};
template<typename E>
std::ostream& operator<<(std::ostream& os,const Arrays<E>& arr) {
	os << arr.toString();
	return os;
}
