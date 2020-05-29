#
# This file is auto-generated, please do not modify directly!
#

import unittest
import gm


class TestDotProduct(unittest.TestCase):

    def testVec2f(self):
        vectorA = gm.Vec2f(0.0, 1.0);
        vectorB = gm.Vec2f(0.0, 5.0);
        self.assertEqual(gm.DotProduct(vectorA, vectorB), 5.0);

    def testVec3f(self):
        vectorA = gm.Vec3f(0.0, 1.0, 2.0);
        vectorB = gm.Vec3f(0.0, 5.0, 10.0);
        self.assertEqual(gm.DotProduct(vectorA, vectorB), 25.0);

    def testVec4f(self):
        vectorA = gm.Vec4f(0.0, 1.0, 2.0, 3.0);
        vectorB = gm.Vec4f(0.0, 5.0, 10.0, 15.0);
        self.assertEqual(gm.DotProduct(vectorA, vectorB), 70.0);
