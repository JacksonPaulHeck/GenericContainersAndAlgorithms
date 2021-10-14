#include "DataGen.h"
#include "Algorithm.h"

int main(int argc, char** argv){

    AlgoVector<int> sizes;
    
    sizes.push_back(100);
    sizes.push_back(200);
    sizes.push_back(2000);
    sizes.push_back(10000);
    // sizes.push_back(500000);
    // sizes.push_back(1000000);
    // sizes.push_back(2000000);

    DataGen heapSortDataGen(sizes);
    DataGen insertionSortDataGen(sizes);
    DataGen quickSortDataGen(sizes);

    heapSortDataGen.genSets();
    insertionSortDataGen.genSets();
    quickSortDataGen.genSets();

    for(int j = 0; j < sizes.size(); j++){

        std::cout << "Ascending Result: "<< algo_check_ascending(heapSortDataGen.getAsc0Int()[j].begin(), heapSortDataGen.getAsc0Int()[j].end()) << std::endl;
        std::cout << "Random Result: "<< algo_check_random(heapSortDataGen.getRand0Int()[j].begin(), heapSortDataGen.getRand0Int()[j].end()) << std::endl;
        std::cout << "Random 20 Result: "<< algo_check_random(heapSortDataGen.getRand20Int()[j].begin(), heapSortDataGen.getRand20Int()[j].end()) << std::endl;
        std::cout << "Random 40 Result: "<< algo_check_random(heapSortDataGen.getRand40Int()[j].begin(), heapSortDataGen.getRand40Int()[j].end()) << std::endl;
        std::cout << "Descending Result: "<< algo_check_descending(heapSortDataGen.getDesc0Int()[j].begin(), heapSortDataGen.getDesc0Int()[j].end()) << std::endl;
        
        if(sizes[j] <= 1000){
            std::cout << "Insertion Sort: " << sizes[j] <<std::endl;

            auto start = std::chrono::high_resolution_clock::now();
                algo_insertion_sort(insertionSortDataGen.getDesc0Int()[j].begin(), insertionSortDataGen.getDesc0Int()[j].end());
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> float_ms = end - start;
            std::cout << "\tInsertion Sort Desc Int:  " << float_ms.count() << " milliseconds" << std::endl;

            start = std::chrono::high_resolution_clock::now();
                algo_insertion_sort(insertionSortDataGen.getAsc0Int()[j].begin(), insertionSortDataGen.getAsc0Int()[j].end());
            end = std::chrono::high_resolution_clock::now();
            float_ms = end - start;
            std::cout << "\tInsertion Sort Asc Int:  " << float_ms.count() << " milliseconds" << std::endl;

            start = std::chrono::high_resolution_clock::now();
                algo_insertion_sort(insertionSortDataGen.getRand0Int()[j].begin(), insertionSortDataGen.getRand0Int()[j].end());  
            end = std::chrono::high_resolution_clock::now();
            float_ms = end - start;
            std::cout << "\tInsertion Sort Rand Int:  " << float_ms.count() << " milliseconds" << std::endl;

            start = std::chrono::high_resolution_clock::now();
                algo_insertion_sort(insertionSortDataGen.getRand20Int()[j].begin(), insertionSortDataGen.getRand20Int()[j].end());
            end = std::chrono::high_resolution_clock::now();
            float_ms = end - start;
            std::cout << "\tInsertion Sort Rand 20 Int:  " << float_ms.count() << " milliseconds" << std::endl;

            start = std::chrono::high_resolution_clock::now();
                algo_insertion_sort(insertionSortDataGen.getRand40Int()[j].begin(), insertionSortDataGen.getRand40Int()[j].end());
            end = std::chrono::high_resolution_clock::now();
            float_ms = end - start;
            std::cout << "\tInsertion Sort Rand 40 Int:  " << float_ms.count() << " milliseconds" << std::endl;

            start = std::chrono::high_resolution_clock::now();
                algo_insertion_sort(insertionSortDataGen.getDesc0Str()[j].begin(), insertionSortDataGen.getDesc0Str()[j].end());
            end = std::chrono::high_resolution_clock::now();
            float_ms = end - start;
            std::cout << "\tInsertion Sort Desc Str:  " << float_ms.count() << " milliseconds" << std::endl;

            start = std::chrono::high_resolution_clock::now();
                algo_insertion_sort(insertionSortDataGen.getAsc0Str()[j].begin(), insertionSortDataGen.getAsc0Str()[j].end());
            end = std::chrono::high_resolution_clock::now();
            float_ms = end - start;
            std::cout << "\tInsertion Sort Asc Str:  " << float_ms.count() << " milliseconds" << std::endl;

            start = std::chrono::high_resolution_clock::now();
                algo_insertion_sort(insertionSortDataGen.getRand0Str()[j].begin(), insertionSortDataGen.getRand0Str()[j].end());  
            end = std::chrono::high_resolution_clock::now();
            float_ms = end - start;
            std::cout << "\tInsertion Sort Rand Str:  " << float_ms.count() << " milliseconds" << std::endl;

            start = std::chrono::high_resolution_clock::now();
                algo_insertion_sort(insertionSortDataGen.getRand20Str()[j].begin(), insertionSortDataGen.getRand20Str()[j].end());
            end = std::chrono::high_resolution_clock::now();
            float_ms = end - start;
            std::cout << "\tInsertion Sort Rand 20 Str:  " << float_ms.count() << " milliseconds" << std::endl;

            start = std::chrono::high_resolution_clock::now();
                algo_insertion_sort(insertionSortDataGen.getRand40Str()[j].begin(), insertionSortDataGen.getRand40Str()[j].end());
            end = std::chrono::high_resolution_clock::now();
            float_ms = end - start;
            std::cout << "\tInsertion Sort Rand 40 Str:  " << float_ms.count() << " milliseconds" << std::endl;
        }
        
        std::cout << "Quick Sort: " << std::endl;
        auto start = std::chrono::high_resolution_clock::now();
            algo_quick_sort(quickSortDataGen.getDesc0Int()[j].begin(), quickSortDataGen.getDesc0Int()[j].end());
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> float_ms = end - start;
        std::cout << "\tQuick Sort Desc Int:  " << float_ms.count() << " milliseconds" << std::endl;

        start = std::chrono::high_resolution_clock::now();
            algo_quick_sort(quickSortDataGen.getAsc0Int()[j].begin(), quickSortDataGen.getAsc0Int()[j].end());
        end = std::chrono::high_resolution_clock::now();
        float_ms = end - start;
        std::cout << "\tQuick Sort Asc Int:  " << float_ms.count() << " milliseconds" << std::endl;

        start = std::chrono::high_resolution_clock::now();
            algo_quick_sort(quickSortDataGen.getRand0Int()[j].begin(), quickSortDataGen.getRand0Int()[j].end());  
        end = std::chrono::high_resolution_clock::now();
        float_ms = end - start;
        std::cout << "\tQuick Sort Rand Int:  " << float_ms.count() << " milliseconds" << std::endl;

        start = std::chrono::high_resolution_clock::now();
            algo_quick_sort(quickSortDataGen.getRand20Int()[j].begin(), quickSortDataGen.getRand20Int()[j].end());
        end = std::chrono::high_resolution_clock::now();
        float_ms = end - start;
        std::cout << "\tQuick Sort Rand 20 Int:  " << float_ms.count() << " milliseconds" << std::endl;

        start = std::chrono::high_resolution_clock::now();
            algo_quick_sort(quickSortDataGen.getRand40Int()[j].begin(), quickSortDataGen.getRand40Int()[j].end());
        end = std::chrono::high_resolution_clock::now();
        float_ms = end - start;
        std::cout << "\tQuick Sort Rand 40 Int:  " << float_ms.count() << " milliseconds" << std::endl;

        start = std::chrono::high_resolution_clock::now();
            algo_quick_sort(quickSortDataGen.getDesc0Str()[j].begin(), quickSortDataGen.getDesc0Str()[j].end());
        end = std::chrono::high_resolution_clock::now();
        float_ms = end - start;
        std::cout << "\tQuick Sort Desc Str:  " << float_ms.count() << " milliseconds" << std::endl;

        start = std::chrono::high_resolution_clock::now();
            algo_quick_sort(quickSortDataGen.getAsc0Str()[j].begin(), quickSortDataGen.getAsc0Str()[j].end());
        end = std::chrono::high_resolution_clock::now();
        float_ms = end - start;
        std::cout << "\tQuick Sort Asc Str:  " << float_ms.count() << " milliseconds" << std::endl;

        start = std::chrono::high_resolution_clock::now();
            algo_quick_sort(quickSortDataGen.getRand0Str()[j].begin(), quickSortDataGen.getRand0Str()[j].end());  
        end = std::chrono::high_resolution_clock::now();
        float_ms = end - start;
        std::cout << "\tQuick Sort Rand Str:  " << float_ms.count() << " milliseconds" << std::endl;

        start = std::chrono::high_resolution_clock::now();
            algo_quick_sort(quickSortDataGen.getRand20Str()[j].begin(), quickSortDataGen.getRand20Str()[j].end());
        end = std::chrono::high_resolution_clock::now();
        float_ms = end - start;
        std::cout << "\tQuick Sort Rand 20 Str:  " << float_ms.count() << " milliseconds" << std::endl;

        start = std::chrono::high_resolution_clock::now();
            algo_quick_sort(quickSortDataGen.getRand40Str()[j].begin(), quickSortDataGen.getRand40Str()[j].end());
        end = std::chrono::high_resolution_clock::now();
        float_ms = end - start;
        std::cout << "\tQuick Sort Rand 40 Str:  " << float_ms.count() << " milliseconds" << std::endl;
            
        std::cout << "Heap Sort: " << std::endl;
        start = std::chrono::high_resolution_clock::now();
            algo_heap_sort(heapSortDataGen.getDesc0Int()[j].begin(), heapSortDataGen.getDesc0Int()[j].end());
        end = std::chrono::high_resolution_clock::now();
        float_ms = end - start;
        std::cout << "\tHeap Sort Desc Int:  " << float_ms.count() << " milliseconds" << std::endl;

        start = std::chrono::high_resolution_clock::now();
            algo_heap_sort(heapSortDataGen.getAsc0Int()[j].begin(), heapSortDataGen.getAsc0Int()[j].end());
        end = std::chrono::high_resolution_clock::now();
        float_ms = end - start;
        std::cout << "\tHeap Sort Asc Int:  " << float_ms.count() << " milliseconds" << std::endl;

        start = std::chrono::high_resolution_clock::now();
            algo_heap_sort(heapSortDataGen.getRand0Int()[j].begin(), heapSortDataGen.getRand0Int()[j].end());  
        end = std::chrono::high_resolution_clock::now();
        float_ms = end - start;
        std::cout << "\tHeap Sort Rand Int:  " << float_ms.count() << " milliseconds" << std::endl;

        start = std::chrono::high_resolution_clock::now();
            algo_heap_sort(heapSortDataGen.getRand20Int()[j].begin(), heapSortDataGen.getRand20Int()[j].end());
        end = std::chrono::high_resolution_clock::now();
        float_ms = end - start;
        std::cout << "\tHeap Sort Rand 20 Int:  " << float_ms.count() << " milliseconds" << std::endl;

        start = std::chrono::high_resolution_clock::now();
            algo_heap_sort(heapSortDataGen.getRand40Int()[j].begin(), heapSortDataGen.getRand40Int()[j].end());
        end = std::chrono::high_resolution_clock::now();
        float_ms = end - start;
        std::cout << "\tHeap Sort Rand 40 Int:  " << float_ms.count() << " milliseconds" << std::endl;

        start = std::chrono::high_resolution_clock::now();
            algo_heap_sort(heapSortDataGen.getDesc0Str()[j].begin(), heapSortDataGen.getDesc0Str()[j].end());
        end = std::chrono::high_resolution_clock::now();
        float_ms = end - start;
        std::cout << "\tHeap Sort Desc Str:  " << float_ms.count() << " milliseconds" << std::endl;

        start = std::chrono::high_resolution_clock::now();
            algo_heap_sort(heapSortDataGen.getAsc0Str()[j].begin(), heapSortDataGen.getAsc0Str()[j].end());
        end = std::chrono::high_resolution_clock::now();
        float_ms = end - start;
        std::cout << "\tHeap Sort Asc Str:  " << float_ms.count() << " milliseconds" << std::endl;

        start = std::chrono::high_resolution_clock::now();
            algo_heap_sort(heapSortDataGen.getRand0Str()[j].begin(), heapSortDataGen.getRand0Str()[j].end());  
        end = std::chrono::high_resolution_clock::now();
        float_ms = end - start;
        std::cout << "\tHeap Sort Rand Str:  " << float_ms.count() << " milliseconds" << std::endl;

        start = std::chrono::high_resolution_clock::now();
            algo_heap_sort(heapSortDataGen.getRand20Str()[j].begin(), heapSortDataGen.getRand20Str()[j].end());
        end = std::chrono::high_resolution_clock::now();
        float_ms = end - start;
        std::cout << "\tHeap Sort Rand 20 Str:  " << float_ms.count() << " milliseconds" << std::endl;

        start = std::chrono::high_resolution_clock::now();
            algo_heap_sort(heapSortDataGen.getRand40Str()[j].begin(), heapSortDataGen.getRand40Str()[j].end());
        end = std::chrono::high_resolution_clock::now();
        float_ms = end - start;
        std::cout << "\tHeap Sort Rand 40 Str:  " << float_ms.count() << " milliseconds" << std::endl;
    }
    //insertionSortDataGen.writeSets();
    heapSortDataGen.writeSets();
    //heapSortDataGen.writeSets();

    return 0;
}
