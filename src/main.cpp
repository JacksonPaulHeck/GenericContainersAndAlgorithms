#include "AlgoVector.h"

int main(int argc, char** argv){
    std::cout << "Hello, World!" << std::endl;

    AlgoVector<int> algoVector;
    // testing algoVector
    for(int i = 0; i < 100; i++){
        algoVector.push_back(i);
    }

    algoVector.print();

    return 0;
}
