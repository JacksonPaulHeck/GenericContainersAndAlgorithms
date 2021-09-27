#include "AlgoVector.h"
#include "AlgoList.h"
#include "AlgoDict.h"
#include "Algorithm.h"

int main(int argc, char** argv){
    std::cout << "Hello, World!" << std::endl;

    AlgoVector<int> algoVector;
    AlgoList<int> algoList;
    AlgoDict<int> algoDict;

    // testing algoVector and algoList
    for(int i = 0; i < 10; i++){
        algoVector.push_back(i);
        algoList.push_back(i);
        algoDict.insert(i);
    }

    std::cout << *algofind(algoVector.forward_begin(), algoVector.forward_end(), 7) << std::endl;
    std::cout << *algofind(algoList.forward_begin(), algoList.forward_end(), 7) << std::endl;
    std::cout << *algofind(algoDict.forward_begin(), algoDict.forward_end(), 7) << std::endl;

    algoVector.print();
    algoList.print();
    algoDict.print();

    return 0;
}
