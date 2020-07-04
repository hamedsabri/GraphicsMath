import unittest
import gm

class Test{{ valueType.className }}(unittest.TestCase):

    def testDefaultInitialization(self):
        gm.{{ valueType.className }}()

    def testListInitialization(self):
        gm.{{ valueType.className }}([
{%- for index in range(5) -%}
{%- if valueType.elementType.isScalar -%}
            {{ valueType.elementType.className }}()
{%- else -%}
            gm.{{ valueType.elementType.className }}()
{%- endif -%}
{%- if index + 1 < 5 -%}
        ,{{ " " }}
{%- endif -%}
{%- endfor -%}
        ])
