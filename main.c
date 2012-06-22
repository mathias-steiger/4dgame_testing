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
 nnn*
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "main.h"

#ifdef windows
FILE *ctt = fopen("CON", "w");
#endif


PFNGLISRENDERBUFFEREXTPROC 
	glIsRenderbufferEXT = NULL;
PFNGLBINDRENDERBUFFEREXTPROC 
	glBindRenderbufferEXT = NULL;
PFNGLDELETERENDERBUFFERSEXTPROC 
	glDeleteRenderbuffersEXT = NULL;
PFNGLGENRENDERBUFFERSEXTPROC 
	glGenRenderbuffersEXT = NULL;
PFNGLRENDERBUFFERSTORAGEEXTPROC 
	glRenderbufferStorageEXT = NULL;
PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC 
	glGetRenderbufferParameterivEXT = NULL;
PFNGLISFRAMEBUFFEREXTPROC 
	glIsFramebufferEXT = NULL;
PFNGLBINDFRAMEBUFFEREXTPROC 
	glBindFramebufferEXT = NULL;
PFNGLDELETEFRAMEBUFFERSEXTPROC 
	glDeleteFramebuffersEXT = NULL;
PFNGLGENFRAMEBUFFERSEXTPROC 
	glGenFramebuffersEXT = NULL;
PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC 
	glCheckFramebufferStatusEXT = NULL;
PFNGLFRAMEBUFFERTEXTURE1DEXTPROC 
	glFramebufferTexture1DEXT = NULL;
PFNGLFRAMEBUFFERTEXTURE2DEXTPROC 
	glFramebufferTexture2DEXT = NULL;
PFNGLFRAMEBUFFERTEXTURE3DEXTPROC 
	glFramebufferTexture3DEXT = NULL;
PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC 
	glFramebufferRenderbufferEXT = NULL;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC 
	glGetFramebufferAttachmentParameterivEXT = NULL;
PFNGLGENERATEMIPMAPEXTPROC 
	glGenerateMipmapEXT = NULL;

int ddebug = 0;

GLuint list1, list2, list3;

float intensval = 0;
float intensui = 1;
float tesseract = 1;
float fack = tesseract*12;
float simplex = 0;
int resetpso = 0;
int posbufrunning = 0;
float maxaac = 0.1f;
float maxaad = 0.1f;
float iterations = 255;
int points = 1;
float lrratio = 0.5;
SDL_Event event; int keyevent = 0;
int mpressl, mpressr, mpresslr, mpress, mpressm; 
int mxsave, mysave;
int mxsave2, mysave2;
int mxsave3, mysave3;
int grab = 0;
int done = 0, prempress = 0, mult = 0;
unsigned long int framecounter = 0, framecounter2 = 40;
GLfloat fogcolor[4] = {0.0f, 0.0f, 0.0f, 1};
int fdjoy;

float zoom2 = 1;
GLuint fbo[20];

GLfloat trotxy = 0.0f, trotyz = 0.0f, trotxz = 0.0f;
GLfloat trotwy = 0.0f, trotwx = 0.0f, trotwz = 0.0f;
GLfloat rrotxy = 0.0f, rrotyz = 0.0f, rrotxz = 0.0f;
GLfloat srotxy = 0.0f, srotyz = 0.0f, srotxz = 0.0f;
GLfloat rotxy = 0.0f, rotyz = 0.0f, rotxz = 0.0f;
GLfloat rotwy = 0.0f, rotwx = 0.0f, rotwz = 0.0f;
GLfloat arotxy = 0.0f, arotyz = 0.0f, arotxz = 0.0f;
GLfloat arotwy = 0.0f, arotwx = 0.0f, arotwz = 0.0f;
GLfloat rrotwy = 0.0f, rrotwx = 0.0f, rrotwz = 0.0f;
GLfloat srotwy = 0.0f, srotwx = 0.0f, srotwz = 0.0f;
GLfloat movx = 0.0f, movy = 0.0f, movz = 0.0f, movw = 0.0f;
GLfloat tmovx = 0.0f, tmovy = 0.0f, tmovz = 0.0f, tmovw = 0.0f;
GLfloat posx = 0.0f, posy = 0.0f, posz = 0.0f, posw = 0.0f;
GLfloat auto1 = 0.0f, auto2 = 0.0f, auto3 = 0.0f, auto4 = 0.0f;
GLfloat zoom = 0;
int skip = 0;
GLfloat azoom = 0.0f;
int lock = 0;
int t_size;
int drawnonce = 1;
int enablemov = 1;
int blurenable = 0;
int tilt = 0;
int stereo = 0;
float blurr = 2;
int arot = 0;
float aspeed = 0.25;
int presschange = 0;
int maxquat, freequat, bquat, movquat;
int pos4d = 0;
int numq = 0;
int quatnum = 0;
float zposbuf[9999999];
float zposbuft;
float depth = 2.5;
int zposbufi[9999999];
int zposbufit;
int posbufrunonce = 0;
int zp1, zp3;
float zp2, zp4;
float lbounds[100];
float fov4d = 1;
int fd;
unsigned char intensswitch;
typedef struct {
	float idx;
	float depth;
} zposo;

zposo zposobj[9999999];
float zfov = 1;
unsigned int buffer;
GLfloat arotx = 0.0f, aroty = 0.0f, arotz = 0.0f;

int w_width = 1280; int w_height = 1024;

Quaternion *q;
Quaternion *qo;
Quaternion *qbuffer;
Quaternion playerpos;
Quaternion playerpost;
Quaternion padd;
Quaternion ptemp;
Quaternion ptemp2;

SDL_Surface *surface;
SDL_Surface *s2D;

GLuint tex[100];
int overtexs = 2048;
SDL_Color fg,bg;
time_t ltime1 = time(NULL), ltime2 = time(NULL);
time_t ltime3 = time(NULL), ltime4 = time(NULL);

GLfloat slp[4][16];
int cmem_size = 0; int floading = 0;
int fractal_type = VBO_TEST;
int accuracy = 100; int accplus = 0, naccuracy = accuracy;
int rand1, rand2, rand3, rand4, rand5, rand6;
int boxtest = 0;
int gldrawmode = GL_POINTS;
int flataxis = 0;
int temp = 0; int count[1200]; GLuint VBObuf[1200];
GLfloat *vertncol[1200];

GLuint texture[100];

int t_num; int numcores = 1;
float bulletfactor = 1;
float bulletf = 1;
int color(int seed, float alpha)
{
	alpha *= 1.5;
        GLfloat gl_color[4];
	if(seed > 4) seed = 5+(((seed+19)/24)%4);
	switch(seed)
	{
	case 1:
 	       gl_color[0] = 1;
 	       gl_color[1] = 1;
 	       gl_color[2] = 1;
 	       gl_color[3] = alpha;
	break;	
	case 1456454:
 	       gl_color[0] = 0.8;
 	       gl_color[1] = 1;
 	       gl_color[2] = 0.2;
 	       gl_color[3] = alpha;
	break;	
	case 2:
 	       gl_color[0] = 0.2;
 	       gl_color[1] = 1;
 	       gl_color[2] = 0.8;
 	       gl_color[3] = alpha;
	break;
	case 3:
 	       gl_color[0] = 0.6;
 	       gl_color[1] = 1;
 	       gl_color[2] = 0.4;
 	       gl_color[3] = alpha;
	break;
	case 4:
 	       gl_color[0] = 0.4;
 	       gl_color[1] = 1;
 	       gl_color[2] = 0.6;
 	       gl_color[3] = alpha;
	break;
	case 5:
	       gl_color[0] = 1;
 	       gl_color[1] = 0.3;
 	       gl_color[2] = 0.3;
 	       gl_color[3] = alpha;
	break;
	case 6:
	       gl_color[0] = 1;
 	       gl_color[1] = 0.6;
 	       gl_color[2] = 0.6;
 	       gl_color[3] = alpha;
	break;
	case 7:
	       gl_color[0] = 1;
 	       gl_color[1] = 0.4;
 	       gl_color[2] = 1;
 	       gl_color[3] = alpha;
	break;
	case 8:
	       gl_color[0] = 0.3;
 	       gl_color[1] = 1;
 	       gl_color[2] = 1;
 	       gl_color[3] = alpha;
	break;
	}


        glColor4fv(gl_color);
        return(0);
}

int construct_tesseract(float xs, float ys, float zs, float ws, float x, float y, float z, float w,
	int num, float s) 
{
	int a = num; int i,j;
	q[a].set(-1,-1, -1, 1); a++;
	q[a].set( 1,-1, -1, 1); a++;
	q[a].set( 1, 1, -1, 1); a++;
	q[a].set(-1, 1, -1, 1); a++;

	q[a].set(-1,-1, 1, 1); a++;
	q[a].set( 1,-1, 1, 1); a++;
	q[a].set( 1, 1, 1, 1); a++;
	q[a].set(-1, 1, 1, 1); a++;

	q[a].set(-1,-1, -1, 1); a++;
	q[a].set(-1, 1, -1, 1); a++;
	q[a].set(-1, 1, 1, 1); a++;
	q[a].set(-1,-1, 1, 1); a++;

	q[a].set(1,-1, -1, 1); a++;
	q[a].set(1, 1, -1, 1); a++;
	q[a].set(1, 1, 1, 1); a++;
	q[a].set(1,-1, 1, 1); a++;

	q[a].set(-1,1, -1, 1); a++;
	q[a].set( 1,1, -1, 1); a++;
	q[a].set( 1,1, 1, 1); a++;
	q[a].set(-1,1, 1, 1); a++;

	q[a].set(-1,-1, -1, 1); a++;
	q[a].set( 1,-1, -1, 1); a++;
	q[a].set( 1,-1, 1, 1); a++;
	q[a].set(-1,-1, 1, 1); a++;
// back
	q[a].set(-1,-1, -1, -1); a++;
	q[a].set( 1,-1, -1, -1); a++;
	q[a].set( 1, 1, -1, -1); a++;
	q[a].set(-1, 1, -1, -1); a++;

	q[a].set(-1,-1, 1, -1); a++;
	q[a].set( 1,-1, 1, -1); a++;
	q[a].set( 1, 1, 1, -1); a++;
	q[a].set(-1, 1, 1, -1); a++;

	q[a].set(-1,-1, -1, -1); a++;
	q[a].set(-1, 1, -1, -1); a++;
	q[a].set(-1, 1, 1, -1); a++;
	q[a].set(-1,-1, 1, -1); a++;

	q[a].set(1,-1, -1, -1); a++;
	q[a].set(1, 1, -1, -1); a++;
	q[a].set(1, 1, 1, -1); a++;
	q[a].set(1,-1, 1, -1); a++;


	q[a].set(-1,1, -1, -1); a++;
	q[a].set( 1,1, -1, -1); a++;
	q[a].set( 1,1, 1, -1); a++;
	q[a].set(-1,1, 1, -1); a++;
	
	q[a].set(-1,-1, -1, -1); a++;
	q[a].set( 1,-1, -1, -1); a++;
	q[a].set( 1,-1, 1, -1); a++;
	q[a].set(-1,-1, 1, -1); a++;

	j = a-num;

	for(i = 0; i < j; i++)
	{ q[a] = q[a-j]; q[a].rotate_o(0, 0, 0, M_PI/2, 0, 0); a++; }

	for(i = 0; i < j; i++)
	{ q[a] = q[a-j]; q[a].rotate_o(0, 0, M_PI/2, 0, 0, 0); a++; }

	for(i = 0; i < j; i++)
	{ q[a] = q[a-j]; q[a].rotate_o(0,0,-M_PI/2,-M_PI/2,0,M_PI/2); a++; }

	for(i = num; i < a; i++)
	{
		q[i] *= s;
		q[i].set(
		q[i].get_a()+x,
		q[i].get_b()+y,
		q[i].get_c()+z,
		q[i].get_d()+w
			);
	}
/*
	for(i = num; i < a; i+=4)
	{
		if(0 && (i-num)/4 == 1 || (i-num)/4 == 3)
		{
			q[i] *= xs*2;
			q[i+2] *= xs*2;
		}
	}
*/
	return(a-num);
}

int surf_equal(int i, int j)
{
	int equalt = 0, equal = 0;
	int u, v;
	for(u = 0; u < 4; u++)
	if(q[(i*4)+u].a == q[(j*4)+u].a && q[(i*4)+u].b == q[(j*4)+u].b 
	&& q[(i*4)+u].c == q[(j*4)+u].c && q[(i*4)+u].d == q[(j*4)+u].d) 
	equalt++;

	if(equalt == 4) return(1);
	for(u = 0; u < 4; u++)
	if(q[(i*4)+u].a == q[(j*4)+u].b && q[(i*4)+u].b == q[(j*4)+u].c 
	&& q[(i*4)+u].c == q[(j*4)+u].d && q[(i*4)+u].d == q[(j*4)+u].a) 
	equalt++;

	if(equalt == 4) return(1);
	for(u = 0; u < 4; u++)
	if(q[(i*4)+u].a == q[(j*4)+u].c && q[(i*4)+u].b == q[(j*4)+u].d 
	&& q[(i*4)+u].c == q[(j*4)+u].a && q[(i*4)+u].d == q[(j*4)+u].b) 
	equalt++;

	if(equalt == 4) return(1);
	for(u = 0; u < 4; u++)
	if(q[(i*4)+u].a == q[(j*4)+u].d && q[(i*4)+u].b == q[(j*4)+u].a 
	&& q[(i*4)+u].c == q[(j*4)+u].b && q[(i*4)+u].d == q[(j*4)+u].c) 
	equalt++;

	if(equalt == 4) return(1);

	for(u = 0; u < 4; u++)
	if(q[(i*4)+u].a == q[(j*4)+u].d && q[(i*4)+u].b == q[(j*4)+u].c
	&& q[(i*4)+u].c == q[(j*4)+u].b && q[(i*4)+u].d == q[(j*4)+u].a) 
	equalt++;

	if(equalt == 4) return(1);
	for(u = 0; u < 4; u++)
	if(q[(i*4)+u].a == q[(j*4)+u].c && q[(i*4)+u].b == q[(j*4)+u].b
	&& q[(i*4)+u].c == q[(j*4)+u].a && q[(i*4)+u].d == q[(j*4)+u].d) 
	equalt++;

	if(equalt == 4) return(1);
	for(u = 0; u < 4; u++)
	if(q[(i*4)+u].a == q[(j*4)+u].b && q[(i*4)+u].b == q[(j*4)+u].a
	&& q[(i*4)+u].c == q[(j*4)+u].d && q[(i*4)+u].d == q[(j*4)+u].c) 
	equalt++;

	if(equalt == 4) return(1);
	for(u = 0; u < 4; u++)
	if(q[(i*4)+u].a == q[(j*4)+u].a && q[(i*4)+u].b == q[(j*4)+u].d
	&& q[(i*4)+u].c == q[(j*4)+u].c && q[(i*4)+u].d == q[(j*4)+u].b) 
	equalt++;

	if(equalt == 4) return(1);

	if(q[(i*4)+u].a == q[(j*4)+u].a && q[(i*4)+u].b == q[(j*4)+u].c
	&& q[(i*4)+u].c == q[(j*4)+u].b && q[(i*4)+u].d == q[(j*4)+u].d) 
	equalt++;

	if(equalt == 4) return(1);
	if(q[(i*4)+u].a == q[(j*4)+u].d && q[(i*4)+u].b == q[(j*4)+u].b
	&& q[(i*4)+u].c == q[(j*4)+u].a && q[(i*4)+u].d == q[(j*4)+u].c) 
	equalt++;

	if(equalt == 4) return(1);
	if(q[(i*4)+u].a == q[(j*4)+u].c && q[(i*4)+u].b == q[(j*4)+u].a
	&& q[(i*4)+u].c == q[(j*4)+u].d && q[(i*4)+u].d == q[(j*4)+u].b) 
	equalt++;

	if(equalt == 4) return(1);
	if(q[(i*4)+u].a == q[(j*4)+u].b && q[(i*4)+u].b == q[(j*4)+u].d
	&& q[(i*4)+u].c == q[(j*4)+u].c && q[(i*4)+u].d == q[(j*4)+u].a) 
	equalt++;

	if(equalt == 4) return(1);

	if(q[(i*4)+u].a == q[(j*4)+u].d && q[(i*4)+u].b == q[(j*4)+u].b
	&& q[(i*4)+u].c == q[(j*4)+u].c && q[(i*4)+u].d == q[(j*4)+u].a) 
	equalt++;

	if(equalt == 4) return(1);
	if(q[(i*4)+u].a == q[(j*4)+u].a && q[(i*4)+u].b == q[(j*4)+u].c
	&& q[(i*4)+u].c == q[(j*4)+u].d && q[(i*4)+u].d == q[(j*4)+u].b) 
	equalt++;

	if(equalt == 4) return(1);
	if(q[(i*4)+u].a == q[(j*4)+u].b && q[(i*4)+u].b == q[(j*4)+u].d
	&& q[(i*4)+u].c == q[(j*4)+u].a && q[(i*4)+u].d == q[(j*4)+u].c) 
	equalt++;

	if(equalt == 4) return(1);
	if(q[(i*4)+u].a == q[(j*4)+u].c && q[(i*4)+u].b == q[(j*4)+u].a
	&& q[(i*4)+u].c == q[(j*4)+u].b && q[(i*4)+u].d == q[(j*4)+u].d) 
	equalt++;

	if(equalt == 4) return(1);

	return(0);
}
float get_zposbuf_single(int i)
{
	float result;
	result 	= q[(i)].c+q[(i)].d; 
	return(result);
}


float get_zposbuf(int i)
{
	float result;
	result 	= q[(i*4)].c+q[(i*4)].d 
		+ q[(i*4)+1].c+q[(i*4)+1].d 
		+ q[(i*4)+2].c+q[(i*4)+2].d 
		+ q[(i*4)+3].c+q[(i*4)+3].d;
	return(result);
}

float get_zposbuf_l(int i)
{
	float result;
	result 	= q[(i*4)].c 
		+ q[(i*4)+1].c 
		+ q[(i*4)+2].c 
		+ q[(i*4)+3].c;
	return(result);
}

float get_zposbuf_r(int i)
{
	float result;
	result 	= q[(i*4)].d 
		+ q[(i*4)+1].d 
		+ q[(i*4)+2].d 
		+ q[(i*4)+3].d;
	return(result);
}



void posbuf_run_once()
{
	int i,j,k;

	if(posbufrunonce < 2)
	{
	for(i = 0; i < quatnum/4; i++)
	for(j = 0; j < quatnum/4; j++)
		if(i != j)
		if((zposbuf[i] == zposbuf[j]) || surf_equal(i,j))
		{
			zp1 = (i*4) - (i*4)%24; zp2 = 0;
			if(zp1 < 0) zp1 = 0;
			for(k = 0; k < 24; k++)
				zp2 += q[zp1+k].c+fov4d*q[zp1+k].d+1000;
			zp3 = (j*4) - (j*4)%24; zp4 = 0;
			if(zp3 < 0) zp3 = 0;
			for(k = 0; k < 24; k++)
				zp4 += q[zp3+k].c+fov4d*q[zp3+k].d+1000;
			if(zp2 > zp4) k = i;
			else k = j;
			q[(k*4)].set(q[(k*4)].a, q[(k*4)].b, 
				q[(k*4)].c, q[(k*4)].d+0.000001);
			q[(k*4)+1].set(q[(k*4)+1].a, q[(k*4)+1].b, 
				q[(k*4)+1].c, q[(k*4)+1].d+0.000001);
			q[(k*4)+2].set(q[(k*4)+2].a, q[(k*4)+2].b, 
				q[(k*4)+2].c, q[(k*4)+2].d+0.0000001);
			q[(k*4)+3].set(q[(k*4)+3].a, q[(k*4)+3].b, 
				q[(k*4)+3].c, q[(k*4)+3].d+0.000001);
			zposbuf[k] = get_zposbuf(k);
				
		}
	posbufrunonce++; 
	}

}

void siftDown(zposo zposobj[], int root, int bottom) {
  int maxChild = root * 2 + 1;
 
  // Find the biggest child
  if(maxChild < bottom) {
    int otherChild = maxChild + 1;
    // Reversed for stability
    maxChild = (zposobj[otherChild].depth > zposobj[maxChild].depth)?otherChild:maxChild;
  } else {
    // Don't overflow
    if(maxChild > bottom) return;
  }
 
  // If we have the correct ordering, we are done.
  if(zposobj[root].depth >= zposobj[maxChild].depth) return;
 
  // Swap
  zposo temp = zposobj[root];
  zposobj[root] = zposobj[maxChild];
  zposobj[maxChild] = temp;
 
  // Tail queue recursion. Will be compiled as a loop with correct compiler switches.
  siftDown(zposobj, maxChild, bottom);
}

void heapsort() {
//	printf("heapsort start\n");
  int i; zposo temp;
 
  for (i = (quatnum / 2); i >= 0; i--) {
    siftDown(zposobj, i, quatnum - 1);
  }
 
  for (i = quatnum-1; i >= 1; i--) {
    // Swap
    temp = zposobj[0];
    zposobj[0] = zposobj[i];
    zposobj[i] = temp;
 
    siftDown(zposobj, 0, i-1);
  }
}
 
int posbuf_run(int mode)
{
	if(ddebug) printf("posbuf start %d\n", quatnum);
	posbufrunning = 1;
	int i,j,k; int *zpointer;
	zposbuft = 0;
	zposbufit = 0;
	if(mode == -1) 
	{
	for(j = 0; j < quatnum; j++)
	{	
		zposobj[j].idx = j;
		zposobj[j].depth = q[j].depth();
	}

	heapsort();
	float tt = 0;
	for(j = 0; j < quatnum; j++)
	{
		zposbufi[j] = zposobj[j].idx;
	}
/*	zpointer = zposbufi;
	zposbufi = zposbufi_pre;
	zposbufi_pre = zpointer;
*/
	}
	else
	{
		for(i = 0; i < quatnum/4; i++)
		{
		//	if(enablemov) if(i > movquat/4) break;
			if(mode == 10) zposbuf[i] = get_zposbuf(i);
			if(mode == 0) zposbuf[i] = get_zposbuf_l(i);
			if(mode == 1) zposbuf[i] = get_zposbuf_r(i);
			zposbufi[i] = i;
		}


	for(i = 0; i < quatnum/4; i++)
	{
		for(j = 0; j < quatnum/4; j++)
		{
		//	if(enablemov) if(i > movquat/4) break;
			if(zposbuf[i] < zposbuf[j])
			{
			zposbuft = zposbuf[j];
			zposbuf[j] = zposbuf[i];
			zposbuf[i] = zposbuft;

			zposbufit = zposbufi[j];
			zposbufi[j] = zposbufi[i];
			zposbufi[i] = zposbufit;

			}
		}
	}
	}
	if(ddebug) printf("posbuf finish %d\n", quatnum);
	posbufrunning = 0;
}

int quat_rotate(Quaternion *qqq, int num)
{
	qqq[num].rotate_o(
		trotxz, 
		trotyz, 
		trotxy, 
		trotwx, 
		trotwy, 
		trotwz
		);
	return(0);
}

int quad_draw_mult(Quaternion *qqq, int num)
{
	int tco[4][2] = {{1,1}, {1,0}, {0,0}, {0,1}};
	int i;
	glBegin(GL_QUADS);

	for(i = 0; i < 4; i++)
	{
	glTexCoord2f(tco[i][0], tco[i][1]);
		glVertex3f(
			qqq[num+i].a, 
			qqq[num+i].b, 
			depth*(-qqq[num+i].c*zfov-(1*qqq[num+i].d*1*fov4d))
			); 
	}
	glEnd();

	return(0);
}


int quad_draw_new2(Quaternion *qqq, int num)
{
	int tco[4][2] = {{1,1}, {1,0}, {0,0}, {0,1}};
	int i;
	glBegin(GL_QUADS);

	for(i = 0; i < 4; i++)
	{
	glTexCoord2f(tco[i][0], tco[i][1]);
		glVertex3f(
			(qqq[num+i].a+(1*qqq[num+i].d*0.33333*fov4d)+(0*qqq[num+i].c*zfov*0.5)), 
			qqq[num+i].b, 
			depth*(-qqq[num+i].c*zfov*1-(1*qqq[num+i].d*1*fov4d))
			); 
	}
	glEnd();

	return(0);
}



int quad_draw_new(Quaternion *qqq, int num)
{
	int tco[4][2] = {{1,1}, {1,0}, {0,0}, {0,1}};
	int i;
	glBegin(GL_QUADS);

	for(i = 0; i < 4; i++)
	{
		glTexCoord2f(tco[i][0], tco[i][1]);
		glVertex3f(
			(qqq[num+i].a-(qqq[num+i].d*0.25*fov4d)+qqq[num+i].c*zfov*0.25), 
			qqq[num+i].b, 
			depth*(-qqq[num+i].c*zfov*0.5-(qqq[num+i].d*0.5*fov4d))
			); 
	}
	glEnd();

	return(0);
}

int quad_draw_shit(Quaternion *qqq, int num)
{
	int tco[4][2] = {{1,1}, {1,0}, {0,0}, {0,1}};
	int i; float x = 0; int pre = 1;
	glBegin(GL_QUADS);
	for(i = 0; i < 4; i++)
	{
		x = -1*(depth*((1*qqq[num+i].c*zfov)+(1*(qqq[num+i].d*fov4d))));
		pre = (x < 0) ? -1 : 1;
		x = (x < 0) ? -x : x;
		glTexCoord2f(tco[i][0], tco[i][1]);
		glVertex3f(
			(qqq[num+i].a*1+0*(qqq[num+i].d*fov4d)), 
			(qqq[num+i].b+0*qqq[num+i].c*zfov),
			pre*((int)x ? x*log(0.001*x) : 0) 
			); 
	}
	glEnd();

	return(0);
}

int points_draw(Quaternion *qqq, int num, char dir, float val)
{
	int i = 0; float off = 0;
	if(qqq[num+i].c > maxaac) { maxaac = qqq[num+i].c; if(ddebug) printf("max: %f", maxaac); }
	if(qqq[num+i].d > maxaad) { maxaad = qqq[num+i].d; if(ddebug) printf("max: %f", maxaad); }
	glPointSize(12.0f + 0*6.0f*(((-qqq[num+i].c+maxaac)/(maxaac*2))+((-qqq[num+i].d+maxaad)/(maxaad*2)))); //26
	float wwd = 30.0f;
	float wwwd = 10.0f;
	float x = tesseract*((qqq[num+i].d+maxaad)/(maxaad*2));
	float mult1 = -((wwd*(val - x))*(wwd*(val - x))) + 1;
	float mult1i = -(((wwd*wwwd)*(val - x))*((wwd*wwwd)*(val - x))) + 1;
	x = (tesseract*((qqq[num+i].c+maxaac)/(maxaac*2)));
	float mult2 = -((wwd*(val - x))*(wwd*(val - x))) + 1;
	float mult2i = -(((wwd*wwwd)*(val - x))*((wwd*wwwd)*(val - x))) + 1;
	if(mult1 < 0) mult1 = 0;
	if(mult2 < 0) mult2 = 0;
	if(mult1i < 0) mult1i = 0;
	if(mult2i < 0) mult2i = 0;

	float backgrr = 0.01;
//	glColor4f(qqq[num+i].cr+tesseract*((qqq[num+i].c+maxaac)/(maxaac*2)), qqq[num+i].cg, qqq[num+i].cb+tesseract*((qqq[num+i].d+maxaad)/(maxaad*2)), 0.0023 +tesseract*0.2);
	glColor4f(mult2*0.6 + backgrr*0.125f, qqq[num+i].cg+backgrr*0.125f +0.03, mult1, 0.5f*(0.2f + ((mult1i+mult2i)*0.5*(0.0023 +tesseract*0.2))));
//	glColor4f(qqq[num+i].cr, qqq[num+i].cg, qqq[num+i].cb, 0.0023 +tesseract*0.2);
	glBegin(GL_POINTS);
	if(dir == 'l') off = -1;
	else if(dir == 'r') off = 1;
		glVertex3f(
/*			(qqq[num+i].a+0.33333333*(qqq[num+i].d*1*fov4d))+off, 
			(qqq[num+i].b+0.33333333*(qqq[num+i].d*1*fov4d)), 
			depth*(-qqq[num+i].c*zfov-0.33333333*(qqq[num+i].d*1*fov4d))
*/
			qqq[num+i].a, 
			qqq[num+i].b, 
			depth*(-qqq[num+i].c*zfov-(qqq[num+i].d*fov4d*0))


		//	(qqq[num+i].a), 
	//		(qqq[num+i].b), 0 
//			depth*(-qqq[num+i].c)
			); 
	glEnd();

	return(0);
}


int quad_draw(Quaternion *qqq, int num)
{
	int tco[4][2] = {{1,1}, {1,0}, {0,0}, {0,1}};
	int i;
	glBegin(GL_QUADS);
	
	for(i = 0; i < 4; i++)
	{
		glTexCoord2f(tco[i][0], tco[i][1]);
		glVertex3f(
			(qqq[num+i].a+0.33333333*(qqq[num+i].d*1*fov4d)), 
			(qqq[num+i].b+0.33333333*(qqq[num+i].d*1*fov4d)), 
			depth*(-qqq[num+i].c*zfov-0.33333333*(qqq[num+i].d*1*fov4d))
			); 
	}
	glEnd();

	return(0);
}


int quad_draw_good(Quaternion *qqq, int num)
{
	int tco[4][2] = {{1,1}, {1,0}, {0,0}, {0,1}};
	int i;
	glBegin(GL_QUADS);
	
	for(i = 0; i < 4; i++)
	{
		glTexCoord2f(tco[i][0], tco[i][1]);
		glVertex3f(
			(qqq[num+i].a*1-(qqq[num+i].d*1*fov4d)+qqq[num+i].c*zfov*1), 
			(qqq[num+i].b+0*(qqq[num+i].d*1*fov4d)+0*qqq[num+i].c*zfov*1), 
			depth*(-qqq[num+i].c*zfov-(qqq[num+i].d*fov4d))
			); 
	}
	glEnd();

	return(0);
}

int quad_draw_std(Quaternion *qqq, int num)
{
	int tco[4][2] = {{1,1}, {1,0}, {0,0}, {0,1}};
	int i;
	glBegin(GL_QUADS);

	for(i = 0; i < 4; i++)
	{
		glTexCoord2f(tco[i][0], tco[i][1]);
		glVertex3f(qqq[num+i].a, qqq[num+i].b, -qqq[num+i].c*depth*3); 
	}
	glEnd();

	return(0);
}


int quad_draw_l(Quaternion *qqq, int num)
{
	glBegin(GL_QUADS);

	glTexCoord2f(1,1);
	glVertex3f(qqq[num].a, qqq[num].b, (-qqq[num].d*(lrratio)-qqq[num].c*(1-lrratio))*depth); 
	glTexCoord2f(1,0);
	glVertex3f(qqq[num+1].a, qqq[num+1].b, (-qqq[num+1].d*(lrratio)-qqq[num+1].c*(1-lrratio))*depth); 
	glTexCoord2f(0,0);
	glVertex3f(qqq[num+2].a, qqq[num+2].b, (-qqq[num+2].d*(lrratio)-qqq[num+2].c*(1-lrratio))*depth); 
	glTexCoord2f(0,1);
	glVertex3f(qqq[num+3].a, qqq[num+3].b, (-qqq[num+3].d*(lrratio)-qqq[num+3].c*(1-lrratio))*depth); 

	glEnd();

	return(0);
}


int quad_draw_r(Quaternion *qqq, int num)
{
	glBegin(GL_QUADS);

	glTexCoord2f(1,1);
	glVertex3f(qqq[num].a, qqq[num].b, (-qqq[num].c*(lrratio)-qqq[num].d*(1-lrratio))*depth); 
	glTexCoord2f(1,0);
	glVertex3f(qqq[num+1].a, qqq[num+1].b, (-qqq[num+1].c*(lrratio)-qqq[num+1].d*(1-lrratio))*depth); 
	glTexCoord2f(0,0);
	glVertex3f(qqq[num+2].a, qqq[num+2].b, (-qqq[num+2].c*(lrratio)-qqq[num+2].d*(1-lrratio))*depth); 
	glTexCoord2f(0,1);
	glVertex3f(qqq[num+3].a, qqq[num+3].b, (-qqq[num+3].c*(lrratio)-qqq[num+3].d*(1-lrratio))*depth); 

	glEnd();

	return(0);
}


int quad_draw_alt2(Quaternion *qqq, int num)
{
	glBegin(GL_QUADS);

	glTexCoord2f(1,1);
	glVertex3f(qqq[num].a, qqq[num].b, 0); 
	glTexCoord2f(1,0);
	glVertex3f(qqq[num+1].a, qqq[num+1].b, 0); 
	glTexCoord2f(0,0);
	glVertex3f(qqq[num+2].a, qqq[num+2].b, 0); 
	glTexCoord2f(0,1);
	glVertex3f(qqq[num+3].a, qqq[num+3].b, 0); 

	glEnd();

	return(0);
}

int quad_draw_alt(Quaternion *qqq, int num)
{
	glBegin(GL_QUADS);

	glTexCoord2f(1,1);
	glVertex3f(qqq[num].a, qqq[num].b, -qqq[num].c-qqq[num].d); 
	glTexCoord2f(1,0);
	glVertex3f(qqq[num+1].a, qqq[num+1].b, -qqq[num+1].c-qqq[num+1].d); 
	glTexCoord2f(0,0);
	glVertex3f(qqq[num+2].a, qqq[num+2].b, -qqq[num+2].c-qqq[num+2].d); 
	glTexCoord2f(0,1);
	glVertex3f(qqq[num+3].a, qqq[num+3].b, -qqq[num+3].c-qqq[num+3].d); 

	glEnd();

	return(0);
}

void DrawStereo()								/* Draw The Blurred Image */
{
	int i;
	int num; int wd = (w_width-overtexs), hd = (w_height-overtexs);
	if(wd <= 0) wd = 0;
	if(hd <= 0) hd = 0;
/*	glViewport(
		wd*0.5,
		hd*0.5,
		overtexs+wd*0.5, 
		overtexs+hd*0.5
			);
*
*/
//	glViewport(0, 0, overtexs, overtexs);

	if(!tilt)
	{
		glBindTexture(GL_TEXTURE_2D, 0); 
		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
	}
	else
	{
		glBindTexture(GL_TEXTURE_2D, 3); 
		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 3);
	}


	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glEnable(GL_TEXTURE_2D);
//	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_BLEND);		
//	glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, wd*0.5, hd*0.5, overtexs, overtexs, 0);
/*
	unsigned int* data;
	data = (unsigned int*)malloc(sizeof(unsigned int)*4*overtexs*overtexs);
	*data = 0;
*/
        glMatrixMode(GL_PROJECTION); 
        glPushMatrix();          
        glLoadIdentity();       
        glOrtho( 0, w_width, w_height, 0, -1, 1 ); 
        glMatrixMode(GL_MODELVIEW);                 
        glPushMatrix();                            
        glLoadIdentity();      
           

//	if(overtexs < w_height || overtexs < w_width) glViewport (0, 0, w_width, w_height);
//	else glViewport (0, 0, overtexs, overtexs);

	glViewport (0, 0, w_width, w_height);

		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glBindTexture(GL_TEXTURE_2D,tex[1]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);		
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2f(0,1);	
		glVertex2f(0,hd*0.5);	

		glTexCoord2f(0,0);
		glVertex2f(0,w_height-(hd*0.5));

		glTexCoord2f(1,0);
		glVertex2f(w_width/2,w_height-(hd*0.5));		

		glTexCoord2f(1,1);				
		glVertex2f(w_width/2,(hd*0.5));
	glEnd();

	glBindTexture(GL_TEXTURE_2D,tex[2]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);		
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2f(0,1);	
		glVertex2f(w_width/2,hd*0.5);	

		glTexCoord2f(0,0);
		glVertex2f(w_width/2,w_height-(hd*0.5));

		glTexCoord2f(1,0);
		glVertex2f(w_width,w_height-(hd*0.5));		

		glTexCoord2f(1,1);				
		glVertex2f(w_width,(hd*0.5));
	glEnd();

glDisable(GL_TEXTURE_2D);

	float cc[5][4] = {
		{(w_width/2-4), 0, (w_width/2+4), w_height},
		{0, 0, 2, w_height},
		{(w_width-2), 0, (w_width), w_height},
		{0, 0, (w_width), 2},
		{0, w_height-2, (w_width), w_height}
	};
	for(i = 0; i < 5; i++)
	{
		glBegin(GL_QUADS);		
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			glVertex2f(cc[i][0],cc[i][1]);	
			glVertex2f(cc[i][0],cc[i][3]);
			glVertex2f(cc[i][2],cc[i][3]);
			glVertex2f(cc[i][2],cc[i][1]);
		glEnd();
	}	
	
glEnable(GL_TEXTURE_2D);


        glMatrixMode( GL_PROJECTION );
        glPopMatrix();
        glMatrixMode( GL_MODELVIEW );
        glPopMatrix();      

	glBindTexture(GL_TEXTURE_2D,0);

//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	if(!tilt)
		glViewport(0,0,w_width,w_height); 
	else
	{
		glViewport(0,0,overtexs,overtexs); 
		glBindTexture(GL_TEXTURE_2D, 0); 
		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glDisable(GL_DEPTH_TEST);
 		glDisable(GL_BLEND);
	//	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glLoadIdentity();
		glViewport(0,0,w_width,w_height); 
		
		glTranslatef(0, 0, -20);

		glBindTexture(GL_TEXTURE_2D,tex[3]);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

		glBegin(GL_QUADS);		
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2f(0,1);	
		glVertex3f(-10, 10, -10);	

		glTexCoord2f(0,0);
		glVertex3f(10, 10, 10);

		glTexCoord2f(1,0);
		glVertex3f(10, -10, 10);		

		glTexCoord2f(1,1);				
		glVertex3f(-10, -10, -10);
		glEnd();


	}

}


void DrawBlur(int times, float inc)								/* Draw The Blurred Image */
{

	int num; int wd = (w_width-overtexs), hd = (w_height-overtexs);
	if(wd <= 0) wd = 0;
	if(hd <= 0) hd = 0;
	float spost = -((times-1)*inc)/2;
	float alphainc = 0.9999f / times;	
	float alpha = 0.8f;							
/*	glViewport(
		wd*0.5,
		hd*0.5,
		overtexs+wd*0.5, 
		overtexs+hd*0.5
			);
*
*/
//	glViewport(0, 0, overtexs, overtexs);

	glBindTexture(GL_TEXTURE_2D, 0); 
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);		
	glBindTexture(GL_TEXTURE_2D,tex[0]);
//	glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, wd*0.5, hd*0.5, overtexs, overtexs, 0);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
/*
	unsigned int* data;
	data = (unsigned int*)malloc(sizeof(unsigned int)*4*overtexs*overtexs);
	*data = 0;
*/
        glMatrixMode(GL_PROJECTION); 
        glPushMatrix();          
        glLoadIdentity();       
        glOrtho( 0, w_width, w_height, 0, -1, 1 ); 
        glMatrixMode(GL_MODELVIEW);                 
        glPushMatrix();                            
        glLoadIdentity();      
           
	alphainc = alpha / times;		

	if(overtexs < w_height || overtexs < w_width) glViewport (0, 0, w_width, w_height);
	else glViewport (0, 0, overtexs, overtexs);

	glBegin(GL_QUADS);		
	for (num = 0;num < times;num++)	
	{
		glColor4f(1.0f, 1.0f, 1.0f, alpha+spost*5);
		glTexCoord2f(0-spost,1+spost);	
		glVertex2f(wd*0.25,hd*0.25);	

		glTexCoord2f(0-spost,0-spost);
		glVertex2f(wd*0.25,w_height-(hd*0.75));

		glTexCoord2f(1+spost,0-spost);
		glVertex2f(w_width-(wd*0.75),w_height-(hd*0.75));		

		glTexCoord2f(1+spost,1+spost);				
		glVertex2f(w_width-(wd*0.75),(hd*0.25));						

		spost += inc;										
		alpha = alpha - alphainc;							
	}
	glEnd();

	glBegin(GL_QUADS);		
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2f(0,1);	
		glVertex2f(wd*0.25,hd*0.25);	

		glTexCoord2f(0,0);
		glVertex2f(wd*0.25,w_height-(hd*0.75));

		glTexCoord2f(1,0);
		glVertex2f(w_width-(wd*0.75),w_height-(hd*0.75));		

		glTexCoord2f(1,1);				
		glVertex2f(w_width-(wd*0.75),(hd*0.25));
	glEnd();
	
        glMatrixMode( GL_PROJECTION );
        glPopMatrix();
        glMatrixMode( GL_MODELVIEW );
        glPopMatrix();      

	glBindTexture(GL_TEXTURE_2D,0);

//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glViewport(0,0,w_width,w_height); 
}

static void drawdl(char dir, float val)
{
	int i;
	int incz = !skip?1:10;
	for(i = quatnum-1; i >=0; i-=incz)
		points_draw(q, zposbufi[i], dir, val);
}


int drawGLscene()
{
	while(resetpso) SDL_Delay(10);

	int i,j,k; float alpha; unsigned char clear;
	int sloop = 0;	float ratio;
	for(sloop = 0; sloop < 2; sloop++)
{
	if(blurenable)	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo[0]);
	else if(stereo)
	{
		
		if(sloop == 0) glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo[1]);
		if(sloop == 1) glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo[2]);
	}
	if(!blurenable && !stereo) glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);



if(stereo) 
{
//		ratio = (GLfloat)w_width/(2*(GLfloat)w_height);
//		gluPerspective(45.0f, ratio, 0.1f, 800.0f);
ratio = w_width/3;
glViewport(-ratio,0,overtexs+ratio*2,overtexs); 
}

	glMatrixMode(GL_MODELVIEW);
	glDisable(GL_DEPTH_TEST);
 	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_DST_ALPHA);
//	glBlendFunc(GL_SRC_ALPHA,GL_ONE);
	//	GL_ACCUM_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
	glLoadIdentity();

//	if(stereo && sloop == 0) { glTranslatef(0, 0, 0); }
//	if(stereo && sloop == 1) { glTranslatef(0, 0, 0); }
	glBindTexture(GL_TEXTURE_2D, 0);

//	while(lock);
//	lock = 1;
//	rrotxz = rrotyz = rrotxy = rrotwx = rrotwy = rrotwz = 0;

//	lock = 0;
	if(azoom)
	{
		if(zoom > 3 || zoom < -3) azoom = -azoom;
		zoom += azoom;
	}

	playerpos.set(posx, posy, posz, posw);

	glDisable(GL_FOG);

	glFogfv(GL_FOG_COLOR, fogcolor);
	glFogi(GL_FOG_MODE, GL_LINEAR);
	glFogf(GL_FOG_DENSITY, 500);
	glFogf(GL_FOG_START, (1+((zoom*10)))*sqrt(sqrt(depth/20)));
	glFogf(GL_FOG_END, (5+((zoom*10)))*sqrt(sqrt(depth/20)));
	glTranslatef(0, 0, -10*zoom);

	if(points) 
	{
		if(!intensswitch)
		{
			intensval += 0.025f*intensui;
			if(intensval > 1.1f) intensval = -0.1f;
		}
//		list1 = glGenLists (1);
//		glNewList(list1, GL_COMPILE);
		if(stereo && sloop == 0) drawdl('l', intensval);
		if(stereo && sloop == 1) drawdl('r', intensval);
		else drawdl('c', intensval);
//		glEndList();
//		glCallList(list1);
if(ddebug) printf("draw finish %d\n", quatnum);
	}
	else
	{
		if(stereo) posbuf_run(sloop);
		else posbuf_run(10);

		for(j = (quatnum/4)-1; j >= 0; j--)
		{
			i = 4*zposbufi[j];
			if(enablemov) if(i >= movquat) continue;	

			color(2, 1);
			if(zposbufi[j] >= movquat/4) 
				glBindTexture(GL_TEXTURE_2D, texture[2]);
			if(zposbufi[j] >= 0) 
//		else if(zposbufi[j] >= freequat/4) 
				glBindTexture(GL_TEXTURE_2D, texture[1]);
			else if(zposbufi[j] >= bquat/4) 
				glBindTexture(GL_TEXTURE_2D, texture[2]);
			else if(zposbufi[j] >= 0) 
				glBindTexture(GL_TEXTURE_2D, texture[2]);
			else 	glBindTexture(GL_TEXTURE_2D, texture[2]);

			color(((48+i)/48), 0.2f);
			if(zposbufi[j] >= 0) color(((48+i)/48), 0.2f);
			else if(stereo && sloop == 0) quad_draw_l(q, i);
			else if(stereo && sloop == 1) quad_draw_r(q, i);
			//else quad_draw_new(q, i);
			else quad_draw(q, i);
		}
	}
	qbuffer[0].set(padd.a+playerpos.a-1, padd.b+playerpos.b, 
			padd.c+playerpos.c, padd.d+playerpos.d);
	qbuffer[1].set(padd.a+playerpos.a+1, padd.b+playerpos.b, 
			padd.c+playerpos.c, padd.d+playerpos.d);
	qbuffer[2].set(playerpos.a+1, playerpos.b+0.05, 
			playerpos.c, playerpos.d);
	qbuffer[3].set(playerpos.a-1, playerpos.b+0.05, 
			playerpos.c, playerpos.d);

	qbuffer[4].set(padd.a+playerpos.a, padd.b+playerpos.b-1, 
			padd.c+playerpos.c, padd.d+playerpos.d);
	qbuffer[5].set(padd.a+playerpos.a, padd.b+playerpos.b+1, 
			padd.c+playerpos.c, padd.d+playerpos.d);
	qbuffer[6].set(playerpos.a+0.05, playerpos.b+1, 
			playerpos.c, playerpos.d);
	qbuffer[7].set(playerpos.a+0.05, playerpos.b-1, 
			playerpos.c, playerpos.d);


	color(3, 1);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	for(i = 0; i < 8; i++)
		quat_rotate(qbuffer, i);
//	quad_draw(qbuffer, 0);
//	quad_draw(qbuffer, 4);

	if(blurenable) DrawBlur(10*blurr,0.001f);
}
	if(stereo) DrawStereo();

	SDL_GL_SwapBuffers();

	drawnonce = 1;
	return(0);
}

int idrawGLscene()
{
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
	SDL_GL_SwapBuffers();
}

void update_fractal() { }
void randreinit()
{
	fd = open("/dev/random", O_RDONLY);
        read(fd, &buffer, sizeof(unsigned int));
    	close(fd);
        srand(buffer);
	rand1 = 10000000*(2.0f * ((float)rand() / (float)RAND_MAX) - 1.0f);
        read(fd, &buffer, sizeof(unsigned int));
        srand(buffer);
	rand2 = 10000000*(2.0f * ((float)rand() / (float)RAND_MAX) - 1.0f);
        read(fd, &buffer, sizeof(unsigned int));
        srand(buffer);
	rand3 = 10000000*(2.0f * ((float)rand() / (float)RAND_MAX) - 1.0f);
        read(fd, &buffer, sizeof(unsigned int));
        srand(buffer);
	rand4 = 10000000*(2.0f * ((float)rand() / (float)RAND_MAX) - 1.0f);
        read(fd, &buffer, sizeof(unsigned int));
        srand(buffer);
	rand5 = 10000000*(2.0f * ((float)rand() / (float)RAND_MAX) - 1.0f);
        read(fd, &buffer, sizeof(unsigned int));
    	close(fd);
        srand(buffer);
	rand6 = 10000000*(2.0f * ((float)rand() / (float)RAND_MAX) - 1.0f);

}
int mainloop(void*)
{
	int drawchange = 0; int refreshdelay[2] = {33, 33}; int rdelay = 33;
	Uint32 time1 = SDL_GetTicks(), time2 = SDL_GetTicks();
	float ts; int u; int i;
	
	if(!init_SDL(surface))
	{ fprintf(stderr, "SDL_OPENGL failed\n"); exit(1);}
	if(!initGL(w_width, w_height))
	{ fprintf(stderr, "OpenGL failed\n"); exit(1);}

	SDL_WM_SetCaption( "Tesseract", NULL );

	glPointSize(8.0f);

	resizewindow(1280, 1024); 

	load_textures();

	lbounds[0] = 10;
	ts = lbounds[0];

	q = (Quaternion*)(malloc(9999999*sizeof(Quaternion)));
	qbuffer = (Quaternion*)(malloc(9999*sizeof(Quaternion)));
	quatnum = 0;

//	quatnum += construct_tesseract(1,1,1,1, 0, 0, 0, 1,quatnum, 0.5);
playerpost.set(0,0,0,0);
	float acc = fack;

	float spp[18] = { 
		0,
		0, 
		(GLfloat)iterations, // 255 iterations
		0.35f,
		0,
		F_QUATMANDEL,
		-acc+playerpost.a,
		acc+playerpost.a,
		-acc+playerpost.b,
		acc+playerpost.b,
		-acc+playerpost.c,
		acc+playerpost.c,
		-acc+playerpost.d,
		acc+playerpost.d,
		acc,
		zoom2,
		tesseract,
		simplex
		};

	if(points)
		{
			quatnum = calc_fractal(spp, q);
		}
	else
		quatnum += construct_tesseract(1,1,1,1, 0, 0, 0, 0,quatnum, 0.5);

	bquat = quatnum; 
	t_size = quatnum;
/*
	quatnum += construct_tesseract(1,1,1,1, -ts,  ts,  ts,  ts,quatnum, 0.5);
	quatnum += construct_tesseract(1,1,1,1,  ts, -ts,  ts,  ts,quatnum, 0.5);
	quatnum += construct_tesseract(1,1,1,1,  ts,  ts, -ts,  ts,quatnum, 0.5);
	quatnum += construct_tesseract(1,1,1,1,  ts,  ts,  ts,  ts,quatnum, 0.5);
	quatnum += construct_tesseract(1,1,1,1,  ts, -ts, -ts,  ts,quatnum, 0.5);
	quatnum += construct_tesseract(1,1,1,1, -ts, -ts,  ts,  ts,quatnum, 0.5);
	quatnum += construct_tesseract(1,1,1,1, -ts,  ts, -ts,  ts,quatnum, 0.5);
	quatnum += construct_tesseract(1,1,1,1, -ts, -ts, -ts,  ts,quatnum, 0.5);

	quatnum += construct_tesseract(1,1,1,1, -ts,  ts,  ts,  -ts,quatnum, 0.5);
	quatnum += construct_tesseract(1,1,1,1,  ts, -ts,  ts,  -ts,quatnum, 0.5);
	quatnum += construct_tesseract(1,1,1,1,  ts,  ts, -ts,  -ts,quatnum, 0.5);
	quatnum += construct_tesseract(1,1,1,1,  ts,  ts,  ts,  -ts,quatnum, 0.5);
	quatnum += construct_tesseract(1,1,1,1,  ts, -ts, -ts,  -ts,quatnum, 0.5);
	quatnum += construct_tesseract(1,1,1,1, -ts, -ts,  ts,  -ts,quatnum, 0.5);
	quatnum += construct_tesseract(1,1,1,1, -ts,  ts, -ts,  -ts,quatnum, 0.5);
	quatnum += construct_tesseract(1,1,1,1, -ts, -ts, -ts,  -ts,quatnum, 0.5);
*/

	freequat = quatnum; 
//	quatnum += construct_tesseract(1,1,1,1, 0,  0, 0, 0,quatnum, 0.5);

/*
	for(u = 4; u <= 8; u+=2)
	quatnum += construct_tesseract(1,1,1,1, 0,  0, 0, -(5-u*4),quatnum, 1.75);

	for(u = 4; u <= 8; u+=2)
	quatnum += construct_tesseract(1,1,1,1, 0,  0, -(5-u*4), 0,quatnum, 1.75);

	for(u = 4; u <= 8; u+=2)
	quatnum += construct_tesseract(1,1,1,1, 0, -(5-u*4), 0, 0,quatnum, 1.75);

	for(u = 4; u <= 8; u+=2)
	quatnum += construct_tesseract(1,1,1,1, -(5-u*4),  0,  0, 0,quatnum, 1.75);

*/

	movquat = quatnum;

/*
	quatnum += construct_tesseract(1,1,1,1, 0,  0,  0, 0,quatnum, 0.8);
	quatnum += construct_tesseract(1,1,1,1, 0,  0,  0, 0,quatnum, 1.1);
	quatnum += construct_tesseract(1,1,1,1, 0,  0,  0, 0,quatnum, 0.1);
	quatnum += construct_tesseract(1,1,1,1, 0,  0,  0, 0,quatnum, 0.1);
	quatnum += construct_tesseract(1,1,1,1, 0,  0,  0, 0,quatnum, 0.1);
	quatnum += construct_tesseract(1,1,1,1, 0,  0,  0, 0,quatnum, 0.1);

	quatnum += construct_tesseract(1,1,1,1, 0,  0,  0, 0,quatnum, 0.1);
	quatnum += construct_tesseract(1,1,1,1, 0,  0,  0, 0,quatnum, 0.1);
	quatnum += construct_tesseract(1,1,1,1, 0,  0,  0, 0,quatnum, 0.1);
	quatnum += construct_tesseract(1,1,1,1, 0,  0,  0, 0,quatnum, 0.1);
	quatnum += construct_tesseract(1,1,1,1, 0,  0,  0, 0,quatnum, 0.1);
	quatnum += construct_tesseract(1,1,1,1, 0,  0,  0, 0,quatnum, 0.1);
*/
	maxquat = quatnum;

	int yy;
	printf("quatnum: %d\n", quatnum);

//	for(u = 0; u < quatnum; u++)
//		qo[u] = q[u];

	playerpos.set(0,0,0,0);
	playerpost.set(0,0,0,0);
	padd.set(0,0,0,0);
	ptemp.set(0,0,0,0);
	ptemp2.set(0,0,0,0);

			randreinit();

	init_fbo(0);	
	init_fbo(1);	
	init_fbo(2);
	
	init_fbo(3);	

	for(i = 0; i < quatnum/4; i++)
	{
		zposbuf[i] = get_zposbuf(i);
		zposbufi[i] = i;
	}

	while(!done)
	{
		framecounter++;
		if(framecounter > 4294967000UL) framecounter = 0;
		drawchange = keylistener();
		SDL_Delay(rdelay*0.5);
		if(!(framecounter%5))
		{
//			printf("Delay: %d\n", rdelay);
			time1 = SDL_GetTicks();
			refreshdelay[framecounter%2] = 
				1000/((((int)(time1-time2)) > 0)
				? (int)(time1-time2) : 1000 );
			time2 = time1;
			if(abs(refreshdelay[framecounter%2]
			- refreshdelay[(framecounter-1)%2])
			>= 2)
			{ 
				rdelay = (refreshdelay[framecounter%2]
				       + refreshdelay[(framecounter-1)%2])/2; 
				rdelay -= 16;
				if(rdelay <= 0) rdelay = 0;
				rdelay = 33;
			}
		}
		if(!(framecounter%((int)(33*20))))
			randreinit();		
		drawGLscene();
	}
	printf("Quit called, cleaning up\n");
	SDL_Quit(); 

	return(0);
}

int sleeper2(void*)
{
	while(!done)
		if(!resetpso) posbuf_run(-1);
		else SDL_Delay(100);
	
}
int sleeper4(void*)
{
	float acc = fack;

	float spp[18] = { 
		0,
		0, 
		(GLfloat)iterations, // 255 iterations
		0.35f,
		0,
		F_QUATMANDEL,
		-acc+playerpos.a*10*zoom2,
		acc+playerpos.a*10*zoom2,
		-acc+playerpos.b*10*zoom2,
		acc+playerpos.b*10*zoom2,
		-acc+playerpos.c*10*zoom2,
		acc+playerpos.c*10*zoom2,
		-acc+playerpos.d*10*zoom2,
		acc+playerpos.d*10*zoom2,
		acc,
		zoom2,
		tesseract,
		simplex
		};


	float prevzoom = zoom2;
	int ttt,j;

	while(!done)
	{
		if(prevzoom != zoom2 || movx || movy || movz || movw)
		{
			if(points)
			{
		float inccc=0.5*zoom2;
		posx += movx*inccc;
		posy += movy*inccc;
		posz += movz*inccc;
		posw += movw*inccc;
     	 movx = 0; movz = 0; movw = 0; movy = 0;

	printf("ppos: %f, %f, %f, %f\n", posx, posy, posz, posw);
		resetpso = 1; SDL_Delay(100); while(posbufrunning) SDL_Delay(10);
				spp[6] = -acc+posx;
				spp[7] = acc+posx;
				spp[8] = -acc+posy;
				spp[9] = acc+posy;
				spp[10] = -acc+posz;
				spp[11] = acc+posz;
				spp[12] = -acc+posw;
				spp[13] = acc+posw;
				ttt = calc_fractal(spp, q);
				quatnum = ttt;
				maxquat = quatnum;
				for(j = 0; j < quatnum; j++)
					zposbufi[j] = j;
	if(ddebug) 			printf("calcfractal finish %d\n", quatnum);
		SDL_Delay(1000);
		resetpso = 0;
			}
			prevzoom = zoom2;
		}
		else SDL_Delay(100);
	}
}

int sleeper(void*)
{
	int i;
	trotxy = rrotxy; trotyz = rrotyz; trotxz = rrotxz;
	trotwy = rrotwy; trotwx = rrotwx; trotwz = rrotwz;

//	while(!drawnonce);
/*	posbuf_run();
	posbuf_run();
*/
//	posbuf_run_once();
	while(!done)
	{	
		if(arot)
		{
	//		while(lock);
	//		lock = 1;
			arotxz = aspeed*(0.05*((rand1%((int)(234525)))
				/234525.0));
			arotyz = aspeed*(0.05*((rand2%((int)(457646)))
				/457646.0));
			arotxy = aspeed*(0.05*((rand3%((int)(957431)))
				/957431.0));
			arotwx = aspeed*(0.05*((rand4%((int)(255689)))
				/255689.0));
			arotwy = aspeed*(0.05*((rand5%((int)(737345)))
				/737345.0));
			arotwz = aspeed*(0.05*((rand6%((int)(231455)))
				/231455.0));
	//		lock = 0;
		}
		else
		{
			arotxz = arotyz = arotxy = arotwx = arotwy = arotwz = 0;
		}
		if(((trotxy != rrotxy || trotyz != rrotyz || trotxz != rrotxz 
		|| trotwy != rrotwy || trotwx != rrotwx || trotwz != rrotwz) || arot) && !lock && !resetpso)
		{	
			while(lock);
			lock = 1;
			trotxz = arotxz+rrotxz;
			trotyz = arotyz+rrotyz;
			trotxy = arotxy+rrotxy;
			trotwx = arotwx+rrotwx;
			trotwy = arotwy+rrotwy;
			trotwz = arotwz+rrotwz;
			lock = 0;
			if(!enablemov && 0) // ?????? CMPQ
			{
				if(bulletf == 1)
				{
					if(auto2 == 0 && auto1 == 0) auto2 = 10.0f;
					if(auto2 >=  10 && auto1 < 10) auto1 += 0.2f;
					if(auto1 >=  10 && auto2 > -10) auto2 -= 0.2f;
					if(auto2 <= -10 && auto1 > -10) auto1 -= 0.2f;
					if(auto1 <= -10 && auto2 < 10) auto2 += 0.2f;

					if(auto2 >= 10 && auto1 > 2.0f && auto1 < 2.2f) auto4 = 10;
					if(auto4 >=  10 && auto3 < 10) auto3 += 0.2f;
					if(auto3 >=  10 && auto4 > -10) auto4 -= 0.2f;
					if(auto4 <= -10 && auto3 > -10) auto3 -= 0.2f;
					if(auto3 <= -10 && auto4 < 10) auto4 += 0.2f;
				}
			
				i = 0;

				int yy;
		//		for(yy = 0; yy < maxquat; yy++)
		//			q[yy] = qo[yy];
			}

			for(i = 0; i < quatnum; i++)
			{
		//		q[i] = qo[i];
				if(enablemov) if(i > movquat) break;
				quat_rotate(q, i);
			}
	if(ddebug) 			printf("rotate finish %d\n", quatnum);
			trotxy = rrotxy; trotyz = rrotyz; trotxz = rrotxz;
			trotwy = rrotwy; trotwx = rrotwx; trotwz = rrotwz;
			SDL_Delay(33);
		}
		else SDL_Delay(1);
	}

}

int main(int argc, char **argv)
{
	int w;
	for(w = 0; w< 1200; w++) count[w] = 0;
	int t_numt;
	SDL_Thread *thread = SDL_CreateThread(mainloop, NULL);
	SDL_Thread *thread2= SDL_CreateThread(sleeper, NULL);
	SDL_Thread *thread3= SDL_CreateThread(sleeper2, NULL);
	SDL_Thread *thread4= SDL_CreateThread(sleeper4, NULL);
	SDL_WaitThread(thread, NULL);
	SDL_WaitThread(thread2, NULL);
	SDL_WaitThread(thread3, NULL);
	SDL_WaitThread(thread4, NULL);
 
	printf("thread exited\n");
	exit(0);
	return(0);
}
