#pragma once
#include<iostream>
#include<string>
#include<stdexcept>
#include"Lists.h"
template<typename E>
class Arrays :public Lists<E> {
public:
	Arrays(int capacity=DEFAULT_CAPACITY) :capacity(capacity>DEFAULT_CAPACITY?capacity:DEFAULT_CAPACITY),lenght(0) {
		this->dates = new E[this->capacity];
	}
	virtual int size()const override {
		return this->lenght;
	}
	virtual bool isEmpty()const override {
		return this->lenght == 0;
	}
	virtual void clear() override {
		this->capacity = 0;
		this->lenght = 0;
		delete[] this->dates;
		this->dates = nullptr;
	}

	virtual void add(E element) override {
		this->add(this->lenght, element);
	}
	virtual void add(int index, E element) override {
		rangeCheckIndex(index);
		rangeCheckCapacity();
		for (int i = lenght; i >index; i--)
		{
			this->dates[i + 1] = this->dates[i];
		}
		this->dates[index] = element;
		this->lenght++;
	}
	virtual E remove() override {
		return remove(this->lenght - 1);
	}
	virtual E remove(int index) override {
		rangeCheckIndex(index);
		E old(this->dates[index]);
		this->lenght--;
		for (int i = index; i < this->lenght; i++)
		{
			this->dates[i] = this->dates[i + 1];
		}
		return old;
	}
	virtual E get(int index)const override {
		this->rangeCheckIndex(index);
		return this->dates[index];
	}
	virtual void set(int index, E element) {
		rangeCheckIndex(index);
		E old(this->dates[index]);
		this->dates[index] = element;
	}
	virtual int indexOf(E element)const override {
		for (int i = 0; i < this->lenght; i++)
		{
			if (this->dates[i] == element)
				return i;
		}
		return Lists<E>::ELEMENT_NOT_EXISTS;
	}
	virtual bool contains(E element)const {
		return indexOf(element) != Lists<E>::ELEMENT_NOT_EXISTS;
	}
	virtual std::string toString()const {
		std::string sb;
		sb.append("size:").append(std::to_string(this->lenght)).append(" [");
		for (int i = 0; i < this->lenght; i++) {
			if (i != 0) {
				sb.append(",");
			}
			sb.append(std::to_string(this->dates[i]));
		}
		sb.append("]");
		return sb;
	}
	~Arrays() {
		this->clear();
	}
private:
	virtual void rangeCheckIndex(int index)const override {
		if (index<0||index>this->lenght)
		{
			throw std::out_of_range("索引不合法");
		}
	}
	void rangeCheckCapacity() {
		if ((lenght + 1) >= this->capacity) {
			int newCapacity = (this->capacity + (this->capacity >> 1));
			E* temp = new E[newCapacity];
			for (int i = 0; i < lenght; i++) {
				temp[i] = this->dates[i];
			}
			delete[] this->dates;
			this->dates = temp;
			this->capacity = newCapacity;
		}
	}
	int capacity;
	int lenght;
	static int const DEFAULT_CAPACITY = 10;
	E* dates;
};