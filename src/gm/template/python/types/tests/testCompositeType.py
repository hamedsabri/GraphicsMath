import unittest
import gm

class Test{{ valueType.className }}(unittest.TestCase):

    def testDefaultInitialization(self):
        gm.{{ valueType.className }}()

    def testElementInitialization(self):
        gm.{{ valueType.className }}(
{%- for index in range(valueType.elementSize) -%}
            gm.{{ valueType.elements[ index ].type.className }}()
{%- if index + 1 < valueType.elementSize -%}
        ,{{ " " }}
{%- endif -%}
{%- endfor -%}
        )
