#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for interface in function.interfaces %}
TEST_CASE( "{{ function.name }}_{{ interface.testSuffix }}" )
{
{% for argument in interface.arguments -%}
    {{ argument.type.namespacedClassName }} {{ argument.key }};
{%- endfor %}
    BENCHMARK( "{{ function.name }}" ){ return gm::{{ function.name }}(
{%- for index in range(interface.arguments|length) -%}
    {{ interface.arguments[index].key }}
{%- if index + 1 < interface.arguments|length -%}
        ,
{%- endif -%}
{%- endfor %}
    ); };
}
{% endfor %}
