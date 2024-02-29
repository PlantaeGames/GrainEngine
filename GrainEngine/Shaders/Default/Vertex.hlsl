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
    float4 out_Position : SV_Position;
};

Output main(float3 position : Position)
{
    Output output;
    
    // transforming
    
    output.out_Position.x += position.x;
    output.out_Position.y += position.y;
    output.out_Position.z += position.z;
    
    // perspective transformation
 
    
    output.out_Position = float4(position.x, position.y, position.z, 1.0f);
    
    return output;
}