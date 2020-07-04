import unittest
import gm

class Test{{ valueType.className }}(unittest.TestCase):

    def testDefaultInitialization(self):
        gm.{{ valueType.className }}()

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
        {{ valueType.varName }} = gm.{{ valueType.className }}(
{%- for index in range(valueType.elementSize) -%}
    {{ valueType.PyValue(index * 2) }}
{%- if index + 1 < valueType.elementSize -%}
        ,{{ " " }}
{%- endif -%}
{%- endfor -%}
        )
{%- for index in range(valueType.elementSize) %}
        self.assertAlmostEqual({{ valueType.varName }}[ {{ index }} ], {{ valueType.PyValue(index * 2) }})
{%- endfor %}

    def testElementWriteAccess(self):
        {{ valueType.varName }} = gm.{{ valueType.className }}()
{%- for index in range(valueType.elementSize) %}
        {{ valueType.varName }}[ {{ index }} ] = {{ valueType.PyValue(index * 2) }};
{%- endfor -%}
{%- for index in range(valueType.elementSize) %}
        self.assertAlmostEqual({{ valueType.varName }}[ {{ index }} ], {{ valueType.PyValue(index * 2) }})
{%- endfor %}

