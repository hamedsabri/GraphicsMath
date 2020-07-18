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
