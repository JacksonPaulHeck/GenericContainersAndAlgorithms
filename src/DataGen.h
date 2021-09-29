#ifndef _DATAGEN_H
#define _DATAGEN_H

#include <iostream>
#include <fstream>
#include <exception>
#include <vector>
#include <string>

using namespace std;

class DataGen {
    public:
        DataGen(vector<int> sizesToUse);
        void genSets();
        void writeSets();
        void genRand0(int size);
        void genAsc0(int size);
        void genDesc0(int size);
        void genRand20(int size);
        void genRand40(int size);

        vector<int> sizes;
        vector<vector<int>> rand0Int;
        vector<vector<int>> asc0Int;
        vector<vector<int>> desc0Int;
        vector<vector<int>> rand20Int;
        vector<vector<int>> rand40Int;

        vector<vector<string>> rand0Str;
        vector<vector<string>> asc0Str;
        vector<vector<string>> desc0Str;
        vector<vector<string>> rand20Str;
        vector<vector<string>> rand40Str;
};

DataGen::DataGen(vector<int> sizesToUse) {
    this->sizes = sizesToUse;
};

void DataGen::genSets() {
    for (int i = 0; i < sizes.size(); i++) {
        genRand0(sizes[i]);
        genAsc0(sizes[i]);
        genDesc0(sizes[i]);
        genRand20(sizes[i]);
        genRand40(sizes[i]);
    }
};

void DataGen::writeSets() {
    ofstream setFile;
    setFile.open("./input/datasets.txt");

    setFile << "Integers" << endl;

    for (int i = 0; i < sizes.size(); i++) {
        int subSize = rand0Int[i].size();

        setFile << "Randomized, size " << subSize << ", 0%" << endl;
        for (int j = 0; j < subSize; j++) {
            setFile << rand0Int[i][j] << ", ";
        }
        setFile << endl << endl;

        setFile << "Ascending, size " << subSize << ", 0%" << endl;
        for (int j = 0; j < subSize; j++) {
            setFile << asc0Int[i][j] << ", ";
        }
        setFile << endl << endl;

        setFile << "Descending, size " << subSize << ", 0%" << endl;
        for (int j = 0; j < subSize; j++) {
            setFile << desc0Int[i][j] << ", ";
        }
        setFile << endl << endl;

        setFile << "Randomized, size " << subSize << ", 20%" << endl;
        for (int j = 0; j < subSize; j++) {
            setFile << rand20Int[i][j] << ", ";
        }
        setFile << endl << endl;

        setFile << "Randomized, size " << subSize << ", 40%" << endl;
        for (int j = 0; j < subSize; j++) {
            setFile << rand40Int[i][j] << ", ";
        }
        setFile << endl << endl;
    }

    setFile << endl << "Strings" << endl;

    for (int i = 0; i < sizes.size(); i++) {
        int subSize = rand0Str[i].size();

        setFile << "Randomized, size " << subSize << ", 0%" << endl;
        for (int j = 0; j < subSize; j++) {
            setFile << rand0Str[i][j] << ", ";
        }
        setFile << endl << endl;

        setFile << "Ascending, size " << subSize << ", 0%" << endl;
        for (int j = 0; j < subSize; j++) {
            setFile << asc0Str[i][j] << ", ";
        }
        setFile << endl << endl;

        setFile << "Descending, size " << subSize << ", 0%" << endl;
        for (int j = 0; j < subSize; j++) {
            setFile << desc0Str[i][j] << ", ";
        }
        setFile << endl << endl;

        setFile << "Randomized, size " << subSize << ", 20%" << endl;
        for (int j = 0; j < subSize; j++) {
            setFile << rand20Str[i][j] << ", ";
        }
        setFile << endl << endl;

        setFile << "Randomized, size " << subSize << ", 40%" << endl;
        for (int j = 0; j < subSize; j++) {
            setFile << rand40Str[i][j] << ", ";
        }
        setFile << endl << endl;
    }
};

void DataGen::genRand0(int size) {
    vector<int> intSet;
    vector<string> stringSet;

    //generate integer set
    rand0Int.push_back(intSet);

    //generate string set
    rand0Str.push_back(stringSet);
};

void DataGen::genAsc0(int size) {
    vector<int> intSet;
    vector<string> stringSet;

    //generate integer set
    asc0Int.push_back(intSet);

    //generate string set
    asc0Str.push_back(stringSet);
};

void DataGen::genDesc0(int size) {
    vector<int> intSet;
    vector<string> stringSet;

    //generate integer set
    desc0Int.push_back(intSet);

    //generate string set
    desc0Str.push_back(stringSet);
};

void DataGen::genRand20(int size) {
    vector<int> intSet;
    vector<string> stringSet;

    //generate integer set
    rand20Int.push_back(intSet);

    //generate string set
    rand20Str.push_back(stringSet);
};

void DataGen::genRand40(int size) {
    vector<int> intSet;
    vector<string> stringSet;

    //generate integer set
    rand40Int.push_back(intSet);

    //generate string set
    rand40Str.push_back(stringSet);
};
#endif