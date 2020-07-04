import unittest
import gm

class Test{{ rangeType.className }}(unittest.TestCase):

    def testDefaultInitialization(self):
        gm.{{ rangeType.className }}()

    def testMinMaxInitialization(self):
        gm.{{ rangeType.className }}(
{%- if rangeType.elementType.isScalar -%}
            {{ rangeType.elementType.className }}(),
            {{ rangeType.elementType.className }}(),
{%- else -%}
            gm.{{ rangeType.elementType.className }}(),
            gm.{{ rangeType.elementType.className }}(),
{%- endif -%}
        )
