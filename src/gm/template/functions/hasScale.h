{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Check if a matrix has a scaling transformation.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <gm/functions/lengthSquared.h>
#include <gm/functions/transformVector.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set matrix     = interface.ArgName("matrix") %}
{% set matrixType = interface.ArgType("matrix") %}
{% set vectorType = VectorType((matrixType.shape[0] - 1,), ScalarType(FLOAT)) %}
/// Check if the transformation matrix \p {{ matrix }} has a scaling factor in any dimension.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ matrix }} Transformation matrix.
///
/// \return If the matrix performs a scaling transformation.
///
/// \sa SetScale
{{- functionUtils.signature(function, interface) -}}
{
    return {{ vectorType.className }}(
{%- for outerIndex in range(vectorType.elementSize) -%}
        LengthSquared( TransformVector( {{ matrix }}, {{ vectorType.className }}(
{%- for innerIndex in range(vectorType.elementSize) -%}
{%- if innerIndex == outerIndex -%}
            1
{%- else -%}
           0
{%- endif -%}
{%- if innerIndex + 1 < vectorType.elementSize -%}
            ,
{%- endif -%}
{%- endfor -%}
        ) ) )
{%- if outerIndex + 1 < vectorType.elementSize -%}
            ,
{%- endif -%}
{%- endfor -%}
    ) != {{ vectorType.className }}(
{%- for index in range(vectorType.elementSize) -%}
    1
{%- if index + 1 < vectorType.elementSize -%}
            ,
{%- endif -%}
{%- endfor -%}
    );
}
{% endfor %}
{% endblock %}
