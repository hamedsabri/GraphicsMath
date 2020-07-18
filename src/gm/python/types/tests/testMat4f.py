#
# This file is auto-generated, please do not modify directly!
#

import unittest
import gm


class TestMat4f(unittest.TestCase):
    def testDefaultInitialization(self):
        matrix = gm.Mat4f()
        self.assertEqual(
            matrix,
            gm.Mat4f(
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
                0.0,
            ),
        )

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

    def testMatrixElementReadAccess(self):
        matrix = gm.Mat4f(
            0.0,
            1.0,
            2.0,
            3.0,
            4.0,
            5.0,
            6.0,
            7.0,
            8.0,
            9.0,
            10.0,
            11.0,
            12.0,
            13.0,
            14.0,
            15.0,
        )

        self.assertEqual(matrix[0, 0], 0.0)
        self.assertEqual(matrix[0, 1], 1.0)
        self.assertEqual(matrix[0, 2], 2.0)
        self.assertEqual(matrix[0, 3], 3.0)

        self.assertEqual(matrix[1, 0], 4.0)
        self.assertEqual(matrix[1, 1], 5.0)
        self.assertEqual(matrix[1, 2], 6.0)
        self.assertEqual(matrix[1, 3], 7.0)

        self.assertEqual(matrix[2, 0], 8.0)
        self.assertEqual(matrix[2, 1], 9.0)
        self.assertEqual(matrix[2, 2], 10.0)
        self.assertEqual(matrix[2, 3], 11.0)

        self.assertEqual(matrix[3, 0], 12.0)
        self.assertEqual(matrix[3, 1], 13.0)
        self.assertEqual(matrix[3, 2], 14.0)
        self.assertEqual(matrix[3, 3], 15.0)

    def testMatrixElementWriteAccess(self):
        matrix = gm.Mat4f()

        matrix[0, 0] = 0.0
        matrix[0, 1] = 1.0
        matrix[0, 2] = 2.0
        matrix[0, 3] = 3.0

        matrix[1, 0] = 4.0
        matrix[1, 1] = 5.0
        matrix[1, 2] = 6.0
        matrix[1, 3] = 7.0

        matrix[2, 0] = 8.0
        matrix[2, 1] = 9.0
        matrix[2, 2] = 10.0
        matrix[2, 3] = 11.0

        matrix[3, 0] = 12.0
        matrix[3, 1] = 13.0
        matrix[3, 2] = 14.0
        matrix[3, 3] = 15.0

        self.assertEqual(
            matrix,
            gm.Mat4f(
                0.0,
                1.0,
                2.0,
                3.0,
                4.0,
                5.0,
                6.0,
                7.0,
                8.0,
                9.0,
                10.0,
                11.0,
                12.0,
                13.0,
                14.0,
                15.0,
            ),
        )
