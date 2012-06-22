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


/* left mouse was pressed */
int lmousepress(int mprevx, int mprevy) 
{
        int mroty, mrotx;
        SDL_GetMouseState(&mrotx, &mroty);
	if(!grab)
	{
	        rrotxy = 0.00001*(framecounter%2)-(w_width/2-mrotx)/(180 * 3.141592654f*10.0f);
	        rrotyz = 0.00001*(framecounter%2)-(w_height/2-mroty)/(180 * 3.141592654f*10.0f);
	}
	else
	{
	        rrotxy = -((mxsave-mrotx))/(180 * 3.141592654f*1.0f);
	        rrotyz = -((mysave-mroty))/(180 * 3.141592654f*1.0f);
		mxsave = mrotx;
		mysave = mroty;
	}
	rotxy += rrotxy;
	rotyz += rrotyz;
	rrotwx = 0;
	rrotwy = 0;
	rrotxz = 0;
	rrotwz = 0;
/*
if(presschange)
{
	ptemp = ptemp2;
	ptemp.rotate_o(-rotxz, -rotyz, -rotxy, -rotwx, -rotwy, -rotwz);
	padd.set(0,0,0,1);
	padd.add(ptemp.a, ptemp.b, ptemp.c, ptemp.d);
	ptemp2 = padd;
	padd.rotate_r(-rotxz, -rotyz, -rotxy, -rotwx, -rotwy, -rotwz);
	presschange = 0;
}
*/
	return(0);
}

/* no mouse was pressed */
int nolmousepress()
{
	/* check menu */
        int mroty, mrotx; int mu;
        SDL_GetMouseState(&mrotx, &mroty);
	return(0);
}

/* right mouse was pressed */
int rmousepress(int mrotx, int mroty) 
{
	/* zoom */
	SDL_GetMouseState(&mrotx, &mroty);
	if(!grab)
	{
	        rrotwx = 0.00001*(framecounter%2)-(w_width/2-mrotx)/(180 * 3.141592654f*10.0f);
	        rrotwy = 0.00001*(framecounter%2)-(w_height/2-mroty)/(180 * 3.141592654f*10.0f);
	}
	else
	{
	        rrotwx = -((mxsave2-mrotx))/(180 * 3.141592654f*1.0f);
	        rrotwy = -((mysave2-mroty))/(180 * 3.141592654f*1.0f);
		mxsave2 = mrotx;
		mysave2 = mroty;
	}
	rotwx += rrotwx;
	rotwy += rrotwy;
	rrotxy = 0;
	rrotxz = 0;
	rrotwz = 0;
	rrotyz = 0;
/*
if(!presschange)
{
	ptemp = ptemp2;
	ptemp.rotate_o(-rotxz, -rotyz, -rotxy, -rotwx, -rotwy, -rotwz);
	padd.set(0,0,1,0);	
	padd.add(ptemp.a, ptemp.b, ptemp.c, ptemp.d);
	ptemp2 = padd;
	padd.rotate_r(-rotxz, -rotyz, -rotxy, -rotwx, -rotwy, -rotwz);
	presschange = 1;
}
*/
        return(0);
}

int mmousepress(int mrotx, int mroty) 
{
	/* zoom */
	SDL_GetMouseState(&mrotx, &mroty);
	if(!grab)
	{
	        rrotxz = 0.00001*(framecounter%2)-(w_width/2-mrotx)/(180 * 3.141592654f*10.0f);
	        rrotwz = 0.00001*(framecounter%2)-(w_height/2-mroty)/(180 * 3.141592654f*10.0f);
	}
	else
	{
	        rrotxz = -((mxsave3-mrotx))/(180 * 3.141592654f*1.0f);
	        rrotwz = -((mysave3-mroty))/(180 * 3.141592654f*1.0f);
		mxsave3 = mrotx;
		mysave3 = mroty;
	}
	rotxz += rrotxz;
	rotwz += rrotwz;
	rrotxy = 0;
	rrotyz = 0;
	rrotwx = 0;
	rrotwy = 0;
        return(0);
}


 
int keypress(SDL_keysym *keysym, int ud)
{
	switch(keysym->sym) 
	{
/* quit */
	case SDLK_ESCAPE:
		if(ud) { done=0; }
		break;
	case SDLK_UP:
		if(ud) movz += 1;
		break;
	case SDLK_DOWN:
		if(ud) movz -= 1;
		break;
	case SDLK_LEFT:
		if(ud) movx += 1;
		break;
	case SDLK_RIGHT:
		if(ud) movx -= 1;
		break;
	case SDLK_RCTRL:
		if(ud) movw += 1;
		break;
	case SDLK_RSHIFT:
		if(ud) movw -= 1;
		break;
	case SDLK_PAGEDOWN:
		if(ud) movy += 1;
		break;
	case SDLK_PAGEUP:
		if(ud) movy -= 1;
		break;


	case SDLK_SPACE:
		if(ud) bulletf = -bulletf;
		break;
	case SDLK_RETURN:
		break;
	case SDLK_f:
		if(ud) {fogcolor[0] = 1; fogcolor[1] = 0; fogcolor[2] = 1; fogcolor[3] = 1;}
		if(!ud) {fogcolor[0] = 0; fogcolor[1] = 0; fogcolor[2] = 0; fogcolor[3] = 1;}
		break;
	case SDLK_RIGHTBRACKET:
		zfov-=0.5;
		if(zfov < 1) { zfov+=0.5; zfov*=0.5; }
		break;
	case SDLK_LEFTBRACKET:
		if(zfov < 1) zfov*=2; 
		else zfov+= 0.5;
		break;
	case SDLK_s:
		if(!ud) arot = ~arot;
		break;
	case SDLK_w:
		if(!ud) grab = ~grab;
		break;

	case SDLK_5:
		if(!ud) skip = !skip?1:0;
		break;

	case SDLK_q:
		if(!ud) aspeed /= 2;
		break;
	case SDLK_a:
		if(!ud) aspeed *= 2;
		break;

	case SDLK_o:
		if(!ud) intensui /= 1.1;
		break;
	case SDLK_p:
		if(!ud) intensui *= 1.1;
		break;

	case SDLK_j:
		if(lrratio <= 0) break;
		if(!ud) lrratio -= 0.05;
		break;
	case SDLK_k:
		if(lrratio >= 1) break;
		if(!ud) lrratio += 0.05;
		break;

	case SDLK_n:
		if(!ud) blurr /= 2;
		break;
	case SDLK_m:
		if(!ud) blurr *= 2;
		break;

	case SDLK_t:
		if(!ud) 
		{
		stereo = ~stereo;
			if(stereo) resizewindow(w_width/2, w_height);
			else resizewindow(w_width, w_height);
		}
		break;


	case SDLK_y:
		if(!ud) tilt = ~tilt;
		break;

	case SDLK_b:
		if(!ud) blurenable = ~blurenable;
		break;
	case SDLK_g:
		if(!ud) enablemov = ~enablemov;
		break;
	case SDLK_i:
		if(!ud) intensswitch = ~intensswitch;
		break;

	case SDLK_1:
		if(!ud) zoom2 *=2;
		break;
	case SDLK_2:
		if(!ud) zoom2 /=2;
		break;

	case SDLK_c:
		if(!ud) depth += 0.2f;
		break;
	case SDLK_v:
		if(!ud) depth -= 0.2f;
		break;
	case SDLK_EQUALS:
		if(fov4d < 1) fov4d*=2; 
		else fov4d+= 0.5;
		break;
	case SDLK_0:
		fov4d = 1;
		break;
	case SDLK_MINUS:
		fov4d-=0.5;
		if(fov4d < 1) { fov4d+=0.5; fov4d*=0.5; }
		break;
		default:
		break;
	}
	return(0);
}

/* check for input events and return if a redraw needs to be done */
int keylistener()
{
	int mu = 0; int i; int fd;
	int mprevx, mprevy; bool leftB = false, rightB = false, middleB = false; 
	bool mwheelup = false, mwheeldown = false; struct js_event js; 
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_VIDEORESIZE:
			w_width = event.resize.w; 
			w_height = event.resize.h; 
			resizewindow(w_width, w_height);
			printf("debug: draw function called (resize %dx%d)\n", w_width, w_height);
			break;
		case SDL_KEYDOWN:
			if(keypress(&event.key.keysym, 1)) done = 1;
			break;
		case SDL_KEYUP:
			keypress(&event.key.keysym, 0);
			break;
		case SDL_MOUSEBUTTONDOWN:
			SDL_GetMouseState(&mprevx, &mprevy);
			leftB =(event.button.button == SDL_BUTTON_LEFT);
			rightB=(event.button.button == SDL_BUTTON_RIGHT);
			middleB=(event.button.button == SDL_BUTTON_MIDDLE);
			mwheelup=(event.button.button == SDL_BUTTON_WHEELUP);
			mwheeldown=(event.button.button == SDL_BUTTON_WHEELDOWN);
	//		if(leftB && rightB) mpresslr = 1;
			if(leftB) { mpressl = 1; SDL_GetMouseState(&mxsave, &mysave); }
			if(rightB) { mpressr = 1; SDL_GetMouseState(&mxsave2, &mysave2); }
			if(middleB) { mpressm = 1; SDL_GetMouseState(&mxsave3, &mysave3); }

			break;
		case SDL_MOUSEBUTTONUP:
			leftB =(event.button.button == SDL_BUTTON_LEFT);
			rightB=(event.button.button == SDL_BUTTON_RIGHT);
			middleB=(event.button.button == SDL_BUTTON_MIDDLE);
			mwheelup=(event.button.button == SDL_BUTTON_WHEELUP);
			mwheeldown=(event.button.button == SDL_BUTTON_WHEELDOWN);
//			if(leftB && rightB) mpresslr = 0;
			if(leftB) { mpressl = 0; mxsave = 0; mysave = 0; rrotxy = 0; rrotyz = 0; }
			if(rightB) { mpressr = 0; mxsave2 = 0; mysave2 = 0;  rrotwx = 0; rrotwy = 0; }
			if(middleB) { mpressm = 0; mxsave3 = 0; mysave3 = 0; rrotxz = 0; rrotwz = 0; }
			break;
		case SDL_JOYAXISMOTION:
//			for(i = 1; i < 24; i++) 
//				printf(" %d : %d", i, SDL_JoystickGetAxis(joys, i));
//			printf("\n");
			break;
		case SDL_JOYBUTTONDOWN:
			printf("BUTTON\n");
			break;
		case SDL_QUIT:
			done = 1;
			break;
			default:
			break;
		}
	}
/*
			printf("START\n");
                        for(i = 0; i < 4;) 
                        { 
			while(read(fd, &js, sizeof(struct js_event)) == sizeof(struct js_event))
			printf("Event: type %d, time %d, number %d, value %d\n",
                                js.type, js.time, js.number, js.value);
			if(js.number == 0)
        rotxy = (js.value)*0.000001f;
			if(js.number == 1)
        rotyz = (js.value)*0.000001f;
			if(js.number == 2)
        rotwx = (js.value)*0.000001f;
			if(js.number == 3)
        rotwy = (js.value)*0.000001f; 

			i++;
                        }   
			printf("END\n");
*/
	/* perform a function for each mousebutton according to the
	 * circumstances it was pressed in */
	while(lock);
	lock = 1;
	if(mpressl) lmousepress(0, 0);
	if(mpressr) rmousepress(0,0); 
	if(mpressm) mmousepress(0,0);
	if(mwheelup) zoom-=0.2;
	if(mwheeldown) zoom+=0.2;
	lock = 0;
//	else zoom = 0;
	return(0);
}
