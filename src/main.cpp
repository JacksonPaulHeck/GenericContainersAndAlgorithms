#include "AlgoVector.h"
#include "AlgoList.h"
#include "AlgoDict.h"

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

    algoVector.print();
    algoList.print();
    algoDict.print();

    return 0;
}
