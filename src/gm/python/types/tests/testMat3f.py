#
# This file is auto-generated, please do not modify directly!
#

import unittest
import gm


class TestMat3f(unittest.TestCase):
    def testInitialization(self):
        gm.Mat3f()

    def testElementInitialization(self):
        gm.Mat3f(0.0, 2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0)

    def testElementReadAccess(self):
        matrix = gm.Mat3f(0.0, 2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0)
        self.assertAlmostEqual(matrix[0], 0.0)
        self.assertAlmostEqual(matrix[1], 2.0)
        self.assertAlmostEqual(matrix[2], 4.0)
        self.assertAlmostEqual(matrix[3], 6.0)
        self.assertAlmostEqual(matrix[4], 8.0)
        self.assertAlmostEqual(matrix[5], 10.0)
        self.assertAlmostEqual(matrix[6], 12.0)
        self.assertAlmostEqual(matrix[7], 14.0)
        self.assertAlmostEqual(matrix[8], 16.0)

    def testElementWriteAccess(self):
        matrix = gm.Mat3f()
        matrix[0] = 0.0
        matrix[1] = 2.0
        matrix[2] = 4.0
        matrix[3] = 6.0
        matrix[4] = 8.0
        matrix[5] = 10.0
        matrix[6] = 12.0
        matrix[7] = 14.0
        matrix[8] = 16.0
        self.assertAlmostEqual(matrix[0], 0.0)
        self.assertAlmostEqual(matrix[1], 2.0)
        self.assertAlmostEqual(matrix[2], 4.0)
        self.assertAlmostEqual(matrix[3], 6.0)
        self.assertAlmostEqual(matrix[4], 8.0)
        self.assertAlmostEqual(matrix[5], 10.0)
        self.assertAlmostEqual(matrix[6], 12.0)
        self.assertAlmostEqual(matrix[7], 14.0)
        self.assertAlmostEqual(matrix[8], 16.0)
