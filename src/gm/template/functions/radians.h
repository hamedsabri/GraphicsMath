#pragma once

/// \file functions/{{ function.headerFileName }}
/// \ingroup GM_group_functions_basic
///
/// Unit conversion from an angle encoded as degrees into radians.

#include <gm/gm.h>

#include <gm/base/constants.h>

GM_NS_OPEN

{% for interface in function.interfaces %}
/// Converts angle \p {{ interface.ArgName("angle") }} from degrees to radians.
/// \ingroup GM_group_functions_basic
///
/// \return the angle in units of radians.
GM_HOST_DEVICE inline {{ interface.returnType }} {{ function.name }}( {{ interface.typedArgs }} )
{
    constexpr {{ interface.ArgType("angle").className }} degreesToRadiansRatio = GM_PI / {{ interface.ArgType("angle").CppValue(180) }};
    return {{ interface.ArgName("angle") }} * degreesToRadiansRatio;
}
{% endfor %}

GM_NS_CLOSE
