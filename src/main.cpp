#include "Driver.h"
#include <fstream>

int main(int argc, char **argv) {
  std::ifstream sizesInput(argv[1]);
  std::ofstream dataOutput(argv[2]);

  for(int i = 0; i < sizeof(argv); i++){
    std::cout << argv[i] << std::endl;
  }

  AlgoVector<int> sizes;

  while(!sizesInput.eof()){
    std::string line;
    getline(sizesInput, line);
    std::cout << line << std::endl;
    sizes.push_back(stoi(line));
  }

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
