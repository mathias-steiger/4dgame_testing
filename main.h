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

#include <stdlib.h>
#include <stdio.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>

#include <SDL/SDL.h>
#include <SDL/SDL_thread.h>
#include <SDL/SDL_ttf.h>

#include <unistd.h>

#include <linux/input.h>
#include <linux/joystick.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
#include <complex>
#include <math.h>

#include <sys/time.h>

#define TRUE  1
#define FALSE 0

#define PI 3.1415926536

/* VBO defines */
#define GL_ARRAY_BUFFER_ARB 0x8892
#define GL_STATIC_DRAW_ARB 0x88E4

/* menu attribute defines */
#define M_BG   0x01
#define M_ACT  0x02
#define M_RED  0x04
#define M_EXEC 0x08
#define M_INPUT 0x10

/* fractal type and function defines */
#define F_TEST1 1
#define F_NEWTON 2
#define F_MANDELBULB 3
#define F_QUATMANDEL 4
#define F_BOXTEST 100
#define F_AXISTEST 101
#define VBO_TEST 299

/* menu function defines */
#define MF_SHOW_FORMULA 20
#define MF_CHANGE_VARS 21
#define MF_ACCURACY 30
#define MF_ABOUT 50 
#define MF_HELP 51
#define MF_QUIT 52

#define MF_SUB_INPUT 71

typedef struct
{
	GLfloat pw1, ph1;
	GLfloat pw2,ph2;
} gltexcoord;

int drawGLscene();

#include "numbers.h"
#include "math.h"
#include "sdlglfunc.h"
#include "input.h"

