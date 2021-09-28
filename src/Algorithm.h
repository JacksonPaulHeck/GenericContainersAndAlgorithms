#include <bits/move.h>
#include <iostream>

template<typename ForwardIter, typename T>
ForwardIter algo_find( ForwardIter beg, ForwardIter end, T value) {
    while(beg != end) {
        if(*beg == value){
            return beg;
        }
        beg++;
    }
    return beg;
}

template<typename T>
void algo_swap(T& a, T& b){
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename RandomAccessIter>
void algo_iter_swap(RandomAccessIter a, RandomAccessIter b){
      algo_swap(*a, *b);
}

template<typename RandomAccessIter>
RandomAccessIter algo_min_element(RandomAccessIter first, RandomAccessIter last){
    if(first == last){
        return first;
    }
    RandomAccessIter result = first;
    while(++first != last){
        if(*first < *result){
            result = first;
        }
    }
    return result;
}

template<typename RandomAccessIter>
void algo_insertion_sort( RandomAccessIter begin, RandomAccessIter end) {
    algo_iter_swap( begin, algo_min_element( begin, end ));
    for ( RandomAccessIter b = begin; ++b < end; begin = b){
        for( RandomAccessIter c = b; *c < *begin; --c, --begin ){
            algo_iter_swap( begin, c );
        }
    }
}

template <typename RandomAccessIter>
void algo_quick_sort(RandomAccessIter begin, RandomAccessIter end) {
    if (end <= begin) return;
    RandomAccessIter pivot = begin, middle = begin + 1;
    for (RandomAccessIter i = begin + 1; i < end; ++i) {
        if (*i < *pivot) {
            algo_iter_swap(i, middle);
            ++middle;
        }
    }
    algo_iter_swap(begin, middle - 1);
    algo_quick_sort(begin, middle - 1);
    algo_quick_sort(middle, end);
}