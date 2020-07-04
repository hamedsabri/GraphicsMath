{% extends "types/baseType.h" %}

{% block includes %}
#include <vector>

{% if valueType.elementType.isVector %}
#include <gm/types/{{ valueType.elementType.headerFileName }}>
{%- endif %}
{% endblock %}

{% block body %}
/// \typedef {{ valueType.className }}
/// \ingroup gm_types_{{ valueType.CATEGORY }}
///
/// Type definition of an array of \ref {{ valueType.elementType.className }}.
using {{ valueType.className }} = std::vector< {{ valueType.elementType.className }} >;
{% endblock %}
