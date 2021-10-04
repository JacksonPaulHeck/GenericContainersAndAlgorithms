#include "AlgoListNode.h"
#include <cstddef>
#include <fstream>
#include <iterator> // For std::forward_iterator_tag
//#include <iostream>


// template <typename T>
// struct AlgoListNode {
//     T * data;
//     AlgoListNode *next;
// 	AlgoListNode(){
// 		next = nullptr;
// 	}
// 	AlgoListNode(T dataIn){
// 		data = dataIn;
// 		next = nullptr;
// 	}
// };

template <typename T> 
class AlgoStack;

template <typename T>
class AlgoList{
	friend class AlgoStack<T>;
    struct Iterator {
      using iterator_category = std::forward_iterator_tag;
      using difference_type   = std::ptrdiff_t;
      using value_type        = AlgoListNode<T>;
      using pointer           = AlgoListNode<T>*;
      using reference         = AlgoListNode<T>&;
      
      Iterator(pointer ptr) : m_ptr(ptr) {}
      reference operator*() const { return *m_ptr; }
      pointer operator->() { return m_ptr; }
      Iterator& operator++() { m_ptr=m_ptr->next; return *this; }  
      Iterator operator++(T) { Iterator tmp = *this; ++(*this); return tmp; }
      friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
      friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; }; 
    private: 
      pointer m_ptr;
  };
public:
	AlgoList();
	//~AlgoList();
	void insert(T);
    void push_front(T);
	void push_back(T);
	void pop_front();
	void pop_back();
	T & peek_front();
	T & peek_back();
	void print();
	void print(std::ofstream&);
	AlgoListNode<T>* search(T);
	bool empty();
    
    Iterator forward_begin() { return Iterator(head); }
    Iterator forward_end() { return Iterator(tail); }

private:
	AlgoListNode<T> * head;
	AlgoListNode<T> * tail;
};



template <typename T>
AlgoList<T>::AlgoList(){
	head = nullptr;
	tail = nullptr;
}

// template <typename T>
// AlgoList<T>::~AlgoList(){

// }

template <typename T>
bool AlgoList<T>::empty(){
	return this->head == nullptr;
}

template <typename T>
void AlgoList<T>::push_front(T dataIn)
{
		AlgoListNode<T> * node = new AlgoListNode<T>(dataIn);
		node->next = this->head;
		if (empty()) {
			this->tail = node;
		}
		this->head = node;
}

template <typename T>
void AlgoList<T>::push_back(T dataIn)
{
		AlgoListNode<T> * node = new AlgoListNode<T>(dataIn);
		if(empty()){
			this->head = node;
			return;
		}
		AlgoListNode<T> * curr = head;
		while(curr && curr->next){
			curr = curr->next;
		}

		curr->next = node;
}

template <typename T>
T & AlgoList<T>::peek_back(){
	return tail->data;
}

template <typename T>
T & AlgoList<T>::peek_front(){
	return head->data;
}

template <typename T>
void AlgoList<T>::pop_back(){
	AlgoListNode<T>* temp = tail;
	head = head->next;
	delete temp;
}

template <typename T>
void AlgoList<T>::pop_front(){
	AlgoListNode<T>* temp = head;
	head = head->next;
	delete temp;
}

template <typename T>
void AlgoList<T>::insert(T dataIn){
	if(empty()){
		push_front(dataIn);
	}else{
		if(dataIn < head->data){
			push_front(dataIn);
		}
		else if(dataIn >= tail->data){
			push_back(dataIn);
		}
		else{
			AlgoListNode<T> * curr = head;
			AlgoListNode<T> * temp = new AlgoListNode<T>(dataIn);
			while(curr != tail){
				if((temp->data < curr->next->data) && (temp->data >= curr->data)){
					AlgoListNode<T> * next = curr->next; 
					curr->next = temp;
					temp->next = next;
					break;
				}
				curr = curr->next;
			}
		}
	}
}

template <typename T>
void AlgoList<T>::print()
{
	if(empty()){
		std::cout << "The AlgoList is empty" << std::endl;
	
	}else{
		AlgoListNode<T> * curr = head;
		while(curr->next != nullptr){
			std::cout << curr->data << " -> ";
			curr = curr->next;
		}
        std::cout << curr->data << std::endl;
	}
}

template <typename T>
void AlgoList<T>::print(std::ofstream & file)
{
	if(empty()){
		file << "The AlgoList is empty" << tail;
	
	}else{
		AlgoListNode<T> * curr = head;
		while(curr->next != nullptr){
			file << curr->data << " -> ";
			curr = curr->next;
		}
        file << curr->data << std::endl;
	}
}

template <typename T>
AlgoListNode<T>* AlgoList<T>::search(T key){
	AlgoListNode<T>* node;
	bool found = false;

	node = head;

	while((!found) && (node != nullptr)){
		if(node->data == key){
			found = true;
        }
		else{
			node = node->next;
        }
	}
	return node;
}