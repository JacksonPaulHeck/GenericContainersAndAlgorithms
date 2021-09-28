#include <bits/move.h>
#include <iostream>
#include <algorithm>

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

struct Iter_less_iter{
    template<typename RandomAccessIter>
    bool operator()(RandomAccessIter a, RandomAccessIter b) const{
        return *a < *b; 
    }
};

struct Iter_less_val{
    Iter_less_val() = default;

    Iter_less_val(Iter_less_iter) { }

    template<typename RandomAccessIter, typename T>
    bool operator()(RandomAccessIter iter, T& val) const{ 
        return *iter < val;
    }

    Iter_less_val iter_comp_val(Iter_less_iter){
        return Iter_less_val();
    }
};

template<typename RandomAccessIter, typename T, typename Compare>
void push_heap(RandomAccessIter first, long int hole, long int top, T val, Compare& comp){
    long int parent = (hole - 1) / 2;
    while (hole > top && comp(first + parent, val)) {
        *(first + hole) = *(first + parent);
        hole = parent;
        parent = (hole - 1) / 2;
    }
    *(first + hole) = val;
}

template<typename RandomAccessIter, typename Compare>
void pop_heap(RandomAccessIter first, RandomAccessIter last, RandomAccessIter result, Compare& comp){
    auto val = *result;
    *result = *first;
    adjust_heap(first, long(0), long(last - first), val, comp);
}

template<typename RandomAccessIter>
void pop_heap(RandomAccessIter first, RandomAccessIter last){
    Iter_less_iter comp;
    if (last - first > 1){
	    --last;
        pop_heap(first, last, last, comp);
	}
}

template<typename RandomAccessIter, typename T, typename Compare>
void adjust_heap(RandomAccessIter first, long int hole, long int len, T val, Compare comp){
    const long int top = hole;
    long int second = hole;
    while (second < (len - 1) / 2){
        second = 2 * (second + 1);
        if (comp(first + second, first + (second - 1))){
            second--;
        }
        *(first + hole) = _GLIBCXX_MOVE(*(first + second));
        hole = second;
    }
    if ((len & 1) == 0 && second == (len - 2) / 2){
        second = 2 * (second + 1);
        *(first + hole) = *(first + (second - 1));
        hole = second - 1;
    }
    Iter_less_val cmp(comp);
    push_heap(first, hole, top, val, cmp);
}

template<typename RandomAccessIter>
void make_heap(RandomAccessIter first, RandomAccessIter last){
    Iter_less_iter comp;
    if (last - first < 2){
        return;
    }
    const long int len = last - first;
    long int parent = (len - 2) / 2;
    while (true){
        auto val = *(first + parent);
        adjust_heap(first, parent, len, val, comp);
        if (parent == 0)
            return;
        parent--;
    }
}


template <class RandomAccessIter>
void algo_heap_sort(RandomAccessIter begin, RandomAccessIter end) {
    make_heap(begin, end);
    while (begin != end)
        std::pop_heap(begin, end--);
}