import unittest
import gm

class Test{{ compositeType.className }}(unittest.TestCase):

    def testDefaultInitialization(self):
        gm.{{ compositeType.className }}()

    def testElementInitialization(self):
        gm.{{ compositeType.className }}(
{%- for index in range(compositeType.elementSize) -%}
            gm.{{ compositeType.elements[ index ].type.className }}()
{%- if index + 1 < compositeType.elementSize -%}
        ,{{ " " }}
{%- endif -%}
{%- endfor -%}
        )
