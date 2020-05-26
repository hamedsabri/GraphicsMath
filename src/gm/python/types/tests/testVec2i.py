#
# This file is auto-generated, please do not modify directly!
#

import unittest
import gm


class TestVec2i(unittest.TestCase):
    def testDefaultInitialization(self):
        gm.Vec2i()

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
