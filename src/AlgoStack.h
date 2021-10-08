#include "AlgoVector.h"
#include <fstream>

template<typename T>
class AlgoStack {
private:
    int length;
    AlgoVector<T> data;
public:
    AlgoStack();
    // ~AlgoStack();
    bool empty();
    void clear();
    void push(const T &);
    void pop();
    T & top();
    int size() const;
    void print();
    void print(std::ofstream&);
};

template<typename T>
AlgoStack<T>::AlgoStack() {
    data = AlgoVector<T>();
    length = 0;
}

template<typename T>
bool AlgoStack<T>::empty(){
    return length == 0;
}

template<typename T>
void AlgoStack<T>::clear() {
    while(length == 0){
        data.pop_back();
    }
    length = 0;
}

template<typename T>
void AlgoStack<T>::push(const T &it) {
    data.push_back(it);
    length++;
}

template<typename T>
void AlgoStack<T>::pop() {
    if (length != 0) {
        data.pop_back();
        length--;
    }
}

template<typename T>
T & AlgoStack<T>::top() {
    return data[data.size()-1];
}

template<typename T>
int AlgoStack<T>::size() const {
    return length;
}

template<typename T>
void AlgoStack<T>::print(){
    data.print();
}

template<typename T>
void AlgoStack<T>::print(std::ofstream & file){
    data.print(file);
}