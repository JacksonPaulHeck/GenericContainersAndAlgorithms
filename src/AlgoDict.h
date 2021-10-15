#include "AlgoStack.h"
#include <bits/stdc++.h>
#include <cstddef>

template <typename T> class AlgoTreeNode {
public:
  T data;
  AlgoTreeNode *left;
  AlgoTreeNode *right;
  int height;
  friend bool operator==(const AlgoTreeNode<T> &a, const T b) {
    return a.data == b;
  };
  friend std::ostream &operator<<(std::ostream &a, const AlgoTreeNode<T> &b) {
    a << b.data;
    return a;
  };
  friend std::istream &operator>>(std::istream &a, AlgoTreeNode<T> &b) {
    a >> b.data;
    return a;
  };
};

template <typename T> class AlgoDict {
  struct Iterator {
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = AlgoTreeNode<T>;
    using pointer = AlgoTreeNode<T> *;
    using reference = AlgoTreeNode<T> &;

    Iterator(pointer ptr) : m_ptr(ptr) {
      fillStack(m_ptr);
      next();
    }
    reference operator*() const { return (*m_ptr); }
    pointer operator->() { return m_ptr; }
    Iterator &operator++() {
      next();
      return *this;
    }
    Iterator operator++(int) {
      Iterator tmp = *this;
      ++(*this);
      return tmp;
    }
    friend bool operator==(const Iterator &a, const Iterator &b) {
      return a.m_ptr == b.m_ptr;
    };
    friend bool operator==(const Iterator &a, const T b) {
      return a.m_ptr->data == b;
    };
    friend bool operator!=(const Iterator &a, const Iterator &b) {
      return a.m_ptr != b.m_ptr;
    };
    friend std::ofstream &operator<<(std::ofstream &a, const Iterator &b) {
      a << *(b.m_ptr);
      return a;
    };
    friend std::istream &operator>>(std::istream &a, Iterator &b) {
      a >> *(b.m_ptr);
      return a;
    };

  private:
    pointer m_ptr;
    AlgoStack<pointer> m_stack;

    void fillStack(pointer node) {
      if (node != nullptr) {
        fillStack(node->right);
        m_stack.push(node);
        fillStack(node->left);
      }
      return;
    }
    void next() {
      if (!m_stack.empty()) {
        m_ptr = m_stack.top();
        m_stack.pop();
      } else {
        m_ptr = nullptr;
      }
    }
  };

public:
  AlgoDict();
  ~AlgoDict();
  void insert(T);
  void print();
  void print(std::ofstream &);
  AlgoTreeNode<T> *search(T);
  Iterator begin() { return Iterator(root); }
  Iterator end() { return Iterator(nullptr); }
  int size();

private:
  AlgoTreeNode<T> *root;
  int length;
  bool isEmpty();
  AlgoTreeNode<T> *insert(AlgoTreeNode<T> *, T);
  void print(AlgoTreeNode<T> *, int);
  void print(AlgoTreeNode<T> *, int, std::ofstream &);
  void destroy(AlgoTreeNode<T> *);
  int max(int, int);
  int balance(AlgoTreeNode<T> *);
  AlgoTreeNode<T> *rightRotate(AlgoTreeNode<T> *);
  AlgoTreeNode<T> *leftRotate(AlgoTreeNode<T> *);
  int height(AlgoTreeNode<T> *);
};

template <typename T> AlgoDict<T>::AlgoDict() {
  this->root = NULL;
  this->length = 0;
}

template <typename T> AlgoDict<T>::~AlgoDict() { destroy(root); }

template <typename T> void AlgoDict<T>::destroy(AlgoTreeNode<T> *node) {
  if (node != nullptr) {
    destroy(node->left);
    destroy(node->right);
    delete node;
  }
}

template <typename T> void AlgoDict<T>::insert(T dataIn) {
  root = insert(root, dataIn);
  length++;
}

template <typename T> int AlgoDict<T>::max(int a, int b) {
  return (a > b) ? a : b;
}

template <typename T> int AlgoDict<T>::balance(AlgoTreeNode<T> *node) {
  if (node == nullptr) {
    return 0;
  }
  return height(node->left) - height(node->right);
}

template <typename T>
AlgoTreeNode<T> *AlgoDict<T>::rightRotate(AlgoTreeNode<T> *node) {
  AlgoTreeNode<T> *left = node->left;
  AlgoTreeNode<T> *right = left->right;

  // Perform rotation
  left->right = node;
  node->left = right;

  // Update heights
  node->height = 1 + max(height(node->left), height(node->right));
  left->height = 1 + max(height(left->left), height(left->right));

  return left;
}

template <typename T>
AlgoTreeNode<T> *AlgoDict<T>::leftRotate(AlgoTreeNode<T> *node) {
  AlgoTreeNode<T> *right = node->right;
  AlgoTreeNode<T> *left = right->left;

  // Perform rotation
  right->left = node;
  node->right = left;

  // Update heights
  node->height = 1 + max(height(node->left), height(node->right));
  right->height = 1 + max(height(right->left), height(right->right));

  return right;
}

template <typename T> int AlgoDict<T>::height(AlgoTreeNode<T> *node) {
  if (node == nullptr) {
    return 0;
  }
  return node->height;
}

template <typename T>
AlgoTreeNode<T> *AlgoDict<T>::insert(AlgoTreeNode<T> *node, T dataIn) {
  if (node == nullptr) {
    AlgoTreeNode<T> *temp = new AlgoTreeNode<T>;
    temp->data = dataIn;
    temp->left = nullptr;
    temp->right = nullptr;
    temp->height = 1;
    node = temp;
    return node;
  } else if (node->data < dataIn) {
    node->right = insert(node->right, dataIn);
  } else if (node->data > dataIn) {
    node->left = insert(node->left, dataIn);
  } else {
    return node;
  }
  node->height = 1 + max(height(node->left), height(node->right));
  int bal = balance(node);

  if (bal > 1 && dataIn < node->left->data) {
    return rightRotate(node);
  }
  if (bal < -1 && dataIn > node->right->data) {
    return leftRotate(node);
  }
  if (bal > 1 && dataIn > node->left->data) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }
  if (bal < -1 && dataIn < node->right->data) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }
  return node;
}

template <typename T> void AlgoDict<T>::print() {
  if (root == nullptr) {
    std::cout << "Nothing in tree" << std::endl;
  }
  print(root, 0);
}

template <typename T> void AlgoDict<T>::print(std::ofstream &file) {
  if (root == nullptr) {
    file << "Nothing in tree" << std::endl;
  }
  print(root, 0, file);
}

template <typename T>
void AlgoDict<T>::print(AlgoTreeNode<T> *node, int space) {
  if (node == nullptr)
    return;
  space += 10;

  print(node->right, space);

  std::cout << std::endl;
  for (int i = 10; i < space; i++) {
    std::cout << " ";
  }
  std::cout << node->data << std::endl;

  print(node->left, space);
}

template <typename T>
void AlgoDict<T>::print(AlgoTreeNode<T> *node, int space, std::ofstream &file) {
  if (node == nullptr)
    return;
  space += 10;

  print(node->right, space, file);

  file << std::endl;
  for (int i = 10; i < space; i++) {
    file << " ";
  }
  file << node->data << std::endl;

  print(node->left, space, file);
}

template <typename T> bool AlgoDict<T>::isEmpty() { return root != nullptr; }

template <typename T> int AlgoDict<T>::size() { return length; }