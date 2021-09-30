#include "AlgoList.h"
#include <fstream>

template<typename T>
class AlgoStack {
private:
    int length;
    AlgoList<T> *data;
public:
    AlgoStack();
    ~AlgoStack();
    bool empty();
    void clear();
    void push(const T &);
    T pop();
    T & top();
    int size() const;
    void print();
    void print(std::ofstream&);
};

template<typename T>
AlgoStack<T>::AlgoStack() {
    data = new AlgoList<T>;
    length = 0;
}
template<typename T>
AlgoStack<T>::~AlgoStack() {
    delete data;
}
template<typename T>
bool AlgoStack<T>::empty(){
    return data->empty();
}

template<typename T>
void AlgoStack<T>::clear() {
    while(!data->empty()){
        data->pop_front();
    }
    length = 0;
}

template<typename T>
void AlgoStack<T>::push(const T &it) {
    data->push_front(it);
    length++;
}

template<typename T>
T AlgoStack<T>::pop() {
    std::cout << "POP FUNCTION CALL --------------------------- POP FUNCTION CALL " << std::endl << "\t" << data->empty() << std::endl;
    if (!data->empty()) {
        length--;
        return data->pop_front();
    }
    return T();
}

template<typename T>
T & AlgoStack<T>::top() {
    std::cout << "TOP FUNCTION CALL --------------------------- TOP FUNCTION CALL " << std::endl << "\t"<< data->empty() << std::endl;
    return data->peek_front();
}

template<typename T>
int AlgoStack<T>::size() const {
    return length;
}

template<typename T>
void AlgoStack<T>::print(){
    data->print();
}

template<typename T>
void AlgoStack<T>::print(std::ofstream & file){
    data->print(file);
}