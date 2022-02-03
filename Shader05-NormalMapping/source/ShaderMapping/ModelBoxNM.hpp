#pragma once

#include "CELLMath.hpp"
#include "Camera.hpp"
#include "ShaderLightNM2.hpp"
class   ModelBoxNM
{
public:
    struct V3N3UV2
    {
        float x,y,z;
        float nx,ny,nz;
        float u, v;
    };

    struct NORMALMAP
    {
        float x, y, z;
        float nx, ny, nz;
        float u, v;
        float tx,ty,tz;
        float bx,by,bz;
    };
public:
    NORMALMAP _data[36];
public:
    ModelBoxNM(const CELL::float3& halfSize)
    {     
        V3N3UV2  verts[] =
        {
            { 0.5f, -0.5f,  0.5f ,  1.0, 0.0, 0.0, 0.0f, 0.0f  },
            { 0.5f, -0.5f, -0.5f ,  1.0, 0.0, 0.0, 1.0f, 0.0f  },
            { 0.5f,  0.5f, -0.5f ,  1.0, 0.0, 0.0, 1.0f, 1.0f  },
                                                               
            { 0.5f,  0.5f, -0.5f ,  1.0, 0.0, 0.0, 1.0f, 1.0f  },
            { 0.5f,  0.5f,  0.5f ,  1.0, 0.0, 0.0, 0.0f, 1.0f  },
            { 0.5f, -0.5f,  0.5f ,  1.0, 0.0, 0.0, 0.0f, 0.0f  },
                                                               
            {-0.5f, -0.5f, -0.5f ,  -1.0, 0.0,0.0, 0.0f, 0.0f  },
            {-0.5f, -0.5f,  0.5f ,  -1.0, 0.0,0.0, 1.0f, 0.0f  },
            {-0.5f,  0.5f,  0.5f ,  -1.0, 0.0,0.0, 1.0f, 1.0f  },
                                                               
            {-0.5f,  0.5f,  0.5f ,  -1.0, 0.0,0.0, 1.0f, 1.0f  },
            {-0.5f,  0.5f, -0.5f ,  -1.0, 0.0,0.0, 0.0f, 1.0f  },
            {-0.5f, -0.5f, -0.5f ,  -1.0, 0.0,0.0, 0.0f, 0.0f  },
                                                               
            {-0.5f,  0.5f,  0.5f ,  -0.0, 1.0,0.0, 1.0f, 0.0f  },
            { 0.5f,  0.5f,  0.5f ,  -0.0, 1.0,0.0, 0.0f, 0.0f  },
            { 0.5f,  0.5f, -0.5f ,  -0.0, 1.0,0.0, 0.0f, 1.0f  },

            { 0.5f,  0.5f, -0.5f ,  0.0, 1.0,0.0, 0.0f, 1.0f   },
            {-0.5f,  0.5f, -0.5f ,  0.0, 1.0,0.0, 1.0f, 1.0f   },
            {-0.5f,  0.5f,  0.5f ,  0.0, 1.0,0.0, 1.0f, 0.0f   },

            {-0.5f, -0.5f, -0.5f ,  0.0, -1.0,0.0, 1.0f, 0.0f  },
            { 0.5f, -0.5f, -0.5f ,  0.0, -1.0,0.0, 0.0f, 0.0f  },
            { 0.5f, -0.5f,  0.5f ,  0.0, -1.0,0.0, 0.0f, 1.0f  },
                                                              
            { 0.5f, -0.5f,  0.5f ,  0.0, -1.0,0.0, 0.0f, 1.0f  },
            {-0.5f, -0.5f,  0.5f ,  0.0, -1.0,0.0, 1.0f, 1.0f  },
            {-0.5f, -0.5f, -0.5f ,  0.0, -1.0,0.0, 1.0f, 0.0f  },

            {-0.5f, -0.5f,  0.5f,   0.0, 0.0, 1.0,  0.0f, 0.0f },
            { 0.5f, -0.5f,  0.5f,   0.0, 0.0, 1.0,  1.0f, 0.0f },
            { 0.5f,  0.5f,  0.5f,   0.0, 0.0, 1.0,  1.0f, 1.0f },
                                                               
            { 0.5f,  0.5f,  0.5f,   0.0, 0.0, 1.0,  1.0f, 1.0f },
            {-0.5f,  0.5f,  0.5f,   0.0, 0.0, 1.0,  0.0f, 1.0f },
            {-0.5f, -0.5f,  0.5f,   0.0, 0.0, 1.0,  0.0f, 0.0f },
                                                               
            { 0.5f, -0.5f, -0.5f,   0.0, 0.0,-1.0,  0.0f, 0.0f },
            {-0.5f, -0.5f, -0.5f,   0.0, 0.0,-1.0,  1.0f, 0.0f },
            {-0.5f,  0.5f, -0.5f,   0.0, 0.0,-1.0,  1.0f, 1.0f },
                                                               
            {-0.5f,  0.5f, -0.5f,   0.0, 0.0,-1.0,  1.0f, 1.0  },
            { 0.5f,  0.5f, -0.5f,   0.0, 0.0,-1.0,  0.0f, 1.0  },
            { 0.5f, -0.5f, -0.5f,   0.0, 0.0,-1.0,  0.0f, 0.0  },
        };
        for (int i = 0 ;i < 36 ; ++ i )
        {
            verts[i].x*=    halfSize.x;
            verts[i].y*=    halfSize.y;
            verts[i].z*=    halfSize.z;
        }
        convertTBN(verts,_data);
        //memcpy(_data,verts,sizeof(verts));
    }
    void convertTBN(V3N3UV2* vertices,NORMALMAP* nmVerts)
    {
        for (size_t i = 0; i <36; i += 3) 
        {
            nmVerts[i + 0].x = vertices[i + 0].x;
            nmVerts[i + 0].y = vertices[i + 0].y;
            nmVerts[i + 0].z = vertices[i + 0].z;

            nmVerts[i + 1].x = vertices[i + 1].x;
            nmVerts[i + 1].y = vertices[i + 1].y;
            nmVerts[i + 1].z = vertices[i + 1].z;

            nmVerts[i + 2].x = vertices[i + 2].x;
            nmVerts[i + 2].y = vertices[i + 2].y;
            nmVerts[i + 2].z = vertices[i + 2].z;

            nmVerts[i + 0].nx = vertices[i + 0].nx;
            nmVerts[i + 0].ny = vertices[i + 0].ny;
            nmVerts[i + 0].nz = vertices[i + 0].nz;

            nmVerts[i + 1].nx = vertices[i + 1].nx;
            nmVerts[i + 1].ny = vertices[i + 1].ny;
            nmVerts[i + 1].nz = vertices[i + 1].nz;

            nmVerts[i + 2].nx = vertices[i + 2].nx;
            nmVerts[i + 2].ny = vertices[i + 2].ny;
            nmVerts[i + 2].nz = vertices[i + 2].nz;

            nmVerts[i + 0].u = vertices[i + 0].u;
            nmVerts[i + 0].v = vertices[i + 0].v;

            nmVerts[i + 1].u = vertices[i + 1].u;
            nmVerts[i + 1].v = vertices[i + 1].v;

            nmVerts[i + 2].u = vertices[i + 2].u;
            nmVerts[i + 2].v = vertices[i + 2].v;


            // Shortcuts for vertices
            float3  v0  =   float3(vertices[i + 0].x,vertices[i + 0].y,vertices[i + 0].z);
            float3  v1  =   float3(vertices[i + 1].x,vertices[i + 1].y,vertices[i + 1].z);
            float3  v2  =   float3(vertices[i + 2].x,vertices[i + 2].y,vertices[i + 2].z);

            float2  uv0 =   float2(vertices[i + 0].u, vertices[i + 0].v);
            float2  uv1 =   float2(vertices[i + 1].u, vertices[i + 1].v);
            float2  uv2 =   float2(vertices[i + 2].u, vertices[i + 2].v);
            
            // Edges of the triangle : postion delta
            float3  deltaPos1   =   v1 - v0;
            float3  deltaPos2   =   v2 - v0;
            // UV delta
            float2 deltaUV1     =   uv1 - uv0;
            float2 deltaUV2     =   uv2 - uv0;

            float   r           =   1.0f / (deltaUV1.x * deltaUV2.y - deltaUV1.y * deltaUV2.x);
            float3 tangent      =   (deltaPos1 * deltaUV2.y - deltaPos2 * deltaUV1.y)*r;
            float3 binormal     =   (deltaPos2 * deltaUV1.x - deltaPos1 * deltaUV2.x)*r;

            nmVerts[i + 0].tx = tangent.x;  nmVerts[i + 1].tx = tangent.x;  nmVerts[i + 2].tx = tangent.x;
            nmVerts[i + 0].ty = tangent.y;  nmVerts[i + 1].ty = tangent.y;  nmVerts[i + 2].ty = tangent.y;
            nmVerts[i + 0].tz = tangent.z;  nmVerts[i + 1].tz = tangent.z;  nmVerts[i + 2].tz = tangent.z;

            nmVerts[i + 0].bx = binormal.x; nmVerts[i + 1].bx = binormal.x; nmVerts[i + 2].bx = binormal.x;
            nmVerts[i + 0].by = binormal.y; nmVerts[i + 1].by = binormal.y; nmVerts[i + 2].by = binormal.y;
            nmVerts[i + 0].bz = binormal.z; nmVerts[i + 1].bz = binormal.z; nmVerts[i + 2].bz = binormal.z;
        }
    }
};

class   ModelMgrNM
{
public:
    typedef std::vector<CELL::matrix4>  ArrayMatrix;
public:
    ShaderLightNM2  _program;
    ModelBoxNM      _modelBox;
    ArrayMatrix     _locals;
public:
    ModelMgrNM()
        :_modelBox(float3(30,30,30))
    {
        for (float x = 0; x < 1; x += 5)
        {
            for (float z = 0; z < 1; z += 5)
            {
                CELL::matrix4   mat;
                mat.translate(float3(x, 0, z));
                _locals.push_back(mat);
            }
        }
    }

    void    render(Camera& camera)
    {

    static  float angle =   0;
    angle   +=  0.01f;
        _program.begin();
        for (size_t i = 0; i < _locals.size(); ++i)
        {
            {
                CELL::matrix4   matRot;
                matRot.rotateYXZ(angle,angle,angle);
                CELL::matrix4   model   =   _locals[i] * matRot;
                CELL::matrix3   mview3x3=   mat4_to_mat3(model)._inverse(); // 关键点
                CELL::matrix4   view    =   camera.getView();
                CELL::matrix4   proj    =   camera.getProject();
                CELL::matrix4   mvp     =   proj * view * model;
                glUniformMatrix4fv(_program._mvp,   1, false, mvp.data());
                glUniformMatrix4fv(_program._model, 1, false, model.data());
                glUniformMatrix4fv(_program._view,  1, false, view.data());

                glUniformMatrix3fv(_program._noMatrix, 1, false, mview3x3.data());
                glUniform1i(_program._texture, 0);
                glUniform1i(_program._texture1, 1);
                glUniform3f(_program._lightPos, camera._eye.x, camera._eye.y, camera._eye.z);
                glUniform3f(_program._cameraPos, camera._eye.x, camera._eye.y, camera._eye.z);

                /// 这个将点数据传递给shader
                glVertexAttribPointer(_program._position, 3, GL_FLOAT, GL_FALSE, sizeof(ModelBoxNM::NORMALMAP), _modelBox._data);
                glVertexAttribPointer(_program._normal, 3, GL_FLOAT, GL_FALSE, sizeof(ModelBoxNM::NORMALMAP), &_modelBox._data[0].nx);
                glVertexAttribPointer(_program._uv, 2, GL_FLOAT, GL_FALSE, sizeof(ModelBoxNM::NORMALMAP), &_modelBox._data[0].u);
                glVertexAttribPointer(_program._tagent, 3, GL_FLOAT, GL_FALSE, sizeof(ModelBoxNM::NORMALMAP), &_modelBox._data[0].tx);
                glVertexAttribPointer(_program._biTagent, 3, GL_FLOAT, GL_FALSE, sizeof(ModelBoxNM::NORMALMAP), &_modelBox._data[0].bx);
                glDrawArrays(GL_TRIANGLES, 0, 36);
            }
            
        }
        _program.end();        
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
};
