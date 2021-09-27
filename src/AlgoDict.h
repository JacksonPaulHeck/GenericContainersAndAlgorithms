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
public:
	JPDict();
	~JPDict();
	void insert(T);
	void print();
	JPTreeNode<T>* search(T);
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
