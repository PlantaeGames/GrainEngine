float4 main(float4 _color : Color) : SV_Target
{
    return float4(_color.r, _color.g, _color.b, _color.a);
}