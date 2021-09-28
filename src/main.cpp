#include "AlgoVector.h"
#include "AlgoList.h"
#include "AlgoDict.h"
#include "Algorithm.h"
#include <iterator>
#include <algorithm>

int main(int argc, char** argv){
    AlgoVector<int> algoVector;
    AlgoList<int> algoList;
    AlgoDict<int> algoDict;

    // testing algoVector and algoList
    for(int i = 0; i < 1000; i++){
        algoList.push_back(i);
        algoDict.insert(i);
        algoVector.push_back(i);
    }

    std::random_shuffle(algoVector.begin(), algoVector.end());
    
    std::cout << "Find Test: " << std::endl;
    std::cout << *algo_find(algoVector.forward_begin(), algoVector.forward_end(), 7) << std::endl;
    std::cout << *algo_find(algoList.forward_begin(), algoList.forward_end(), 7) << std::endl;
    std::cout << *algo_find(algoDict.forward_begin(), algoDict.forward_end(), 7) << std::endl;
    algoVector.print();

    //algo_insertion_sort(algoVector.begin(), algoVector.end());
    algo_quick_sort(algoVector.begin(), algoVector.end());
    //algo_heap_sort(algoVector.begin(), algoVector.end());

    std::cout << "Print: " << std::endl;
    algoVector.print();
    //algoList.print();
    //algoDict.print();

    return 0;
}
