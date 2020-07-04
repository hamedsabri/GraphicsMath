#pragma once

/// \file {{ arrayType.headerFileName }}
/// \ingroup gm_types_array

#include <vector>

#include <gm/gm.h>

{% if arrayType.elementType.isVector %}
#include <gm/types/{{ arrayType.elementType.headerFileName }}>
{%- endif %}

GM_NS_OPEN

/// \typedef {{ arrayType.className }}
/// \ingroup gm_types_array
///
/// Type definition of an array of \ref {{ arrayType.elementType.className }}.
using {{ arrayType.className }} = std::vector< {{ arrayType.elementType.className }} >;

GM_NS_CLOSE
