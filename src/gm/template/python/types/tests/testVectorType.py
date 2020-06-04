import unittest
import gm

class Test{{ vectorType.className }}(unittest.TestCase):

    def testDefaultInitialization(self):
        gm.{{ vectorType.className }}()

    def testElementInitialization(self):
        gm.{{ vectorType.className }}(
{%- for index in range(vectorType.elementSize) -%}
    {{ vectorType.PyValue(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,{{ " " }}
{%- endif -%}
{%- endfor -%}
        )

    def testElementReadAccess(self):
        {{ vectorType.varName }} = gm.{{ vectorType.className }}(
{%- for index in range(vectorType.elementSize) -%}
    {{ vectorType.PyValue(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,{{ " " }}
{%- endif -%}
{%- endfor -%}
        )
{%- for index in range(vectorType.elementSize) %}
        self.assertAlmostEqual({{ vectorType.varName }}[ {{ index }} ], {{ vectorType.PyValue(index * 2) }})
{%- endfor %}

    def testElementWriteAccess(self):
        {{ vectorType.varName }} = gm.{{ vectorType.className }}()
{%- for index in range(vectorType.elementSize) %}
        {{ vectorType.varName }}[ {{ index }} ] = {{ vectorType.PyValue(index * 2) }};
{%- endfor -%}
{%- for index in range(vectorType.elementSize) %}
        self.assertAlmostEqual({{ vectorType.varName }}[ {{ index }} ], {{ vectorType.PyValue(index * 2) }})
{%- endfor %}

