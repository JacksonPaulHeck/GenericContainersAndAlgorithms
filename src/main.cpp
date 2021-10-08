#include "DataGen.h"
#include "Algorithm.h"

int main(int argc, char** argv){

    AlgoVector<int> sizes;
    
    sizes.push_back(1000);
    sizes.push_back(10000);
    // sizes.push_back(100000);
    // sizes.push_back(500000);
    // sizes.push_back(1000000);
    // sizes.push_back(2000000);

    DataGen dataGen(sizes);

    dataGen.genSets();

    // dataGen.writeSets();
    std::cout << "Ascending Result: "<< algo_check_ascending(dataGen.getAsc0Int()[0].begin(), dataGen.getAsc0Int()[0].end()) << std::endl;
    std::cout << "Random Result: "<< algo_check_random(dataGen.getRand0Int()[0].begin(), dataGen.getRand0Int()[0].end()) << std::endl;
    std::cout << "Descending Result: "<< algo_check_descending(dataGen.getDesc0Int()[0].begin(), dataGen.getDesc0Int()[0].end()) << std::endl;

    dataGen.writeSets();

    return 0;
}
