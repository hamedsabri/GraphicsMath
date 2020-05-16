#pragma once

/// \file {{ arrayType.headerFileName }}

#include <vector>

{% if arrayType.elementType.isVector %}
#include <gm/types/{{ arrayType.elementType.headerFileName }}>
{%- endif %}

GM_NS_OPEN

{% if arrayType.elementType.isVector %}
/// An array of \ref {{ arrayType.elementType.className }}.
{%- else %}
/// An array of \p {{ arrayType.elementType.className }}.
{%- endif %}
using {{ arrayType.className }} = std::vector< {{ arrayType.elementType.className }} >;

GM_NS_CLOSE

