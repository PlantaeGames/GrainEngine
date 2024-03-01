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

Output main(float3 _position : Position)
{
    Output output;
    
    // transforming
    
    output.out_Position = float4(_position.x, _position.y, _position.z, 0.0f);
    output.out_Position.x += position.x;
    output.out_Position.y += position.y;
    output.out_Position.z += position.z;
    //output.out_Position.x += position.x;
    //output.out_Position.y += position.y;
    //output.out_Position.z += position.z;
    output.out_Position.w = 1.0f;
    
    
    // perspective transformation
 
    output.out_Position.x = output.out_Position.x / camPosition.z;
    output.out_Position.y = output.out_Position.y / camPosition.z;
    
    //output.out_Position = float4(position.x, position.y, position.z, 1.0f);
    
    return output;
}