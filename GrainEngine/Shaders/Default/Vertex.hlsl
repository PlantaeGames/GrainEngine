cbuffer TransformBuffer : register(b0)
{
    float3 position;
    float3 rotation;
    float3 scale;
};

cbuffer PerspectiveBuffer : register(b1)
{
    float3 camPosition;
    float3 camRotation;
    float3 camScale;
};

struct Output
{
    float4 out_Color : Color;
    float4 out_Position : SV_Position;
};

Output main(float3 _position : Position, float4 _color : Color)
{
    Output output;
    
    // transforming
    
    output.out_Position = float4(_position.x, _position.y, _position.z, 1.0f);
    
    output.out_Position.x += position.x;
    output.out_Position.y += position.y;
    output.out_Position.z += position.z;
    
    output.out_Position.x *= scale.x;
    output.out_Position.y *= scale.y;
    output.out_Position.z *= scale.z;
    
    // rotation z
    float magnitude = sqrt(pow(output.out_Position.x, 2) + pow(output.out_Position.y, 2));
    float angle = radians(rotation.z);
    
    float newX = mul(magnitude, cos(angle));
    float newY = mul(magnitude, sin(angle));
    
    output.out_Position.x = newX;
    output.out_Position.y = newY;
    
    // perspective transformation
 
    //output.out_Position.x = output.out_Position.x / output.out_Position.z;
    //output.out_Position.y = output.out_Position.y / output.out_Position.z;
    //output.out_Position.z = output.out_Position.z / output.out_Position.z;
    
    output.out_Color = float4(_color.r, _color.g, _color.b, _color.a);
    return output;
}