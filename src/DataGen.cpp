#include "DataGen.h"
#include <algorithm>
#include "Algorithm.h"
#include <string>
#include <bits/stdc++.h>

DataGen::DataGen(AlgoVector<int> sizesToUse) {
    this->sizes = sizesToUse;
    this->dataFile = "./test/datasets.csv";
    this->strLength = 10;
};

string DataGen::getDataFile() {
    return dataFile;
}

void DataGen::genSets() {
    cout << "Gen Sets" << endl;
    for (int i = 0; i < sizes.size(); i++) {
        cout << i << endl;

        cout << "Gen Asc Int" << endl;

        auto start = std::chrono::high_resolution_clock::now();
        genAscInt0(sizes[i]);
        auto end = std::chrono::high_resolution_clock::now();
        auto int_s = std::chrono::duration<double, std::milli>(end - start);
        std::cout << "genAscInt0 elapsed time is " << int_s.count() << " milliseconds" << std::endl;


        cout << "Gen Rand Int" << endl;

        start = std::chrono::high_resolution_clock::now();
        genRandInt0(sizes[i], i);
        end = std::chrono::high_resolution_clock::now();
        int_s = std::chrono::duration<double, std::milli>(end - start);
        std::cout << "genRandInt0 elapsed time is " << int_s.count() << " milliseconds" << std::endl;


        cout << "Gen Desc Int" << endl;
        
        start = std::chrono::high_resolution_clock::now();
        genDescInt0(sizes[i], i);
        end = std::chrono::high_resolution_clock::now();
        int_s = std::chrono::duration<double, std::milli>(end - start);
        std::cout << "genDescInt0 elapsed time is " << int_s.count() << " milliseconds" << std::endl;

        cout << "Gen Rand Int 20" << endl;
       
        start = std::chrono::high_resolution_clock::now();
        genRandInt20(sizes[i], i);
        end = std::chrono::high_resolution_clock::now();
        int_s = end - start;
        std::cout << "genRandInt20 elapsed time is " << int_s.count() << " milliseconds" << std::endl;
        
        cout << "Gen Rand Int 40" << endl;

        start = std::chrono::high_resolution_clock::now();
        genRandInt40(sizes[i], i);
        end = std::chrono::high_resolution_clock::now();
        int_s = std::chrono::duration<double, std::milli>(end - start);
        std::cout << "genRandInt40 elapsed time is " << int_s.count() << " milliseconds" << std::endl;

        cout << "Gen Asc Str" << endl;

        start = std::chrono::high_resolution_clock::now();
        genAscStr0(sizes[i]);
        end = std::chrono::high_resolution_clock::now();
        int_s = std::chrono::duration<double, std::milli>(end - start);
        std::cout << "genAscStr0 elapsed time is " << int_s.count() << " milliseconds" << std::endl;

        cout << "Gen Rand Str" << endl;

        start = std::chrono::high_resolution_clock::now();
        genRandStr0(sizes[i], i);
        end = std::chrono::high_resolution_clock::now();
        int_s = std::chrono::duration<double, std::milli>(end - start);
        std::cout << "genRandStr0 elapsed time is " << int_s.count() << " milliseconds" << std::endl;

        cout << "Gen Desc Str" << endl;

        start = std::chrono::high_resolution_clock::now();
        genDescStr0(sizes[i], i);
        end = std::chrono::high_resolution_clock::now();
        int_s = std::chrono::duration<double, std::milli>(end - start);
        std::cout << "genDescStr0 elapsed time is " << int_s.count() << " milliseconds" << std::endl;

        cout << "Gen Rand Str 20" << endl;

        start = std::chrono::high_resolution_clock::now();
        genRandStr20(sizes[i], i);
        end = std::chrono::high_resolution_clock::now();
        int_s = std::chrono::duration<double, std::milli>(end - start);
        std::cout << "genRandStr20 elapsed time is " << int_s.count() << " milliseconds" << std::endl;

        cout << "Gen Rand Str 40" << endl;

        start = std::chrono::high_resolution_clock::now();
        genRandStr40(sizes[i], i);
        end = std::chrono::high_resolution_clock::now();
        int_s = std::chrono::duration<double, std::milli>(end - start);
        std::cout << "genRandStr40 elapsed time is " << int_s.count() << " milliseconds" << std::endl;

    }
};

void DataGen::writeSets() {
    ofstream setFile;
    setFile.open(dataFile);

    setFile << "Integers" << endl;

    for (int i = 0; i < sizes.size(); i++) {

        setFile << "Randomized, size " << rand0Int[i].size() << ", 0%" << endl;
        for (int j = 0; j < rand0Int[i].size(); j++) {
            setFile << rand0Int[i][j] << ", ";
        }
        setFile << endl << endl;

        setFile << "Ascending, size " << asc0Int[i].size() << ", 0%" << endl;
        for (int j = 0; j < asc0Int[i].size(); j++) {
            setFile << asc0Int[i][j] << ", ";
        }
        setFile << endl << endl;

        setFile << "Descending, size " << desc0Int[i].size() << ", 0%" << endl;
        for (int j = 0; j < desc0Int[i].size(); j++) {
            setFile << desc0Int[i][j] << ", ";
        }
        setFile << endl << endl;

        setFile << "Randomized, size " << rand20Int[i].size() << ", 20%" << endl;
        for (int j = 0; j < rand20Int[i].size(); j++) {
            setFile << rand20Int[i][j] << ", ";
        }
        setFile << endl << endl;

        setFile << "Randomized, size " << rand40Int[i].size() << ", 40%" << endl;
        for (int j = 0; j < rand40Int[i].size(); j++) {
            setFile << rand40Int[i][j] << ", ";
        }
        setFile << endl << endl;
    }

    setFile << endl << "Strings" << endl;

    for (int i = 0; i < sizes.size(); i++) {
        setFile << "Randomized, size " << rand0Str[i].size() << ", 0%" << endl;
        for (int j = 0; j < rand0Str[i].size(); j++) {
            setFile << rand0Str[i][j] << ", ";
        }
        setFile << endl << endl;

        setFile << "Ascending, size " << asc0Str[i].size() << ", 0%" << endl;
        for (int j = 0; j < asc0Str[i].size(); j++) {
            setFile << asc0Str[i][j] << ", ";
        }
        setFile << endl << endl;

        setFile << "Descending, size " << desc0Str[i].size() << ", 0%" << endl;
        for (int j = 0; j < desc0Str[i].size(); j++) {
            setFile << desc0Str[i][j] << ", ";
        }
        setFile << endl << endl;

        setFile << "Randomized, size " << rand20Str[i].size() << ", 20%" << endl;
        for (int j = 0; j < rand20Str[i].size(); j++) {
            setFile << rand20Str[i][j] << ", ";
        }
        setFile << endl << endl;

        setFile << "Randomized, size " << rand40Str[i].size() << ", 40%" << endl;
        for (int j = 0; j < rand40Str[i].size(); j++) {
            setFile << rand40Str[i][j] << ", ";
        }
        setFile << endl << endl;
    }
};

void DataGen::genAscInt0(int size) {
    AlgoVector<int> intSet;
//---generate integer set---
    int num = 0;
    for (int i = 0; i < size; i++) {
        num += (rand() % 2 + 1);
        intSet.push_back(num);        
    }
    //std::random_shuffle(intSet.begin(), intSet.end());
    asc0Int.push_back(intSet);
}

void DataGen::genAscStr0(int size) {
    AlgoVector<string> stringSet;
//---generate string set---
    for (int i = 0; i < size; i++) {
        string str;
        str.reserve(strLength);

        //generates new string using lookup table
        static const char alphanum[] = 
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

        for (int s = 0; s < strLength; s++) {
            str += alphanum[rand() % (sizeof(alphanum) - 1)];
        }

        bool isDupe = false;

        // for (int j = 0; j < stringSet.size(); j++) {
        //     if (str == stringSet[j]) {
        //         i--;
        //         isDupe = true;
        //         break;
        //     }
        // }

        if (!isDupe) {
            stringSet.push_back(str);
        }
    }
    asc0Str.push_back(stringSet);
};

void DataGen::genRandInt0(int size, int iteration) {
    AlgoVector<int> intSet;
//---generate integer set---
    for (int i = 0; i < size; i++) {
        intSet.push_back(asc0Int[iteration][i]);
    }
    random_shuffle(intSet.begin(), intSet.end());
    rand0Int.push_back(intSet);
}
void DataGen::genRandStr0(int size, int iteration) {
    AlgoVector<string> stringSet;
//---generate string set---
    for (int i = 0; i < size; i++) {
        stringSet.push_back(asc0Str[iteration][i]);
    }
    random_shuffle(stringSet.begin(), stringSet.end());
    rand0Str.push_back(stringSet);
};

void DataGen::genDescInt0(int size, int iteration) {
    AlgoVector<int> intSetReverse;
    for(int j = asc0Int[iteration].size()-1; j >= 0; j--){
        intSetReverse.push_back(asc0Int[iteration][j]);
    }
    desc0Int.push_back(intSetReverse);
}
void DataGen::genDescStr0(int size, int iteration) {
    AlgoVector<string> stringSetReverse;
    for(int j = asc0Str[iteration].size()-1; j >= 0; j--){
        stringSetReverse.push_back(asc0Str[iteration][j]);
    }
    desc0Str.push_back(stringSetReverse);
};

void DataGen::genRandInt20(int size, int iteration) {
    AlgoVector<int> intSet;

//---generate string set---
    while(intSet.size() < size){
        intSet.push_back(rand0Int[iteration][intSet.size()]);
        if(intSet.size() % 5 == 1 && intSet.size() + 1 < size){
            intSet.push_back(rand0Int[iteration][intSet.size()-1]);
        }
    }
    rand20Int.push_back(intSet);
}

void DataGen::genRandStr20(int size, int iteration) {
    AlgoVector<string> stringSet;

//---generate string set---
    while(stringSet.size() < size){
        stringSet.push_back(rand0Str[iteration][stringSet.size()]);
        if(stringSet.size() % 5 == 1 && stringSet.size() + 1 < size){
            stringSet.push_back(rand0Str[iteration][stringSet.size()-1]);
        }
    }
    rand20Str.push_back(stringSet);
};

void DataGen::genRandInt40(int size, int iteration) {
    AlgoVector<int> intSet;

//---generate string set---
    while(intSet.size() < size){
        intSet.push_back(rand0Int[iteration][intSet.size()]);
        if(intSet.size() % 10 == 1 && intSet.size() + 3 < size){
            intSet.push_back(rand0Int[iteration][intSet.size()-1]);
            intSet.push_back(rand0Int[iteration][intSet.size()-2]);
            intSet.push_back(rand0Int[iteration][intSet.size()-3]);
        }
    }
    rand40Int.push_back(intSet);
}

void DataGen::genRandStr40(int size, int iteration) {
    AlgoVector<string> stringSet;

//---generate string set---
    while(stringSet.size() < size){
        stringSet.push_back(rand0Str[iteration][stringSet.size()]);
        if(stringSet.size() % 10 == 1 && stringSet.size() + 3 < size){
            stringSet.push_back(rand0Str[iteration][stringSet.size()-1]);
            stringSet.push_back(rand0Str[iteration][stringSet.size()-2]);
            stringSet.push_back(rand0Str[iteration][stringSet.size()-3]);
        }
    }
    rand40Str.push_back(stringSet);
};

AlgoVector<AlgoVector<int>> & DataGen::getRand0Int(){
    return this->rand0Int;
}
AlgoVector<AlgoVector<int>> & DataGen::getAsc0Int(){
    return this->asc0Int;
}
AlgoVector<AlgoVector<int>> & DataGen::getDesc0Int(){
    return this->desc0Int;
}
AlgoVector<AlgoVector<int>> & DataGen::getRand20Int(){
    return this->rand20Int;
}
AlgoVector<AlgoVector<int>> & DataGen::getRand40Int(){
    return this->rand40Int;
}