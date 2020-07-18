#
# This file is auto-generated, please do not modify directly!
#

import unittest
import gm


class TestVec2f(unittest.TestCase):
    def testDefaultInitialization(self):
        vector = gm.Vec2f()
        self.assertEqual(vector, gm.Vec2f(0.0, 0.0))

    def testElementInitialization(self):
        gm.Vec2f(0.0, 2.0)

    def testElementReadAccess(self):
        vector = gm.Vec2f(0.0, 2.0)
        self.assertAlmostEqual(vector[0], 0.0)
        self.assertAlmostEqual(vector[1], 2.0)

    def testElementWriteAccess(self):
        vector = gm.Vec2f()
        vector[0] = 0.0
        vector[1] = 2.0
        self.assertAlmostEqual(vector[0], 0.0)
        self.assertAlmostEqual(vector[1], 2.0)

    def testNamedElementReadAccessX(self):
        vector = gm.Vec2f(0.0, 1.0)
        self.assertEqual(vector.x, 0)

    def testNamedElementWriteAccessX(self):
        vector = gm.Vec2f()
        vector.x = 0
        self.assertEqual(vector[0], 0)

    def testNamedElementReadAccessY(self):
        vector = gm.Vec2f(0.0, 1.0)
        self.assertEqual(vector.y, 1)

    def testNamedElementWriteAccessY(self):
        vector = gm.Vec2f()
        vector.y = 1
        self.assertEqual(vector[1], 1)
