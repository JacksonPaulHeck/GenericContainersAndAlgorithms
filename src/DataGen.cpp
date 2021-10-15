#include "DataGen.h"
#include "Algorithm.h"
#include <chrono>

DataGen::DataGen(AlgoVector<int> sizesToUse) {
  this->sizes = sizesToUse;
  this->dataFile = "./test/datasets.csv";
  this->strLength = 10;
};

std::string DataGen::getDataFile() { return dataFile; }

void DataGen::genSets() {
  for (int i = 0; i < sizes.size(); i++) {
    genAscInt0(sizes[i]);
    genInts(sizes[i], i);
    genRandIntPercents(sizes[i], i);
    genAscStr0(sizes[i]);
    genStrs(sizes[i], i);
    genRandStrPercents(sizes[i], i);
  }
};

void DataGen::writeSets() {
  std::ofstream setFile;
  setFile.open(dataFile);

  setFile << "Integers" << std::endl;

  for (int i = 0; i < sizes.size(); i++) {

    setFile << "Randomized, size " << rand0Int[i].size() << ", 0%" << std::endl;
    for (int j = 0; j < rand0Int[i].size(); j++) {
      setFile << rand0Int[i][j] << ", ";
    }
    setFile << std::endl << std::endl;

    setFile << "Ascending, size " << asc0Int[i].size() << ", 0%" << std::endl;
    for (int j = 0; j < asc0Int[i].size(); j++) {
      setFile << asc0Int[i][j] << ", ";
    }
    setFile << std::endl << std::endl;

    setFile << "Descending, size " << desc0Int[i].size() << ", 0%" << std::endl;
    for (int j = 0; j < desc0Int[i].size(); j++) {
      setFile << desc0Int[i][j] << ", ";
    }
    setFile << std::endl << std::endl;

    setFile << "Randomized, size " << rand20Int[i].size() << ", 20%"
            << std::endl;
    for (int j = 0; j < rand20Int[i].size(); j++) {
      setFile << rand20Int[i][j] << ", ";
    }
    setFile << std::endl << std::endl;

    setFile << "Randomized, size " << rand40Int[i].size() << ", 40%"
            << std::endl;
    for (int j = 0; j < rand40Int[i].size(); j++) {
      setFile << rand40Int[i][j] << ", ";
    }
    setFile << std::endl << std::endl;
  }

  setFile << std::endl << "Strings" << std::endl;

  for (int i = 0; i < sizes.size(); i++) {
    setFile << "Randomized, size " << rand0Str[i].size() << ", 0%" << std::endl;
    for (int j = 0; j < rand0Str[i].size(); j++) {
      setFile << rand0Str[i][j] << ", ";
    }
    setFile << std::endl << std::endl;

    setFile << "Ascending, size " << asc0Str[i].size() << ", 0%" << std::endl;
    for (int j = 0; j < asc0Str[i].size(); j++) {
      setFile << asc0Str[i][j] << ", ";
    }
    setFile << std::endl << std::endl;

    setFile << "Descending, size " << desc0Str[i].size() << ", 0%" << std::endl;
    for (int j = 0; j < desc0Str[i].size(); j++) {
      setFile << desc0Str[i][j] << ", ";
    }
    setFile << std::endl << std::endl;

    setFile << "Randomized, size " << rand20Str[i].size() << ", 20%"
            << std::endl;
    for (int j = 0; j < rand20Str[i].size(); j++) {
      setFile << rand20Str[i][j] << ", ";
    }
    setFile << std::endl << std::endl;

    setFile << "Randomized, size " << rand40Str[i].size() << ", 40%"
            << std::endl;
    for (int j = 0; j < rand40Str[i].size(); j++) {
      setFile << rand40Str[i][j] << ", ";
    }
    setFile << std::endl << std::endl;
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
  // std::random_shuffle(intSet.begin(), intSet.end());
  asc0Int.push_back(intSet);
}

void DataGen::genAscStr0(int size) {
  AlgoDict<std::string> stringSet;
  static const char alphanum[] = "0123456789"
                                 "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                 "abcdefghijklmnopqrstuvwxyz";
  //---generate string set---
  srand(time(NULL));
  for (int i = 0; i < size; i++) {
    std::string str;
    str.reserve(strLength);
    str = "          ";

    // generates new string using lookup table
    str[0] = alphanum[(rand()) % (sizeof(alphanum) - 1)];
    str[1] = alphanum[(rand()) % (sizeof(alphanum) - 1)];
    str[2] = alphanum[(rand()) % (sizeof(alphanum) - 1)];
    str[3] = alphanum[(rand()) % (sizeof(alphanum) - 1)];
    str[4] = alphanum[(rand()) % (sizeof(alphanum) - 1)];
    str[5] = alphanum[(rand()) % (sizeof(alphanum) - 1)];
    str[6] = alphanum[(rand()) % (sizeof(alphanum) - 1)];
    str[7] = alphanum[(rand()) % (sizeof(alphanum) - 1)];
    str[8] = alphanum[(rand()) % (sizeof(alphanum) - 1)];
    str[9] = alphanum[(rand()) % (sizeof(alphanum) - 1)];

    stringSet.insert(str);
  }

  AlgoVector<std::string> stringVec;
  for (auto i : stringSet) {
    stringVec.push_back(i.data);
  }
  asc0Str.push_back(stringVec);
};

void DataGen::genInts(int size, int iteration) {
  AlgoVector<int> intSet;
  AlgoVector<int> intSetReverse;
  //---generate integer set---
  for (int i = 0; i < size; i++) {
    intSet.push_back(asc0Int[iteration][i]);
    intSetReverse.push_back(asc0Int[iteration][size - i - 1]);
  }
  algo_random_shuffle(intSet.begin(), intSet.end());
  rand0Int.push_back(intSet);
  desc0Int.push_back(intSetReverse);
}
void DataGen::genStrs(int size, int iteration) {
  AlgoVector<std::string> stringSet;
  AlgoVector<std::string> stringSetReverse;
  //---generate string set---
  for (int i = 0; i < size; i++) {
    stringSet.push_back(asc0Str[iteration][i]);
    stringSetReverse.push_back(asc0Str[iteration][size - i - 1]);
  }
  algo_random_shuffle(stringSet.begin(), stringSet.end());
  rand0Str.push_back(stringSet);
  desc0Str.push_back(stringSetReverse);
};

void DataGen::genRandIntPercents(int size, int iteration) {
  AlgoVector<int> intSet20;
  AlgoVector<int> intSet40;

  //---generate string set---
  while (intSet20.size() < size && intSet40.size() < size) {
    intSet40.push_back(rand0Int[iteration][intSet40.size()]);
    if (intSet40.size() % 10 == 1 && intSet40.size() + 3 < size) {
      intSet40.push_back(rand0Int[iteration][intSet40.size() - 1]);
      intSet40.push_back(rand0Int[iteration][intSet40.size() - 2]);
      intSet40.push_back(rand0Int[iteration][intSet40.size() - 3]);
    }
    intSet20.push_back(rand0Int[iteration][intSet20.size()]);
    if (intSet20.size() % 5 == 1 && intSet20.size() + 1 < size) {
      intSet20.push_back(rand0Int[iteration][intSet20.size() - 1]);
    }
  }
  rand20Int.push_back(intSet20);
  rand40Int.push_back(intSet40);
}

void DataGen::genRandStrPercents(int size, int iteration) {
  AlgoVector<std::string> stringSet20;
  AlgoVector<std::string> stringSet40;

  //---generate string set---
  while (stringSet20.size() < size && stringSet40.size() < size) {
    stringSet40.push_back(rand0Str[iteration][stringSet40.size()]);
    if (stringSet40.size() % 10 == 1 && stringSet40.size() + 3 < size) {
      stringSet40.push_back(rand0Str[iteration][stringSet40.size() - 1]);
      stringSet40.push_back(rand0Str[iteration][stringSet40.size() - 2]);
      stringSet40.push_back(rand0Str[iteration][stringSet40.size() - 3]);
    }
    stringSet20.push_back(rand0Str[iteration][stringSet20.size()]);
    if (stringSet20.size() % 5 == 1 && stringSet20.size() + 1 < size) {
      stringSet20.push_back(rand0Str[iteration][stringSet20.size() - 1]);
    }
  }
  rand20Str.push_back(stringSet20);
  rand40Str.push_back(stringSet40);
};

AlgoVector<AlgoVector<int>> &DataGen::getRand0Int() { return this->rand0Int; }
AlgoVector<AlgoVector<int>> &DataGen::getAsc0Int() { return this->asc0Int; }
AlgoVector<AlgoVector<int>> &DataGen::getDesc0Int() { return this->desc0Int; }
AlgoVector<AlgoVector<int>> &DataGen::getRand20Int() { return this->rand20Int; }
AlgoVector<AlgoVector<int>> &DataGen::getRand40Int() { return this->rand40Int; }

AlgoVector<AlgoVector<std::string>> &DataGen::getRand0Str() {
  return this->rand0Str;
}
AlgoVector<AlgoVector<std::string>> &DataGen::getAsc0Str() {
  return this->asc0Str;
}
AlgoVector<AlgoVector<std::string>> &DataGen::getDesc0Str() {
  return this->desc0Str;
}
AlgoVector<AlgoVector<std::string>> &DataGen::getRand20Str() {
  return this->rand20Str;
}
AlgoVector<AlgoVector<std::string>> &DataGen::getRand40Str() {
  return this->rand40Str;
}