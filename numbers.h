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

#ifndef FRAC3D_NUMBER_SYSTEMS
#define FRAC3D_NUMBER_SYSTEMS

class Quaternion
{
	public: 
	Quaternion();
	Quaternion(float a, float b, float c, float d);
	
	~Quaternion() {}

	void set(float a, float b, float c, float d);
	void add(float aa, float bb, float cc, float dd);
	void rotate(float a1, float a2, float a3, float a4, float a5, float a6);
	void rotate_o(float a1, float a2, float a3, float a4, float a5, float a6);
	void rotate_r(float a6, float a5, float a4, float a3, float a2, float a1);
	float get_a();
	float get_b();
	float get_c();
	float get_d();

	float depth();

	float norm();
	Quaternion & invert();

	Quaternion & operator+=(Quaternion & q);
	Quaternion & operator-=(Quaternion & q);
	Quaternion & operator*=(Quaternion & q);
	Quaternion & operator/=(Quaternion & q);
	Quaternion & operator*=(const double & r);

	bool operator==(Quaternion & q);

	Quaternion operator+(Quaternion & q);
	Quaternion operator-(Quaternion & q);
	Quaternion operator*(Quaternion & q);
	Quaternion operator/(Quaternion & q);
	Quaternion operator*(const double & r);

	float a, b, c, d;
	float cr, cg, cb;

};

#endif
