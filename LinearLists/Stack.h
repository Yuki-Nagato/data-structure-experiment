#pragma once
#include "Node.h"
#include <algorithm>

template <class T>
class LinkedStack {
public:
	LinkedStack() :root(nullptr), _size(0) {}
	~LinkedStack() {
		clear();
	}
	void push(const T& data) {
		root = new Node<T>(data, root);
		++_size;
	}
	T& peek() {
		return root->data;
	}
	T pop() {
		T rst(root->data);
		Node<T>* p = root;
		root = root->next;
		delete p;
		--_size;
		return rst;
	}
	size_t size() const {
		return _size;
	}
	bool empty() const {
		return _size == 0;
	}
	void clear() {
		while (root != nullptr) {
			Node<T>* p = root;
			root = root->next;
			delete p;
		}
		_size = 0;
	}
private:
	Node<T>* root;
	size_t _size;
};

template <class T>
class ArrayStack {
private:
	T * _data;
	size_t _size;
	size_t _max_size;
public:
	ArrayStack(size_t size=8) : _size(0), _max_size(size) {
		_data = new T[size];
	}
	~ArrayStack() {
		delete[] _data;
	}
	void push(const T& data) {
		if (_size >= _max_size) {
			T* newData = new T[_max_size * 2];
			std::copy(_data, _data + _max_size, newData);
			delete[] _data;
			_data = newData;
			_max_size *= 2;
		}
		_data[_size++] = data;
	}
	T& peek() {
		return _data[_size - 1];
	}
	T pop() {
		return _data[--_size];
	}
	size_t size() const {
		return _size;
	}
	bool empty() const {
		return _size == 0;
	}
};