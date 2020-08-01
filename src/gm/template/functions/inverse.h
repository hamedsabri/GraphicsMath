{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Matrix inverse.
///
/// Using Gauss-Jordan elimination, compute the inverse matrix.
///
/// The inverse matrix of \f$A\f$ is the unique matrix \f$A^-1\f$ such that
/// \f[
/// A * A^-1 = I
/// \f]
/// where \f$I\f$ is the identity matrix.
///
/// This is a fairly involved operation, and one of the few implementations in GraphicsMath where
/// helper functions are available to improve readability.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <gm/base/diagnostic.h>
#include <gm/types/vec4f.h>
#include <gm/functions/setIdentity.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set matrix     = interface.ArgName("matrix") %}
{% set inverse    = interface.ArgName("inverse") %}
{% set matrixType = interface.ArgType("matrix") %}

/// Find a row \em below row \p i_pivotRowIndex in matrix \p o_matrix such that its co-efficient
/// (at \p i_pivotColIndex) is not 0, then exchange it with the pivot row.
///
/// \return a positive integer if a viable row is found.  Otherwise, \p -1.
GM_HOST_DEVICE inline int _FindRowToExchange( const {{ matrixType.className }}& {{ matrix }},
                                              int i_pivotIndex )
{
    GM_ASSERT( {{ matrix }}( i_pivotIndex, i_pivotIndex ) == 0 );

    for ( int rowIndex = i_pivotIndex + 1; rowIndex < {{ matrixType.shape[0] }}; rowIndex++ )
    {
        if ( {{ matrix }}( rowIndex, i_pivotIndex ) != 0 )
        {
            return rowIndex;
        }
    }

    return -1;
}

/// Exchange row \p i_rowIndexA and row \p i_rowIndexB on matrix \p o_matrix in-place.
GM_HOST_DEVICE inline void _RowExchange( int i_rowIndexA,
                                         int i_rowIndexB,
                                         {{ matrixType.className }}& o_matrix )
{
    Vec4f rowA(
    {% for colIndex in range(matrixType.shape[1]) -%}
        o_matrix( i_rowIndexA, {{ colIndex }} )
    {%- if colIndex + 1 < matrixType.shape[1] -%}
        ,
    {%- endif -%}
    {%- endfor %}
    );

    {% for colIndex in range(matrixType.shape[1]) -%}
    o_matrix( i_rowIndexA, {{ colIndex }} ) = o_matrix( i_rowIndexB, {{ colIndex }} );
    {% endfor %}

    {% for colIndex in range(matrixType.shape[1]) -%}
    o_matrix( i_rowIndexB, {{ colIndex }} ) = rowA[ {{ colIndex }} ];
    {% endfor %}
}

/// Perform a Gauss elimination step by zeroing out all the co-efficients below the pivot row,
/// by subtracting a factor the row from them.
GM_HOST_DEVICE inline void _GaussEliminationStep( int i_pivotIndex,
                                                  {{ matrixType.className }}& o_matrix,
                                                  {{ matrixType.className }}& o_inverse )
{
    GM_ASSERT( o_matrix( i_pivotIndex, i_pivotIndex ) != 0 );

    // Precompute the reciprocal of the pivot co-efficient.
    const {{ matrixType.elementType.className }} pivotReciprocal = 1.0 / o_matrix( i_pivotIndex, i_pivotIndex );

    // Cache the pivot rows.
    Vec4f pivotRow(
    {% for colIndex in range(matrixType.shape[1]) -%}
        o_matrix( i_pivotIndex, {{ colIndex }} )
    {%- if colIndex + 1 < matrixType.shape[1] -%}
        ,
    {%- endif -%}
    {%- endfor %}
    );

    Vec4f inversePivotRow(
    {% for colIndex in range(matrixType.shape[1]) -%}
        o_inverse( i_pivotIndex, {{ colIndex }} )
    {%- if colIndex + 1 < matrixType.shape[1] -%}
        ,
    {%- endif -%}
    {%- endfor %}
    );

    for ( int rowIndex = i_pivotIndex + 1; rowIndex < {{ matrixType.shape[0] }}; rowIndex++ )
    {
        {{ matrixType.elementType.className }} coefficient = o_matrix( rowIndex, i_pivotIndex );
        if ( coefficient != 0 )
        {
            {{ matrixType.elementType.className }} eliminationFactor = coefficient * pivotReciprocal;
            Vec4f eliminationRow = pivotRow * eliminationFactor;
            for ( int colIndex = i_pivotIndex; colIndex < {{ matrixType.shape[1] }}; colIndex++ )
            {
                o_matrix( rowIndex, colIndex ) -= eliminationRow[ colIndex ];
            }

            Vec4f inverseEliminationRow = inversePivotRow * eliminationFactor;
            for ( int colIndex = 0; colIndex < {{ matrixType.shape[1] }}; colIndex++ )
            {
                o_inverse( rowIndex, colIndex ) -= inverseEliminationRow[ colIndex ];
            }
        }
    }
}

/// Perform a Jordan elimination step by zeroing out all the co-efficients above the pivot row.
/// by subtracting a factor the row from them.
///
/// FIXME: This code duplication sucks.  We can reduce Gauss and Jordan steps into a single function
/// fairly elegantly with an IntRange which supports reverse iteration (where the min is greater than the max).
GM_HOST_DEVICE inline void _JordanEliminationStep( int i_pivotIndex,
                                                   {{ matrixType.className }}& o_matrix,
                                                   {{ matrixType.className }}& o_inverse )
{
    GM_ASSERT( o_matrix( i_pivotIndex, i_pivotIndex ) != 0 );

    // Precompute the reciprocal of the pivot co-efficient.
    const {{ matrixType.elementType.className }} pivotReciprocal = 1.0 / o_matrix( i_pivotIndex, i_pivotIndex );

    // Cache the pivot rows.
    Vec4f pivotRow(
    {% for colIndex in range(matrixType.shape[1]) -%}
        o_matrix( i_pivotIndex, {{ colIndex }} )
    {%- if colIndex + 1 < matrixType.shape[1] -%}
        ,
    {%- endif -%}
    {%- endfor %}
    );

    Vec4f inversePivotRow(
    {% for colIndex in range(matrixType.shape[1]) -%}
        o_inverse( i_pivotIndex, {{ colIndex }} )
    {%- if colIndex + 1 < matrixType.shape[1] -%}
        ,
    {%- endif -%}
    {%- endfor %}
    );

    for ( int rowIndex = i_pivotIndex - 1; rowIndex >= 0; rowIndex-- )
    {
        {{ matrixType.elementType.className }} coefficient = o_matrix( rowIndex, i_pivotIndex );
        if ( coefficient != {{ matrixType.elementType.CppValue( 0 ) }} )
        {
            {{ matrixType.elementType.className }} eliminationFactor = coefficient * pivotReciprocal;
            Vec4f eliminationRow = pivotRow * eliminationFactor;
            for ( int colIndex = i_pivotIndex; colIndex >= 0; colIndex-- )
            {
                o_matrix( rowIndex, colIndex ) -= eliminationRow[ colIndex ];
            }

            Vec4f inverseEliminationRow = inversePivotRow * eliminationFactor;
            for ( int colIndex = {{ matrixType.shape[1] - 1 }}; colIndex >= 0; colIndex-- )
            {
                o_inverse( rowIndex, colIndex ) -= inverseEliminationRow[ colIndex ];
            }
        }
    }
}

/// Compute the inverse of matrix {{ matrix }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ matrix }} The input matrix to invert.
/// \param {{ inverse }} The inverse of \p {{ matrix }}.
///
/// \return Whether or not {{ matrix }} is invertable.
{{- functionUtils.signature(function, interface) -}}
{
    // Left working matrix.  This will assume the identity matrix after
    // the full Gauss-Jordan elimination.
    {{ matrixType.className }} matrix = {{ matrix }};

    // This matrix begins as the identity, and will assume the inverse after elimination.
    SetIdentity( {{ inverse }} );

    //
    // Gauss step: multiply A by elimination matrix to produce upper-echelon matrix.
    //

    {% for pivotIndex in range(matrixType.shape[0]) -%}
    // Pivot #{{ pivotIndex }}
    if ( matrix( {{ pivotIndex }}, {{ pivotIndex }} ) == 0 )
    {
        // Try to perform row exchange.
        int rowToExchange = _FindRowToExchange( matrix, {{ pivotIndex }} );
        if ( rowToExchange != -1 )
        {
            _RowExchange( {{ pivotIndex }}, rowToExchange, matrix );
            _RowExchange( {{ pivotIndex }}, rowToExchange, {{ inverse }} );
        }
        else
        {
            // A matrix is invertible if and only if all its columns are independent.  Failure to find a
            // row to exchange to produce a pivot means that this column is singular (it is a combination of
            // the previous columns), thus this matrix is not generally invertible.
            return false;
        }

    }

    _GaussEliminationStep( {{ pivotIndex }}, matrix, {{ inverse }} );

    {% endfor %}

    //
    // Jordan step: Multiply upper echelon matrix U by E to reduce to diagonal matrix.
    //

    {% for pivotIndex in range(matrixType.shape[0] - 1, 0, -1) -%}
    _JordanEliminationStep( {{ pivotIndex }}, matrix, {{ inverse }} );
    {% endfor %}

    //
    // Rows of inverse by diagonal coefficients of left matrix D.
    //
    {% for pivotIndex in range(matrixType.shape[0]) -%}
    {
        const {{ matrixType.elementType.className }} pivot = matrix( {{ pivotIndex }}, {{ pivotIndex }} );
        if ( pivot != {{ matrixType.elementType.CppValue( 1 ) }} )
        {
            const {{ matrixType.elementType.className }} pivotInverse =
                {{ matrixType.elementType.CppValue( 1 ) }} / pivot;
            {% for colIndex in range(matrixType.shape[1]) -%}
            {{ inverse }}( {{ pivotIndex }}, {{ colIndex }} ) *= pivotInverse;
            {%- endfor %}
        }
    }
    {%- endfor %}

    // Succesful inversion.
    return true;
}
{% endfor %}
{% endblock %}
