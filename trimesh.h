#ifndef _TRIMESH
#define _TRIMESH

#include "ofMain.h"

class trimesh {
    
public:
    
    int rows;
    int cols;
    float width;
    float height;
    std::map<int, float> vertexMap;
    
    ofVboMesh mesh;
    ofVbo myVbo;
    ofColor meshColor;
    int color;
    
    trimesh(int _rows, int _cols, float _width, float _height, int _color);
    void update();
    void draw();
};

#endif
