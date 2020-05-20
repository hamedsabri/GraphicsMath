#include <pybind11/pybind11.h>

// Types
#include "bindMat3f.h"
#include "bindMat4f.h"
#include "bindVec2f.h"
#include "bindVec2i.h"
#include "bindVec3f.h"
#include "bindVec3i.h"
#include "bindVec4f.h"
#include "bindVec4i.h"

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
