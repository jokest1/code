#pragma once
#include<memory>
template<typename E>
class _base_node
{
public:
	E element;
	std::shared_ptr<_base_node> parent;
	std::shared_ptr<_base_node> left = nullptr;
	std::shared_ptr<_base_node> right = nullptr;
	
public:
	_base_node(E element, std::shared_ptr<_base_node> parent):element(element),parent(parent) {

	}
};
template<typename E>
class Tree {
public:
	int size() {
		return this->length;
	}
	bool isEmpty() {
		return this->length == 0;
	}
	void clear() {
		this->length = 0;
		this->root = nullptr;
	}
	void add(E element) {
		if (this->root == nullptr) {
			this->root = make_shared<_base_node<E>>(element, nullptr);
		}
		else {

		}
		this->length++;
	}
private:
	size_t length;
	std::shared_ptr<_base_node<E>> root = nullptr;
};