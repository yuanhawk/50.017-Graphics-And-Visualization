//
// Created by Tan Li Yuan on 22/5/22.
//

#include "Mesh.h"

Mesh::Mesh() {
    VAO = 0;
    VBO = 0;
}

void Mesh::CreateMesh(GLfloat *vertices, unsigned int numOfVertices) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * numOfVertices, vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

void Mesh::RenderMesh() {
    glBindVertexArray(VAO);

    // render the triangle
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // render the triangle edges
    //glDrawArrays(GL_LINE_LOOP, 0, 3);

    // render the triangle vertices
    //glEnable(GL_PROGRAM_POINT_SIZE);
    //glPointSize(50.0);
    //glDrawArrays(GL_POINTS, 0, 3);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);
}

void Mesh::ClearMesh() {
    if (VBO != 0) {
        glDeleteBuffers(1, &VBO);
        VBO = 0;
    }
    if (VAO != 0) {
        glDeleteVertexArrays(1, &VAO);
        VAO = 0;
    }
}

Mesh::~Mesh() {
    ClearMesh();
}
