#version 330 core
 
layout (lines_adjacency) in; //基元类型模式lines_adjacency,输入图元邻接线，输入数组gl_in[]大小为4，刚好绘制三次bezier曲线需要四个控制点
layout (line_strip, max_vertices = 200) out; //将一个点变为最多32个可连成线条的点 交给FragShader

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void creatBezier(){
   int segments = 1000;
   float delta = 1.0 / float(segments);
   vec4 v;
   for ( int i=0; i<=segments; ++i )
   {
	    float   t   =   delta * float(i);//插值计算参数t与segment关联起来
        vec3    p0  =   gl_in[0].gl_Position.xyz;   
        vec3    p1  =   gl_in[1].gl_Position.xyz;   
        vec3    p2  =   gl_in[2].gl_Position.xyz;   
        vec3    p3  =   gl_in[3].gl_Position.xyz;   
        float   len =   length(p1 - p0)/2.0;   
        // Linear interpolation 
        vec3    p;  
        p.x = (1 - t) * (1 - t) * (1 - t) * p0.x + 3 * t * (1 - t) * (1 - t)* p1.x + 3 * t*t* (1 - t)* p2.x + t * t * t * p3.x;
        p.y = (1 - t) * (1 - t) * (1 - t) * p0.y + 3 * t * (1 - t) * (1 - t)* p1.y + 3 * t*t* (1 - t)* p2.y + t * t * t * p3.y;
        p.z =   0;
        gl_Position = projection * view * model * vec4(p, 1); 
       EmitVertex();
  }
}
 
void main(){
    creatBezier();
}
