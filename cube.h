#ifndef _CUBE
#define _CUBE

#include "ofMain.h"

class cube
{
    public:

    float w;
    float h;
    float d;

    float x;
    float y;
    float z;

    ofColor cubeColor;
    float cubeHue;

    void update();
    void draw();

    cube(float _w, float _h, float _d, float _cubeHue);
    void setLocation(float _x, float _y, float _z);

    ofMesh mesh;
    ofVbo myVbo;


    private:
};

#endif
