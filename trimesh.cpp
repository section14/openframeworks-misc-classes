#include "trimesh.h"

trimesh::trimesh(int _rows, int _cols, float _width, float _height, int _color)
{
    rows = _rows + 1;
    cols = _cols + 1;
    width = _width;
    height = _height;
    color = _color;
    
    //calculate height and width
    float rowWidth = width / rows;
    float colHeight = height / cols;
    
    //color var
    meshColor = ofColor();
    
    //create verticies
    for (int rowCount = 0; rowCount<rows; rowCount++)
    {
        for (int colCount = 0; colCount<cols; colCount++)
        {
            float y = rowCount * rowWidth * -1;
            float x = colCount * colHeight;
            
            mesh.addVertex(ofVec3f(x,y,0));
            meshColor.setHsb(color,200,200,200);
            mesh.addColor(meshColor);
        }
    }
    
    /////////////////////////////////
    //create index vector///////////
    ///////////////////////////////
    vector<int> indices;
    
    //location along the drawing path
    int indexLocation = 0;
    
    //two points per column, don't connect indexes
    //on the last row
    int rowSteps = rows - 1;
    int colSteps = cols * 2;
    
    //spacing switch keeps you in the correct place
    //for counting spaces between indexes
    int spacingSwitch = 0;
    
    for (int row = 0; row<rowSteps; row++)
    {
        for (int col = 0; col<colSteps; col++)
        {
            //if this is the last index location
            //write final location
            if (col == colSteps - 1)
            {
                indices.push_back(indexLocation);
            }
            else
            {
                //if spacing switch is even increment index location forward
                //by the number of columns, otherwise refer to next if statement
                if (spacingSwitch%2 == 0)
                {
                    indexLocation += cols;
                    indices.push_back(indexLocation);
                }
                else
                {
                    //if row is even subtract from total columns
                    //else add to total colums for index number spacing
                    if (row%2 == 0)
                    {
                        indexLocation -= cols-1;
                        indices.push_back(indexLocation);
                    }
                    else
                    {
                        indexLocation -= cols+1;
                        indices.push_back(indexLocation);
                    }
                }
                
            }
            
            spacingSwitch++;
            
        }
    }
    
    /////////////////////////////////
    //add indicies to mesh /////////
    ///////////////////////////////
    
    //add 0,0,0 location manually
    mesh.addIndex(0);
    
    for (int i=0; i<indices.size(); i++)
    {
        mesh.addIndex(indices[i]);
    }
    
    //add to vbo
    myVbo.setMesh(mesh, GL_DYNAMIC_DRAW);
}

void trimesh::update()
{

}

void trimesh::draw()
{
    myVbo.drawElements(GL_TRIANGLE_STRIP, mesh.getNumIndices());
}


}
