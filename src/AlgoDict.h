#include <cstddef>
#include <bits/stdc++.h>

template <typename T>
class JPTreeNode{
	public:
		T data;
		struct JPTreeNode * left;
		struct JPTreeNode * right;
		int height;
		friend std::ostream& operator<<(std::ostream& a, const JPTreeNode<T>& b){
			a << b.data;
			return a;
		};
		friend std::istream& operator>>(std::istream& a, JPTreeNode<T>& b){
			a >> b.data;
			return a;
		};
};

template <typename T>
class JPDict{
	struct Iterator {
		using iterator_category = std::forward_iterator_tag;
		using difference_type   = std::ptrdiff_t;
		using value_type        = JPTreeNode<T>;
		using pointer           = JPTreeNode<T>*;
		using reference         = JPTreeNode<T>&;

		Iterator(pointer ptr) : m_ptr(ptr) {
			fillStack(m_ptr);
			next();
		}
		reference operator*() const { return (*m_ptr); }
		pointer operator->() { return m_ptr; }
		Iterator& operator++() {
			next();
			return *this; 
		}  
		Iterator operator++(T) { Iterator tmp = *this; ++(*this); return tmp; }
		friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
		friend bool operator== (const Iterator& a, const T& b) { return a.m_ptr->data == b; };
		friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; }; 
		friend std::ostream& operator<<(std::ostream& a, const Iterator& b){
			a << *(b.m_ptr);
			return a;
		};
		friend std::istream& operator>>(std::istream& a, Iterator& b){
			a >> *(b.m_ptr);
			return a;
		};

		private: 
			pointer m_ptr;
			std::stack<pointer> m_stack;

			void fillStack(pointer node){
				if(node != nullptr){
					fillStack(node->right);
					m_stack.push(node);
					fillStack(node->left);
				}
				return;
			}
			void next() {				
				if(!m_stack.empty()){
					m_ptr = m_stack.top();
					m_stack.pop();
				}else {
					m_ptr = nullptr;
				}
			}
			
	};
public:
	JPDict();
	~JPDict();
	void insert(T);
	void print();
	JPTreeNode<T>* search(T);
	Iterator forward_begin() { return Iterator(root); }
    Iterator forward_end() { return Iterator(nullptr); }
private:
	JPTreeNode<T> * root;
	bool isEmpty();
	JPTreeNode<T>* insert(JPTreeNode<T>*, T);
	void print(JPTreeNode<T>*, int);
	void destroy(JPTreeNode<T>*);
	int max (int, int);
	int balance (JPTreeNode<T>*);
	JPTreeNode<T>* rightRotate(JPTreeNode<T> *);
	JPTreeNode<T>* leftRotate(JPTreeNode<T> *);
	int height(JPTreeNode<T> *);
};

template<typename T>
JPDict<T>::JPDict(){
	this->root = NULL;
}

template<typename T>
JPDict<T>::~JPDict(){
	destroy(root);
}

template <typename T>
void JPDict<T>::destroy(JPTreeNode<T>* node){
	if(node != nullptr){
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}

template <typename T>
void JPDict<T>::insert(T dataIn){
	root = insert(root, dataIn);
}

template <typename T>
int JPDict<T>::max(int a, int b) {
	return (a > b)? a : b;
}

template <typename T>
int JPDict<T>::balance(JPTreeNode<T> * node){
	if(node == nullptr){
		return 0;
	}
	return height(node->left) - height(node->right);

}

template <typename T>
JPTreeNode<T>* JPDict<T> :: rightRotate(JPTreeNode<T> * node){
    JPTreeNode<T> * left = node->left;
    JPTreeNode<T> * right = left->right;
 
    // Perform rotation
    left->right = node;
    node->left = right;
 
    // Update heights
	node->height = 1 + max(height(node->left), height(node->right));
    left->height = 1 + max(height(left->left), height(left->right));

	return left;
}

template <typename T>
JPTreeNode<T>* JPDict<T> :: leftRotate(JPTreeNode<T> * node){
    JPTreeNode<T> * right = node->right;
    JPTreeNode<T> * left = right->left;
 
    // Perform rotation
    right->left = node;
    node->right = left;
 
    // Update heights
	node->height = 1 + max(height(node->left), height(node->right));
    right->height = 1 + max(height(right->left), height(right->right));

	return right;
}

template <typename T>
int JPDict<T> :: height(JPTreeNode<T>* node){
    if (node == nullptr){
        return 0;
	}
    return node->height;
}

template <typename T>
JPTreeNode<T>* JPDict<T>::insert(JPTreeNode<T> * node, T dataIn){
	if(node == nullptr){
		JPTreeNode<T> * temp = new JPTreeNode<T>;
		temp->data = dataIn;
		temp->left = nullptr;
		temp->right = nullptr;
		temp->height = 1;
		node = temp;
		return node;
	}else if (node->data < dataIn){
		node->right = insert(node->right, dataIn);
	}else if (node->data > dataIn) {
		node->left = insert(node->left, dataIn);
	}else{
		return node;
	}
	node->height = 1 + max(height(node->left), height(node->right));
	int bal = balance(node);

	if(bal > 1 && dataIn < node->left->data){
	 	return rightRotate(node);
	}
	if(bal < -1 && dataIn > node->right->data){
		return leftRotate(node);
	}
	if(bal > 1 && dataIn > node->left->data){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if(bal < -1 && dataIn < node->right->data){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}

template <typename T>
void JPDict<T> :: print(){
	if(root == nullptr){
		std::cout << "Nothing in tree" << std::endl;
	}
	print(root, 0);
}

template <typename T>
void JPDict<T> :: print(JPTreeNode<T> * node, int space){
    if (node == nullptr)
        return;
    space += 10;
 
    print(node->right, space);
 
    std::cout << std::endl;
    for (int i = 10; i < space; i++){
        std::cout << " ";
	}
    std::cout << node->data << std::endl;

    print(node->left, space);
}

template <typename T>
bool JPDict<T> :: isEmpty(){
	return root != nullptr;
}
