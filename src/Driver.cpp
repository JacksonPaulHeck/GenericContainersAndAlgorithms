#include "Driver.h"
#include <algorithm>

void insertionSortAscInt(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_insertion_sort(data.getAsc0Int()[j].begin(), data.getAsc0Int()[j].end());

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";

}
void quickSortAscInt(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_quick_sort(data.getAsc0Int()[j].begin(), data.getAsc0Int()[j].end());

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}
void heapSortAscInt(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_heap_sort(data.getAsc0Int()[j].begin(), data.getAsc0Int()[j].end());

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}

void insertionSortDescInt(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_insertion_sort(data.getDesc0Int()[j].begin(), data.getDesc0Int()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}
void quickSortDescInt(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_quick_sort(data.getDesc0Int()[j].begin(), data.getDesc0Int()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}
void heapSortDescInt(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_heap_sort(data.getDesc0Int()[j].begin(), data.getDesc0Int()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}

void insertionSortRandomInt(DataGen & data, std::ostream & outFile, int j){
    auto start = std::chrono::high_resolution_clock::now();
    algo_insertion_sort(data.getRand0Int()[j].begin(), data.getRand0Int()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}
void quickSortRandomInt(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_quick_sort(data.getRand0Int()[j].begin(), data.getRand0Int()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}
void heapSortRandomInt(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_heap_sort(data.getRand0Int()[j].begin(), data.getRand0Int()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}

void insertionSortRandom20Int(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_insertion_sort(data.getRand20Int()[j].begin(), data.getRand20Int()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}
void quickSortRandom20Int(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_quick_sort(data.getRand20Int()[j].begin(), data.getRand20Int()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}
void heapSortRandom20Int(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_heap_sort(data.getRand20Int()[j].begin(), data.getRand20Int()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}

void insertionSortRandom40Int(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_insertion_sort(data.getRand40Int()[j].begin(), data.getRand40Int()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}
void quickSortRandom40Int(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_quick_sort(data.getRand40Int()[j].begin(), data.getRand40Int()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}
void heapSortRandom40Int(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_heap_sort(data.getRand40Int()[j].begin(), data.getRand40Int()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}

void insertionSortAscStr(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_insertion_sort(data.getAsc0Str()[j].begin(), data.getAsc0Str()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}
void quickSortAscStr(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_quick_sort(data.getAsc0Str()[j].begin(), data.getAsc0Str()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}
void heapSortAscStr(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_heap_sort(data.getAsc0Str()[j].begin(), data.getAsc0Str()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}

void insertionSortDescStr(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_insertion_sort(data.getDesc0Str()[j].begin(), data.getDesc0Str()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}
void quickSortDescStr(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_quick_sort(data.getDesc0Str()[j].begin(), data.getDesc0Str()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}
void heapSortDescStr(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_heap_sort(data.getDesc0Str()[j].begin(), data.getDesc0Str()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}

void insertionSortRandomStr(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_insertion_sort(data.getRand0Str()[j].begin(), data.getRand0Str()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}
void quickSortRandomStr(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_quick_sort(data.getRand0Str()[j].begin(), data.getRand0Str()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}
void heapSortRandomStr(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_heap_sort(data.getRand0Str()[j].begin(), data.getRand0Str()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}

void insertionSortRandom20Str(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_insertion_sort(data.getRand20Str()[j].begin(), data.getRand20Str()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}
void quickSortRandom20Str(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_quick_sort(data.getRand20Str()[j].begin(), data.getRand20Str()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}
void heapSortRandom20Str(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_heap_sort(data.getRand20Str()[j].begin(), data.getRand20Str()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}

void insertionSortRandom40Str(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_insertion_sort(data.getRand40Str()[j].begin(), data.getRand40Str()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}
void quickSortRandom40Str(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_quick_sort(data.getRand40Str()[j].begin(), data.getRand40Str()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}
void heapSortRandom40Str(DataGen & data, std::ostream & outFile, int j) {
    auto start = std::chrono::high_resolution_clock::now();
    algo_heap_sort(data.getRand40Str()[j].begin(), data.getRand40Str()[j].end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;
    outFile << float_ms.count() << ", ";
}

void generateInsertionSortData(DataGen & data, std::ostream & outFile, AlgoVector<int> & sizes){
    outFile << "Insertion Sort Ascending Integer: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        if(sizes[j] <= 1000){
                insertionSortAscInt(data, outFile, j);
        }
    }
    outFile << std::endl;
        
    outFile << "Insertion Sort Descending Integer: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        if(sizes[j] <= 1000){
                insertionSortDescInt(data, outFile, j);
        }
    }
    outFile << std::endl;

    outFile << "Insertion Sort Random Integer: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        if(sizes[j] <= 1000){
                insertionSortRandomInt(data, outFile, j);
        }
    }
    outFile << std::endl;

    outFile << "Insertion Sort Random 20% Integer: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        if(sizes[j] <= 1000){
                insertionSortRandom20Int(data, outFile, j);
        }
    }
    outFile << std::endl;

    outFile << "Insertion Sort Random 40% Integer: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        if(sizes[j] <= 1000){
                insertionSortRandom40Int(data, outFile, j);
        }
    }
    outFile << std::endl;

    outFile << "Insertion Sort Ascending String: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        if(sizes[j] <= 1000){
                insertionSortAscStr(data, outFile, j);
        }
    }
    outFile << std::endl;

    outFile << "Insertion Sort Descending String: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        if(sizes[j] <= 1000){
                insertionSortDescStr(data, outFile, j);
        }
    }
    outFile << std::endl;

    outFile << "Insertion Sort Random String: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        if(sizes[j] <= 1000){
                insertionSortRandomStr(data, outFile, j);
        }
    }
    outFile << std::endl;

    outFile << "Insertion Sort Random 20% String: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        if(sizes[j] <= 1000){
                insertionSortRandom20Str(data, outFile, j);
        }
    }
    outFile << std::endl;

    outFile << "Insertion Sort Random 40% String: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        if(sizes[j] <= 1000){
                insertionSortRandom40Str(data, outFile, j);
        }
    }
    outFile << std::endl;
    
}

void generateQuickSortData(DataGen & data, std::ostream & outFile, AlgoVector<int> & sizes){
    outFile << "Quick Sort Ascending Integer: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        quickSortAscInt(data, outFile, j);
    }
    outFile << std::endl;
    outFile << "Quick Sort Descending Integer: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        quickSortDescInt(data, outFile, j);
    }
    outFile << std::endl;
    outFile << "Quick Sort Random Integer: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        quickSortRandomInt(data, outFile, j);
    }
    outFile << std::endl;
    outFile << "Quick Sort Random 20% Integer: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        quickSortRandom20Int(data, outFile, j);
    }
    outFile << std::endl;
    outFile << "Quick Sort Random 40% Integer: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        quickSortRandom40Int(data, outFile, j);
    }
    outFile << std::endl;
    outFile << "Quick Sort Ascending String: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        quickSortAscStr(data, outFile, j);
    }
    outFile << std::endl;
    outFile << "Quick Sort Descending String: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        quickSortDescStr(data, outFile, j);
    }
    outFile << std::endl;
    outFile << "Quick Sort Random String: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        quickSortRandomStr(data, outFile, j);
    }
    outFile << std::endl;
    outFile << "Quick Sort Random 20% String: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        quickSortRandom20Str(data, outFile, j);
    }
    outFile << std::endl;
    outFile << "Quick Sort Random 40% String: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        quickSortRandom40Str(data, outFile, j);
    }
    outFile << std::endl;
}

void generateHeapSortData(DataGen & data, std::ostream & outFile, AlgoVector<int> & sizes){
    outFile << "Heap Sort Ascending Integer: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        heapSortAscInt(data, outFile, j);
    }
    outFile << std::endl;
    outFile << "Heap Sort Descending Integer: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        heapSortDescInt(data, outFile, j);
    }
    outFile << std::endl;
    outFile << "Heap Sort Random Integer: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        heapSortRandomInt(data, outFile, j);
    }
    outFile << std::endl;
    outFile << "Heap Sort Random 20% Integer: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        heapSortRandom20Int(data, outFile, j);
    }
    outFile << std::endl;
    outFile << "Heap Sort Random 40% Integer: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        heapSortRandom40Int(data, outFile, j);
    }
    outFile << std::endl;
    outFile << "Heap Sort Ascending String: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        heapSortAscStr(data, outFile, j);
    }
    outFile << std::endl;
    outFile << "Heap Sort Descending String: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        heapSortDescStr(data, outFile, j);
    }
    outFile << std::endl;
    outFile << "Heap Sort Random String: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        heapSortRandomStr(data, outFile, j);
    }
    outFile << std::endl;
    outFile << "Heap Sort Random 20% String: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        heapSortRandom20Str(data, outFile, j);
    }
    outFile << std::endl;
    outFile << "Heap Sort Random 40% String: " << std::endl;
    for(int j = 0; j < sizes.size(); j++){
        heapSortRandom40Str(data, outFile, j);
    }
    outFile << std::endl;
}

bool checkData(DataGen & insertionData, DataGen & quickData, DataGen & heapData, std::ostream & outFile, AlgoVector<int> & sizes){
    
    bool isValid = true;
    for(int j = 0; j < sizes.size(); j++){
        // isValid = 
        // algo_check_ascending(insertionData.getAsc0Int()[j].begin(), insertionData.getAsc0Int()[j].end()) &&
        // algo_check_random(insertionData.getRand0Int()[j].begin(), insertionData.getRand0Int()[j].end()) &&
        // algo_check_random(insertionData.getRand20Int()[j].begin(), insertionData.getRand20Int()[j].end()) &&
        // algo_check_random(insertionData.getRand40Int()[j].begin(), insertionData.getRand40Int()[j].end()) &&
        // algo_check_descending(insertionData.getDesc0Int()[j].begin(), insertionData.getDesc0Int()[j].end()) &&

        // algo_check_ascending(insertionData.getAsc0Str()[j].begin(), insertionData.getAsc0Str()[j].end()) &&
        // algo_check_random(insertionData.getRand0Str()[j].begin(), insertionData.getRand0Str()[j].end()) &&
        // algo_check_random(insertionData.getRand20Str()[j].begin(), insertionData.getRand20Str()[j].end()) &&
        // algo_check_random(insertionData.getRand40Str()[j].begin(), insertionData.getRand40Str()[j].end()) &&
        // algo_check_descending(insertionData.getDesc0Str()[j].begin(), insertionData.getDesc0Str()[j].end()) &&

        // algo_check_ascending(quickData.getAsc0Int()[j].begin(), quickData.getAsc0Int()[j].end()) &&
        // algo_check_random(quickData.getRand0Int()[j].begin(), quickData.getRand0Int()[j].end()) &&
        // algo_check_random(quickData.getRand20Int()[j].begin(), quickData.getRand20Int()[j].end()) &&
        // algo_check_random(quickData.getRand40Int()[j].begin(), quickData.getRand40Int()[j].end()) &&
        // algo_check_descending(quickData.getDesc0Int()[j].begin(), quickData.getDesc0Int()[j].end()) &&

        // algo_check_ascending(quickData.getAsc0Str()[j].begin(), quickData.getAsc0Str()[j].end()) &&
        // algo_check_random(quickData.getRand0Str()[j].begin(), quickData.getRand0Str()[j].end()) &&
        // algo_check_random(quickData.getRand20Str()[j].begin(), quickData.getRand20Str()[j].end()) &&
        // algo_check_random(quickData.getRand40Str()[j].begin(), quickData.getRand40Str()[j].end()) &&
        // algo_check_descending(quickData.getDesc0Str()[j].begin(), quickData.getDesc0Str()[j].end()) &&

        // algo_check_ascending(heapData.getAsc0Int()[j].begin(), heapData.getAsc0Int()[j].end()) &&
        // algo_check_random(heapData.getRand0Int()[j].begin(), heapData.getRand0Int()[j].end()) &&
        // algo_check_random(heapData.getRand20Int()[j].begin(), heapData.getRand20Int()[j].end()) &&
        // algo_check_random(heapData.getRand40Int()[j].begin(), heapData.getRand40Int()[j].end()) &&
        // algo_check_descending(heapData.getDesc0Int()[j].begin(), heapData.getDesc0Int()[j].end()) &&

        // algo_check_ascending(heapData.getAsc0Str()[j].begin(), heapData.getAsc0Str()[j].end()) &&
        // algo_check_random(heapData.getRand0Str()[j].begin(), heapData.getRand0Str()[j].end()) &&
        // algo_check_random(heapData.getRand20Str()[j].begin(), heapData.getRand20Str()[j].end()) &&
        // algo_check_random(heapData.getRand40Str()[j].begin(), heapData.getRand40Str()[j].end()) &&
        // algo_check_descending(heapData.getDesc0Str()[j].begin(), heapData.getDesc0Str()[j].end());
    }
    return isValid;
}

void printSizes(AlgoVector<int> & sizes, std::ostream & outFile){
    for(int i = 0; i < sizes.size()-1; i++){
        outFile << sizes[i] << ", ";
    }
    outFile << sizes[sizes.size()-1] << std::endl;
}