#include "DataGen.h"
#include "Algorithm.h"

int main(int argc, char** argv){

    AlgoVector<int> sizes;
    
    sizes.push_back(1000);
    sizes.push_back(10000);
    sizes.push_back(100000);
    sizes.push_back(500000);
    sizes.push_back(1000000);
    sizes.push_back(2000000);

    DataGen dataGen(sizes);

    dataGen.genSets();
    return 0;
}
