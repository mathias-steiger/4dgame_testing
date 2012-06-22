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

#ifndef FRAC3D_SDL_GLFUNC
#define FRAC3D_SDL_GLFUNC

extern GLfloat *vertncol[1200]; 
extern GLuint VBObuf[1200];
extern GLuint fbo[20];

extern PFNGLGENBUFFERSARBPROC glGenBuffersARB;
extern PFNGLBINDBUFFERARBPROC glBindBufferARB;
extern PFNGLBUFFERDATAARBPROC glBufferDataARB;
extern PFNGLDELETEBUFFERSARBPROC glDeleteBuffersARB;

extern PFNGLISRENDERBUFFEREXTPROC 
glIsRenderbufferEXT;
extern PFNGLBINDRENDERBUFFEREXTPROC 
glBindRenderbufferEXT;
extern PFNGLDELETERENDERBUFFERSEXTPROC 
glDeleteRenderbuffersEXT;
extern PFNGLGENRENDERBUFFERSEXTPROC 
glGenRenderbuffersEXT;
extern PFNGLRENDERBUFFERSTORAGEEXTPROC 
glRenderbufferStorageEXT;
extern PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC 
glGetRenderbufferParameterivEXT;
extern PFNGLISFRAMEBUFFEREXTPROC 
glIsFramebufferEXT;
extern PFNGLBINDFRAMEBUFFEREXTPROC 
glBindFramebufferEXT;
extern PFNGLDELETEFRAMEBUFFERSEXTPROC 
glDeleteFramebuffersEXT;
extern PFNGLGENFRAMEBUFFERSEXTPROC 
glGenFramebuffersEXT;
extern PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC 
glCheckFramebufferStatusEXT;
extern PFNGLFRAMEBUFFERTEXTURE1DEXTPROC 
glFramebufferTexture1DEXT;
extern PFNGLFRAMEBUFFERTEXTURE2DEXTPROC 
glFramebufferTexture2DEXT;
extern PFNGLFRAMEBUFFERTEXTURE3DEXTPROC 
glFramebufferTexture3DEXT;
extern PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC 
glFramebufferRenderbufferEXT;
extern PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC 
glGetFramebufferAttachmentParameterivEXT;
extern PFNGLGENERATEMIPMAPEXTPROC 
glGenerateMipmapEXT;




extern int overtexs;

int po2(int input);
int resizewindow(int width, int height);
void SDL_GL_Enter2DMode();
void SDL_GL_Leave2DMode();
int init_SDL(SDL_Surface *screen);
extern int count[1200];
extern int gldrawmode;

extern GLuint texture[100];
extern GLuint tex[100];

int load_textures();
int init_fbo(int n); 
int init_fbodef();
void set_texco(int width, int height);
GLuint convert_texture(SDL_Surface *texsurface, GLuint *texture);
int initGL(int width, int height);
void load_vbo(int num);
int draw_vbo(int num);
#endif
