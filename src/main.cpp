#include "AlgoList.h"
#include "AlgoDict.h"
#include "AlgoVector.h"
#include <iostream>
#include <ostream>
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

    std::cout << "DataFile: " << dataGen.getDataFile() << std::endl;

    dataGen.genSets();

        cout << "writeSets" << endl;

        auto start = std::chrono::high_resolution_clock::now();
        dataGen.writeSets();
        auto end = std::chrono::high_resolution_clock::now();
        auto int_s = std::chrono::duration<double, std::milli>(end - start);
        std::cout << "writeSets elapsed time is " << int_s.count() << " milliseconds" << std::endl;


    // AlgoVector<string> stringSet;

    // stringSet.push_back("string1");
    // stringSet.push_back("string2");
    // stringSet.push_back("string3");
    // stringSet.push_back("string4");
    // stringSet.push_back("string5");
    // stringSet.push_back("string6");
    // stringSet.push_back("string7");

    // for(auto i : stringSet){
    //     cout << i << endl;
    // }

    return 0;
}
