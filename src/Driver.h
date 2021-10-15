#include "Algorithm.h"
#include "DataGen.h"
#include <ostream>

void insertionSortAscInt(DataGen &, std::ostream &, int);
void quickSortAscInt(DataGen &, std::ostream &, int);
void heapSortAscInt(DataGen &, std::ostream &, int);

void insertionSortDescInt(DataGen &, std::ostream &, int);
void quickSortDescInt(DataGen &, std::ostream &, int);
void heapSortDescInt(DataGen &, std::ostream &, int);

void insertionSortRandomInt(DataGen &, std::ostream &, int);
void quickSortRandomInt(DataGen &, std::ostream &, int);
void heapSortRandomInt(DataGen &, std::ostream &, int);

void insertionSortRandom20Int(DataGen &, std::ostream &, int);
void quickSortRandom20Int(DataGen &, std::ostream &, int);
void heapSortRandom20Int(DataGen &, std::ostream &, int);

void insertionSortRandom40Int(DataGen &, std::ostream &, int);
void quickSortRandom40Int(DataGen &, std::ostream &, int);
void heapSortRandom40Int(DataGen &, std::ostream &, int);

void insertionSortAscStr(DataGen &, std::ostream &, int);
void quickSortAscStr(DataGen &, std::ostream &, int);
void heapSortAscStr(DataGen &, std::ostream &, int);

void insertionSortDescStr(DataGen &, std::ostream &, int);
void quickSortDescStr(DataGen &, std::ostream &, int);
void heapSortDescStr(DataGen &, std::ostream &, int);

void insertionSortRandomStr(DataGen &, std::ostream &, int);
void quickSortRandomStr(DataGen &, std::ostream &, int);
void heapSortRandomStr(DataGen &, std::ostream &, int);

void insertionSortRandom20Str(DataGen &, std::ostream &, int);
void quickSortRandom20Str(DataGen &, std::ostream &, int);
void heapSortRandom20Str(DataGen &, std::ostream &, int);

void insertionSortRandom40Str(DataGen &, std::ostream &, int);
void quickSortRandom40Str(DataGen &, std::ostream &, int);
void heapSortRandom40Str(DataGen &, std::ostream &, int);

void generateInsertionSortData(DataGen &, std::ostream &, AlgoVector<int> &);
void generateQuickSortData(DataGen &, std::ostream &, AlgoVector<int> &);
void generateHeapSortData(DataGen &, std::ostream &, AlgoVector<int> &);

bool checkData(DataGen &, DataGen &, DataGen &, std::ostream &, AlgoVector<int> &);

void printSizes(AlgoVector<int> &, std::ostream &);