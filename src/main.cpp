#include "AlgoList.h"
#include "AlgoDict.h"
#include "AlgoVector.h"
#include <ostream>
#include "DataGen.h"
#include "Algorithm.h"

int main(int argc, char** argv){

    AlgoVector<int> sizes;

    sizes.push_back(5000);

    DataGen dataGen(sizes);

    std::cout << "DataFile: " << dataGen.getDataFile() << std::endl;

    dataGen.genSets();

    AlgoVector<AlgoVector<int>> rand0IntVectors = dataGen.getRand0Int();
    AlgoVector<AlgoVector<int>> asc0IntVectors = dataGen.getAsc0Int();

    

    dataGen.writeSets();

    return 0;
}
