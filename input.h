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

#ifndef FRAC3D_SDL_INPUT 
#define FRAC3D_SDL_INPUT
extern unsigned char intensswitch;
extern float lrratio;
extern float intensui;
extern int lock;
extern int skip;
extern int mxsave, mysave;
extern int mxsave2, mysave2;
extern int mxsave3, mysave3;
extern int grab;
extern int tilt;
extern unsigned long int framecounter;
extern int blurenable;
extern int stereo;
extern int enablemov;
extern int arot;
extern int presschange;
extern float blurr;
extern Quaternion padd;
extern Quaternion ptemp;
extern Quaternion ptemp2;
extern GLfloat fogcolor[4];
extern GLfloat movx, movy, movz, movw;
extern GLfloat posx, posy, posz, posw;
extern GLfloat rotxy, rotyz, rotxz, rotwy, rotwx, rotwz;
extern GLfloat rrotxy, rrotyz, rrotxz, rrotwy, rrotwx, rrotwz, zoom;
extern gltexcoord texco;
extern float fov4d;
extern float zfov;
extern float depth;
extern float aspeed;
extern int fdjoy;
extern float bulletfactor;
extern float bulletf;
extern int done, prevmpress, mult;
extern SDL_Joystick *joys;
extern SDL_Event event; 
extern int keyevent, mpressl, mpressr, mpresslr, mpressm;
extern int accplus;
extern int pos4d;
extern int w_height, w_width;
extern int accuracy;
int lmousepress(int mprevx, int mprevy);
int nolmousepress();
int keypress(SDL_keysym *keysym, int ud);
int keylistener();

#endif
