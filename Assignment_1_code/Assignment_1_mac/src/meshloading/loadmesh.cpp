//
// Created by yuanhawk on 5/28/22.
//

#include "loadmesh.h"

loadmesh::loadmesh(vector<float> verList, vector<unsigned int> triList) {
    this->verList = verList;
    this->triList = triList;
}

bool loadmesh::ReadFile(const char *fileLocation) {
    vector<string> vert, verNorm;
    ifstream fileStream(fileLocation, ios::in);

    if (!fileStream.is_open()) {
        cout << "Failed to read " << fileLocation << "! File doesn't exist." << endl;
        return false;
    }

    vector<float> verNormList;
    string line = "";

    int countVert = 0, countNorm = 0;
    while (!fileStream.eof()) {
        getline(fileStream, line);
        if (line[0] == 'v') {
            if (line[1] == 'n') {
                verNorm.push_back(line.substr(3, line.length()));
                countNorm++;
            } else if (line[1] == ' ') {
                vert.push_back(line.substr(2, line.length()));
                countVert++;
            }
        } else if (line[0] == 'f') {
            line = line.substr(2, line.length());

            stringstream stream(line);
            while (getline(stream, line, '/')) {
                stringstream sstream(line);
                while(getline(sstream, line, ' ')) {
                    unsigned int val = stoul(line, nullptr, 0);
                    triList.push_back(val);
                }
            }
        }
    }

    int countLarger = -1;
    countNorm > countVert ? countLarger = countNorm : countLarger = countVert;

    for (int i = 0; i < countLarger; ++i) {
        line.append(vert[i] + " " + verNorm[i]);
        stringstream sstream(line);
        while(getline(sstream, line, ' ')) {
            cout << line << endl;
            float val = stof(line);
            verList.push_back(val);
        }
    }

    fileStream.close();
    return true;
}