#pragma once

template <class T>
class Node {
public:
	T data;
	Node<T>* next;
	Node(const T& data = T(), Node<T>* next = nullptr) :data(data), next(next) {}
};