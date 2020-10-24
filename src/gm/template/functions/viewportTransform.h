{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Viewport transformation.
///
/// A viewport transformation transforms clip space coordinates into 2D viewport coordinates.
/// It is used to place a 2D image onto a viewport.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <gm/functions/matrixProduct.h>
#include <gm/functions/setTranslate.h>
#include <gm/functions/setScale.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set dimensions = interface.ArgName("dimensions") %}
{% set offset     = interface.ArgName("offset") %}
/// Construct an viewport transformation matrix.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ dimensions }} Dimensions (width, height) of the 2D image to show on the viewport.
/// \param {{ offset }} Offset (X, Y) of the 2D image, in viewport space.
///
/// \return Viewport transformation matrix.
{{- functionUtils.signature(function, interface) -}}
{
    Mat4f scaleXform = Mat4f::Identity();
    SetScale(
        Vec3f(
            {{ dimensions }}.X() * 0.5f,
            {{ dimensions }}.Y() * 0.5f,
            1
        ),
        scaleXform
    );

    Mat4f translateXform = Mat4f::Identity();
    SetTranslate(
        Vec3f(
            ( {{ dimensions }}.X() * 0.5f ) + {{ offset }}.X(),
            ( {{ dimensions }}.Y() * 0.5f ) + {{ offset }}.Y(),
            0
        ),
        translateXform
    );

    return MatrixProduct( translateXform, scaleXform );

}
{% endfor %}
{% endblock %}
