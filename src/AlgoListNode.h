#include <iostream>

template <typename T> 
class AlgoList;

template <typename T>
class AlgoListNode{
	friend class AlgoList<T>;
public:
	AlgoListNode(T);
	T getData();
    friend bool operator== (const AlgoListNode<T>& a, const T b) { return a.data == b; };
	friend std::ostream& operator<<(std::ostream& a, const AlgoListNode<T>& b){
		a << b.data;
		return a;
	};
	friend std::istream& operator>>(std::istream& a, AlgoListNode<T>& b){
		a >> b.data;
		return a;
	};
private:
	T data;
	AlgoListNode* next;
};

template <typename T>
AlgoListNode<T>::AlgoListNode(T dataIn){
	data = dataIn;
	next = nullptr;
}