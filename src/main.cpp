#include "Driver.h"
#include <fstream>

int main(int argc, char **argv) {
  std::ofstream dataOutput("./output/data.csv");
  AlgoVector<int> sizes;

  sizes.push_back(100);
  sizes.push_back(200);
  sizes.push_back(300);
  sizes.push_back(400);
  sizes.push_back(500);
  sizes.push_back(600);
  sizes.push_back(700);
  sizes.push_back(800);
  sizes.push_back(900);
  sizes.push_back(1000);
  sizes.push_back(2000);
  sizes.push_back(3000);
  // sizes.push_back(500000);
  // sizes.push_back(1000000);
  // sizes.push_back(2000000);

  DataGen heapSortDataGen(sizes);
  DataGen insertionSortDataGen(sizes);
  DataGen quickSortDataGen(sizes);

  auto start = std::chrono::high_resolution_clock::now();
  heapSortDataGen.genSets();
  insertionSortDataGen.genSets();
  quickSortDataGen.genSets();
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> float_ms = end - start;
  std::cout << "\tSets Generated:  " << float_ms.count() << " milliseconds"
            << std::endl;

  printSizes(sizes, dataOutput);

  bool dataValidity = checkData(insertionSortDataGen, quickSortDataGen,
                                heapSortDataGen, dataOutput, sizes);

  if (dataValidity) {
    generateInsertionSortData(insertionSortDataGen, dataOutput, sizes);
    generateQuickSortData(quickSortDataGen, dataOutput, sizes);
    generateHeapSortData(heapSortDataGen, dataOutput, sizes);
  }

  // insertionSortDataGen.writeSets();
  // heapSortDataGen.writeSets();

  return 0;
}
