#
# This file is auto-generated, please do not modify directly!
#

import unittest
import gm


class TestVec2i(unittest.TestCase):
    def testDefaultInitialization(self):
        vector = gm.Vec2i()
        self.assertEqual(vector, gm.Vec2i(0, 0))

    def testElementInitialization(self):
        gm.Vec2i(0, 2)

    def testElementReadAccess(self):
        vector = gm.Vec2i(0, 2)
        self.assertAlmostEqual(vector[0], 0)
        self.assertAlmostEqual(vector[1], 2)

    def testElementWriteAccess(self):
        vector = gm.Vec2i()
        vector[0] = 0
        vector[1] = 2
        self.assertAlmostEqual(vector[0], 0)
        self.assertAlmostEqual(vector[1], 2)

    def testNamedElementReadAccessX(self):
        vector = gm.Vec2i(0, 1)
        self.assertEqual(vector.x, 0)

    def testNamedElementWriteAccessX(self):
        vector = gm.Vec2i()
        vector.x = 0
        self.assertEqual(vector[0], 0)

    def testNamedElementReadAccessY(self):
        vector = gm.Vec2i(0, 1)
        self.assertEqual(vector.y, 1)

    def testNamedElementWriteAccessY(self):
        vector = gm.Vec2i()
        vector.y = 1
        self.assertEqual(vector[1], 1)
