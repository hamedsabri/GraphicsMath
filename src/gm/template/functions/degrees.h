#pragma once

/// \file functions/{{ function.headerFileName }}
/// \ingroup gm_functions_basic
///
/// Unit conversion from an angle encoded as radians into degrees.

#include <gm/gm.h>

#include <gm/base/constants.h>

GM_NS_OPEN

{% for interface in function.interfaces %}
/// Converts angle \p {{ interface.ArgName("angle") }} from radians to degrees.
/// \ingroup gm_functions_basic
///
/// \return the angle in units of degrees.
GM_HOST_DEVICE inline {{ interface.returnType }} {{ function.name }}( {{ interface.typedArgs }} )
{
    constexpr {{ interface.ArgType("angle").className }} radiansToDegreesRatio = {{ interface.ArgType("angle").CppValue(180) }} / GM_PI;
    return {{ interface.ArgName("angle") }} * radiansToDegreesRatio;
}
{% endfor %}

GM_NS_CLOSE
