#pragma once

/// \file {{ context.headerFileName }}

#include <vector>

{% if context.elementType.isVector %}
#include <gm/type/{{ context.elementType.headerFileName }}>
{%- endif %}

GM_NS_BEGIN

using {{ context.className }} = std::vector< {{ context.elementType.className }} >;

GM_NS_END

