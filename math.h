/*
 *  3dfrac - a 3D live-view fractal generator
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

#ifndef FRAC3D_FRACTAL_MATH
#define FRAC3D_FRACTAL_MATH


extern float iterations;
extern float zoom2;
int abs_val(int v);
int calc_fractal(float *sp, Quaternion *qq);
int calc_quatmandel_fractal
	(int sp, GLfloat iter_accur, GLfloat scale, int num);
#endif
