//
// Created by yuanhawk on 5/28/22.
//
#include <vector>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class loadmesh {

public:
    loadmesh(vector<float> verList, vector<unsigned> triList);

    bool ReadFile(const char* fileLocation);

    vector<float> getVerList() {
        return verList;
    };
    vector<unsigned int> getTriList() {
        return triList;
    }

private:
    vector<float> verList;
    vector<unsigned int> triList;
};