/*ident	"@(#)cls4:demo/complex/norm.test.C	1.1" */
/*******************************************************************************
 
C++ source for the C++ Language System, Release 3.0.  This product
is a new release of the original cfront developed in the computer
science research center of AT&T Bell Laboratories.

Copyright (c) 1991 AT&T and UNIX System Laboratories, Inc.
Copyright (c) 1984, 1989, 1990 AT&T.  All Rights Reserved.

THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE of AT&T and UNIX System
Laboratories, Inc.  The copyright notice above does not evidence
any actual or intended publication of such source code.

*******************************************************************************/
#include	<complex.h>

#define	NUM_TESTS	9

/*
 **************************************************************
 * 
 * norm(c) returns the square of the magnitude of the
 * vector c on the complex plane.  Thus, the return value
 * for the nine standard test cases from each quadrant
 * will be 1 or 2, except for the origin, which is 0.
 * 
 * nine test cases:
 *                          |
 *                          |
 *                          |
 *      x (SQRT(2), 3*PI/4) x (1, PI/2)        x (SQRT(2), PI/4)
 *        (-1, 1)           | (0, 1)             (1, 1)
 *                          |
 *                          |
 *                          |
 *                          |
 *                          |
 *                          |
 *                          |
 *                          |
 *      (1, PI)             |(0, 0)          (1, 0)
 * -----x-------------------x-------------------x---------
 *      (-1, 0)             |(0, 0)          (1, 0)
 *                          |
 *                          |
 *                          |
 *                          |
 *                          |
 *                          |
 *                          |
 *                          |
 *                          |
 *      x (SQRT(2), 5*PI/4) x (1, 3*PI/2)       x (SQRT(2), 7*PI/4)
 *        (-1, -1)          | (0, -1)             (1, -1)
 *                          |
 *                          |
 * 					(polar coordinates)
 * 						over
 * 					(cartesian coordinates)
 * 
 **************************************************************
 */

main()
{
	complex	c[NUM_TESTS];

	double	ans[NUM_TESTS];

	double	d;

	c[0] = complex(0, 0);		ans[0] = 0;
	c[1] = complex(1, 0);		ans[1] = 1;
	c[2] = complex(1, 1);		ans[2] = 2;
	c[3] = complex(0, 1);		ans[3] = 1;
	c[4] = complex(-1, 1);		ans[4] = 2;
	c[5] = complex(-1, 0);		ans[5] = 1;
	c[6] = complex(-1, -1);		ans[6] = 2;
	c[7] = complex(0, -1);		ans[7] = 1;
	c[8] = complex(1, -1);		ans[8] = 2;

	for ( int i = 0; i < NUM_TESTS; i++ ) {

		errno = 0;

		d = norm(c[i]);

		if ( errno ) {
			cout << "*** test failed *** norm("
				<< c[i] << "), errno=" << errno << "\n";
			continue;
		}

		if ( d != ans[i] ) {
			cout << "*** test failed *** norm("
				<< c[i] << ") = " << d << ", correct answer = "
				<< ans[i] << "\n";
		}
		else
			cout << "*** test passed *** norm("
				<< c[i] << ") = " << d << "\n";
	}
	return 0;
}
