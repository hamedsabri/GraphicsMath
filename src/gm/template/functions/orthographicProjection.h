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
{% set viewingVolume = interface.ArgName("viewingVolume") %}
/// Construct an orthographic projection matrix from an axis-aligned, rectilinear viewing volume.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ viewingVolume }} Orthographic viewing volume.
///
/// \return Orthographic projection transformation matrix.
{{- functionUtils.signature(function, interface) -}}
{
    // Center viewing volume about origin, such that the scaling is applied uniformly.
    gm::Mat4f centeringXform = gm::Mat4f::Identity();
    SetTranslate( gm::Vec3f(
            -( {{ viewingVolume }}.Max().X() + {{ viewingVolume }}.Min().X() ) * 0.5f,
            -( {{ viewingVolume }}.Max().Y() + {{ viewingVolume }}.Min().Y() ) * 0.5f,
            -( {{ viewingVolume }}.Max().Z() + {{ viewingVolume }}.Min().Z() ) * 0.5f
        ),
        centeringXform
    );

    // Scale viewing volume into a volume of min=(-1, -1, -1), max=(1, 1, 1)
    gm::Mat4f scaleXform = gm::Mat4f::Identity();
    SetScale(
        gm::Vec3f(
            2.0f / ( {{ viewingVolume }}.Max().X() - {{ viewingVolume }}.Min().X() ),
            2.0f / ( {{ viewingVolume }}.Max().Y() - {{ viewingVolume }}.Min().Y() ),
            2.0f / ( {{ viewingVolume }}.Max().Z() - {{ viewingVolume }}.Min().Z() )
        ),
        scaleXform
    );

    return gm::MatrixProduct( scaleXform, centeringXform );
}
{% endfor %}
{% endblock %}
