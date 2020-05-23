#
# This file is auto-generated, please do not modify directly!
#

import unittest
import gm


class TestVec2f(unittest.TestCase):
    def testInitialization(self):
        gm.Vec2f()

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
