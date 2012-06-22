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
// file stolen and fudged

#include "main.h"


/* draw an ordinary point */
void fractal_draw_point(int *l, int *ct, GLfloat *scale, int *m, 
	GLfloat **vvnc, GLfloat *sp)
{
	vvnc[0][(*ct)]   = l[0]/((*scale)*sp[12]);
	vvnc[0][(*ct)+1] = l[1]/((*scale)*sp[12]);
	vvnc[0][(*ct)+2] = l[2]/((*scale)*sp[12]);

	vvnc[1][(*ct)]   = 0.7f;
	vvnc[1][(*ct)+1]   = 0.3f;
	vvnc[1][(*ct)+2]   = 1.0f;
	(*ct) += 3;
}

/* confine the scanned area in the loop to something less big that
 * resembles the shape of the fractal */
int fractal_conf_box(char axis, int *l, int *ct, GLfloat *scale, int *m, 
	GLfloat **vvnc, GLfloat *sp, int *draw)
{
	switch(axis)
	{
	case 'x':
		if(l[2] >=  (l[0] + sp[12]*1.7f)) // left-top
			return(1); 
		if(l[2] <= (-l[0] - sp[12]*1.6f)) // left-bottom
			return(2); 
		if(l[2] <=  (l[0] - sp[12]*1.3f)) // right-bottom
			return(2); 
		if(l[2] >= (-l[0] + sp[12]*1.3f)) // right-top
			return(1); 
		break;
	case 'y':
		if(l[1] >=  (l[0] + sp[12]*1.7f)) // left-top
			return(1); 
		if(l[1] <= (-l[0] - sp[12]*1.6f)) // left-bottom
			return(2); 
		if(l[1] <=  (l[0] - sp[12]*1.3f)) // right-bottom
			return(2); 
		if(l[1] >= (-l[0] + sp[12]*1.3f)) // right-top
			return(1); 
		break;
	case 'z':
		if(l[1] >=  (l[2] + sp[12]*1.3f)) // left-top
			return(2); 
		if(l[1] <= (-l[2] - sp[12]*1.3f)) // left-bottom
			return(2); 
		if(l[1] <=  (l[2] - sp[12]*1.3f)) // right-bottom
			return(2); 
		if(l[1] >= (-l[2] + sp[12]*1.3f)) // right-top
			return(2); 
		break;
	default: return(0);
	}
	return(0);
}

/* draw a box point, only every tenth point of the grid area */
void fractal_boxtest(int *l, int *ct, GLfloat *scale, int *m, 
	GLfloat **vvnc, GLfloat *sp, int *draw)
{
	if(!((l[0]-(int)sp[6])%10) 
	&& !((l[1]-(int)sp[8])%10) 
	&& !((l[2]-(int)sp[10])%10) ) 
		vvnc[0][(*ct)+2] = l[0]-sp[6]+l[1]-sp[8]+l[2]-sp[10]+0.26f;
}
/* iteration formula for the quaternion mandelbulb */
GLfloat calc_quatmandel_function(Quaternion *z3, Quaternion *z1,
	Quaternion *z2, int iter_count, char xyz, GLfloat iter_accur)
{
	int k;
	/* reset our numbers because we are using pointers to save
	 * memory and processing power */
	z1->set(0,0,0,0); z2->set(0,0,0,0);

	/* iterate as long as we are inside the mandelbrot set */
	for(k = 0; k < iter_accur; k++)
	{
		/* this is the standard mandelbrot formula */
		// TODO: higher powers and parameters
		(*z1) = (*z2)*(*z2) + (*z3);
		if((*z1) == (*z2)) return(0);
		(*z2) = (*z1);
		if(fabs(z1->get_a())  > 2) return((GLfloat)k*0.25f);
	}
	return(0);
}

/* iteration formula for the quaternion mandelbulb */
GLfloat calc_quatmandel_function2(Quaternion *z1, Quaternion *z2,
	Quaternion *z3, Quaternion *z4, Quaternion *z5, Quaternion *z6, int iter_count, char xyz, GLfloat iter_accur)
{
	int k;
	/* reset our numbers because we are using pointers to save
	 * memory and processing power */
	z3->set(0,0,0,0); z4->set(0,0,0,0);
	z5->set(0,0,0,0); 
	z6->set(0,0,0,0); 

	(*z2) = (*z1);
	/* iterate as long as we are inside the mandelbrot set */
	for(k = 0; k < iter_accur; k++)
	{
		/* this is the standard mandelbrot formula */
		// TODO: higher powers and parameters
		(*z3) = ((*z2)*(*z2)*(*z2));
		z3->a = z3->a - 1;
		(*z4) = ((*z2)*(*z2))*3.0f;
		(*z5) = (*z3)/(*z4);

		(*z1) = (*z2) + (*z5);
		if(fabs(fabs(z2->get_a()) - fabs(z1->get_a())) < 0.000001f
		&& fabs(fabs(z2->get_b()) - fabs(z1->get_b())) < 0.000001f
		&& fabs(fabs(z2->get_c()) - fabs(z1->get_c())) < 0.000001f
		&& fabs(fabs(z2->get_d()) - fabs(z1->get_d())) < 0.000001f
		) return((GLfloat)k*0.25f);
	//	printf("%f\n", fabs(fabs(z2->get_a()) - fabs(z1->get_a())));
		(*z2) = (*z1);
	}
	return(0);
}


/* calculates the fractal area given by the thread parameters inside
 * the thread it was called in */
int calc_fractal(GLfloat *sp, Quaternion *qq)
{
	/* probably more save to not share the VBO array pointer first */
	int ct = 0;  const int macc = 3*sp[14]; const int facc = sp[14];
	GLfloat iter_accur = sp[2]; int confb; int draw = 1;
	GLfloat scale = sp[3]; int cseed = 1; float zzoom = sp[15];
	const int num = (int)(sp[4]);
	float l[8]; const int type = (int)sp[5];

	Quaternion quat1, quat2, quat3, quat4, quat5, quat6, resq;

	float spo[20]; int ret3 = 0;
	float rescol = 0;
	float outer = 0;
	int counttt = 0;
	
	int ret89 = 0;
	int ret1011 = 0;
	int ret1213 = 0;
	for(ct = 0; ct < 17; ct++)
		spo[ct] = sp[ct];

	if(sp[17]) { sp[9] = sp[8]; sp[11] = sp[10];}
	/* change the scan area according to the fractal shape */
	switch(type)
	{
	case F_QUATMANDEL:
		cseed = 5;
/*		sp[6]  -= sp[12]*0.25f; sp[7]  -= sp[12]*0.25f;
		sp[8]  *= 0.8f;     sp[9]  *= 0.8f;
		sp[10] *= 0.8f;     sp[11] *= 0.8f;*/
	break;
	default:
	break;
	}
	/* giant loop, x axis */
	for(l[0] = sp[6]; l[0] <= sp[7]; l[0]++)
	{
//	if(!(l[0] == sp[6]) && !(fabs(l[0]) == (int)(sp[7]/2)) && !(fabs(l[0]) == (int)(sp[7]/4)) && !(l[0] == sp[7])) continue;
	
//	if(!(l[0] == 0)) continue;

	if(sp[17]) sp[11] = sp[10];
	ret1011 = 0;
	if(sp[17] && !ret89 && sp[9] >= spo[9]) ret89 = 1; 
	else if(sp[17] && !ret89) sp[9]+=1;
	else if(sp[17]) sp[9]-=1;
//	if(sp[17] && !(sp[8] > sp[9]-1)){ sp[9]-=1; }
	/* giant loop, y axis */
	for(l[1] = sp[8]; l[1] <= sp[9]; l[1]++)
	{
//              printf("loop %f: count %d\n", l[1], counttt);
	if(sp[17]) sp[13] = spo[12];
	ret1213 = 0;
	if(sp[17] && !ret1011 && sp[11] >= spo[11]) ret1011 = 1; 
	else if(sp[17] && !ret1011) sp[11]+=1;
	else if(sp[17]) sp[11]-=1;

//	if(sp[17] && !(sp[10] > sp[11]-1)){sp[11]-=1; }
	/* giant loop, z axis */
	for(l[2] = sp[10]; l[2] <= sp[11]; l[2]++)
	{
	if(sp[17] && !ret1213 && sp[13] >= spo[13]) ret1213 = 1; 
	else if(sp[17] && !ret1213) sp[13]+=1;
	else if(sp[17]) sp[13]-=1;
//	if(sp[17] && !(sp[12] > sp[13]-1)){ sp[13]-=1; }
	for(l[3] = sp[12]; l[3] <= sp[13]; l[3]++)
	{
//	if(l[3] > 0) break;
	if( 
/*	!((l[1] == sp[8] || l[1] == sp[9]) && (l[0] == sp[6] || l[0] == sp[7]) &&
	(l[2] == sp[10] || l[2] == sp[11]) && (l[3] == sp[12] || l[3] == sp[13]))*/

	!((l[1] == sp[8] || l[1] == sp[9]) && (l[0] == sp[6] || l[2] == sp[7]))
	&& !((l[1] == sp[8] || l[1] == sp[9]) && (l[2] == sp[10] || l[2] == sp[11]))
	&& !((l[1] == sp[8] || l[1] == sp[9]) && (l[3] == sp[12] || l[3] == sp[13]))
	&& !((l[2] == sp[10] || l[2] == sp[11]) && (l[0] == sp[6] || l[0] == sp[7]))
	&& !((l[2] == sp[10] || l[2] == sp[11]) && (l[1] == sp[8] || l[1] == sp[9]))
	&& !((l[2] == sp[10] || l[2] == sp[11]) && (l[3] == sp[12] || l[3] == sp[13]))
	&& !((l[3] == sp[12] || l[3] == sp[13]) && (l[0] == sp[6] || l[0] == sp[7]))
	&& !((l[3] == sp[12] || l[3] == sp[13]) && (l[1] == sp[8] || l[1] == sp[9]))
	&& !((l[3] == sp[12] || l[3] == sp[13]) && (l[2] == sp[10] || l[2] == sp[11]))
	&& !((l[0] == sp[6] || l[0] == sp[7]) && (l[1] == sp[8] || l[1] == sp[9]))
	&& !((l[0] == sp[6] || l[0] == sp[7]) && (l[2] == sp[10] || l[2] == sp[11]))
	&& !((l[0] == sp[6] || l[0] == sp[7]) && (l[3] == sp[12] || l[3] == sp[13]))

/*
	!((l[1] == sp[8] || l[1] == sp[9]) &&
	(l[2] == sp[10] || l[2] == sp[11]) && (l[3] == sp[12] || l[3] == sp[13]))
	&&
	!((l[0] == sp[6] || l[0] == sp[7]) &&
	(l[2] == sp[10] || l[2] == sp[11]) && (l[3] == sp[12] || l[3] == sp[13]))
	&&
	!((l[0] == sp[6] || l[0] == sp[7]) && (l[1] == sp[8] || l[1] == sp[9]) &&
	(l[3] == sp[12] || l[3] == sp[13]))
	&&
	!((l[0] == sp[6] || l[0] == sp[7]) && (l[1] == sp[8] || l[1] == sp[9]) &&
	(l[2] == sp[10] || l[2] == sp[11]))


	&& sp[16]
/*	&& !(l[3] == sp[12]) // full point cube
	&& !(l[3] == sp[13])
	&& !(l[2] == sp[10])
	&& !(l[2] == sp[11])*/
	) continue;

	if(sp[16])
		rescol = 1;
	else
	{
		quat1.set((float)((l[0])*3)/((facc*2)*zoom2), 
			(float)((l[1])*3)/((facc*2)*zoom2),
			(float)((l[2])*3)/((facc*2)*zoom2), (float)((l[3])*3)/((facc*2)*zoom2));
		rescol = calc_quatmandel_function(&quat1,
			&quat2, &quat3, 1, 0, iter_accur);
//		rescol = calc_quatmandel_function2(&quat1,
//			&quat2, &quat3, &quat4, &quat5, &quat6, 1, 0, iter_accur);
		if(!outer) outer = rescol;
	}
	if( rescol > 0.25 && (fabs(rescol-outer) > 64*0.25  || sp[16])) //!(rescol > 64*0.25f && rescol < 75*0.25f))
	{
		/* set x,y coordinates */
		resq.a   = l[0]/(facc*scale);
		resq.b   = l[1]/(facc*scale);
		resq.c 	 = l[2]/(facc*scale);
		resq.d 	 = l[3]/(facc*scale);

//		printf("found: %f, %f, %f, %f\n", resq.a, resq.b, resq.c, resq.d);
		/* set color */
	if(sp[16])
	{
/*		if(l[2] == sp[10])
			{ resq.cr = 1; resq.cg = 0; resq.cb = 0; }
		else if(l[2] == sp[11])
			{ resq.cr = 0; resq.cg = 1; resq.cb = 0; }
		else if(l[3] == sp[12])
			{ resq.cr = 0; resq.cg = 0; resq.cb = 1; }
		else if(l[3] == sp[13])
			{ resq.cr = 1; resq.cg = 1; resq.cb = 0; }
		else
			{ resq.cr = 0; resq.cg = 0; resq.cb = 0; }*/
//		resq.cr = ((l[2]/(2*facc))+0.5)*0.8 + 0.2;
//		resq.cg = ((l[3]/(2*facc))+0.5)*0.8 + 0.2;
		resq.cb = 0;
		resq.cr = 0;
		resq.cg = 0;
	if(!(!((l[1] == sp[8] || l[1] == sp[9]) &&
	(l[2] == sp[10] || l[2] == sp[11]) && (l[3] == sp[12] || l[3] == sp[13]))
	&&
	!((l[0] == sp[6] || l[0] == sp[7]) &&
	(l[2] == sp[10] || l[2] == sp[11]) && (l[3] == sp[12] || l[3] == sp[13]))
	&&
	!((l[0] == sp[6] || l[0] == sp[7]) && (l[1] == sp[8] || l[1] == sp[9]) &&
	(l[3] == sp[12] || l[3] == sp[13]))
	&&
	!((l[0] == sp[6] || l[0] == sp[7]) && (l[1] == sp[8] || l[1] == sp[9]) &&
	(l[2] == sp[10] || l[2] == sp[11]))))
		resq.cg = 0.2;


	if((l[1] == sp[8] || l[1] == sp[9]) && (l[0] == sp[6] || l[0] == sp[7]) &&
	(l[2] == sp[10] || l[2] == sp[11]) && (l[3] == sp[12] || l[3] == sp[13]))
	{
		resq.cg = 1;
	}

	}
	else
	{
		resq.cr   = (float)((int)
			(rescol*1200*cseed)%2158)/2158;
		resq.cg = (float)((int)
			(rescol*1200*cseed)%2258)/2258;
		resq.cb = (float)((int)
			(rescol*1200*cseed)%2358)/2358;
	}
//		resq.cb = 0.5f;
		/* set z coordinates */
		qq[counttt] = resq;
		counttt++;
	}
	}
	}
	}

	}
	/* set the array address for the actual array */
	printf("point count: %d\n", counttt);
	return(counttt);
}


