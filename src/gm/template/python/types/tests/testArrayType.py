import unittest
import gm

class Test{{ arrayType.className }}(unittest.TestCase):

    def testDefaultInitialization(self):
        gm.{{ arrayType.className }}()

    def testListInitialization(self):
        gm.{{ arrayType.className }}([
{%- for index in range(5) -%}
{%- if arrayType.elementType.isScalar -%}
            {{ arrayType.elementType.className }}()
{%- else -%}
            gm.{{ arrayType.elementType.className }}()
{%- endif -%}
{%- if index + 1 < 5 -%}
        ,{{ " " }}
{%- endif -%}
{%- endfor -%}
        ])
