#
# This file is auto-generated, please do not modify directly!
#

import unittest
import gm


class TestVec4i(unittest.TestCase):
    def testDefaultInitialization(self):
        gm.Vec4i()

    def testElementInitialization(self):
        gm.Vec4i(0, 2, 4, 6)

    def testElementReadAccess(self):
        vector = gm.Vec4i(0, 2, 4, 6)
        self.assertAlmostEqual(vector[0], 0)
        self.assertAlmostEqual(vector[1], 2)
        self.assertAlmostEqual(vector[2], 4)
        self.assertAlmostEqual(vector[3], 6)

    def testElementWriteAccess(self):
        vector = gm.Vec4i()
        vector[0] = 0
        vector[1] = 2
        vector[2] = 4
        vector[3] = 6
        self.assertAlmostEqual(vector[0], 0)
        self.assertAlmostEqual(vector[1], 2)
        self.assertAlmostEqual(vector[2], 4)
        self.assertAlmostEqual(vector[3], 6)
