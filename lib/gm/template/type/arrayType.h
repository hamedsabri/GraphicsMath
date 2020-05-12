#pragma once

/// \file {{ context.headerFileName }}

#include <vector>

{% if context.elementType.isVector %}
#include <gm/type/{{ context.elementType.headerFileName }}>
{%- endif %}

GM_NAMESPACE_BEGIN

using {{ context.className }} = std::vector< {{ context.elementType.className }} >;

GM_NAMESPACE_END

