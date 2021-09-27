#include "AlgoListNode.h"

template <typename T>
class AlgoList{
public:
	AlgoList();
	~AlgoList();
	void insert(T);
    void push_front(T);
	void push_back(T);
	void print();
	AlgoListNode<T>* search(T);

private:
	AlgoListNode<T> *head;
	AlgoListNode<T> *tail;
	bool isEmpty();
};



template <typename T>
AlgoList<T>::AlgoList(){
	head = NULL;
	tail = NULL;
}

template <typename T>
AlgoList<T>::~AlgoList(){
	if (!isEmpty()){    
      AlgoListNode<T> *curr = head;
      AlgoListNode<T> *temp;

      while ( curr != 0 ){  
         temp = curr;
         curr = curr->next;
         delete temp;
      }
   }
}

template <typename T>
bool AlgoList<T>::isEmpty()
{
	if(head == NULL && tail == NULL){
		return 1;
    }
	else{
		return 0;
    }
}

template <typename T>
void AlgoList<T>::push_front(T dataIn)
{
	if(isEmpty()){
		AlgoListNode<T> * temp = new AlgoListNode<T>(dataIn);
		head = temp;
		tail = temp;
	}else{
		AlgoListNode<T> * temp = new AlgoListNode<T>(dataIn);
		temp->next = head;
		head = temp;
	}
}

template <typename T>
void AlgoList<T>::push_back(T dataIn)
{
	if(isEmpty()){
		AlgoListNode<T> * temp = new AlgoListNode<T>(dataIn);
		head = temp;
		tail = temp;
	}else{
		AlgoListNode<T> * temp = new AlgoListNode<T>(dataIn);
		tail->next = temp;
		tail = temp;
	}
}

template <typename T>
void AlgoList<T>::insert(T dataIn){
	if(isEmpty()){
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
	if(isEmpty()){
		std::cout << "The AlgoList is empty" << tail;
	
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
AlgoListNode<T>* AlgoList<T>::search(T key){
	AlgoListNode<T>* node;
	bool found = false;

	node = head;

	while((!found) && (node != NULL)){
		if(node->data == key){
			found = true;
        }
		else{
			node = node->next;
        }
	}
	return node;
}