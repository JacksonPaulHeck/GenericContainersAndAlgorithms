#include "Driver.h"
#include <fstream>

int main(int argc, char **argv) {
  std::ofstream dataOutput("./output/data.csv");
  AlgoVector<int> sizes;

  sizes.push_back(100);
  sizes.push_back(250);
  sizes.push_back(500);
  sizes.push_back(1000);
  sizes.push_back(2500);
  sizes.push_back(5000);
  sizes.push_back(10000);
  sizes.push_back(25000);
  sizes.push_back(50000);


  DataGen heapSortDataGen(sizes);
  DataGen insertionSortDataGen(sizes);
  DataGen quickSortDataGen(sizes);

  auto start = std::chrono::high_resolution_clock::now();
  heapSortDataGen.genSets();
  insertionSortDataGen.genSets();
  quickSortDataGen.genSets();
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> float_ms = end - start;
  std::cout << "\tSets Generated: " << float_ms.count() << " milliseconds"
            << std::endl;

  printSizes(sizes, dataOutput);

  std::cout << "\tRunning Insertion Sort" << std::endl;
  generateInsertionSortData(insertionSortDataGen, dataOutput, sizes);

  std::cout << "\tRunning Quick Sort" << std::endl;
  generateQuickSortData(quickSortDataGen, dataOutput, sizes);

  std::cout << "\tRunning Heap Sort" << std::endl;
  generateHeapSortData(heapSortDataGen, dataOutput, sizes);
  
  std::cout << "\tChecking Data" << std::endl;
  bool isSorted = checkData(insertionSortDataGen, quickSortDataGen,
                            heapSortDataGen, dataOutput, sizes);
  
  if(isSorted == true){
    std::cout << "\tData Sucessfully Sorted" << std::endl;
  }else{
    std::cout << "\tData Unsucessfully Sorted" << std::endl;
  }


  return 0;
}
