import unittest
import gm

class Test{{ valueType.className }}(unittest.TestCase):

    def testDefaultInitialization(self):
        gm.{{ valueType.className }}()

    def testMinMaxInitialization(self):
        gm.{{ valueType.className }}(
{%- if valueType.elementType.isScalar -%}
            {{ valueType.elementType.className }}(),
            {{ valueType.elementType.className }}(),
{%- else -%}
            gm.{{ valueType.elementType.className }}(),
            gm.{{ valueType.elementType.className }}(),
{%- endif -%}
        )
