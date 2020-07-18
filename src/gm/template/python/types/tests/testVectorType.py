import unittest
import gm

{% import "python/types/typeUtils.py" as typeUtils %}

class Test{{ valueType.className }}(unittest.TestCase):

    def testDefaultInitialization(self):
        {{ valueType.varName }} = gm.{{ valueType.className }}()
        self.assertEqual({{ valueType.varName }}, {{- typeUtils.GenUniformSequence(valueType, 0) -}})

    def testElementInitialization(self):
        gm.{{ valueType.className }}(
{%- for index in range(valueType.elementSize) -%}
    {{ valueType.PyValue(index * 2) }}
{%- if index + 1 < valueType.elementSize -%}
        ,{{ " " }}
{%- endif -%}
{%- endfor -%}
        )

    def testElementReadAccess(self):
        {{ valueType.varName }} = {{- typeUtils.GenArithmeticSequence(valueType, 2) -}}
{% for index in range(valueType.elementSize) %}
        self.assertAlmostEqual({{ valueType.varName }}[ {{ index }} ], {{ valueType.PyValue(index * 2) }})
{%- endfor %}

    def testElementWriteAccess(self):
        {{ valueType.varName }} = gm.{{ valueType.className }}()
{%- for index in range(valueType.elementSize) %}
        {{ valueType.varName }}[ {{ index }} ] = {{ valueType.PyValue(index * 2) }}
{%- endfor -%}
{% for index in range(valueType.elementSize) %}
        self.assertAlmostEqual({{ valueType.varName }}[ {{ index }} ], {{ valueType.PyValue(index * 2) }})
{%- endfor %}

{% if valueType.shape|length == 2 %}
    def testMatrixElementReadAccess(self):
        {{ valueType.varName }} = {{- typeUtils.GenArithmeticSequence(valueType, 1) -}}

{% for row in range(valueType.shape[1]) %}
{% for col in range(valueType.shape[0]) %}
        self.assertEqual( {{ valueType.varName }}[ {{ row }}, {{ col }} ], {{ valueType.PyValue(row * valueType.shape[1] + col) }} )
{%- endfor %}
{% endfor %}

    def testMatrixElementWriteAccess(self):
        {{ valueType.varName }} = gm.{{ valueType.className }}()
{% for row in range(valueType.shape[1]) %}
{% for col in range(valueType.shape[0]) %}
        {{ valueType.varName }}[ {{ row }}, {{ col }} ] = {{ valueType.PyValue(row * valueType.shape[1] + col) }}
{%- endfor %}
{%- endfor %}

        self.assertEqual( {{ valueType.varName }}, {{- typeUtils.GenArithmeticSequence(valueType, 1) -}})
{%- endif %}

{% for namedElement in valueType.namedElements %}
    def testNamedElementReadAccess{{ namedElement.accessorName }}(self):
        {{ valueType.varName }} = {{- typeUtils.GenArithmeticSequence(valueType, 1) }}
        self.assertEqual({{ valueType.varName }}.{{ namedElement.name }}, {{ loop.index0 }})

    def testNamedElementWriteAccess{{ namedElement.accessorName }}(self):
        {{ valueType.varName }} = gm.{{ valueType.className }}()
        {{ valueType.varName }}.{{ namedElement.name }} = {{ loop.index0 }}
        self.assertEqual({{ valueType.varName }}[{{ loop.index0 }}], {{ loop.index0 }})
{% endfor %}
