{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Axis-aligned bounding box (AABB) transformation.
///
/// The 8 points forming the AABB are individually transformed, then a new AABB is expanded
/// based on the 6 points.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <gm/functions/transformPoint.h>
#include <gm/functions/expand.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set aabb     = interface.ArgName("aabb") %}
{% set aabbType = interface.ArgType("aabb") %}
{% set matrix     = interface.ArgName("matrix") %}
{% set matrixType = interface.ArgType("matrix") %}
/// Transform an axis-aligned bounding box \p {{ aabb }} with the transformation matrix \p {{ matrix }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ matrix }} The transformation matrix.
/// \param {{ aabb }} The axis-aligned bounding box to transform.
///
/// \return Transformed axis-aligned bounding box.
{{- functionUtils.signature(function, interface) -}}
{
    {{ aabbType.className }} newAABB;
    newAABB = Expand( newAABB, TransformPoint( {{ matrix }}, {{ aabb }}.Min() ) );
    newAABB = Expand( newAABB, TransformPoint( {{ matrix }},
            {{ aabbType.elementType.className }}(
                {{ aabb }}.Min()[ 0 ],
                {{ aabb }}.Min()[ 1 ],
                {{ aabb }}.Max()[ 2 ]
            )
        )
    );
    newAABB = Expand( newAABB, TransformPoint( {{ matrix }},
            {{ aabbType.elementType.className }}(
                {{ aabb }}.Min()[ 0 ],
                {{ aabb }}.Max()[ 1 ],
                {{ aabb }}.Min()[ 2 ]
            )
        )
    );
    newAABB = Expand( newAABB, TransformPoint( {{ matrix }},
            {{ aabbType.elementType.className }}(
                {{ aabb }}.Min()[ 0 ],
                {{ aabb }}.Max()[ 1 ],
                {{ aabb }}.Max()[ 2 ]
            )
        )
    );
    newAABB = Expand( newAABB, TransformPoint( {{ matrix }},
            {{ aabbType.elementType.className }}(
                {{ aabb }}.Max()[ 0 ],
                {{ aabb }}.Min()[ 1 ],
                {{ aabb }}.Min()[ 2 ]
            )
        )
    );
    newAABB = Expand( newAABB, TransformPoint( {{ matrix }},
            {{ aabbType.elementType.className }}(
                {{ aabb }}.Max()[ 0 ],
                {{ aabb }}.Max()[ 1 ],
                {{ aabb }}.Min()[ 2 ]
            )
        )
    );
    newAABB = Expand( newAABB, TransformPoint( {{ matrix }},
            {{ aabbType.elementType.className }}(
                {{ aabb }}.Max()[ 0 ],
                {{ aabb }}.Max()[ 1 ],
                {{ aabb }}.Max()[ 2 ]
            )
        )
    );
    return Expand( newAABB, TransformPoint( {{ matrix }}, {{ aabb }}.Max() ) );
}
{% endfor %}
{% endblock %}
