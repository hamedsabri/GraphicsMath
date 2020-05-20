#include <pybind11/pybind11.h>

PYBIND11_MODULE( gm, module )
{
    module.doc() = "GraphicsMath python module.";
}

