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

int po2(int input)
{
	int value = 1;
	while ( value < input ) value <<= 1;
	return value;
}

int resizewindow(int width, int height)
{
	GLfloat ratio;
	static SDL_Surface *screen = SDL_GetVideoSurface();
	/* avoid division by zero */
	if(!height) height = 1;
	if(!width) width = 1;
	screen = SDL_SetVideoMode(width, height, 16, screen->flags);
	ratio = (GLfloat)width/(GLfloat)height;
	/* adapt the GL view */
	glViewport(0, 0, (GLint)width, (GLint)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, ratio, 0.1f, 800.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	return(1);
}


int init_SDL(SDL_Surface *screen)
{
	int videoflags;
        const SDL_VideoInfo *videoinfo;
        SDL_Init(SDL_INIT_VIDEO);
        videoinfo = SDL_GetVideoInfo();

        videoflags  = SDL_OPENGL;
        videoflags |= SDL_GL_DOUBLEBUFFER;
        videoflags |= SDL_HWPALETTE;
        videoflags |= SDL_RESIZABLE;
//	videoflags |= SDL_GL_MULTISAMPLEBUFFERS;
	
	videoflags |= SDL_SWSURFACE;
	videoflags |= SDL_HWACCEL;
/*
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
*/
//	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
//	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
	if(screen = SDL_SetVideoMode(1280, 1024, 16, videoflags)) 
		printf("successs");
	else printf("errorrr");


#ifdef windows
        freopen("CON", "w", stdout);
        freopen("CON", "w", stderr);
#endif

//	joys->naxes = 16;
//	joys->axes = (Sint16 *)SDL_malloc
//	(joys->naxes*sizeof(Sint16));
	return(1);
}

int initGL(int width, int height)
{
	init_fbodef();
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
//	glEnable(GL_DEPTH_TEST);					//?
//	glDepthFunc(GL_LEQUAL);						//?
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
//	glEnable(GL_MULTISAMPLE);
//	glEnable(GL_FOG);
	glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ONE);

//	glGenRenderbuffersEXT(1, NULL);
//	glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, GL_DEPTH_COMPONENT, 1024, 768);
//	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo);

	return(1);
}

int load_textures()
{
	SDL_Surface *TextureImage[1];
	if((TextureImage[0] = SDL_LoadBMP("./surf01.bmp")))
	{
		glGenTextures(1, &texture[0]);
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexImage2D(GL_TEXTURE_2D, 0, 4, TextureImage[0]->w,
			TextureImage[0]->h, 0, GL_BGRA,
			GL_UNSIGNED_BYTE, TextureImage[0]->pixels);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//	if(TextureImage[0]) SDL_FreeSurface(TextureImage[0]);

	}
	else printf("Texture failed\n");
	if((TextureImage[0] = SDL_LoadBMP("./surf02.bmp")))
	{
		glGenTextures(1, &texture[1]);
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glTexImage2D(GL_TEXTURE_2D, 0, 2, TextureImage[0]->w,
			TextureImage[0]->h, 0, GL_RGBA,
			GL_UNSIGNED_BYTE, TextureImage[0]->pixels);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//	if(TextureImage[0]) SDL_FreeSurface(TextureImage[0]);

	}
	else printf("Texture failed\n");
	if((TextureImage[0] = SDL_LoadBMP("./surf03.bmp")))
	{
		glGenTextures(1, &texture[2]);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexImage2D(GL_TEXTURE_2D, 0, 2, TextureImage[0]->w,
			TextureImage[0]->h, 0, GL_BGRA,
			GL_UNSIGNED_BYTE, TextureImage[0]->pixels);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//	if(TextureImage[0]) SDL_FreeSurface(TextureImage[0]);

	}
	else printf("Texture failed\n");

	if((TextureImage[0] = SDL_LoadBMP("./surf04.bmp")))
	{
		glGenTextures(1, &texture[3]);
		glBindTexture(GL_TEXTURE_2D, texture[3]);
		glTexImage2D(GL_TEXTURE_2D, 0, 2, TextureImage[0]->w,
			TextureImage[0]->h, 0, GL_BGRA,
			GL_UNSIGNED_BYTE, TextureImage[0]->pixels);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//	if(TextureImage[0]) SDL_FreeSurface(TextureImage[0]);

	}
	else printf("Texture failed\n");



	return(1);
}

int init_fbo(int n)
{
	unsigned int* data;
	data = (unsigned int*)
		malloc(sizeof(unsigned int)*4*overtexs*overtexs);
	*data = 0;
	glGenFramebuffersEXT(1, &fbo[n]);
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo[n]);

	glGenTextures(1, &tex[n]);
	glBindTexture(GL_TEXTURE_2D, tex[n]);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, overtexs, overtexs, 0, GL_RGB,
		GL_UNSIGNED_BYTE, data);

//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, overtexs, overtexs, 0, GL_RGBA,
//		GL_INT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glFramebufferTexture2DEXT(
		GL_FRAMEBUFFER_EXT,
		GL_COLOR_ATTACHMENT0_EXT,
		GL_TEXTURE_2D, tex[n], 0);
	free(data);

	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);




	return(0);
}

int init_fbodef()
{
	glIsRenderbufferEXT = 
		(PFNGLISRENDERBUFFEREXTPROC)
		SDL_GL_GetProcAddress("glIsRenderbufferEXT");
	glBindRenderbufferEXT = 
		(PFNGLBINDRENDERBUFFEREXTPROC)
		SDL_GL_GetProcAddress("glBindRenderbufferEXT");
	glDeleteRenderbuffersEXT = 
		(PFNGLDELETERENDERBUFFERSEXTPROC)
		SDL_GL_GetProcAddress("glDeleteRenderbuffersEXT");
	glGenRenderbuffersEXT = 
		(PFNGLGENRENDERBUFFERSEXTPROC)
		SDL_GL_GetProcAddress("glGenRenderbuffersEXT");
	glRenderbufferStorageEXT = 
		(PFNGLRENDERBUFFERSTORAGEEXTPROC)
		SDL_GL_GetProcAddress("glRenderbufferStorageEXT");
	glGetRenderbufferParameterivEXT = 
		(PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC)
		SDL_GL_GetProcAddress("glGetRenderbufferParameterivEXT");
	glIsFramebufferEXT = 
		(PFNGLISFRAMEBUFFEREXTPROC)
		SDL_GL_GetProcAddress("glIsFramebufferEXT");
	glBindFramebufferEXT = 
		(PFNGLBINDFRAMEBUFFEREXTPROC)
		SDL_GL_GetProcAddress("glBindFramebufferEXT");
	glDeleteFramebuffersEXT = 
		(PFNGLDELETEFRAMEBUFFERSEXTPROC)
		SDL_GL_GetProcAddress("glDeleteFramebuffersEXT");
	glGenFramebuffersEXT = 
		(PFNGLGENFRAMEBUFFERSEXTPROC)
		SDL_GL_GetProcAddress("glGenFramebuffersEXT");
	glCheckFramebufferStatusEXT = 
		(PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC)
		SDL_GL_GetProcAddress("glCheckFramebufferStatusEXT");
	glFramebufferTexture1DEXT = 
		(PFNGLFRAMEBUFFERTEXTURE1DEXTPROC)
		SDL_GL_GetProcAddress("glFramebufferTexture1DEXT");
	glFramebufferTexture2DEXT = 
		(PFNGLFRAMEBUFFERTEXTURE2DEXTPROC)
		SDL_GL_GetProcAddress("glFramebufferTexture2DEXT");
	glFramebufferTexture3DEXT = 
		(PFNGLFRAMEBUFFERTEXTURE3DEXTPROC)
		SDL_GL_GetProcAddress("glFramebufferTexture3DEXT");
	glFramebufferRenderbufferEXT = 
		(PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC)
		SDL_GL_GetProcAddress("glFramebufferRenderbufferEXT");
	glGetFramebufferAttachmentParameterivEXT = 
		(PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)
		 SDL_GL_GetProcAddress("glGenerateMipmapEXT");
	return(0);
} 
