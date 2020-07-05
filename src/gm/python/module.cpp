//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

// Type Declarations.
void BindMat3f( pybind11::module& );
void BindMat4f( pybind11::module& );
void BindVec2f( pybind11::module& );
void BindVec3f( pybind11::module& );
void BindVec4f( pybind11::module& );
void BindVec2i( pybind11::module& );
void BindVec3i( pybind11::module& );
void BindVec4i( pybind11::module& );
void BindFloatRange( pybind11::module& );
void BindIntRange( pybind11::module& );
void BindVec2fRange( pybind11::module& );
void BindVec3fRange( pybind11::module& );
void BindVec4fRange( pybind11::module& );
void BindVec2iRange( pybind11::module& );
void BindVec3iRange( pybind11::module& );
void BindVec4iRange( pybind11::module& );
void BindFloatArray( pybind11::module& );
void BindIntArray( pybind11::module& );
void BindBoolArray( pybind11::module& );
void BindMat3fArray( pybind11::module& );
void BindMat4fArray( pybind11::module& );
void BindVec2fArray( pybind11::module& );
void BindVec3fArray( pybind11::module& );
void BindVec4fArray( pybind11::module& );
void BindVec2iArray( pybind11::module& );
void BindVec3iArray( pybind11::module& );
void BindVec4iArray( pybind11::module& );

// Function Declarations.
void BindLinearInterpolation( pybind11::module& );
void BindNormalize( pybind11::module& );
void BindMin( pybind11::module& );
void BindAbs( pybind11::module& );
void BindDegrees( pybind11::module& );
void BindRandomNumber( pybind11::module& );
void BindMax( pybind11::module& );
void BindFloor( pybind11::module& );
void BindTranspose( pybind11::module& );
void BindSetScale( pybind11::module& );
void BindCeil( pybind11::module& );
void BindDotProduct( pybind11::module& );
void BindSetTranslate( pybind11::module& );
void BindDistance( pybind11::module& );
void BindRadians( pybind11::module& );
void BindLength( pybind11::module& );
void BindSetIdentity( pybind11::module& );
void BindLinearMap( pybind11::module& );
void BindLengthSquared( pybind11::module& );
void BindRaySphereIntersection( pybind11::module& );
void BindMatrixProduct( pybind11::module& );
void BindRayPosition( pybind11::module& );
void BindQuadraticRoots( pybind11::module& );
void BindIsIdentity( pybind11::module& );

PYBIND11_MODULE( gm, o_module )
{
    o_module.doc() = "GraphicsMath python module.";

    // Types.
    BindMat3f( o_module );
    BindMat4f( o_module );
    BindVec2f( o_module );
    BindVec3f( o_module );
    BindVec4f( o_module );
    BindVec2i( o_module );
    BindVec3i( o_module );
    BindVec4i( o_module );
    BindFloatRange( o_module );
    BindIntRange( o_module );
    BindVec2fRange( o_module );
    BindVec3fRange( o_module );
    BindVec4fRange( o_module );
    BindVec2iRange( o_module );
    BindVec3iRange( o_module );
    BindVec4iRange( o_module );
    BindFloatArray( o_module );
    BindIntArray( o_module );
    BindBoolArray( o_module );
    BindMat3fArray( o_module );
    BindMat4fArray( o_module );
    BindVec2fArray( o_module );
    BindVec3fArray( o_module );
    BindVec4fArray( o_module );
    BindVec2iArray( o_module );
    BindVec3iArray( o_module );
    BindVec4iArray( o_module );

    // Functions.
    BindLinearInterpolation( o_module );
    BindNormalize( o_module );
    BindMin( o_module );
    BindAbs( o_module );
    BindDegrees( o_module );
    BindRandomNumber( o_module );
    BindMax( o_module );
    BindFloor( o_module );
    BindTranspose( o_module );
    BindSetScale( o_module );
    BindCeil( o_module );
    BindDotProduct( o_module );
    BindSetTranslate( o_module );
    BindDistance( o_module );
    BindRadians( o_module );
    BindLength( o_module );
    BindSetIdentity( o_module );
    BindLinearMap( o_module );
    BindLengthSquared( o_module );
    BindRaySphereIntersection( o_module );
    BindMatrixProduct( o_module );
    BindRayPosition( o_module );
    BindQuadraticRoots( o_module );
    BindIsIdentity( o_module );
}
