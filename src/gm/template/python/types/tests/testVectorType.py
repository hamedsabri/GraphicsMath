import unittest
import gm

class Test{{ vectorType.className }}(unittest.TestCase):

    def testInitialization(self):
        gm.{{ vectorType.className }}()

    def testElementInitialization(self):
        gm.{{ vectorType.className }}(
{%- for index in range(vectorType.elementSize) -%}
    {{ vectorType.GetPyNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,{{ " " }}
{%- endif -%}
{%- endfor -%}
        )

    def testElementReadAccess(self):
        {{ vectorType.variablePrefix }} = gm.{{ vectorType.className }}(
{%- for index in range(vectorType.elementSize) -%}
    {{ vectorType.GetPyNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,{{ " " }}
{%- endif -%}
{%- endfor -%}
        )
{%- for index in range(vectorType.elementSize) %}
        self.assertAlmostEqual({{ vectorType.variablePrefix }}[ {{ index }} ], {{ vectorType.GetPyNumber(index * 2) }})
{%- endfor %}

    def testElementWriteAccess(self):
        {{ vectorType.variablePrefix }} = gm.{{ vectorType.className }}()
{%- for index in range(vectorType.elementSize) %}
        {{ vectorType.variablePrefix }}[ {{ index }} ] = {{ vectorType.GetPyNumber(index * 2) }};
{%- endfor -%}
{%- for index in range(vectorType.elementSize) %}
        self.assertAlmostEqual({{ vectorType.variablePrefix }}[ {{ index }} ], {{ vectorType.GetPyNumber(index * 2) }})
{%- endfor %}

