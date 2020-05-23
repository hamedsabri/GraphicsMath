#
# This file is auto-generated, please do not modify directly!
#

import unittest
import gm


class TestVec3f(unittest.TestCase):
    def testInitialization(self):
        gm.Vec3f()

    def testElementInitialization(self):
        gm.Vec3f(0.0, 2.0, 4.0)

    def testElementReadAccess(self):
        vector = gm.Vec3f(0.0, 2.0, 4.0)
        self.assertAlmostEqual(vector[0], 0.0)
        self.assertAlmostEqual(vector[1], 2.0)
        self.assertAlmostEqual(vector[2], 4.0)

    def testElementWriteAccess(self):
        vector = gm.Vec3f()
        vector[0] = 0.0
        vector[1] = 2.0
        vector[2] = 4.0
        self.assertAlmostEqual(vector[0], 0.0)
        self.assertAlmostEqual(vector[1], 2.0)
        self.assertAlmostEqual(vector[2], 4.0)
