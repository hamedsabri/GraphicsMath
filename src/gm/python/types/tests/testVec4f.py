#
# This file is auto-generated, please do not modify directly!
#

import unittest
import gm


class TestVec4f(unittest.TestCase):
    def testDefaultInitialization(self):
        vector = gm.Vec4f()
        self.assertEqual(vector, gm.Vec4f(0.0, 0.0, 0.0, 0.0))

    def testElementInitialization(self):
        gm.Vec4f(0.0, 2.0, 4.0, 6.0)

    def testElementReadAccess(self):
        vector = gm.Vec4f(0.0, 2.0, 4.0, 6.0)
        self.assertAlmostEqual(vector[0], 0.0)
        self.assertAlmostEqual(vector[1], 2.0)
        self.assertAlmostEqual(vector[2], 4.0)
        self.assertAlmostEqual(vector[3], 6.0)

    def testElementWriteAccess(self):
        vector = gm.Vec4f()
        vector[0] = 0.0
        vector[1] = 2.0
        vector[2] = 4.0
        vector[3] = 6.0
        self.assertAlmostEqual(vector[0], 0.0)
        self.assertAlmostEqual(vector[1], 2.0)
        self.assertAlmostEqual(vector[2], 4.0)
        self.assertAlmostEqual(vector[3], 6.0)

    def testNamedElementReadAccessX(self):
        vector = gm.Vec4f(0.0, 1.0, 2.0, 3.0)
        self.assertEqual(vector.x, 0)

    def testNamedElementWriteAccessX(self):
        vector = gm.Vec4f()
        vector.x = 0
        self.assertEqual(vector[0], 0)

    def testNamedElementReadAccessY(self):
        vector = gm.Vec4f(0.0, 1.0, 2.0, 3.0)
        self.assertEqual(vector.y, 1)

    def testNamedElementWriteAccessY(self):
        vector = gm.Vec4f()
        vector.y = 1
        self.assertEqual(vector[1], 1)

    def testNamedElementReadAccessZ(self):
        vector = gm.Vec4f(0.0, 1.0, 2.0, 3.0)
        self.assertEqual(vector.z, 2)

    def testNamedElementWriteAccessZ(self):
        vector = gm.Vec4f()
        vector.z = 2
        self.assertEqual(vector[2], 2)

    def testNamedElementReadAccessW(self):
        vector = gm.Vec4f(0.0, 1.0, 2.0, 3.0)
        self.assertEqual(vector.w, 3)

    def testNamedElementWriteAccessW(self):
        vector = gm.Vec4f()
        vector.w = 3
        self.assertEqual(vector[3], 3)
