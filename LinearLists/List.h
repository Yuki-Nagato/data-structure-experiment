#pragma once
#include "Node.h"
#include <vector>
#include <iostream>

template <class T>
class ArrayList {
public:
	ArrayList(size_t size = 8) : _max_size(size), _size(0) {
		_data = new T[size];
	}
	ArrayList(const std::vector<T>& dataList) : _max_size(dataList.size()), _size(dataList.size()) {
		_data = new T[_size];
		for (int i = 0; i < _size; i++) {
			_data[i] = dataList[i];
		}
	}
	~ArrayList() {
		delete[] _data;
	}
	bool insert(const T& data, const size_t position) {
		if (position<1 || position>_size + 1)
			return false;
		if (_size < _max_size) {
			for (size_t i = _size; i >= position; i--) {
				_data[i] = _data[i - 1];
			}
			_data[position - 1] = data;
		}
		else {
			_max_size *= 2;
			T* newdata = new T[_max_size];
			for (size_t i = 0; i < position - 1; i++) {
				newdata[i] = _data[i];
			}
			newdata[position - 1] = data;
			for (size_t i = position - 1; i < _size; i++) {
				newdata[i + 1] = _data[i];
			}
			delete[] _data;
			_data = newdata;
		}
		++_size;
		return true;
	}
	bool remove(const size_t position) {
		if (position<1 || position>_size)
			return false;
		for (size_t i = position; i < _size; i++)
			_data[i - 1] = _data[i];
		--_size;
		return true;
	}
	size_t size() const {
		return _size;
	}
	bool empty() const {
		return _size == 0;
	}
	void clear() {
		_size = 0;
	}
	T& get(const size_t position) {
		return _data[position - 1];
	}
	void add(const T& data) {
		insert(data, _size + 1);
	}
	friend std::ostream& operator<< (std::ostream& os, const ArrayList<T>& list) {
		for (int i = 0; i < list._size-1; i++) {
			os << list._data[i] << ' ';
		}
		os << list._data[list._size - 1];
		return os;
	}
private:
	T * _data;
	size_t _size;
	size_t _max_size;
};

template <class T>
class LinkedList {
public:
	LinkedList() : _size(0), head(new Node<T>()) {}
	LinkedList(const std::vector<T>& dataList) : _size(dataList.size()), head(new Node<T>()) {
		for (int i = dataList.size(); i > 0; i--) {
			addFront(dataList[i - 1]);
		}
	}
	~LinkedList() {
		clear();
		delete head;
	}
	void add(const T& data) {
		insert(data, _size + 1);
	}
	void addFront(const T& data) {
		head->next = new Node<T>(data, head->next);
	}
	bool insert(const T& data, const size_t position) {
		if (position<1 || position>_size + 1)
			return false;
		Node<T>* p = head;
		for (size_t i = 1; i < position; ++i)
			p = p->next;
		p->next = new Node<T>(data, p->next);
		++_size;
		return true;
	}
	bool remove(const size_t position) {
		if (position<1 || position>_size)
			return false;
		Node<T>* p = head;
		for (size_t i = 1; i < position; ++i)
			p = p->next;
		Node<T>* q = p->next;
		p->next = q->next;
		delete q;
		return true;
	}
	void clear() {
		Node<T>* p = head, *q = head->next;
		while (q != nullptr) {
			p = q->next;
			delete q;
			q = p;
		}
	}
	size_t size() const {
		return _size;
	}
	bool empty() const {
		return _size == 0;
	}
	T& get(const size_t position) {
		Node<T>* p = head;
		for (size_t i = 0; i<position; ++i) {
			p = p->next;
		}
		return p->data;
	}
	void reverse() {
		if (_size <= 1)
			return;
		Node<T>* p = head->next, *q = p->next;
		p->next = nullptr;
		while ((p = q) != nullptr) {
			q = q->next;
			p->next = head->next;
			head->next = p;
		}
	}
	friend std::ostream& operator<< (std::ostream& os, const LinkedList<T>& list) {
		Node<T>* p = list.head->next;
		while (p != nullptr) {
			os << p->data;
			p = p->next;
			if (p != nullptr)
				os << ' ';
		}
		return os;
	}

private:
	size_t _size;
	Node<T>* head;
};