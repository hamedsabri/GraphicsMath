#
# This file is auto-generated, please do not modify directly!
#

import unittest
import gm


class TestVec3i(unittest.TestCase):
    def testDefaultInitialization(self):
        vector = gm.Vec3i()
        self.assertEqual(vector, gm.Vec3i(0, 0, 0))

    def testElementInitialization(self):
        gm.Vec3i(0, 2, 4)

    def testElementReadAccess(self):
        vector = gm.Vec3i(0, 2, 4)
        self.assertAlmostEqual(vector[0], 0)
        self.assertAlmostEqual(vector[1], 2)
        self.assertAlmostEqual(vector[2], 4)

    def testElementWriteAccess(self):
        vector = gm.Vec3i()
        vector[0] = 0
        vector[1] = 2
        vector[2] = 4
        self.assertAlmostEqual(vector[0], 0)
        self.assertAlmostEqual(vector[1], 2)
        self.assertAlmostEqual(vector[2], 4)

    def testNamedElementReadAccessX(self):
        vector = gm.Vec3i(0, 1, 2)
        self.assertEqual(vector.x, 0)

    def testNamedElementWriteAccessX(self):
        vector = gm.Vec3i()
        vector.x = 0
        self.assertEqual(vector[0], 0)

    def testNamedElementReadAccessY(self):
        vector = gm.Vec3i(0, 1, 2)
        self.assertEqual(vector.y, 1)

    def testNamedElementWriteAccessY(self):
        vector = gm.Vec3i()
        vector.y = 1
        self.assertEqual(vector[1], 1)

    def testNamedElementReadAccessZ(self):
        vector = gm.Vec3i(0, 1, 2)
        self.assertEqual(vector.z, 2)

    def testNamedElementWriteAccessZ(self):
        vector = gm.Vec3i()
        vector.z = 2
        self.assertEqual(vector[2], 2)
