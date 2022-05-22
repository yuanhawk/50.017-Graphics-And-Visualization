//
// Created by Tan Li Yuan on 22/5/22.
//

#include <glad/glad.h>

class Mesh {
public:
    Mesh();

    void CreateMesh(GLfloat *vertices, unsigned int numOfVertices);
    void RenderMesh();
    void ClearMesh();

    ~Mesh();

private:
    unsigned int VAO, VBO;
};