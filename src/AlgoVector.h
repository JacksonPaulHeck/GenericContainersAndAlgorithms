#ifndef _ALGOVECTOR_H
#define _ALGOVECTOR_H

#include <iostream>
#include <exception>

struct outOfRangeVector : std::exception {
    const char *what() const noexcept override { return "Index is out of range for AlgoVector!"; }
};

template <typename T> class AlgoVector {
    struct ForwardIterator {
      using iterator_category = std::forward_iterator_tag;
      using difference_type   = std::ptrdiff_t;
      using value_type        = T;
      using pointer           = T*;
      using reference         = T&;
      
      ForwardIterator(pointer ptr) : m_ptr(ptr) {}
      reference operator*() const { return *m_ptr; }
      pointer operator->() { return m_ptr; }
      ForwardIterator& operator++() { m_ptr++; return *this; }
      ForwardIterator operator++(int) { ForwardIterator tmp = *this; ++(*this); return tmp; }
      friend bool operator== (const ForwardIterator& a, const ForwardIterator& b) { return a.m_ptr == b.m_ptr; };
      friend bool operator!= (const ForwardIterator& a, const ForwardIterator& b) { return a.m_ptr != b.m_ptr; };  
      friend std::ofstream& operator<<(std::ofstream& a, const ForwardIterator& b){
        a << *(b.m_ptr);
        return a;
      };
      friend std::istream& operator>>(std::istream& a, ForwardIterator& b){
        a >> *(b.m_ptr);
        return a;
      };   
    private:
      pointer m_ptr;
  };

   struct RandomAccessIterator {
      using iterator_category = std::random_access_iterator_tag;
      using difference_type   = std::ptrdiff_t;
      using value_type        = T;
      using pointer           = T*;
      using reference         = T&;
      
      RandomAccessIterator(pointer ptr) : m_ptr(ptr) {}

      reference operator*() const { return *m_ptr; }
      pointer operator->() { return m_ptr; }
      
      RandomAccessIterator& operator++() { m_ptr++; return *this; }
      RandomAccessIterator operator++(int) { RandomAccessIterator tmp = *this; ++(*this); return tmp; }

      RandomAccessIterator& operator--() { m_ptr--; return *this; }
      RandomAccessIterator operator--(int) { RandomAccessIterator tmp = *this; --(*this); return tmp; }

      RandomAccessIterator operator+(const difference_type& movement){pointer oldPtr = m_ptr;m_ptr+=movement;RandomAccessIterator temp(*this);m_ptr = oldPtr;return temp;}
      RandomAccessIterator operator-(const difference_type& movement){pointer oldPtr = m_ptr;m_ptr-=movement;RandomAccessIterator temp(*this);m_ptr = oldPtr;return temp;}
      difference_type operator-(const RandomAccessIterator& rawIterator){return std::distance(rawIterator.m_ptr,this->m_ptr);}

      bool operator< (RandomAccessIterator& b) { 
        if(b.m_ptr == nullptr){
            return false;
        }
        return m_ptr < b.m_ptr;
      };
      bool operator> (RandomAccessIterator& b) { 
        if(b.m_ptr == nullptr){
            return false;
        }
        return m_ptr < b.m_ptr;
      };

    //   friend bool operator< (RandomAccessIterator& a, RandomAccessIterator& b) { return a < b; };
    //   friend bool operator> (RandomAccessIterator& a, RandomAccessIterator& b) { return a > b; };

      friend bool operator== (const RandomAccessIterator& a, const RandomAccessIterator& b) { return a.m_ptr == b.m_ptr; };
      friend bool operator!= (const RandomAccessIterator& a, const RandomAccessIterator& b) { return a.m_ptr != b.m_ptr; };
      friend bool operator<= (const RandomAccessIterator& a, const RandomAccessIterator& b) { return a.m_ptr <= b.m_ptr; };
      friend bool operator>= (const RandomAccessIterator& a, const RandomAccessIterator& b) { return a.m_ptr >= b.m_ptr; };


      RandomAccessIterator& operator=(const RandomAccessIterator& rawIterator) = default;
      RandomAccessIterator& operator=(RandomAccessIterator* ptr){m_ptr = ptr;return (*this);}

      friend std::ostream& operator<<(std::ostream& a, const RandomAccessIterator& b){
        if(b != nullptr){
          a << *(b.m_ptr);
        }
        return a;
      };
      friend std::istream& operator>>(std::istream& a, RandomAccessIterator& b){
        if(b != nullptr){
          a >> *(b.m_ptr);
        }
        return a;
      };
    private:
      pointer m_ptr;
  };

  private:
      T *data;
      int capacity;
      int max_capacity;
      void resize();
  public:
      AlgoVector();
      explicit AlgoVector(int);
      AlgoVector(AlgoVector<T> &);
      ~AlgoVector();
      AlgoVector<T> & operator=(const AlgoVector<T> &);
      void push_back(const T &);
      void pop_back();
      T & operator[](int) const;
      int size();
      int max_size();
      T & at(int index) const;
      void print();
      void print(std::ofstream&);

      RandomAccessIterator begin() { return RandomAccessIterator(&data[0]); }
      RandomAccessIterator end() { return RandomAccessIterator(&data[capacity]); }
      ForwardIterator forward_begin(){ return ForwardIterator(&data[0]);}
      ForwardIterator forward_end() { return ForwardIterator(&data[capacity]);}
};

template <typename T> AlgoVector<T>::AlgoVector() { // Empty Constructor
  max_capacity = 1;
  capacity = 0;
  data = new T[max_capacity];
}

template <typename T>
AlgoVector<T>::AlgoVector(int size) { // Constructor based off of defined size
  capacity = size;
  max_capacity = size;
  data = new T[size];
}

template <typename T>
AlgoVector<T>::AlgoVector(AlgoVector<T> &vector) { // Copy Constructor
  capacity = vector.capacity;
  max_capacity = vector.max_capacity;
  data = new T[max_capacity];
  for (int i = 0; i < capacity; i++) {
    data[i] = vector[i];
  }
}

template <typename T> AlgoVector<T>::~AlgoVector() { // Destructor
  if (data != nullptr) {
    delete[] data;
  }
}

template <typename T>
AlgoVector<T> &AlgoVector<T>::operator=(
    const AlgoVector<T> &algoVector) { // Assignment operator from another AlgoVector
    if (this != &algoVector) {
        delete[] data;
        capacity = algoVector.capacity;
        max_capacity = algoVector.max_capacity;
        data = new T[max_capacity];
        for (int i = 0; i < capacity; i++) {
        data[i] = algoVector.data[i];
        }
    }
    return *this;
}

template <typename T>
void AlgoVector<T>::resize() { // resize used if the vector needs to grow
  T *temp = new T[max_capacity * 2];
  for (int i = 0; i < max_capacity; i++) {
    temp[i] = data[i];
  }
  max_capacity *= 2;
  delete[] data;
  data = temp;
}

template <typename T>
void AlgoVector<T>::push_back(const T &Data) { // adds an element to the end of the vector
  if (capacity >= max_capacity) {
    resize();
    T *temp = new T[max_capacity + 1];
    for (int i = 0; i < capacity; i++) {
      temp[i] = data[i];
    }
    temp[capacity] = Data;
    delete[] data;
    data = temp;
  }else{
    data[capacity] = Data;
  }
  capacity++;
}

template <typename T>
void AlgoVector<T>::pop_back() { // pops the last element off of the vector
  if (capacity > 0) {
    T *temp = new T[capacity];
    for (int i = 0; i < capacity - 1; i++) {
      temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    capacity--;
  }
}

template <typename T>
T & AlgoVector<T>::operator[](int index) const { // subscript operator
  if (!(index < 0 || index >= capacity)) {
    return data[index];
  } else {
    throw outOfRangeVector();
  }
}

template <typename T> T &AlgoVector<T>::at(int index) const { // subscript operator
  if (!(index < 0 || index >= capacity)) {
    return data[index];
  } else {
    throw outOfRangeVector();
  }
}

template <typename T> int AlgoVector<T>::size() { // check the size of the vector
  return capacity;
}

template <typename T>
int AlgoVector<T>::max_size() { // check the max_capacity of the vector
  return max_capacity;
}

template <typename T>
void AlgoVector<T>::print(){
  for(int i = 0; i < capacity-1; i++){
    std::cout << data[i] << " ";
  }
  std::cout << data[capacity-1] << std::endl;
}

template <typename T>
void AlgoVector<T>::print(std::ofstream & file){
  for(int i = 0; i < capacity-1; i++){
    file << data[i] << " ";
  }
  file << data[capacity-1] << std::endl;
}

#endif