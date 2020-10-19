{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Orthographic projection.
///
/// Construct an transformation matrix which projects vertices into a viewing volume.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <gm/functions/matrixProduct.h>
#include <gm/functions/setTranslate.h>
#include <gm/functions/setScale.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set left   = interface.ArgName("left") %}
{% set right  = interface.ArgName("right") %}
{% set bottom = interface.ArgName("bottom") %}
{% set top    = interface.ArgName("top") %}
{% set near   = interface.ArgName("near") %}
{% set far    = interface.ArgName("far") %}
/// Construct an orthographic projection matrix from an axis-aligned, rectilinear viewing volume.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ left }} Left of the viewing volume.
/// \param {{ right }} Right of the viewing volume.
/// \param {{ bottom }} Bottom of the viewing volume.
/// \param {{ top }} Top of the viewing volume.
/// \param {{ near }} Distance to the near clipping plane.
/// \param {{ far }} Distance to the far clipping plane.
///
/// \return Orthographic projection transformation matrix.
{{- functionUtils.signature(function, interface) -}}
{
    GM_ASSERT( {{ left }} >= 0.0f );
    GM_ASSERT( {{ right }} >= {{ left }} );
    GM_ASSERT( {{ bottom }} >= 0.0f );
    GM_ASSERT( {{ top }} >= {{ bottom }} );
    GM_ASSERT( {{ near }} >= 0.0f );
    GM_ASSERT( {{ far }} >= {{ near }} );

    // Center viewing volume about origin, such that the scaling is applied uniformly.
    gm::Mat4f centeringXform = gm::Mat4f::Identity();
    SetTranslate( gm::Vec3f(
            -( {{ right }} + {{ left }} ) * 0.5f,
            -( {{ top }} + {{ bottom }} ) * 0.5f,
            -( {{ far }} + {{ near }} ) * 0.5f
        ),
        centeringXform
    );

    // Scale viewing volume into a volume of min=(-1, -1, -1), max=(1, 1, 1)
    gm::Mat4f scaleXform = gm::Mat4f::Identity();
    SetScale(
        gm::Vec3f(
            2.0f / ( {{ right }} - {{ left }} ),
            2.0f / ( {{ top }} - {{ bottom }} ),
            2.0f / ( {{ far }} - {{ near }} )
        ),
        scaleXform
    );

    return gm::MatrixProduct( scaleXform, centeringXform );
}
{% endfor %}
{% endblock %}
