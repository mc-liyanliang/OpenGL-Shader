#pragma once

#include "GLSLProgram.hpp"

/// gl_Vertex,gl_Normal,
class   ShaderLight :public GLSLProgram
{
public:
    uniform     _mvp;
    uniform     _lightDir;
    uniform     _lightColor;
    uniform     _lightDiffuse;
    uniform     _texture;
    uniform     _texture1;
    attribute   _position;
    attribute   _normal;
    attribute   _uv;
    attribute   _uv1;
public:
    virtual void    initialize()
    {
        const char* vs  =   "#version 330 \n\
                            uniform mat4   _mvp;\n\
                            uniform vec3   _lightDir;\n\
                            uniform vec3   _lightColor;\n\
                            uniform vec3   _lightDiffuse;\n\
                            in      vec3    _position;\n\
                            in      vec3    _normal;\n\
                            in      vec2    _uv;\n\
                            in      vec2    _uv1;\n\
                            out     vec4    _outColor;\n\
                            out     vec2    _outUV;\n\
                            out     vec2    _outUV1;\n\
                            void main()\n\
                            {\n\
                                _outUV      =   _uv;\n\
                                _outUV1     =   _uv1;\n\
                                float NDotL =   max(dot(_normal, _lightDir), 0.0); \n\
                                _outColor   =   vec4(_lightColor * NDotL + _lightDiffuse,1);\n\
                                gl_Position =   _mvp * vec4(_position,1.0);\n\
                            }";
        const char* ps =    "#version 330 \n\
                            in      vec4        _outColor;\n\
                            in      vec2        _outUV;\n\
                            in      vec2        _outUV1;\n\
                            uniform sampler2D   _texture;\n\
                            uniform sampler2D   _texture1;\n\
                            void main()\n\
                            {\n\
                                vec4    color   =   texture2D(_texture,_outUV);\n\
                                vec4    color1  =   texture2D(_texture1,_outUV1);\n\
                                gl_FragColor    =   (color1 * 0.5 + color * 0.5) * _outColor;\n\
                            }";
        createProgram(vs, ps);
        _mvp        =   glGetUniformLocation(_program,  "_mvp");
        _lightDir   =   glGetUniformLocation(_program,  "_lightDir");
        _lightColor =   glGetUniformLocation(_program,  "_lightColor");
        _lightDiffuse = glGetUniformLocation(_program, "_lightDiffuse");
        _texture    =   glGetUniformLocation(_program, "_texture");
        _texture1   =   glGetUniformLocation(_program, "_texture1");
        _position   =   glGetAttribLocation(_program,   "_position");
        _normal     =   glGetAttribLocation(_program,   "_normal");
        _uv         =   glGetAttribLocation(_program,   "_uv");
        _uv1        =   glGetAttribLocation(_program,   "_uv1");
    }

    /**
    *    π”√shader
    */
    virtual void    begin()
    {
        glEnableVertexAttribArray(_position);
        glEnableVertexAttribArray(_normal);
        glEnableVertexAttribArray(_uv);
        glEnableVertexAttribArray(_uv1);
        glUseProgram(_program);
    }
    /**
    *   Ω· ¯
    */
    virtual void    end()
    {
        glDisableVertexAttribArray(_position);
        glDisableVertexAttribArray(_normal);
        glDisableVertexAttribArray(_uv);
        glDisableVertexAttribArray(_uv);
        glUseProgram(0);
    }


};