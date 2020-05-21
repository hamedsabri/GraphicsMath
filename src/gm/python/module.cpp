#include <pybind11/pybind11.h>

// Type Declarations.
void BindMat4f( pybind11::module& );
void BindMat3f( pybind11::module& );
void BindVec2i( pybind11::module& );
void BindVec4f( pybind11::module& );
void BindVec2f( pybind11::module& );
void BindVec4i( pybind11::module& );
void BindVec3f( pybind11::module& );
void BindVec3i( pybind11::module& );

PYBIND11_MODULE( gm, o_module )
{
    o_module.doc() = "GraphicsMath python module.";

    // Types
    BindMat4f( o_module );
    BindMat3f( o_module );
    BindVec2i( o_module );
    BindVec4f( o_module );
    BindVec2f( o_module );
    BindVec4i( o_module );
    BindVec3f( o_module );
    BindVec3i( o_module );
}
