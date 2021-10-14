#include "AlgoVector.h"
#include "AlgoDict.h"

class DataGen {
    public:
        DataGen(AlgoVector<int>);
        std::string getDataFile();
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

        AlgoVector<AlgoVector<std::string>> & getRand0Str();
        AlgoVector<AlgoVector<std::string>> & getAsc0Str();
        AlgoVector<AlgoVector<std::string>> & getDesc0Str();
        AlgoVector<AlgoVector<std::string>> & getRand20Str();
        AlgoVector<AlgoVector<std::string>> & getRand40Str();
    private:
        std::string dataFile;
        int strLength;
        AlgoVector<int> sizes;
        AlgoVector<AlgoVector<int>> rand0Int;
        AlgoVector<AlgoVector<int>> asc0Int;
        AlgoVector<AlgoVector<int>> desc0Int;
        AlgoVector<AlgoVector<int>> rand20Int;
        AlgoVector<AlgoVector<int>> rand40Int;
        AlgoVector<AlgoVector<std::string>> rand0Str;
        AlgoVector<AlgoVector<std::string>> asc0Str;
        AlgoVector<AlgoVector<std::string>> desc0Str;
        AlgoVector<AlgoVector<std::string>> rand20Str;
        AlgoVector<AlgoVector<std::string>> rand40Str;
};
