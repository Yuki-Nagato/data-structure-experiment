#pragma once

template <class T>
class CircularQueue {
private:
	T * _data;
	size_t max_size;
	size_t front, end;
public:
	CircularQueue(size_t size = 8) : max_size(size+1), front(0), end(0) {
		_data = new T[max_size];
	}
	~CircularQueue() {
		delete[] _data;
	}
	bool push(const T& data) {
		if ((end + 1) % max_size == front)
			return false;
		_data[end] = data;
		end = (end + 1) % max_size;
		return true;
	}
	T& peek() {
		return _data[front];
	}
	T pop() {
		T rst(_data[front]);
		front = (front + 1) % max_size;
		return rst;
	}
	size_t size() const {
		return (end - front + max_size) % max_size;
	}
	bool empty() const {
		return front == end;
	}
};