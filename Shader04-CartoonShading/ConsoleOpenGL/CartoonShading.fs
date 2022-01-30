#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;

uniform vec3 lightDir;
uniform vec3 lightColor;
uniform vec3 objectColor;

void main()
{    
    // diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(-lightDir);
    float diff = max(dot(norm, lightDir), 0.0);
   
    vec3 color;
    if (diff > 0.95)
     color = vec3(1.0, 1.0, 1.0); 
    else if (diff > 0.5)
     color = vec3(0.7, 0.7 ,0.7);
    else if (diff > 0.25)
     color = vec3(0.5, 0.5, 0.5);
    else 
     color = vec3(0.3, 0.3, 0.3);

    vec3 diffuse = color * lightColor;

    vec3 result =  diffuse * objectColor;

    FragColor = vec4(result, 1.0);
}