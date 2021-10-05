#include <iostream>
#include <fstream>
#include <exception>
#include <vector>
#include <string>
#include <random>
#include <cstring>
#include <climits>
#include "AlgoVector.h"

using namespace std;

class DataGen {
    public:
        DataGen(AlgoVector<int>);
        string getDataFile();
        void genSets();
        void writeSets();
        void genRandInt0(int, int);
        void genAscInt0(int);
        void genDescInt0(int, int);
        void genRandInt20(int, int);
        void genRandInt40(int, int);
        void genRandStr0(int, int);
        void genAscStr0(int);
        void genDescStr0(int, int);
        void genRandStr20(int, int);
        void genRandStr40(int, int);
        AlgoVector<AlgoVector<int>> & getRand0Int();
        AlgoVector<AlgoVector<int>> & getAsc0Int();
        AlgoVector<AlgoVector<int>> & getDesc0Int();
        AlgoVector<AlgoVector<int>> & getRand20Int();
        AlgoVector<AlgoVector<int>> & getRand40Int();
    private:
        string dataFile;
        int strLength;
        AlgoVector<int> sizes;
        AlgoVector<AlgoVector<int>> rand0Int;
        AlgoVector<AlgoVector<int>> asc0Int;
        AlgoVector<AlgoVector<int>> desc0Int;
        AlgoVector<AlgoVector<int>> rand20Int;
        AlgoVector<AlgoVector<int>> rand40Int;
        AlgoVector<AlgoVector<string>> rand0Str;
        AlgoVector<AlgoVector<string>> asc0Str;
        AlgoVector<AlgoVector<string>> desc0Str;
        AlgoVector<AlgoVector<string>> rand20Str;
        AlgoVector<AlgoVector<string>> rand40Str;
};
