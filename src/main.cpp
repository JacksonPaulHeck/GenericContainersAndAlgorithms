#include "AlgoVector.h"
#include "AlgoList.h"
#include "AlgoDict.h"
#include "Algorithm.h"
#include <ostream>


struct Iter_greater_sort_iter{
    template<typename RandomAccessIter>
    bool operator()(RandomAccessIter a, RandomAccessIter b) const{
        return a > b; 
    }
};

struct Iter_greater_iter{
    template<typename RandomAccessIter>
    bool operator()(RandomAccessIter a, RandomAccessIter b) const{
        return *a > *b; 
    }
};

struct Iter_greater_val{
    Iter_greater_val() = default;

    Iter_greater_val(Iter_greater_iter) { }

    template<typename RandomAccessIter, typename T>
    bool operator()(RandomAccessIter iter, T& val) const{ 
        return *iter > val;
    }

    Iter_greater_val iter_comp_val(Iter_greater_val){
        return Iter_greater_val();
    }
};


int main(int argc, char** argv){
    std::ofstream vectorOutFile("output/vector.txt");
    std::ofstream vectorInsertionOutFile("output/vector_insertion.txt");
    std::ofstream vectorQuickOutFile("output/vector_quick.txt");
    std::ofstream vectorHeapOutFile("output/vector_heap.txt");
    std::ofstream listOutFile("output/list.txt");
    std::ofstream dictOutFile("output/dict.txt");
    std::ofstream findOutFile("output/find.txt");
    

    AlgoVector<int> algoVector;    
    AlgoVector<int> algoVectorInsertion;    
    AlgoVector<int> algoVectorQuick;
    AlgoVector<int> algoVectorHeap;

    AlgoList<int> algoList;
    AlgoDict<int> algoDict;

    // testing algoVector and algoList
    for(int i = 0; i < 50; i++){
        algoList.push_back(i);
        algoDict.insert(i);
        algoVector.push_back(i);
        algoVectorInsertion.push_back(i);
        algoVectorQuick.push_back(i);
        algoVectorHeap.push_back(i);
    }

    std::random_shuffle(algoVectorInsertion.begin(), algoVectorInsertion.end());
    std::random_shuffle(algoVectorQuick.begin(), algoVectorQuick.end());
    std::random_shuffle(algoVectorHeap.begin(), algoVectorHeap.end());

    findOutFile << "Find Test: " << std::endl;
    findOutFile << *algo_find(algoVector.forward_begin(), algoVector.forward_end(), 7) << std::endl;
    findOutFile << *algo_find(algoList.forward_begin(), algoList.forward_end(), 7) << std::endl;
    findOutFile << *algo_find(algoDict.forward_begin(), algoDict.forward_end(), 7) << std::endl;
    
    Iter_greater_sort_iter compare;
    Iter_greater_iter comp;
    Iter_greater_val cmp(comp);

    algoVectorInsertion.print(vectorInsertionOutFile);
    algoVectorQuick.print(vectorQuickOutFile);
    algoVectorHeap.print(vectorHeapOutFile);

    // algo_insertion_sort(algoVectorInsertion.begin(), algoVectorInsertion.end(), compare);
    // algo_quick_sort(algoVectorQuick.begin(), algoVectorQuick.end(), compare);
    // algo_heap_sort(algoVectorHeap.begin(), algoVectorHeap.end(), comp, cmp);

    algo_insertion_sort(algoVectorInsertion.begin(), algoVectorInsertion.end());
    algo_quick_sort(algoVectorQuick.begin(), algoVectorQuick.end());
    algo_heap_sort(algoVectorHeap.begin(), algoVectorHeap.end());

    algoVector.print(vectorOutFile);
    algoVectorInsertion.print(vectorInsertionOutFile);
    algoVectorQuick.print(vectorQuickOutFile);
    algoVectorHeap.print(vectorHeapOutFile);
    algoList.print(listOutFile);
    algoDict.print(dictOutFile);

    return 0;
}
