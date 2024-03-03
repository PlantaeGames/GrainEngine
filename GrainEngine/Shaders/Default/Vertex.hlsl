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
    float aspectRatio;
    float fov;
    float nearPlane;
    float farPlane;
};

struct Output
{
    float4 out_Color : Color;
    float4 out_Position : SV_Position;
};

Output main(float3 _position : Position, float4 _color : Color)
{
    Output output;
    
    float4 coordinates;
    coordinates.x = _position.x;
    coordinates.y = _position.y;
    coordinates.z = _position.z;
    coordinates.w = 1;
    
    // rotation
    //  rotation rotation
    row_major matrix zRotationMatrix = 0;
    zRotationMatrix[1][1] = cos(radians(rotation.z));
    zRotationMatrix[1][2] = -sin(radians(rotation.z));
    zRotationMatrix[2][1] = sin(radians(rotation.z));
    zRotationMatrix[2][2] = cos(radians(rotation.z));
    
    zRotationMatrix[0][0] = 1;
    zRotationMatrix[3][3] = 1;
    
    // x rotation
    row_major matrix xRotationMatrix = 0;
    xRotationMatrix[0][0] = cos(radians(rotation.x));
    xRotationMatrix[0][2] = sin(radians(rotation.x));
    xRotationMatrix[2][0] = -sin(radians(rotation.x));
    xRotationMatrix[2][2] = cos(radians(rotation.x));
    
    xRotationMatrix[1][1] = 1;
    xRotationMatrix[3][3] = 1;
    
    // y rotation
    row_major matrix yRotationMatrix = 0;
    yRotationMatrix[0][0] = cos(radians(rotation.y));
    yRotationMatrix[0][1] = -sin(radians(rotation.y));
    yRotationMatrix[1][0] = sin(radians(rotation.y));
    yRotationMatrix[1][1] = cos(radians(rotation.y));
    
    yRotationMatrix[2][2] = 1;
    yRotationMatrix[3][3] = 1;
    
    coordinates = mul(xRotationMatrix, coordinates);
    coordinates = mul(yRotationMatrix, coordinates);
    coordinates = mul(zRotationMatrix, coordinates);
    
    // sclaing
    row_major matrix scalingMatrix = 0;
    scalingMatrix[0][0] = scale.x;
    scalingMatrix[1][1] = scale.y;
    scalingMatrix[2][2] = scale.z;
    scalingMatrix[3][3] = 1;
    
    coordinates = mul(scalingMatrix, coordinates);
    
    // translation
    row_major matrix translationMatrix = 0;
    translationMatrix[0][3] = position.x;
    translationMatrix[1][3] = position.y;
    translationMatrix[2][3] = position.z;
    
    translationMatrix[0][0] = 1;
    translationMatrix[1][1] = 1;
    translationMatrix[2][2] = 1;
    translationMatrix[3][3] = 1;
    
    coordinates = mul(translationMatrix, coordinates);
    
    // camera respective
    coordinates.x -= camPosition.x;
    coordinates.y -= camPosition.y;
    coordinates.z -= camPosition.z;
   
    // perspective transformation  
    // creating perspective transformaopm matrix
    row_major matrix perspectiveMatrix = 0;
    perspectiveMatrix[0][0] = aspectRatio * 1 / tan(radians(fov * 0.5));
    perspectiveMatrix[1][1] = 1 / tan(radians(fov * 0.5));
    perspectiveMatrix[2][2] = (farPlane / (farPlane - nearPlane));
    perspectiveMatrix[2][3] = (-farPlane * nearPlane) / (farPlane - nearPlane);
    perspectiveMatrix[3][2] = 1; // saving original z value;
    
    // applying perspective transformation
    float4 result = mul(perspectiveMatrix, coordinates);
    
    
    // applying weak perspective
    if(result.w != 0)
    {
        result.x /= result.w;
        result.y /= result.w;
        result.z /= result.w;
    }
    
    output.out_Position = float4(result.x, result.y, result.z, 1);

    output.out_Color = float4(_color.r, _color.g, _color.b, _color.a);
    return output;
}