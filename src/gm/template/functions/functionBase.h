{#-
    Base template for all functions.
-#}

#pragma once

/// \file functions/{{ function.headerFileName }}
/// \ingroup gm_functions_{{ function.category }}
///
{% block fileDoc -%}
{%- endblock %}

#include <gm/gm.h>

{% block includes %}
{% endblock %}

GM_NS_OPEN

{% block body %}
{% endblock %}

GM_NS_CLOSE
