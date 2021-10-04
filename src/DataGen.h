#ifndef _DATAGEN_H
#define _DATAGEN_H

#include <iostream>
#include <fstream>
#include <exception>
#include <vector>
#include <string>
#include <random>
#include <cstring>
#include <climits>

using namespace std;

class DataGen {
    public:
        DataGen(vector<int> sizesToUse);
        string getDataFile();
        void genSets();
        void writeSets();
        void genRand0(int size);
        void genAsc0(int size);
        void genDesc0(int size);
        void genRand20(int size);
        void genRand40(int size);

        string dataFile;
        int strLength;
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
    this->dataFile = "./input/datasets.txt";
    this->strLength = 10;
};

string DataGen::getDataFile() {
    return dataFile;
}

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
    setFile.open(dataFile);

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

//---generate integer set---
    for (int i = 0; i < size; i++) {
        int num = rand() % (size * 2);
        bool isDupe = false;

        for (int j = 0; j < intSet.size(); j++) {
            if (num == intSet[j]) {
                i--;
                isDupe = true;
                break;
            }
        }

        if (!isDupe) {
            intSet.push_back(num);
        }
    }
    rand0Int.push_back(intSet);

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

        for (int j = 0; j < stringSet.size(); j++) {
            if (str == stringSet[j]) {
                i--;
                isDupe = true;
                break;
            }
        }

        if (!isDupe) {
            stringSet.push_back(str);
        }
    }
    rand0Str.push_back(stringSet);
};

void DataGen::genAsc0(int size) {
    vector<int> intSet;
    vector<string> stringSet;
    int interval = INT_MAX / size;

//---generate integer set---
    for (int i = 0; i < size; i++) {
        int num = rand() % (interval * (i+1)) + (interval * i);

        bool isDupe = false;

        for (int j = 0; j < intSet.size(); j++) {
            if (num == intSet[j]) {
                i--;
                isDupe = true;
                break;
            }
        }

        if (!isDupe) {
            intSet.push_back(num);
        }
    }
    asc0Int.push_back(intSet);

//---generate string set---
    for (int i = 0; i < size; i++) {
        string str;
        str.reserve(strLength);

        static const char alphanum[] = 
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

        for (int s = 0; s < strLength; s++) {
            str += alphanum[rand() % (sizeof(alphanum) - 1)];
        }

        bool isInvalid = false;

        for (int j = 0; j < stringSet.size(); j++) {
            if (str == stringSet[j]) {
                i--;
                isInvalid = true;
                break;
            }
        }
        if (stringSet.size() >= 1 && str < stringSet[stringSet.size() - 1]) {
            i--;
            isInvalid = true;
        }

        if (!isInvalid) {
            stringSet.push_back(str);
        }

        // possible version to prevent accidentally generating values too high
        /*
        int randNum = rand() % (interval * (i+1)) + (interval * i);

        static const char alphanum[] = 
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

        for (int s = 0; s < strLength; s++) {
            randNum
        }
        */
    }
    asc0Str.push_back(stringSet);
};

void DataGen::genDesc0(int size) {
    vector<int> intSet;
    vector<string> stringSet;
    int interval = size;

//---generate integer set---
    for (int i = size - 1; i >= 0; i++) {
        int num = rand() % (interval * (i+1)) + (interval * i);

        bool isDupe = false;

        for (int j = 0; j < intSet.size(); j++) {
            if (num == intSet[j]) {
                i--;
                isDupe = true;
                break;
            }
        }

        if (!isDupe) {
            intSet.push_back(num);
        }
    }
    desc0Int.push_back(intSet);

//---generate string set--
    for (int i = 0; i < size; i++) {
        string str;
        str.reserve(strLength);

        static const char alphanum[] = 
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

        for (int s = 0; s < strLength; s++) {
            str += alphanum[rand() % (sizeof(alphanum) - 1)];
        }

        bool isInvalid = false;

        for (int j = 0; j < stringSet.size(); j++) {
            if (str == stringSet[j]) {
                i--;
                isInvalid = true;
                break;
            }
        }
        if (stringSet.size() >= 1 && str > stringSet[stringSet.size() - 1]) {
            i--;
            isInvalid = true;
        }

        if (!isInvalid) {
            stringSet.push_back(str);
        }
    }
    desc0Str.push_back(stringSet);
};

void DataGen::genRand20(int size) {
    vector<int> intSet;
    vector<string> stringSet;

    //---generate integer set---
    for (int i = 0; i < size; i++) {
        int num = rand() % (size * 2);

        if (i == 0) {
            while (i < size / 5) {
                intSet.push_back(num);
                i++;
            }
        } else {
            bool isDupe = false;
            for (int j = 0; j < intSet.size(); j++) {
                if (num == intSet[j]) {
                    i--;
                    isDupe = true;
                    break;
                }
            }

            if (!isDupe) {
                intSet.push_back(num);
            }
        }
    }
    rand20Int.push_back(intSet);

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

        if (i == 0) {
            while (i < size / 5) {
                stringSet.push_back(str);
            }
        } else {
            bool isDupe = false;

            for (int j = 0; j < stringSet.size(); j++) {
                if (str == stringSet[j]) {
                    i--;
                    isDupe = true;
                    break;
                }
            }

            if (!isDupe) {
                stringSet.push_back(str);
            }
        }
    }
    rand20Str.push_back(stringSet);
};

void DataGen::genRand40(int size) {
    vector<int> intSet;
    vector<string> stringSet;

    //---generate integer set---
    for (int i = 0; i < size; i++) {
        int num = rand() % (size * 2);

        if (i == 0) {
            while (i < (size / 5) * 2) {
                intSet.push_back(num);
                i++;
            }
        } else {
            bool isDupe = false;
            for (int j = 0; j < intSet.size(); j++) {
                if (num == intSet[j]) {
                    i--;
                    isDupe = true;
                    break;
                }
            }

            if (!isDupe) {
                intSet.push_back(num);
            }
        }
    }
    rand40Int.push_back(intSet);

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

        if (i == 0) {
            while (i < (size / 5) * 2) {
                stringSet.push_back(str);
            }
        } else {
            bool isDupe = false;

            for (int j = 0; j < stringSet.size(); j++) {
                if (str == stringSet[j]) {
                    i--;
                    isDupe = true;
                    break;
                }
            }

            if (!isDupe) {
                stringSet.push_back(str);
            }
        }
    }
    rand40Str.push_back(stringSet);
};
#endif