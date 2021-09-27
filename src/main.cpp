#include "AlgoVector.h"
#include "AlgoList.h"

int main(int argc, char** argv){
    std::cout << "Hello, World!" << std::endl;

    AlgoVector<int> algoVector;
    AlgoList<int> algoList;
    // testing algoVector and algoList
    for(int i = 0; i < 10; i++){
        algoVector.push_back(i);
        algoList.push_back(i);
    }

    algoVector.print();
    algoList.print();

    return 0;
}
