#pragma once

/// \file {{ arrayType.headerFileName }}
/// \ingroup GM_group_arrayTypes

#include <vector>

{% if arrayType.elementType.isVector %}
#include <gm/types/{{ arrayType.elementType.headerFileName }}>
{%- endif %}

GM_NS_OPEN

/// \typedef {{ arrayType.className }}
/// \ingroup GM_group_arrayTypes
///
/// Type definition of an array of \ref {{ arrayType.elementType.className }}.
using {{ arrayType.className }} = std::vector< {{ arrayType.elementType.className }} >;

GM_NS_CLOSE
