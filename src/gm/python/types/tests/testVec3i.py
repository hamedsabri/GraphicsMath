#
# This file is auto-generated, please do not modify directly!
#

import unittest
import gm


class TestVec3i(unittest.TestCase):
    def testDefaultInitialization(self):
        gm.Vec3i()

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
