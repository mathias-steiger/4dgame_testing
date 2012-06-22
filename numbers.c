/*
 *  4dgame TESTING - enter the fourth dimension
 *
 *  Copyright (c) 2012 Mathias Steiger <mathias.steiger@googlemail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "main.h"


/* constructors */
Quaternion::Quaternion()
	{ a = 0; b = 0; c = 0; d = 0; }

Quaternion::Quaternion(float aa, float bb, float cc, float dd)
	{ a = aa; b = bb; c = cc; d = dd; }
/* set every part of the number */
void Quaternion::set(float aa, float bb, float cc, float dd)
	{ a = aa; b = bb; c = cc; d = dd; }
void Quaternion::add(float aa, float bb, float cc, float dd)
	{ a += aa; b += bb; c += cc; d += dd; }

float Quaternion::depth() { return(c+d); }

void Quaternion::rotate(float a1, float a2, float a3, float a4, 
	float a5, float a6)
{
	float aa = a, bb = b, cc = c, dd = d;
	Quaternion unit;

	if(a1 != 0) 
	{
		a = aa*cos(a1) + bb * (-sin(a1));
		b = aa*sin(a1) + bb * cos(a1);
		aa = a; bb = b;
	}
	if(a2 != 0) 
	{
		b = bb*cos(a2) + cc * sin(a2);
		c = bb*(-sin(a2)) + cc * cos(a2);
		bb = b; cc = c;
	}
	if(a3 != 0) 
	{
		a = aa*cos(a3) + cc * (-sin(a3));
		c = aa*sin(a3) + cc * cos(a3);
		aa = a; cc = c;
	}
	if(a4 != 0) 
	{
	unit.set(1, 1, 1, 1);
	unit = unit*(*this);
	unit *= 0.1*a4;
	(*this) += unit;
/*		a = aa*cos(a4) + dd * sin(a4);
		d = aa*(-sin(a4)) + dd * cos(a4);
		aa = a; dd = d;
*/
	}
	if(a5 != 0) 
	{
	unit.set(1, 1, 1, 1);
	unit = (*this)*unit;
	unit *= 0.1*a5;
	(*this) += unit;
/*		a = aa*cos(a4) + dd * sin(a4);
		b = bb*cos(a5) + dd * (-sin(a5));
		d = bb*sin(a5) + dd * cos(a5);
		bb = b; dd = d;
*/
	}

	if(a6 != 0) 
	{
		c = cc*cos(a6) + dd * (-sin(a6));
		d = cc*sin(a6) + dd * cos(a6);
		cc = c; dd = d;
	}
}


void Quaternion::rotate_o(float a1, float a2, float a3, float a4, 
	float a5, float a6)
{
	float aa = a, bb = b, cc = c, dd = d;

	if(a2 != 0) 
	{
		b = bb*cos(a2) + cc * sin(a2);
		c = bb*(-sin(a2)) + cc * cos(a2);
		bb = b; cc = c;
	}

	if(a1 != 0) 
	{
		a = aa*cos(a1) + bb * (-sin(a1));
		b = aa*sin(a1) + bb * cos(a1);
		aa = a; bb = b;
	}
	if(a3 != 0) 
	{
		a = aa*cos(a3) + cc * (-sin(a3));
		c = aa*sin(a3) + cc * cos(a3);
		aa = a; cc = c;
	}
	if(a4 != 0) 
	{
		a = aa*cos(a4) + dd * sin(a4);
		d = aa*(-sin(a4)) + dd * cos(a4);
		aa = a; dd = d;
	}
	if(a5 != 0) 
	{
		b = bb*cos(a5) + dd * (-sin(a5));
		d = bb*sin(a5) + dd * cos(a5);
		bb = b; dd = d;
	}

	if(a6 != 0) 
	{
		c = cc*cos(a6) + dd * (-sin(a6));
		d = cc*sin(a6) + dd * cos(a6);
		cc = c; dd = d;
	}
}

void Quaternion::rotate_r(float a6, float a5, float a4, float a3, 
	float a2, float a1)
{
	float aa = a, bb = b, cc = c, dd = d;

	if(a1 != 0) 
	{
		a = aa*cos(a1) + bb * (-sin(a1));
		b = aa*sin(a1) + bb * cos(a1);
		aa = a; bb = b;
	}
	if(a2 != 0) 
	{
		b = bb*cos(a2) + cc * sin(a2);
		c = bb*(-sin(a2)) + cc * cos(a2);
		bb = b; cc = c;
	}
	if(a3 != 0) 
	{
		a = aa*cos(a3) + cc * (-sin(a3));
		c = aa*sin(a3) + cc * cos(a3);
		aa = a; cc = c;
	}
	if(a4 != 0) 
	{
		a = aa*cos(a4) + dd * sin(a4);
		d = aa*(-sin(a4)) + dd * cos(a4);
		aa = a; dd = d;
	}

	if(a6 != 0) 
	{
		c = cc*cos(a6) + dd * (-sin(a6));
		d = cc*sin(a6) + dd * cos(a6);
		cc = c; dd = d;
	}

	if(a5 != 0) 
	{
		b = bb*cos(a5) + dd * (-sin(a5));
		d = bb*sin(a5) + dd * cos(a5);
		bb = b; dd = d;
	}

}


/* get scalar part */
float Quaternion::get_a(){ return(a); }

/* get vector part element 1 */
float Quaternion::get_b() { return(b); }

/* get vector part element 2 */
float Quaternion::get_c() { return(c); }

/* get vector part element 3 */
float Quaternion::get_d(){ return(d); }

float Quaternion::norm() 
{
  return a*a+b*b+c*c+d*d;
}

Quaternion& Quaternion::invert()
{
  float temp = norm();
  a /= temp;
  b /= -temp;
  c /= -temp;
  d /= -temp;
  return (*this);       // Okay, same norm.
}


/* quaternion addition rule */
Quaternion & Quaternion::operator+=(Quaternion & q)
{
	a += q.a; b += q.b; c += q.c; d += q.d;
	return(*this);
}

/* quaternion substraction rule */
Quaternion & Quaternion::operator-=(Quaternion & q)
{
	a -= q.a; b -= q.b; c -= q.c; d -= q.d;
	return(*this);
}

/* quaternion multiplication rule */
Quaternion & Quaternion::operator*=(Quaternion & q)
{
	/* simple Hamilton product */
	/* ij = k ; ik = -j ; ji = -k ; jk = i; ki = j ; kj = -i
	 */
/*	float aa = a*(q.a) - b*(q.b) - c*(q.c) - d*(q.d);
	float bb = a*(q.b) + b*(q.a) + c*(q.d) - d*(q.c);
	float cc = a*(q.c) - b*(q.d) + c*(q.a) + d*(q.b);
	float dd = a*(q.d) + b*(q.c) - c*(q.b) + d*(q.a);
*/
	float aa = a*(q.a) - b*(q.b) - c*(q.c) - d*(q.d);
	float bb = b*(q.a) + a*(q.b) + d*(q.c) - c*(q.d);
	float cc = c*(q.a) - d*(q.b) + a*(q.c) + b*(q.d);
	float dd = d*(q.a) + c*(q.b) - b*(q.c) + a*(q.d);

	a = aa; b = bb; c = cc; d = dd;

	return(*this);
}

Quaternion & Quaternion::operator/=(Quaternion & q)
{
	Quaternion temp = q;
	return (*this)*=(temp.invert());
}


/*Quaternion & Quaternion::operator/=(Quaternion & q)
{
//	float w = a*a + b*b + c*c + d*d;
	float w = q.a*q.a + q.b*q.b + q.c*q.c + q.d*q.d;


	float aa = (a*(q.a) + b*(q.b) + c*(q.c) + d*(q.d))/w;
	float bb = (a*(q.b) - b*(q.a) - c*(q.d) + d*(q.c))/w;
	float cc = (a*(q.c) + b*(q.d) - c*(q.a) - d*(q.b))/w;
	float dd = (a*(q.d) - b*(q.c) + c*(q.b) - d*(q.a))/w;

	a = aa; b = bb; c = cc; d = dd;

	return(*this);
}*/


/* quaternion multiplication with real number */
Quaternion & Quaternion::operator*=(const double & r)
{
	a *= r; b *= r; c *= r; d *= r;
	return(*this);
}

bool Quaternion::operator==(Quaternion & q)
{
	if(q.a == a && q.b == b && q.c == c && q.d == d) return(true);
	else return(false);
}

Quaternion Quaternion::operator+(Quaternion & q)
{
	Quaternion quat = (*this);
	quat += q;
	return(quat);
}

Quaternion Quaternion::operator-(Quaternion & q)
{
	Quaternion quat = (*this);
	quat -= q;
	return(quat);
}

Quaternion Quaternion::operator* (Quaternion & q)
{
	Quaternion quat = (*this);
	quat *= q;
	return(quat);
}

Quaternion Quaternion::operator/ (Quaternion & q)
{
	Quaternion quat = (*this);
	quat /= q;
	return(quat);
}


Quaternion Quaternion::operator*(const double & r)
{
 	Quaternion quat = (*this);
	quat *= r;
	return(quat);
}

