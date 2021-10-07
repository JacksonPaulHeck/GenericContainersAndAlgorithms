#include <iostream>
#include <fstream>
#include <exception>
#include "AlgoVector.h"
#include <string>
#include <random>
#include <cstring>
#include <climits>

using namespace std;

class DataGen {
    public:
        DataGen(AlgoVector<int>);
        string getDataFile();
        void genSets();
        void writeSets();
        void genInts(int, int);
        void genAscInt0(int);
        void genRandIntPercents(int, int);
        void genStrs(int, int);
        void genAscStr0(int);
        void genRandStrPercents(int, int);

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
