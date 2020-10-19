{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Perspective projection.
///
/// Construct an transformation matrix which projects vertices into a viewing surface (the near plane),
/// with a sense of depth.  The transformation is based on a left-handed coordinate system.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <gm/functions/matrixProduct.h>
#include <gm/functions/radians.h>
{% endblock %}

{% block body %}
{% set frustumInterface = function.interfaces[0] %}
{% set left   = frustumInterface.ArgName("left") %}
{% set right  = frustumInterface.ArgName("right") %}
{% set bottom = frustumInterface.ArgName("bottom") %}
{% set top    = frustumInterface.ArgName("top") %}
{% set near   = frustumInterface.ArgName("near") %}
{% set far    = frustumInterface.ArgName("far") %}
/// Construct an perspective projection matrix from a frustum specification.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ left }} Left of the near clipping plane.
/// \param {{ right }} Right of the near clipping plane.
/// \param {{ bottom }} Bottom of the near clipping plane.
/// \param {{ top }} Top of the near clipping plane.
/// \param {{ near }} Distance to the near clipping plane.
/// \param {{ far }} Distance to the far clipping plane.
///
/// \return Perspective projection transformation matrix.
{{- functionUtils.signature(function, frustumInterface) -}}
{
    GM_ASSERT( {{ left }} >= 0.0f );
    GM_ASSERT( {{ right }} >= {{ left }} );
    GM_ASSERT( {{ bottom }} >= 0.0f );
    GM_ASSERT( {{ top }} >= {{ bottom }} );
    GM_ASSERT( {{ near }} >= 0.0f );
    GM_ASSERT( {{ far }} >= {{ near }} );

    // Move frustum to origin.
    // Translate x and y by midpoint lengths.
    Mat4f translateXform = Mat4f::Identity();
    translateXform( 0, 3 ) = -( {{ right }} + {{ left }} ) * 0.5f;
    translateXform( 1, 3 ) = -( {{ top }} + {{ bottom }} ) * 0.5f;

    // Non-linear scaling of z-values into a range [-1, 1], such that
    // vertices closer to the camera has more precision.
    float c1 = 2.0 * {{ far }} * {{ near }} / ( {{ near }} - {{ far }} );
    float c2 = ( {{ far }} + {{ near }} ) / ( {{ far }} - {{ near }} );
    Mat4f depthScaleXform = Mat4f::Identity();
    depthScaleXform( 2, 2 ) = -c2;
    depthScaleXform( 2, 3 ) = c1;
    depthScaleXform( 3, 2 ) = 1.0f; // Left handed!
    depthScaleXform( 3, 3 ) = 0.0f;

    // Perspective calculation.
    // The x and y values are projected onto the near clipping plane
    // as x' and y', where:
    // x' = x * near / z
    // y' = y * near / z
    Mat4f projectionXform = Mat4f::Identity();
    projectionXform( 0, 0 ) = {{ near }};
    projectionXform( 1, 1 ) = {{ near }};

    // Scale 2D viewing window to a 2x2 square (centered at origin).
    Mat4f scaleXform = Mat4f::Identity();
    scaleXform( 0, 0 ) = 2.0f / ( {{ right }} - {{ left }} );
    scaleXform( 1, 1 ) = 2.0f / ( {{ top }} - {{ bottom }} );

    return MatrixProduct( scaleXform,
        MatrixProduct( projectionXform,
            MatrixProduct( depthScaleXform, translateXform ) ) );
}

{% set fovInterface = function.interfaces[1] %}
{% set fieldOfView  = fovInterface.ArgName("fieldOfView") %}
{% set aspectRatio  = fovInterface.ArgName("aspectRatio") %}
{% set near         = fovInterface.ArgName("near") %}
{% set far          = fovInterface.ArgName("far") %}
/// Construct an perspective projection matrix from field of view, aspect ratio, and clipping distances.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ fieldOfView }} The vertical angle, in degrees, of the camera lens.
/// \param {{ aspectRatio }} The ratio of the width to the height of the viewing plane.
/// \param {{ near }} Distance to the near clipping plane.
/// \param {{ far }} Distance to the near far clipping plane.
///
/// \return Orthographic projection transformation matrix.
{{- functionUtils.signature(function, fovInterface) -}}
{
    GM_ASSERT( {{ fieldOfView }} > 0.0f );
    GM_ASSERT( {{ aspectRatio }} > 0.0f );

    // Compute the frustum values.
    float fovRadians = Radians( {{ fieldOfView }} );
    float top    = {{ near }} * tan( fovRadians / 2.0f );
    float bottom = -top;
    float right  = top * {{ aspectRatio }};
    float left   = -right;
    return PerspectiveProjection( left, right, bottom, top, {{ near }}, {{ far }} );

}

{% endblock %}
