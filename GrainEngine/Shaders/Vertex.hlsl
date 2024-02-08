float4 main(float2 position : Position) : SV_Position
{
    return float4(position.x, position.y, 0.0f, 1.0f);
}