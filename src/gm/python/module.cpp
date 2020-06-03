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
void BindBounds3f( pybind11::module& );
void BindBounds2i( pybind11::module& );
void BindBounds3i( pybind11::module& );
void BindBounds2f( pybind11::module& );

// Function Declarations.
void BindLengthSquared( pybind11::module& );
void BindFloor( pybind11::module& );
void BindCeil( pybind11::module& );
void BindLength( pybind11::module& );
void BindDotProduct( pybind11::module& );
void BindSetIdentity( pybind11::module& );

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
    BindBounds3f( o_module );
    BindBounds2i( o_module );
    BindBounds3i( o_module );
    BindBounds2f( o_module );

    // Functions.
    BindLengthSquared( o_module );
    BindFloor( o_module );
    BindCeil( o_module );
    BindLength( o_module );
    BindDotProduct( o_module );
    BindSetIdentity( o_module );
}
