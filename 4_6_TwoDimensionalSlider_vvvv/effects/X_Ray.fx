//Simple X Ray
//
//Source AMD / ATI
//Digital Slaves 2008
//
// --------------------------------------------------------------------------------------------------
// PARAMETERS:
// --------------------------------------------------------------------------------------------------

//transforms
float4x4 tW: WORLD;
float4x4 tWV : WORLDVIEW;
float4x4 tV: VIEW;
float4x4 tP: PROJECTION;
float4x4 tWVP: WORLDVIEWPROJECTION;

//Tweak
float Tweak  <string uiname="Tweak";> = 0.5 ;

float4 cAmb : COLOR <String uiname="Color";>  = {1, 1, 1, 1};



//the data structure: "vertexshader to pixelshader"
//used as output data with the VS function
//and as input data with the PS function

struct vs2ps
{
    float4 Pos          : POSITION;
    float4 t0           : TEXCOORD0;
    float4 t1		: TEXCOORD1;
};

// --------------------------------------------------------------------------------------------------
// VERTEXSHADERS
// --------------------------------------------------------------------------------------------------

vs2ps VS(

    float4 Pos          : POSITION,
    float3 normal	: NORMAL,
    float4 t0           : TEXCOORD0,
    float4 t1		: TEXCOORD1)

    
{
    //inititalize all fields of output struct with 0
    vs2ps Out = (vs2ps)0;

    //Float
    
    float4 Normals = float4(normal, 0);

    //transform position
    
    Out.Pos = mul(Pos,tWVP);
    
    Out.t0 =  mul(Pos, tWV);

    Out.t1 = mul(Normals, tWVP);
    
    
    return Out;
}

// --------------------------------------------------------------------------------------------------
// PIXELSHADERS:
// --------------------------------------------------------------------------------------------------

float4 PS(

     float3 t0		: TEXCOORD0,
     float3 t1		: TEXCOORD1): COLOR
     
{

    float  opac = dot(normalize(t0), normalize(t1));
    
           opac = abs(opac);
           opac = 1-pow(opac, Tweak);

    float4 col;
    
           col.rgb = opac * cAmb;
           col.a   = opac ;

    return col;
    
}

// --------------------------------------------------------------------------------------------------
// TECHNIQUES:
// --------------------------------------------------------------------------------------------------

technique X_ray
{
    pass P0
    {

        VertexShader = compile vs_2_0 VS();
        PixelShader = compile ps_2_0 PS();
        
    }
}
