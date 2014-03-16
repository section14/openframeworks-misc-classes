#include "cube.h"

cube::cube(float _w, float _h, float _d, float _cubeHue)
{
    w = _w;
    h = _h;
    d = _d;
    cubeHue = _cubeHue;

    GLfloat vdata[8][3] = {
        {-w, -h, -d}, {-w, h, -d},
        {w, h, -d}, {w, -h, -d},
        {-w, -h, d}, {w, -h, d},
        {-w, h, d}, {w, h, d}
    };

    GLint indices[6][4] = {
        {3, 2, 1, 0},
        {3, 5, 4, 0},
        {3, 5, 7, 2},
        {0, 4, 6, 1},
        {1, 2, 7, 6},
        {5, 4, 6, 7}
    };

    cubeColor = ofColor();
    cubeColor.setHsb(cubeHue,ofRandom(500,255),ofRandom(100,255), 255);

    for (int i=0; i<8; ++i)
    {
        mesh.addVertex(ofVec3f( vdata[i][0], vdata[i][1], vdata[i][2] ));
        mesh.addColor(cubeColor);

        for (int i=0; i<6; ++i)
        {
            mesh.addIndex(indices[i][0]);
            mesh.addIndex(indices[i][1]);
            mesh.addIndex(indices[i][2]);
            mesh.addIndex(indices[i][3]);
        }
    }

    myVbo.setMesh(mesh, GL_STATIC_DRAW);
}

void cube::draw()
{
    myVbo.drawElements(GL_QUADS, 24);
}

void cube::update()
{

}

void cube::setLocation(float _x, float _y, float _z)
{
    x = _x;
    y = _y;
    z = _z;
}
