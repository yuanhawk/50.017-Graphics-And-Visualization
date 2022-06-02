//
// Created by yuanhawk on 5/28/22.
//
#include <vector>

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class objmodel {

public:
    objmodel();

    bool LoadFile(const char* fileLocation);

    vector<float> GetVerList();
    vector<unsigned int> GetTriList();

private:
    struct position { float x, y, z; };
    struct normal { float x, y, z; };
    struct face { int v1, n1, v2, n2, v3, n3; };

    bool CheckString(string& line, const char* text);

    void AddVertexData(int v1, int vn, vector<normal> &vertNorm);

    vector<float> verList;
    vector<unsigned int> triList;
};