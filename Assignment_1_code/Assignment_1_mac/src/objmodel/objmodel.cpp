//
// Created by yuanhawk on 5/28/22.
//

#include "objmodel.h"

// val to be updated with R0: 0 - 2; R1: 3 - 5

objmodel::objmodel() {
}

bool objmodel::LoadFile(const char *fileLocation) {
    vector<normal> vertNorm;
    vector<face> faces;

    ifstream fileStream(fileLocation, ios::in);

    if (!fileStream.is_open()) {
        cout << "Failed to read " << fileLocation << "! File doesn't exist." << endl;
        return false;
    }

    string line = "";

    while (getline(fileStream, line)) {
        if (CheckString(line, "v ")) {
            float x, y, z;
            sscanf(line.c_str(), "v %f %f %f", &x, &y, &z);
            verList.insert(verList.end(), {x, y, z, 0, 0, 0});
        } else if (CheckString(line, "vn ")) {
            normal n;
            sscanf(line.c_str(), "vn %f %f %f", &n.x, &n.y, &n.z);
            vertNorm.push_back(n);
        } else if (CheckString(line, "f ")) {
            int u;
            face f;
            sscanf(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d", &f.v1, &u, &f.n1, &f.v2, &u, &f.n2, &f.v3, &u, &f.n3);
            faces.push_back(f);
        }
    }

    for (face f: faces) {
        AddVertexData(f.v1, f.n1, vertNorm);
        AddVertexData(f.v2, f.n2, vertNorm);
        AddVertexData(f.v3, f.n3, vertNorm);
    }

    fileStream.close();
    return true;
}

bool objmodel::CheckString(string &line, const char *text) {
    size_t textLen = strlen(text);
    if (line.size() < textLen) return false;
    for (size_t i = 0; i < textLen; ++i) {
        if (line[i] != text[i]) return false;
    }
    return true;
}

void objmodel::AddVertexData(int vIn, int vnIn, vector<normal> &vertNorm) {
    normal n = vertNorm[vnIn - 1];

    verList[(vIn - 1) * 6 + 3] = n.x;
    verList[(vIn - 1) * 6 + 4] = n.y;
    verList[(vIn - 1) * 6 + 5] = n.z;

    triList.push_back(vIn - 1);
}

vector<float> objmodel::GetVerList() {
    return verList;
};

vector<unsigned int> objmodel::GetTriList() {
    return triList;
}
