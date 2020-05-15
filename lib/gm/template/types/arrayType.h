#pragma once

/// \file {{ context.headerFileName }}

#include <vector>

{% if context.elementType.isVector %}
#include <gm/types/{{ context.elementType.headerFileName }}>
{%- endif %}

GM_NS_OPEN

{% if context.elementType.isVector %}
/// An array of \ref {{ context.elementType.className }}.
{%- else %}
/// An array of \p {{ context.elementType.className }}.
{%- endif %}
using {{ context.className }} = std::vector< {{ context.elementType.className }} >;

GM_NS_CLOSE

