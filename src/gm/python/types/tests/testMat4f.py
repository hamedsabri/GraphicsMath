#
# This file is auto-generated, please do not modify directly!
#

import unittest
import gm


class TestMat4f(unittest.TestCase):
    def testInitialization(self):
        gm.Mat4f()

    def testElementInitialization(self):
        gm.Mat4f(
            0.0,
            2.0,
            4.0,
            6.0,
            8.0,
            10.0,
            12.0,
            14.0,
            16.0,
            18.0,
            20.0,
            22.0,
            24.0,
            26.0,
            28.0,
            30.0,
        )

    def testElementReadAccess(self):
        matrix = gm.Mat4f(
            0.0,
            2.0,
            4.0,
            6.0,
            8.0,
            10.0,
            12.0,
            14.0,
            16.0,
            18.0,
            20.0,
            22.0,
            24.0,
            26.0,
            28.0,
            30.0,
        )
        self.assertAlmostEqual(matrix[0], 0.0)
        self.assertAlmostEqual(matrix[1], 2.0)
        self.assertAlmostEqual(matrix[2], 4.0)
        self.assertAlmostEqual(matrix[3], 6.0)
        self.assertAlmostEqual(matrix[4], 8.0)
        self.assertAlmostEqual(matrix[5], 10.0)
        self.assertAlmostEqual(matrix[6], 12.0)
        self.assertAlmostEqual(matrix[7], 14.0)
        self.assertAlmostEqual(matrix[8], 16.0)
        self.assertAlmostEqual(matrix[9], 18.0)
        self.assertAlmostEqual(matrix[10], 20.0)
        self.assertAlmostEqual(matrix[11], 22.0)
        self.assertAlmostEqual(matrix[12], 24.0)
        self.assertAlmostEqual(matrix[13], 26.0)
        self.assertAlmostEqual(matrix[14], 28.0)
        self.assertAlmostEqual(matrix[15], 30.0)

    def testElementWriteAccess(self):
        matrix = gm.Mat4f()
        matrix[0] = 0.0
        matrix[1] = 2.0
        matrix[2] = 4.0
        matrix[3] = 6.0
        matrix[4] = 8.0
        matrix[5] = 10.0
        matrix[6] = 12.0
        matrix[7] = 14.0
        matrix[8] = 16.0
        matrix[9] = 18.0
        matrix[10] = 20.0
        matrix[11] = 22.0
        matrix[12] = 24.0
        matrix[13] = 26.0
        matrix[14] = 28.0
        matrix[15] = 30.0
        self.assertAlmostEqual(matrix[0], 0.0)
        self.assertAlmostEqual(matrix[1], 2.0)
        self.assertAlmostEqual(matrix[2], 4.0)
        self.assertAlmostEqual(matrix[3], 6.0)
        self.assertAlmostEqual(matrix[4], 8.0)
        self.assertAlmostEqual(matrix[5], 10.0)
        self.assertAlmostEqual(matrix[6], 12.0)
        self.assertAlmostEqual(matrix[7], 14.0)
        self.assertAlmostEqual(matrix[8], 16.0)
        self.assertAlmostEqual(matrix[9], 18.0)
        self.assertAlmostEqual(matrix[10], 20.0)
        self.assertAlmostEqual(matrix[11], 22.0)
        self.assertAlmostEqual(matrix[12], 24.0)
        self.assertAlmostEqual(matrix[13], 26.0)
        self.assertAlmostEqual(matrix[14], 28.0)
        self.assertAlmostEqual(matrix[15], 30.0)
