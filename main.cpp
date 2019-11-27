#include <iostream>
#include "miniwin.h"
#include<math.h>
#include <windows.h>
#include <conio.h>
#include <sstream>

using namespace miniwin;
using namespace std;

//funciones modificadoras de variables globales



    
int ancho = GetSystemMetrics(SM_CXSCREEN), alto = GetSystemMetrics(SM_CYSCREEN);

float time = 1;
float int_time;
float ifer;

int asup_trap, ainf_trap, alt_trap;

char asup[10], ainf[10], alt[10];

int state_trap;

int model_vac_1, model_vac_2, model_vac_3;
char mv1[10],mv2[10],mv3[10];

int model_vac_1_d, model_vac_2_d, model_vac_3_d;
char mv1d[10],mv2d[10],mv3d[10];

int state_pal;
int model_pal[5];
int convert_pal;

int model_tra[5];

int model_vac[5];

float mover = 0, trax;

short an=ancho, al=6, xs=ancho/2, ys=alto/2;

int ri,gi,bi;

float sz = 25,a = ancho,b = alto;

double random = rand()% 2;

int limit = 1080;

int altu = 1,dela = 1;

float ESCENO;

int ESCENE = 0;

char let[30] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int ima = 0, p;

bool ex = false;

float riter  = 0.55, citer = 0.6;

void fondoC(){
		
		if(b > 0 || a > 0){
			a -= sz;
		}
		
		for(float i=0;i<=(ancho-a)+sz;i+=sz+sz-1){
			for(float j = 0; j<=(alto)+sz;j+=sz+sz-1){
				random = sin((time/10)-(i+j/10));
				color_rgb(255*random,255*random,255*random);
				circulo_lleno(i,j,(sz)*(random));
			}
		}
}	

void fondoR( float tx = ancho/2, float ty = alto/2){
		
		if(time < limit){
			int_time = time;	
		}else{
			int_time = limit+20*sin(time/10);
		}
		
		
	for(float c = -an/2; c<an/2; c+=citer){
		for(float r = -al/2; r<al/2; r+=riter){
			color_rgb(rand()%255,rand()%255,rand()%255);
			punto(xs+((an*c+tx)/an) + (c+r)/1.01,ys+((al*r+ty)/al) + (int_time)*sin(raton_x()/800-int_time/c+r)/1.99);
		}
	}
	
	if(time>=120){
		al = 6;
		an = ancho/2;
	}
	
	color_rgb(ri,gi,bi);
	rectangulo_lleno(ancho/2-(int_time/5),0,ancho/2+(int_time/5),alto);
}

void col_fondo(int r, int g, int b){
	ri = r, gi = g, bi = b;
}

void pil(){
	for(int x; x<200; x++){
		for(int y; y<200; y++){
			punto(x,y);
		}
	}
}

void sys(){
	//var
	
	ESCENE = (int)ESCENO;
	
	char n[10];
	char nu[10];
	char nd[10];
		
	itoa(time, n,10);
	itoa(mover, nu,10);
	itoa(ESCENE, nd,10);
	
	
	//definimos las funciones por defecto del sistema
	
		color(NEGRO);
		texto(10+dela,alto-25+raton_y()/130,"tiempo:");
		texto(70+dela,alto-25+raton_y()/120,n);
		texto(10+dela,alto-50+raton_y()/130,"MOver:");
		texto(70+dela,alto-50+raton_y()/120,nu);
		texto(10+dela,alto-75+raton_y()/130,"escena:");
		texto(70+dela,alto-75+raton_y()/120,nd);
		
		refresca();
		espera(10);
		color_rgb(ri,gi,bi);
		borra();
		switch(tecla()){
			case ESPACIO:
			ESCENO = 2;
			time = 1000;
			break;
			case ESCAPE:
			vcierra();
			break;
			case ARRIBA:
			mover+=1;
			break;
			case ABAJO:
			mover-=1;
			break;
		}
		
		if(time<limit || time == 0){
			time*=1.11;
		}else if(time > 750){
			time+=0.5;
		}
}

void num(int i, int x, int y ,int h){
	
	//variables locales
		
		int w = h/2;
		float r = (h/10+w/5)/4;
		
		
		float 	a1[2] = {x-(w/2), y-(h/2)},
				b1[2] = {x-(w/4), y-(h/2)},
				c1[2] = {x, y-(h/2)},
				d1[2] = {x+(w/4), y-(h/2)},
				e1[2] = {x+(w/2), y-(h/2)};
						
		float 	a2[2] = {a1[0], y-(h*3/8)},
				b2[2] = {b1[0], y-(h*3/8)},
				c2[2] = {c1[0], y-(h*3/8)},
				d2[2] = {d1[0], y-(h*3/8)},
				e2[2] = {e1[0], y-(h*3/8)};
				
		float 	a3[2] = {a1[0], y-(h/4)},
				b3[2] = {b1[0], y-(h/4)},
				c3[2] = {c1[0], y-(h/4)},
				d3[2] = {d1[0], y-(h/4)},
				e3[2] = {e1[0], y-(h/4)};
				
		float 	a4[2] = {a1[0], y-(h/8)},
				b4[2] = {b1[0], y-(h/8)},
				c4[2] = {c1[0], y-(h/8)},
				d4[2] = {d1[0], y-(h/8)},
				e4[2] = {e1[0], y-(h/8)};
				
		float 	a5[2] = {a1[0], y},
				b5[2] = {b1[0], y},
				c5[2] = {c1[0], y},
				d5[2] = {d1[0], y},
				e5[2] = {e1[0], y};
				
		float 	a6[2] = {a1[0], y+(h/8)},
				b6[2] = {b1[0], y+(h/8)},
				c6[2] = {c1[0], y+(h/8)},
				d6[2] = {d1[0], y+(h/8)},
				e6[2] = {e1[0], y+(h/8)};
		
		float 	a7[2] = {a1[0], y+(h/4)},
				b7[2] = {b1[0], y+(h/4)},
				c7[2] = {c1[0], y+(h/4)},
				d7[2] = {d1[0], y+(h/4)},
				e7[2] = {e1[0], y+(h/4)};
				
		float 	a8[2] = {a1[0], y+(h*3/8)},
				b8[2] = {b1[0], y+(h*3/8)},
				c8[2] = {c1[0], y+(h*3/8)},
				d8[2] = {d1[0], y+(h*3/8)},
				e8[2] = {e1[0], y+(h*3/8)};
				
		float 	a9[2] = {x-(w/2), y+(h/2)},
				b9[2] = {x-(w/4), y+(h/2)},
				c9[2] = {x, y+(h/2)},
				d9[2] = {x+(w/4), y+(h/2)},
				e9[2] = {x+(w/2), y+(h/2)};

		//fin variables locales (puntos de anclaje)
	
		switch((int)i){
			case 0:
				linea(b1[0],b1[1],d1[0],d1[1],r);
				linea(d1[0],d1[1],e2[0],e2[1],r);
				linea(e2[0],e2[1],e8[0],e8[1],r);
				linea(e8[0],e8[1],d9[0],d9[1],r);
				linea(d9[0],d9[1],b9[0],b9[1],r);
				linea(b9[0],b9[1],a8[0],a8[1],r);
				linea(a8[0],a8[1],a2[0],a2[1],r);
				linea(a2[0],a2[1],b1[0],b1[1],r);
				linea(b9[0],b9[1],d1[0],d1[1],r);
			break;
			case 1:
				linea(b2[0],b2[1],c1[0],c1[1],r);
				linea(c1[0],c1[1],d1[0],d1[1],r);
				linea(d1[0],d1[1],d9[0],d9[1],r);
			break;
			case 2:
				linea(a2[0],a2[1],a1[0],a1[1],r);
				linea(a1[0],a1[1],e1[0],e1[1],r);
				linea(e1[0],e1[1],e5[0],e5[1],r);
				linea(e5[0],e5[1],a5[0],a5[1],r);
				linea(a5[0],a5[1],a9[0],a9[1],r);
				linea(a9[0],a9[1],e9[0],e9[1],r);
				linea(e9[0],e9[1],e8[0],e8[1],r);
			break;
			case 3:
				linea(a1[0],a1[1],e1[0],e1[1],r);
				linea(e1[0],e1[1],e9[0],e9[1],r);
				linea(e9[0],e9[1],a9[0],a9[1],r);
				linea(e5[0],e5[1],b5[0],b5[1],r);
			break;
			case 4:
				linea(a1[0],a1[1],a5[0],a5[1],r);
				linea(a5[0],a5[1],e5[0],e5[1],r);
				linea(e1[0],e1[1],e9[0],e9[1],r);
			break;
			case 5:
				linea(a1[0],a1[1],e1[0],e1[1],r);
				linea(a1[0],a1[1],a5[0],a5[1],r);
				linea(a5[0],a5[1],e5[0],e5[1],r);
				linea(e5[0],e5[1],e9[0],e9[1],r);
				linea(b9[0],b9[1],e9[0],e9[1],r);
				linea(b9[0],b9[1],a8[0],a8[1],r);
				linea(a8[0],a8[1],a7[0],a7[1],r);
			break;
			case 6:
				linea(e2[0],e2[1],e1[0],e1[1],r);
				linea(e1[0],e1[1],a1[0],a1[1],r);
				linea(a1[0],a1[1],a9[0],a9[1],r);
				linea(a5[0],a5[1],e5[0],e5[1],r);
				linea(e9[0],e9[1],a9[0],a9[1],r);
				linea(e5[0],e5[1],e9[0],e9[1],r);
			break;
			case 7:
				linea(a1[0],a1[1],e1[0],e1[1],r);
				linea(e1[0],e1[1],c5[0],c5[1],r);
				linea(c5[0],c5[1],c9[0],c9[1],r);
			break;
			case 8:
				linea(b1[0],b1[1],d1[0],d1[1],r);
				linea(d1[0],d1[1],e2[0],e2[1],r);
				linea(e2[0],e2[1],e4[0],e4[1],r);
				linea(e4[0],e4[1],d5[0],d5[1],r);
				linea(d5[0],d5[1],b5[0],b5[1],r);
				linea(b5[0],b5[1],a4[0],a4[1],r);
				linea(a4[0],a4[1],a2[0],a2[1],r);
				linea(a2[0],a2[1],b1[0],b1[1],r);
				linea(d5[0],d5[1],e6[0],e6[1],r);
				linea(e8[0],e8[1],e6[0],e6[1],r);
				linea(d9[0],d9[1],e8[0],e8[1],r);
				linea(d9[0],d9[1],b9[0],b9[1],r);
				linea(b9[0],b9[1],a8[0],a8[1],r);
				linea(a8[0],a8[1],a6[0],a6[1],r);
				linea(a6[0],a6[1],b5[0],b5[1],r);
			break;
			case 9:
				linea(a1[0],a1[1],a5[0],a5[1],r);
				linea(a1[0],a1[1],e1[0],e1[1],r);
				linea(e1[0],e1[1],e8[0],e8[1],r);
				linea(e5[0],e5[1],a5[0],a5[1],r);
				linea(e8[0],e8[1],d9[0],d9[1],r);
				linea(d9[0],d9[1],a9[0],a9[1],r);
				linea(a9[0],a9[1],a8[0],a8[1],r);
			break;
		}
}

void letras(char i,int x, int y,int h){
		//variables locales
	
		int w = h/2;
		float r = (h/10+w/5)/3;
		
		float 	a1[2] = {x-(w/2), y-(h/2)},
				b1[2] = {x-(w/4), y-(h/2)},
				c1[2] = {x, y-(h/2)},
				d1[2] = {x+(w/4), y-(h/2)},
				e1[2] = {x+(w/2), y-(h/2)};
						
		float 	a2[2] = {a1[0], y-(h*3/8)},
				b2[2] = {b1[0], y-(h*3/8)},
				c2[2] = {c1[0], y-(h*3/8)},
				d2[2] = {d1[0], y-(h*3/8)},
				e2[2] = {e1[0], y-(h*3/8)};
				
		float 	a3[2] = {a1[0], y-(h/4)},
				b3[2] = {b1[0], y-(h/4)},
				c3[2] = {c1[0], y-(h/4)},
				d3[2] = {d1[0], y-(h/4)},
				e3[2] = {e1[0], y-(h/4)};
				
		float 	a4[2] = {a1[0], y-(h/8)},
				b4[2] = {b1[0], y-(h/8)},
				c4[2] = {c1[0], y-(h/8)},
				d4[2] = {d1[0], y-(h/8)},
				e4[2] = {e1[0], y-(h/8)};
				
		float 	a5[2] = {a1[0], y},
				b5[2] = {b1[0], y},
				c5[2] = {c1[0], y},
				d5[2] = {d1[0], y},
				e5[2] = {e1[0], y};
				
		float 	a6[2] = {a1[0], y+(h/8)},
				b6[2] = {b1[0], y+(h/8)},
				c6[2] = {c1[0], y+(h/8)},
				d6[2] = {d1[0], y+(h/8)},
				e6[2] = {e1[0], y+(h/8)};
		
		float 	a7[2] = {a1[0], y+(h/4)},
				b7[2] = {b1[0], y+(h/4)},
				c7[2] = {c1[0], y+(h/4)},
				d7[2] = {d1[0], y+(h/4)},
				e7[2] = {e1[0], y+(h/4)};
				
		float 	a8[2] = {a1[0], y+(h*3/8)},
				b8[2] = {b1[0], y+(h*3/8)},
				c8[2] = {c1[0], y+(h*3/8)},
				d8[2] = {d1[0], y+(h*3/8)},
				e8[2] = {e1[0], y+(h*3/8)};
				
		float 	a9[2] = {x-(w/2), y+(h/2)},
				b9[2] = {x-(w/4), y+(h/2)},
				c9[2] = {x, y+(h/2)},
				d9[2] = {x+(w/4), y+(h/2)},
				e9[2] = {x+(w/2), y+(h/2)};

		//fin variables locales (puntos de anclaje)
		
		switch(i){
			case 'a':
				linea(a2[0],a2[1],a9[0],a9[1],r);
				linea(a2[0],a2[1],b1[0],b1[1],r);
				linea(b1[0],b1[1],d1[0],d1[1],r);
				linea(e2[0],e2[1],d1[0],d1[1],r);
				linea(e2[0],e2[1],e9[0],e9[1],r);
				linea(a5[0],a5[1],e5[0],e5[1],r);
			break;
			case 'b':
				linea(a1[0],a1[1],a9[0],a9[1],r);
				linea(a1[0],a1[1],d1[0],d1[1],r);
				linea(e2[0],e2[1],d1[0],d1[1],r);
				linea(e2[0],e2[1],e8[0],e8[1],r);
				linea(e8[0],e8[1],d9[0],d9[1],r);
				linea(a9[0],a9[1],d9[0],d9[1],r);
				linea(e5[0],e5[1],b5[0],b5[1],r);
			break;
			case 'c':
				linea(e6[0],e6[1],e8[0],e8[1],r);
				linea(e8[0],e8[1],d9[0],d9[1],r);
				linea(d9[0],d9[1],b9[0],b9[1],r);
				linea(b9[0],b9[1],a8[0],a8[1],r);
				linea(a8[0],a8[1],a2[0],a2[1],r);
				linea(a2[0],a2[1],b1[0],b1[1],r);
				linea(b1[0],b1[1],d1[0],d1[1],r);
				linea(d1[0],d1[1],e2[0],e2[1],r);
				linea(e2[0],e2[1],e4[0],e4[1],r);
			break;
			case 'd':
				linea(a1[0],a1[1],a9[0],a9[1],r);
				linea(a1[0],a1[1],d1[0],d1[1],r);
				linea(d1[0],d1[1],e4[0],e4[1],r);
				linea(e6[0],e6[1],e4[0],e4[1],r);
				linea(e6[0],e6[1],d9[0],d9[1],r);
				linea(d9[0],d9[1],a9[0],a9[1],r);
			break;
			case 'e':
				linea(e2[0],e2[1],e1[0],e1[1],r);
				linea(e1[0],e1[1],a1[0],a1[1],r);
				linea(a1[0],a1[1],a9[0],a9[1],r);
				linea(a9[0],a9[1],e9[0],e9[1],r);
				linea(e8[0],e8[1],e9[0],e9[1],r);
				linea(a5[0],a5[1],d5[0],d5[1],r);
			break;
			case 'f':
				linea(e1[0],e1[1],a1[0],a1[1],r);
				linea(a1[0],a1[1],a9[0],a9[1],r);
				linea(a5[0],a5[1],c5[0],c5[1],r);
			break;
			case 'g':
				linea(e3[0],e3[1],e1[0],e1[1],r);
				linea(e1[0],e1[1],a1[0],a1[1],r);
				linea(a1[0],a1[1],a9[0],a9[1],r);
				linea(a9[0],a9[1],e9[0],e9[1],r);
				linea(e9[0],e9[1],e5[0],e5[1],r);
				linea(e5[0],e5[1],c5[0],c5[1],r);
				linea(c5[0],c5[1],c6[0],c6[1],r);
			break;
			case 'h':
				linea(a1[0],a1[1],a9[0],a9[1],r);
				linea(a5[0],a5[1],e5[0],e5[1],r);
				linea(e1[0],e1[1],e9[0],e9[1],r);
			break;
			case 'i':
				linea(c1[0],c1[1],c9[0],c9[1],r);
				linea(a1[0],a1[1],e1[0],e1[1],r);
				linea(a9[0],a9[1],e9[0],e9[1],r);
			break;
			case 'j':
				linea(a1[0],a1[1],e1[0],e1[1],r);
				linea(d1[0],d1[1],d9[0],d9[1],r);
				linea(d9[0],d9[1],a9[0],a9[1],r);
				linea(a9[0],a9[1],a7[0],a7[1],r);
			break;
			case 'k':
				linea(a1[0],a1[1],a9[0],a9[1],r);
				linea(b5[0],b5[1],e1[0],e1[1],r);
				linea(b5[0],b5[1],e9[0],e9[1],r);
			break;
			case 'l':
				linea(b1[0],b1[1],b9[0],b9[1],r);
				linea(b9[0],b9[1],d9[0],d9[1],r);
			break;
			case 'm':
				linea(a1[0],a1[1],a9[0],a9[1],r);
				linea(a1[0],a1[1],c3[0],c3[1],r);
				linea(c3[0],c3[1],e1[0],e1[1],r);
				linea(e1[0],e1[1],e9[0],e9[1],r);
			break;
			case 'n':
				linea(a9[0],a9[1],a1[0],a1[1],r);
				linea(a1[0],a1[1],e9[0],e9[1],r);
				linea(e1[0],e1[1],e9[0],e9[1],r);
			break;
			case 'o':
				linea(b1[0],b1[1],d1[0],d1[1],r);
				linea(d1[0],d1[1],e2[0],e2[1],r);
				linea(e2[0],e2[1],e8[0],e8[1],r);				
				linea(e8[0],e8[1],d9[0],d9[1],r);
				linea(d9[0],d9[1],b9[0],b9[1],r);
				linea(b9[0],b9[1],a8[0],a8[1],r);
				linea(a8[0],a8[1],a2[0],a2[1],r);
				linea(a2[0],a2[1],b1[0],b1[1],r);
			break;
			case 'p':
				linea(a1[0],a1[1],a9[0],a9[1],r);
				linea(a1[0],a1[1],c1[0],c1[1],r);
				linea(c1[0],c1[1],e2[0],e2[1],r);
				linea(e2[0],e2[1],e4[0],e4[1],r);
				linea(e4[0],e4[1],d5[0],d5[1],r);
				linea(d5[0],d5[1],a5[0],a5[1],r);
			break;
			case 'q':
				linea(b1[0],b1[1],d1[0],d1[1],r);
				linea(d1[0],d1[1],e2[0],e2[1],r);
				linea(e2[0],e2[1],e8[0],e8[1],r);
				linea(e8[0],e8[1],d9[0],d9[1],r);
				linea(d9[0],d9[1],b9[0],b9[1],r);
				linea(b9[0],b9[1],a8[0],a8[1],r);
				linea(a8[0],a8[1],a2[0],a2[1],r);
				linea(a2[0],a2[1],b1[0],b1[1],r);
				linea(c5[0],c5[1],e9[0],e9[1],r);
			break;
			case 'r':
				linea(a1[0],a1[1],c1[0],c1[1],r);
				linea(c1[0],c1[1],e2[0],e2[1],r);
				linea(e2[0],e2[1],e4[0],e4[1],r);
				linea(d5[0],d5[1],e4[0],e4[1],r);
				linea(d5[0],d5[1],a5[0],a5[1],r);
				linea(a5[0],a5[1],e9[0],e9[1],r);
				linea(a1[0],a1[1],a9[0],a9[1],r);
			break;
			case 's':
				linea(e2[0],e2[1],d1[0],d1[1],r);
				linea(d1[0],d1[1],a1[0],a1[1],r);
				linea(a1[0],a1[1],a5[0],a5[1],r);
				linea(a5[0],a5[1],e5[0],e5[1],r);
				linea(e5[0],e5[1],e9[0],e9[1],r);
				linea(e9[0],e9[1],b9[0],b9[1],r);
				linea(b9[0],b9[1],a8[0],a8[1],r);
			break;
			case 't':
				linea(e1[0],e1[1],a1[0],a1[1],r);
				linea(c1[0],c1[1],c9[0],c9[1],r);
			break;
			case 'u':
				linea(a1[0],a1[1],a8[0],a8[1],r);
				linea(a8[0],a8[1],b9[0],b9[1],r);
				linea(b9[0],b9[1],d9[0],d9[1],r);
				linea(d9[0],d9[1],e8[0],e8[1],r);
				linea(e9[0],e9[1],e1[0],e1[1],r);
			break;
			case 'v':
				linea(a1[0],a1[1],c9[0],c9[1],r);
				linea(c9[0],c9[1],e1[0],e1[1],r);
			break;
			case 'w':
				linea(a1[0],a1[1],b9[0],b9[1],r);
				linea(b9[0],b9[1],c7[0],c7[1],r);
				linea(c7[0],c7[1],d9[0],d9[1],r);
				linea(d9[0],d9[1],e1[0],e1[1],r);
			break;
			case 'x':
				linea(a1[0],a1[1],e9[0],e9[1],r);
				linea(a9[0],a9[1],e1[0],e1[1],r);
			break;
			case 'y':
				linea(a1[0],a1[1],c5[0],c5[1],r);
				linea(c5[0],c5[1],e1[0],e1[1],r);
				linea(c5[0],c5[1],c9[0],c9[1],r);
			break;
			case 'z':
				linea(a1[0],a1[1],e1[0],e1[1],r);
				linea(e1[0],e1[1],a9[0],a9[1],r);
				linea(a9[0],a9[1],e9[0],e9[1],r);
			break;
			case '0':
				linea(b1[0],b1[1],d1[0],d1[1],r);
				linea(d1[0],d1[1],e2[0],e2[1],r);
				linea(e2[0],e2[1],e8[0],e8[1],r);
				linea(e8[0],e8[1],d9[0],d9[1],r);
				linea(d9[0],d9[1],b9[0],b9[1],r);
				linea(b9[0],b9[1],a8[0],a8[1],r);
				linea(a8[0],a8[1],a2[0],a2[1],r);
				linea(a2[0],a2[1],b1[0],b1[1],r);
				linea(b9[0],b9[1],d1[0],d1[1],r);
			break;
			case '1':
				linea(b2[0],b2[1],c1[0],c1[1],r);
				linea(c1[0],c1[1],d1[0],d1[1],r);
				linea(d1[0],d1[1],d9[0],d9[1],r);
			break;
			case '2':
				linea(a2[0],a2[1],a1[0],a1[1],r);
				linea(a1[0],a1[1],e1[0],e1[1],r);
				linea(e1[0],e1[1],e5[0],e5[1],r);
				linea(e5[0],e5[1],a5[0],a5[1],r);
				linea(a5[0],a5[1],a9[0],a9[1],r);
				linea(a9[0],a9[1],e9[0],e9[1],r);
				linea(e9[0],e9[1],e8[0],e8[1],r);
			break;
			case '3':
				linea(a1[0],a1[1],e1[0],e1[1],r);
				linea(e1[0],e1[1],e9[0],e9[1],r);
				linea(e9[0],e9[1],a9[0],a9[1],r);
				linea(e5[0],e5[1],b5[0],b5[1],r);
			break;
			case '4':
				linea(a1[0],a1[1],a5[0],a5[1],r);
				linea(a5[0],a5[1],e5[0],e5[1],r);
				linea(e1[0],e1[1],e9[0],e9[1],r);
			break;
			case '5':
				linea(a1[0],a1[1],e1[0],e1[1],r);
				linea(a1[0],a1[1],a5[0],a5[1],r);
				linea(a5[0],a5[1],e5[0],e5[1],r);
				linea(e5[0],e5[1],e9[0],e9[1],r);
				linea(b9[0],b9[1],e9[0],e9[1],r);
				linea(b9[0],b9[1],a8[0],a8[1],r);
				linea(a8[0],a8[1],a7[0],a7[1],r);
			break;
			case '6':
				linea(e2[0],e2[1],e1[0],e1[1],r);
				linea(e1[0],e1[1],a1[0],a1[1],r);
				linea(a1[0],a1[1],a9[0],a9[1],r);
				linea(a5[0],a5[1],e5[0],e5[1],r);
				linea(e9[0],e9[1],a9[0],a9[1],r);
				linea(e5[0],e5[1],e9[0],e9[1],r);
			break;
			case '7':
				linea(a1[0],a1[1],e1[0],e1[1],r);
				linea(e1[0],e1[1],c5[0],c5[1],r);
				linea(c5[0],c5[1],c9[0],c9[1],r);
			break;
			case '8':
				linea(b1[0],b1[1],d1[0],d1[1],r);
				linea(d1[0],d1[1],e2[0],e2[1],r);
				linea(e2[0],e2[1],e4[0],e4[1],r);
				linea(e4[0],e4[1],d5[0],d5[1],r);
				linea(d5[0],d5[1],b5[0],b5[1],r);
				linea(b5[0],b5[1],a4[0],a4[1],r);
				linea(a4[0],a4[1],a2[0],a2[1],r);
				linea(a2[0],a2[1],b1[0],b1[1],r);
				linea(d5[0],d5[1],e6[0],e6[1],r);
				linea(e8[0],e8[1],e6[0],e6[1],r);
				linea(d9[0],d9[1],e8[0],e8[1],r);
				linea(d9[0],d9[1],b9[0],b9[1],r);
				linea(b9[0],b9[1],a8[0],a8[1],r);
				linea(a8[0],a8[1],a6[0],a6[1],r);
				linea(a6[0],a6[1],b5[0],b5[1],r);
			break;
			case '9':
				linea(a1[0],a1[1],a5[0],a5[1],r);
				linea(a1[0],a1[1],e1[0],e1[1],r);
				linea(e1[0],e1[1],e8[0],e8[1],r);
				linea(e5[0],e5[1],a5[0],a5[1],r);
				linea(e8[0],e8[1],d9[0],d9[1],r);
				linea(d9[0],d9[1],a9[0],a9[1],r);
				linea(a9[0],a9[1],a8[0],a8[1],r);
			break;
			case ',':
				linea(d7[0],d7[1],d8[0],d8[1],r);
				linea(c8[0],c8[1],d8[0],d8[1],r);
			break;
			case '.':
				linea(c8[0],c8[1],d8[0],d8[1],r);
				linea(d9[0],d9[1],d8[0],d8[1],r);
				linea(d9[0],d9[1],c9[0],c9[1],r);
				linea(c9[0],c9[1],c8[0],c8[1],r);
			break;
		}
		
		
}
void letras_r(char i,int x, int y,int h, int r){
		//variables locales
	
		int w = h/2;
		
		float 	a1[2] = {x-(w/2), y-(h/2)},
				b1[2] = {x-(w/4), y-(h/2)},
				c1[2] = {x, y-(h/2)},
				d1[2] = {x+(w/4), y-(h/2)},
				e1[2] = {x+(w/2), y-(h/2)};
						
		float 	a2[2] = {a1[0], y-(h*3/8)},
				b2[2] = {b1[0], y-(h*3/8)},
				c2[2] = {c1[0], y-(h*3/8)},
				d2[2] = {d1[0], y-(h*3/8)},
				e2[2] = {e1[0], y-(h*3/8)};
				
		float 	a3[2] = {a1[0], y-(h/4)},
				b3[2] = {b1[0], y-(h/4)},
				c3[2] = {c1[0], y-(h/4)},
				d3[2] = {d1[0], y-(h/4)},
				e3[2] = {e1[0], y-(h/4)};
				
		float 	a4[2] = {a1[0], y-(h/8)},
				b4[2] = {b1[0], y-(h/8)},
				c4[2] = {c1[0], y-(h/8)},
				d4[2] = {d1[0], y-(h/8)},
				e4[2] = {e1[0], y-(h/8)};
				
		float 	a5[2] = {a1[0], y},
				b5[2] = {b1[0], y},
				c5[2] = {c1[0], y},
				d5[2] = {d1[0], y},
				e5[2] = {e1[0], y};
				
		float 	a6[2] = {a1[0], y+(h/8)},
				b6[2] = {b1[0], y+(h/8)},
				c6[2] = {c1[0], y+(h/8)},
				d6[2] = {d1[0], y+(h/8)},
				e6[2] = {e1[0], y+(h/8)};
		
		float 	a7[2] = {a1[0], y+(h/4)},
				b7[2] = {b1[0], y+(h/4)},
				c7[2] = {c1[0], y+(h/4)},
				d7[2] = {d1[0], y+(h/4)},
				e7[2] = {e1[0], y+(h/4)};
				
		float 	a8[2] = {a1[0], y+(h*3/8)},
				b8[2] = {b1[0], y+(h*3/8)},
				c8[2] = {c1[0], y+(h*3/8)},
				d8[2] = {d1[0], y+(h*3/8)},
				e8[2] = {e1[0], y+(h*3/8)};
				
		float 	a9[2] = {x-(w/2), y+(h/2)},
				b9[2] = {x-(w/4), y+(h/2)},
				c9[2] = {x, y+(h/2)},
				d9[2] = {x+(w/4), y+(h/2)},
				e9[2] = {x+(w/2), y+(h/2)};

		//fin variables locales (puntos de anclaje)
		
		switch(i){
			case 'a':
				linea(a2[0],a2[1],a9[0],a9[1],r);
				linea(a2[0],a2[1],b1[0],b1[1],r);
				linea(b1[0],b1[1],d1[0],d1[1],r);
				linea(e2[0],e2[1],d1[0],d1[1],r);
				linea(e2[0],e2[1],e9[0],e9[1],r);
				linea(a5[0],a5[1],e5[0],e5[1],r);
			break;
			case 'b':
				linea(a1[0],a1[1],a9[0],a9[1],r);
				linea(a1[0],a1[1],d1[0],d1[1],r);
				linea(e2[0],e2[1],d1[0],d1[1],r);
				linea(e2[0],e2[1],e8[0],e8[1],r);
				linea(e8[0],e8[1],d9[0],d9[1],r);
				linea(a9[0],a9[1],d9[0],d9[1],r);
				linea(e5[0],e5[1],b5[0],b5[1],r);
			break;
			case 'c':
				linea(e6[0],e6[1],e8[0],e8[1],r);
				linea(e8[0],e8[1],d9[0],d9[1],r);
				linea(d9[0],d9[1],b9[0],b9[1],r);
				linea(b9[0],b9[1],a8[0],a8[1],r);
				linea(a8[0],a8[1],a2[0],a2[1],r);
				linea(a2[0],a2[1],b1[0],b1[1],r);
				linea(b1[0],b1[1],d1[0],d1[1],r);
				linea(d1[0],d1[1],e2[0],e2[1],r);
				linea(e2[0],e2[1],e4[0],e4[1],r);
			break;
			case 'd':
				linea(a1[0],a1[1],a9[0],a9[1],r);
				linea(a1[0],a1[1],d1[0],d1[1],r);
				linea(d1[0],d1[1],e4[0],e4[1],r);
				linea(e6[0],e6[1],e4[0],e4[1],r);
				linea(e6[0],e6[1],d9[0],d9[1],r);
				linea(d9[0],d9[1],a9[0],a9[1],r);
			break;
			case 'e':
				linea(e2[0],e2[1],e1[0],e1[1],r);
				linea(e1[0],e1[1],a1[0],a1[1],r);
				linea(a1[0],a1[1],a9[0],a9[1],r);
				linea(a9[0],a9[1],e9[0],e9[1],r);
				linea(e8[0],e8[1],e9[0],e9[1],r);
				linea(a5[0],a5[1],d5[0],d5[1],r);
			break;
			case 'f':
				linea(e1[0],e1[1],a1[0],a1[1],r);
				linea(a1[0],a1[1],a9[0],a9[1],r);
				linea(a5[0],a5[1],c5[0],c5[1],r);
			break;
			case 'g':
				linea(e3[0],e3[1],e1[0],e1[1],r);
				linea(e1[0],e1[1],a1[0],a1[1],r);
				linea(a1[0],a1[1],a9[0],a9[1],r);
				linea(a9[0],a9[1],e9[0],e9[1],r);
				linea(e9[0],e9[1],e5[0],e5[1],r);
				linea(e5[0],e5[1],c5[0],c5[1],r);
				linea(c5[0],c5[1],c6[0],c6[1],r);
			break;
			case 'h':
				linea(a1[0],a1[1],a9[0],a9[1],r);
				linea(a5[0],a5[1],e5[0],e5[1],r);
				linea(e1[0],e1[1],e9[0],e9[1],r);
			break;
			case 'i':
				linea(c1[0],c1[1],c9[0],c9[1],r);
				linea(a1[0],a1[1],e1[0],e1[1],r);
				linea(a9[0],a9[1],e9[0],e9[1],r);
			break;
			case 'j':
				linea(a1[0],a1[1],e1[0],e1[1],r);
				linea(d1[0],d1[1],d9[0],d9[1],r);
				linea(d9[0],d9[1],a9[0],a9[1],r);
				linea(a9[0],a9[1],a7[0],a7[1],r);
			break;
			case 'k':
				linea(a1[0],a1[1],a9[0],a9[1],r);
				linea(b5[0],b5[1],e1[0],e1[1],r);
				linea(b5[0],b5[1],e9[0],e9[1],r);
			break;
			case 'l':
				linea(b1[0],b1[1],b9[0],b9[1],r);
				linea(b9[0],b9[1],d9[0],d9[1],r);
			break;
			case 'm':
				linea(a1[0],a1[1],a9[0],a9[1],r);
				linea(a1[0],a1[1],c3[0],c3[1],r);
				linea(c3[0],c3[1],e1[0],e1[1],r);
				linea(e1[0],e1[1],e9[0],e9[1],r);
			break;
			case 'n':
				linea(a9[0],a9[1],a1[0],a1[1],r);
				linea(a1[0],a1[1],e9[0],e9[1],r);
				linea(e1[0],e1[1],e9[0],e9[1],r);
			break;
			case 'o':
				linea(b1[0],b1[1],d1[0],d1[1],r);
				linea(d1[0],d1[1],e2[0],e2[1],r);
				linea(e2[0],e2[1],e8[0],e8[1],r);				
				linea(e8[0],e8[1],d9[0],d9[1],r);
				linea(d9[0],d9[1],b9[0],b9[1],r);
				linea(b9[0],b9[1],a8[0],a8[1],r);
				linea(a8[0],a8[1],a2[0],a2[1],r);
				linea(a2[0],a2[1],b1[0],b1[1],r);
			break;
			case 'p':
				linea(a1[0],a1[1],a9[0],a9[1],r);
				linea(a1[0],a1[1],c1[0],c1[1],r);
				linea(c1[0],c1[1],e2[0],e2[1],r);
				linea(e2[0],e2[1],e4[0],e4[1],r);
				linea(e4[0],e4[1],d5[0],d5[1],r);
				linea(d5[0],d5[1],a5[0],a5[1],r);
			break;
			case 'q':
				linea(b1[0],b1[1],d1[0],d1[1],r);
				linea(d1[0],d1[1],e2[0],e2[1],r);
				linea(e2[0],e2[1],e8[0],e8[1],r);
				linea(e8[0],e8[1],d9[0],d9[1],r);
				linea(d9[0],d9[1],b9[0],b9[1],r);
				linea(b9[0],b9[1],a8[0],a8[1],r);
				linea(a8[0],a8[1],a2[0],a2[1],r);
				linea(a2[0],a2[1],b1[0],b1[1],r);
				linea(c5[0],c5[1],e9[0],e9[1],r);
			break;
			case 'r':
				linea(a1[0],a1[1],c1[0],c1[1],r);
				linea(c1[0],c1[1],e2[0],e2[1],r);
				linea(e2[0],e2[1],e4[0],e4[1],r);
				linea(d5[0],d5[1],e4[0],e4[1],r);
				linea(d5[0],d5[1],a5[0],a5[1],r);
				linea(a5[0],a5[1],e9[0],e9[1],r);
				linea(a1[0],a1[1],a9[0],a9[1],r);
			break;
			case 's':
				linea(e2[0],e2[1],d1[0],d1[1],r);
				linea(d1[0],d1[1],a1[0],a1[1],r);
				linea(a1[0],a1[1],a5[0],a5[1],r);
				linea(a5[0],a5[1],e5[0],e5[1],r);
				linea(e5[0],e5[1],e9[0],e9[1],r);
				linea(e9[0],e9[1],b9[0],b9[1],r);
				linea(b9[0],b9[1],a8[0],a8[1],r);
			break;
			case 't':
				linea(e1[0],e1[1],a1[0],a1[1],r);
				linea(c1[0],c1[1],c9[0],c9[1],r);
			break;
			case 'u':
				linea(a1[0],a1[1],a8[0],a8[1],r);
				linea(a8[0],a8[1],b9[0],b9[1],r);
				linea(b9[0],b9[1],d9[0],d9[1],r);
				linea(d9[0],d9[1],e8[0],e8[1],r);
				linea(e9[0],e9[1],e1[0],e1[1],r);
			break;
			case 'v':
				linea(a1[0],a1[1],c9[0],c9[1],r);
				linea(c9[0],c9[1],e1[0],e1[1],r);
			break;
			case 'w':
				linea(a1[0],a1[1],b9[0],b9[1],r);
				linea(b9[0],b9[1],c7[0],c7[1],r);
				linea(c7[0],c7[1],d9[0],d9[1],r);
				linea(d9[0],d9[1],e1[0],e1[1],r);
			break;
			case 'x':
				linea(a1[0],a1[1],e9[0],e9[1],r);
				linea(a9[0],a9[1],e1[0],e1[1],r);
			break;
			case 'y':
				linea(a1[0],a1[1],c5[0],c5[1],r);
				linea(c5[0],c5[1],e1[0],e1[1],r);
				linea(c5[0],c5[1],c9[0],c9[1],r);
			break;
			case 'z':
				linea(a1[0],a1[1],e1[0],e1[1],r);
				linea(e1[0],e1[1],a9[0],a9[1],r);
				linea(a9[0],a9[1],e9[0],e9[1],r);
			break;
			case '0':
				linea(b1[0],b1[1],d1[0],d1[1],r);
				linea(d1[0],d1[1],e2[0],e2[1],r);
				linea(e2[0],e2[1],e8[0],e8[1],r);
				linea(e8[0],e8[1],d9[0],d9[1],r);
				linea(d9[0],d9[1],b9[0],b9[1],r);
				linea(b9[0],b9[1],a8[0],a8[1],r);
				linea(a8[0],a8[1],a2[0],a2[1],r);
				linea(a2[0],a2[1],b1[0],b1[1],r);
				linea(b9[0],b9[1],d1[0],d1[1],r);
			break;
			case '1':
				linea(b2[0],b2[1],c1[0],c1[1],r);
				linea(c1[0],c1[1],d1[0],d1[1],r);
				linea(d1[0],d1[1],d9[0],d9[1],r);
			break;
			case '2':
				linea(a2[0],a2[1],a1[0],a1[1],r);
				linea(a1[0],a1[1],e1[0],e1[1],r);
				linea(e1[0],e1[1],e5[0],e5[1],r);
				linea(e5[0],e5[1],a5[0],a5[1],r);
				linea(a5[0],a5[1],a9[0],a9[1],r);
				linea(a9[0],a9[1],e9[0],e9[1],r);
				linea(e9[0],e9[1],e8[0],e8[1],r);
			break;
			case '3':
				linea(a1[0],a1[1],e1[0],e1[1],r);
				linea(e1[0],e1[1],e9[0],e9[1],r);
				linea(e9[0],e9[1],a9[0],a9[1],r);
				linea(e5[0],e5[1],b5[0],b5[1],r);
			break;
			case '4':
				linea(a1[0],a1[1],a5[0],a5[1],r);
				linea(a5[0],a5[1],e5[0],e5[1],r);
				linea(e1[0],e1[1],e9[0],e9[1],r);
			break;
			case '5':
				linea(a1[0],a1[1],e1[0],e1[1],r);
				linea(a1[0],a1[1],a5[0],a5[1],r);
				linea(a5[0],a5[1],e5[0],e5[1],r);
				linea(e5[0],e5[1],e9[0],e9[1],r);
				linea(b9[0],b9[1],e9[0],e9[1],r);
				linea(b9[0],b9[1],a8[0],a8[1],r);
				linea(a8[0],a8[1],a7[0],a7[1],r);
			break;
			case '6':
				linea(e2[0],e2[1],e1[0],e1[1],r);
				linea(e1[0],e1[1],a1[0],a1[1],r);
				linea(a1[0],a1[1],a9[0],a9[1],r);
				linea(a5[0],a5[1],e5[0],e5[1],r);
				linea(e9[0],e9[1],a9[0],a9[1],r);
				linea(e5[0],e5[1],e9[0],e9[1],r);
			break;
			case '7':
				linea(a1[0],a1[1],e1[0],e1[1],r);
				linea(e1[0],e1[1],c5[0],c5[1],r);
				linea(c5[0],c5[1],c9[0],c9[1],r);
			break;
			case '8':
				linea(b1[0],b1[1],d1[0],d1[1],r);
				linea(d1[0],d1[1],e2[0],e2[1],r);
				linea(e2[0],e2[1],e4[0],e4[1],r);
				linea(e4[0],e4[1],d5[0],d5[1],r);
				linea(d5[0],d5[1],b5[0],b5[1],r);
				linea(b5[0],b5[1],a4[0],a4[1],r);
				linea(a4[0],a4[1],a2[0],a2[1],r);
				linea(a2[0],a2[1],b1[0],b1[1],r);
				linea(d5[0],d5[1],e6[0],e6[1],r);
				linea(e8[0],e8[1],e6[0],e6[1],r);
				linea(d9[0],d9[1],e8[0],e8[1],r);
				linea(d9[0],d9[1],b9[0],b9[1],r);
				linea(b9[0],b9[1],a8[0],a8[1],r);
				linea(a8[0],a8[1],a6[0],a6[1],r);
				linea(a6[0],a6[1],b5[0],b5[1],r);
			break;
			case '9':
				linea(a1[0],a1[1],a5[0],a5[1],r);
				linea(a1[0],a1[1],e1[0],e1[1],r);
				linea(e1[0],e1[1],e8[0],e8[1],r);
				linea(e5[0],e5[1],a5[0],a5[1],r);
				linea(e8[0],e8[1],d9[0],d9[1],r);
				linea(d9[0],d9[1],a9[0],a9[1],r);
				linea(a9[0],a9[1],a8[0],a8[1],r);
			break;
			case ',':
				linea(d7[0],d7[1],d8[0],d8[1],r);
				linea(c8[0],c8[1],d8[0],d8[1],r);
			break;
			case '.':
				linea(c8[0],c8[1],d8[0],d8[1],r);
				linea(d9[0],d9[1],d8[0],d8[1],r);
				linea(d9[0],d9[1],c9[0],c9[1],r);
				linea(c9[0],c9[1],c8[0],c8[1],r);
			break;
		}
		
		
}

void escribir(const char *t, int x, int y, int w){
	int len = strlen(t);
	float m = 0;
	
	for(int i = 0; i < len; i++){
		m += 0.4;
		letras(t[i],x+((w/2)*(i-m)),y, w/2);
	}	
}
void escribir_r(const char *t, int x, int y, int w, int r){
	int len = strlen(t);
	float m = 0;
	
	for(int i = 0; i < len; i++){
		m += 0.4;
		letras_r(t[i],x+((w/2)*(i-m)),y, w/2,r);
	}	
}

void p_glosario(){
	color(BLANCO);
	letras(let[(int)mover],ancho/2,alto/2-100*2/3,200);
	
	if(mover > 25){
		mover = 0;
	}if(mover < 0){
		mover = 25;
	}
	num((int)mover,ancho/2,alto/2+200*2/3,200);
	
}


bool boton(int x1, int y1, int x2, int y2){
	if(raton_x() > x1 && raton_x() < x2 && raton_y() > y1 && raton_y() < y2){
		
		switch(raton_boton_izq()){
			case true:
				rectangulo_lleno(x1,y1,x2,y2);
				return false;
			break;
			case false:
				rectangulo_r(x1,y1,x2,y2,3);
				return true;
			break;
		}
	}
		rectangulo_r(x1,y1,x2,y2,2);
	
}

bool boton_i(int x1, int y1, int x2, int y2){
	if(raton_x() > x1 && raton_x() < x2 && raton_y() > y1 && raton_y() < y2){
		return raton_boton_izq();
	}
	
}

bool boton_t(int x1, int y1, int x2, int y2){
	if(raton_x() > x1 && raton_x() < x2 && raton_y() > y1 && raton_y() < y2){
		
		switch(raton_boton_izq()){
			case true:
				rectangulo_lleno(x1,y1,x2,y2);
				color_rgb(ri,gi,bi);
				linea(dela+(ancho-180),altu+alto-180,dela+(ancho-120),altu+alto-150,3);
				linea(dela+(ancho-120),altu+alto-150,dela+(ancho-180),altu+alto-120,3);
				linea(dela+(ancho-180),altu+alto-120,dela+(ancho-180),altu+alto-180,3);
				return false;
			break;
			case false:
				rectangulo_r(x1,y1,x2,y2,3);
				color_rgb(255,255,255);
				linea(dela+(ancho-180),altu+alto-180,dela+(ancho-120),altu+alto-150,3);
				linea(dela+(ancho-120),altu+alto-150,dela+(ancho-180),altu+alto-120,3);
				linea(dela+(ancho-180),altu+alto-120,dela+(ancho-180),altu+alto-180,3);
				return true;
			break;
			}
		}
		
		rectangulo_r(x1,y1,x2,y2,2);
	
}

void texte(int x, int y, const char *t, int limit){
	int len = strlen(t), j = 0;

	for(int i = 0; i < len-limit; i+=20){
		escribir(t, x+i,y, 20);
	}	 
}

void puntero(int x, int y, int t){
	if(raton_x() < x+t && raton_x() > x-t && raton_y() < y+t && raton_y() > y-t){
		rectangulo_lleno(x+t,y+t  + 5 * cos(time/10),x-t,y-t  + 5 * sin(time/10) );	
	}else{
		rectangulo_lleno(x+t,y+t,x-t,y-t);	
	}
}

bool boton_c(int x, int y, int r){
	if(raton_x() > x-r && raton_x() < x+r && raton_y() > y-r && raton_y() < y+r){
		switch(raton_boton_izq()){
			case true:
				return true;
			break;
			case false:
				return false;
			break;
			}
		
	}
}

void bot_menu(){

	escribir("semaforo",35+dela,altu+65,50);
	escribir("personas",35+dela,altu+125,50);
	escribir("palindromo",35+dela,altu+185,50);
	escribir("vacary",35+dela,altu+245,50);
	escribir("trapecio",35+dela,altu+305,50);
	escribir("opciones",35+dela,altu+395,50);
	escribir("salir",35+dela,altu+455,50);
	
	if(!boton(10+dela,altu+40,210+dela,altu+90)){
		ESCENO = 2;
	}if(!boton(10+dela,altu+100,210+dela,altu+150)){
		ESCENO = 3;
	}if(!boton(10+dela,altu+160,210+dela,altu+210)){
		ESCENO = 4;
	}if(!boton(10+dela,altu+220,210+dela,altu+270)){
		ESCENO = 5;
	}if(!boton(10+dela,altu+280,210+dela,altu+330)){
		ESCENO = 7;
	}if(!boton(10+dela,altu+370,210+dela,altu+420)){
		ESCENO = 6;
	}if(!boton(10+dela,altu+430,210+dela,altu+480)){
		vcierra();
		ex = true;
	}
}


void color_c(int all){
	color_rgb(all,all,all);
}

bool persona(int x, int y, int w, int color){
	
	int he = w/2;
	
	color_rgb(120,120,120); 							//cuerpo
	rectangulo_lleno(x-he,y-w,x+he,y+w);
	color_rgb(255, 209, 209);								//cara
	rectangulo_lleno(x-he,y-w,x+he,y+w/4);
	color_rgb(0,0,0);
	rectangulo_lleno(x+he/2,y-w/2,x+he,y-w/4);
	color_rgb(0,0,0);
	rectangulo_lleno(x-he-(he/10),y+w-(w/10),x+he,y+w);
	color_rgb(0,0,0);
	rectangulo_lleno(x-he+10,y+w/4-5,x+he,y+w/4-10);	//pies
	
	//gorro
	
	switch(color){
		case 0:
			color_rgb(100,0,0);
		break;
		case 1:
			color_rgb(0,100,0);
		break;
		case 3:
			color_rgb(100,100,0);
		break;
		case 4:
			color_rgb(100,0,100);
		break;
		case 5:
			color_rgb(0,100,100);
		break;
		case 6:
			color_rgb(100,100,100);
		break;
		case 7:
			color_rgb(0,0,100);
		break;
		case 8:
			color_rgb(0,120,100);
		break;
		case 9:
			color_rgb(250,100,100);
		break;
		case 10:
			color_rgb(0,200,100);
		break;
	}
	rectangulo_lleno(x-he-(he/5),y-w-2,x+he,y-w+8);
	rectangulo_lleno(x-he-(he/5),y-w-2,x-he+8,y+w*1/3+8);
	
	if(raton_x() > x-he && raton_x() < x+he && raton_y() > y-w && raton_y() < y+w){
		color_rgb(0,0,0);
		rectangulo_lleno(x-he+he/3,y+w*2/3+w/2,x+he-he/3,y+w*2/3+w/2+10);
		
		return raton_boton_izq();
	}
}

int arrtoi(int arrg[], int size){
	
	int arr[size];
	
	for(int i = 0; i< size; i++){
		arr[i] = arrg[i];
	}
	
	stringstream ss;
	    for (unsigned i = 0; i < sizeof arr / sizeof arr [0]; ++i)
	        ss << arr [i];
	
	    int result;
	    ss >> result;
	    cout << result;
	    
	    return result;
}

void controls(){
	for(int i=0; i<50;i++){
			if(!boton_i(60,alto/2-50,110,alto/2+50)){
				color_rgb(211,0,0);
			}else{
				color_rgb(111,0,100);
				if(ESCENE >8){
					espera(200);
					ESCENO -= 1;
				}
			}
			linea(i+60,alto/2+i*cos(i*(25+25*sin(time/10000-i))/2),i+60,alto/2-i*cos(i*(25+25*cos(time/10000-i))/2),5);
		}
		for(int i = 0; i>-50; i--){
			
			if(!boton_i(ancho-110,alto/2-50,ancho-60,alto/2+50)){
				color_rgb(211,0,0);
			}else{
				color_rgb(111,0,100);
				if(ESCENE <12){
					espera(200);
					ESCENO += 1;
				}
			}
			linea(i+ancho-60,alto/2-i*cos(-i*(25+25*sin(time/10000-i))/2),i+ancho-60,alto/2+i*cos(-i*(25+25*cos(time/10000-i))/2),5);
		}
}

int boton_lleno(int x1, int y1, int x2, int y2){
	if(raton_x() > x1 && raton_x() < x2 && raton_y() > y1 && raton_y() < y2){
		color_rgb(20,20,20);
		switch(raton_boton_izq()){
			case true:
				return 1;
				color_rgb(60,60,60);
			break;
			case false:
				return 0;
				color_rgb(0,0,0);
			break;
		}
	}
	rectangulo_lleno(x1,y1,x2,y2);
}



int main(){
	
	vredimensiona(ancho,alto); 	//configuramos el ancho y el alto de la pantalla
	
	while(ex != true){

	//ex = exit variable de salida del programa, evita errores

	while(ESCENE == 0){
	color(BLANCO);
	fondoR();
	//fondoC();
	
	color(BLANCO);
	
	if(time > 1090){
		ESCENO = 1;
	}
	col_fondo(0,0,0);
	sys();
	}
	
	while(ESCENE == 1){
	
	altu = 60 + raton_y()/130;
	dela = raton_x()/130;
	
	color(BLANCO);
	fondoR();
	//fondoC();
	
	color(BLANCO);
	escribir("ascci programs 1.12", 40+dela, 90-(-altu)-120, 90);
	linea(0,altu,ancho-100+dela,altu,2);
	linea(ancho-100+dela,altu,ancho+dela,0,2);
	
	bot_menu();
	
	linea(250+dela, 40+altu, (ancho-100)+dela,40+altu,3);
	escribir("bienvenido a mi programa", 300+dela, 80+altu, 100);
	linea(250+dela, 120+altu, (ancho-100)+dela,120+altu,3);
	
	col_fondo(0,0,0);
	sys();
	}
	
	
	
	//semaforo
	while(ESCENE == 2){
	
	altu = 60 + raton_y()/130;
	dela = raton_x()/130;
	
	color(BLANCO);
	fondoR();
	//fondoC();
	
	color(BLANCO);
	escribir("ascci programs 1.12", 40+dela, 90-(-altu)-120, 90);
	linea(0,altu,ancho-100+dela,altu,2);
	linea(ancho-100+dela,altu,ancho+dela,0,2);
	
	bot_menu();

	linea(250+dela, 40+altu, (ancho-100)+dela,40+altu,3);
	escribir("programa de semaforizacion", 300+dela, 80+altu, 100);
	linea(250+dela, 120+altu, (ancho-100)+dela,120+altu,3);
	
	color(BLANCO);
	rectangulo_r(dela+250,altu+140,dela+(ancho-100),altu+alto-100,2);
	escribir("este programa nos ayudara a conocer como funcionan los semaforos de nuestra ciudad",dela+270,altu+160,40);
	escribir("los cuales estan siendo desconocidos por la mayor parte de la poblacion joven del",dela+270,altu+185,40);
	escribir("pais, por eso nos hemos visto en la necesidad de crear este programa, para mostrar",dela+270,altu+210,40);
	escribir("el como funcionan estos y que hacer cuando estos cambian de color",dela+270,altu+235,40);
	escribir("gracias por utilizar mi programa, atentamente jua pablo bedoya benavides",dela+270,altu+alto-120,40);
	color(BLANCO);
	

	if(!boton_t(dela+(ancho-200),altu+alto-200,dela+(ancho-100),altu+alto-100)){
		ESCENO = 8;
	}
	
	
	col_fondo(0,0,0);
	sys();
	}
	
	
	
	//palindromos
	while(ESCENE == 3){
	
	altu = 60 + raton_y()/130;
	dela = raton_x()/130;
	
	color(BLANCO);
	fondoR();
	//fondoC();
	
	color(BLANCO);
	escribir("ascci programs 1.12", 40+dela, 90-(-altu)-120, 90);
	linea(0,altu,ancho-100+dela,altu,2);
	linea(ancho-100+dela,altu,ancho+dela,0,2);
	
	bot_menu();
	
	linea(250+dela, 40+altu, (ancho-100)+dela,40+altu,3);
	escribir("escalera de edades", 300+dela, 80+altu, 100);
	linea(250+dela, 120+altu, (ancho-100)+dela,120+altu,3);
	
	color(BLANCO);
	rectangulo_r(dela+250,altu+140,dela+(ancho-100),altu+alto-100,2);
	escribir("la bitacora numero dos se trata de el organizar un grupo de personas por su edad",dela+270,altu+160,40);
	escribir("contando con sus nombres tambien, para asi saber cual de ellos es el mayor, el",dela+270,altu+185,40);
	escribir("mediano de ellos y por ultimo el menor de ellos, poniendolos en el lugar que les",dela+270,altu+210,40);
	escribir("corresponde a cada uno de ellos.",dela+270,altu+235,40);
	escribir("gracias por utilizar mi programa, atentamente jua pablo bedoya benavides",dela+270,altu+alto-120,40);
	color(BLANCO);
	if(!boton_t(dela+(ancho-200),altu+alto-200,dela+(ancho-100),altu+alto-100)){
		ESCENO = 9;
	}
	
	col_fondo(0,0,0);
	sys();
	}
	
	//semaforo
	while(ESCENE == 4){
	
	altu = 60 + raton_y()/130;
	dela = raton_x()/130;
	
	color(BLANCO);
	fondoR();
	//fondoC();
	
	color(BLANCO);
	escribir("ascci programs 1.12", 40+dela, 90-(-altu)-120, 90);
	linea(0,altu,ancho-100+dela,altu,2);
	linea(ancho-100+dela,altu,ancho+dela,0,2);
	
	bot_menu();

	linea(250+dela, 40+altu, (ancho-100)+dela,40+altu,3);
	escribir("numeros palindromos", 300+dela, 80+altu, 100);
	linea(250+dela, 120+altu, (ancho-100)+dela,120+altu,3);
	
	color(BLANCO);
	rectangulo_r(dela+250,altu+140,dela+(ancho-100),altu+alto-100,2);
	escribir("los numeros palindromos son aquellos numeros que comparten una singularidad muy pero",dela+270,altu+160,40);
	escribir("muy particular, la cual es que cada vez que se quiera leer este numero sea al ",dela+270,altu+185,40);
	escribir("derecho o al revez este siempre conservara su singularidad la cual es que este ",dela+270,altu+210,40);
	escribir("numero no cambiara de valor sea como sea por ejemplo 12321 el cual se lee igual",dela+270,altu+235,40);
	escribir("gracias por utilizar mi programa, atentamente jua pablo bedoya benavides",dela+270,altu+alto-120,40);
	color(BLANCO);
	
	if(!boton_t(dela+(ancho-200),altu+alto-200,dela+(ancho-100),altu+alto-100)){
		ESCENO = 10;
	}
	
	col_fondo(0,0,0);
	sys();
	}
	
	
	//vacari centro comercial
	while(ESCENE == 5){
	
	altu = 60 + raton_y()/130;
	dela = raton_x()/130;
	
	color(BLANCO);
	fondoR();
	//fondoC();
	
	color(BLANCO);
	escribir("ascci programs 1.12", 40+dela, 90-(-altu)-120, 90);
	linea(0,altu,ancho-100+dela,altu,2);
	linea(ancho-100+dela,altu,ancho+dela,0,2);
	
	
	bot_menu();
	
	linea(250+dela, 40+altu, (ancho-100)+dela,40+altu,3);
	escribir("vacary el centro comercial", 300+dela, 80+altu, 100);
	linea(250+dela, 120+altu, (ancho-100)+dela,120+altu,3);
	
	color(BLANCO);
	rectangulo_r(dela+250,altu+140,dela+(ancho-100),altu+alto-100,2);
	escribir("vacary centro comercial es el centro comercial mas transitado pero ocurren hay en",dela+270,altu+160,40);
	escribir(" el que las facturas estan siendo erroneas y entonces el dueño contrato a un ",dela+270,altu+185,40);
	escribir("programador para solucionarlo y aplicar de verdad los descuentos que la tienda",dela+270,altu+210,40);
	escribir("ofrece por cada compra.",dela+270,altu+235,40);
	escribir("gracias por utilizar mi programa, atentamente jua pablo bedoya benavides",dela+270,altu+alto-120,40);
	color(BLANCO);
	boton_t(dela+(ancho-200),altu+alto-200,dela+(ancho-100),altu+alto-100);
	
	if(!boton_t(dela+(ancho-200),altu+alto-200,dela+(ancho-100),altu+alto-100)){
		ESCENO = 11;
	}
	
	col_fondo(0,0,0);
	sys();
	}
	
	int exis = ancho/2+10, exds = ancho/2+10, exus = ancho/2+10;
	
	while(ESCENE == 6){
		altu = 60 + raton_y()/130;
		dela = raton_x()/130;
		char m[10];
		
		itoa(riter*100,m,10);
	
		color(BLANCO);
		fondoR();
		
		color(BLANCO);
		rectangulo_r(ancho/2-230+dela,altu+alto-alto+30,dela+ancho/2+230,altu+alto-30,3*sin(time));
		
		escribir("configuracion",ancho/2-200+dela,altu+alto-alto+60,50);
		escribir("calidad de fondo",ancho/2-200+dela,altu+alto-alto+100,30);
		escribir(m,ancho/2+160+dela,altu+alto-alto+100,30);
		
		escribir("animaciones suaves",ancho/2-200+dela,altu+alto-alto+140,30);
		
		linea(ancho/2+10+dela,altu+alto-alto+100,ancho/2+120+dela,altu+alto-alto+100,3);
		
		
		
		linea(ancho/2+10+dela,altu+alto-alto+140,ancho/2+120+dela,altu+alto-alto+140,3);
		
		if(raton_x() > ancho/2+10+dela && raton_x() < ancho/2+120+dela && raton_y() > altu+alto-alto+90 && raton_y() < altu+alto-alto+110 ){
		
			if(raton_boton_izq()){
				exis = raton_x()-dela;
				riter = -(-raton_x()+ancho/2)/100;
			}
			
			linea(exis+dela,altu+alto-alto+90,exis+dela,altu+alto-alto+110,5);
		}else{
			linea(exis+dela,altu+alto-alto+90,exis+dela,altu+alto-alto+110,5);
		}
		
		if(raton_x() > ancho/2+10+dela && raton_x() < ancho/2+120+dela && raton_y() > altu+alto-alto+130 && raton_y() < altu+alto-alto+150 ){
		
			if(raton_boton_izq()){
				exus = raton_x()-dela;
				citer = -(-raton_x()+ancho/2)/100;
			}
			
			linea(exus+dela,altu+alto-alto+130,exus+dela,altu+alto-alto+150,5);
		}else{
			linea(exus+dela,altu+alto-alto+130,exus+dela,altu+alto-alto+150,5);
		}
		
		if(!boton(ancho/2-450+dela,altu+alto-alto+400,ancho/2-320+dela,altu+alto-alto+550)){
			ESCENO = 1;
		}
			
	
		escribir("salir",ancho/2-400+dela,altu+alto-alto+480,30);
		
		
		sys();
	}
	
	while(ESCENE == 7){ //trapecio
		altu = 60 + raton_y()/130;
		dela = raton_x()/130;
		
		color(BLANCO);
		fondoR();
		//fondoC();
		
		color(BLANCO);
		escribir("ascci programs 1.12", 40+dela, 90-(-altu)-120, 90);
		linea(0,altu,ancho-100+dela,altu,2);
		linea(ancho-100+dela,altu,ancho+dela,0,2);
		
		
		bot_menu();
		
		linea(250+dela, 40+altu, (ancho-100)+dela,40+altu,3);
		escribir("programa trapecio", 300+dela, 80+altu, 100);
		linea(250+dela, 120+altu, (ancho-100)+dela,120+altu,3);
		
		color(BLANCO);
		rectangulo_r(dela+250,altu+140,dela+(ancho-100),altu+alto-100,2);
		escribir("hay muchas veces en las que un programa es necesario para calcular una cantidad",dela+270,altu+160,40);
		escribir("en esta ocasion el programa que veras esta diseñado para calcular el area, ",dela+270,altu+185,40);
		escribir("perimetro y otros datos de un trapecio. ademas de tener una interfaz grafica",dela+270,altu+210,40);
		escribir("bonita y facil de utilizar.",dela+270,altu+235,40);
		escribir("gracias por utilizar mi programa, atentamente jua pablo bedoya benavides",dela+270,altu+alto-120,40);
		color(BLANCO);
		
		if(!boton_t(dela+(ancho-200),altu+alto-200,dela+(ancho-100),altu+alto-100)){
			ESCENO = 12;
		}
		
		
		
		col_fondo(0,0,0);
		sys();
	}

	
	/* 
	
	aqui empieza lo bueno papuh perro wohooooo
	
	10:48 pm mañana es el dia de presentar esta madre :'v
	
	*/
	
	int movx1, movy1;
	
	while(ESCENE == 8){
		altu = 60 + raton_y()/130;
		dela = raton_x()/130;
	
		color(BLANCO);
		fondoC();
		
		color(BLANCO);
		
		
		rectangulo_r(ancho/2-400,alto-alto+10,ancho/2+400,alto-10, 3 * sin(time));
		color(NEGRO);
		rectangulo_lleno(ancho/2-390,alto-alto+20,ancho/2+390,alto-20);
		
		movx1 = 0, movy1 = -100;
		
		color_rgb(200,200,200);
		rectangulo_r(ancho/2+50+movx1,120-movy1,ancho/2-50+movx1,320-movy1, 5);
		color_rgb(120,120,120);
		rectangulo_lleno(ancho/2+50+movx1,120-movy1,ancho/2-50+movx1,320-movy1);
		
		color(BLANCO);
		escribir("el semaforo",ancho/2-360,70,50);
		escribir("los semaforos, tambien conocidos tecnicamente como senales de control de trafico, son",ancho/2-370,100,30);
		escribir("dispositivos de senales que se situan en intersecciones viales y otros lugares para", ancho/2-370,120,30);
		escribir("regular el trafico, y por ende, el transito peatonal. el primer semaforo, disenado ", ancho/2-370,140,30);
		escribir("por john peake knight, se instalo en londres en 1868.", ancho/2-370,160,30);
		escribir("de click dentro de", ancho/2-350,300,40);
		escribir("los colores del semaforo", ancho/2-350,340,40);
		
		rectangulo_r(ancho/2+100+movx1,120-movy1,ancho/2+350+movx1,320-movy1, 5);
		
		if(boton_c(ancho/2+movx1,160-movy1,30)){
			mover = 1;
		}if(boton_c(ancho/2+movx1,220-movy1,30)){
			mover = 2;
		}if(boton_c(ancho/2+movx1,280-movy1,30)){
			mover = 3;
		}
		
		color_rgb(51, 184, 255);
		rectangulo_lleno(ancho/2-350,alto/2+150,ancho/2+350,alto/2+350);
		color_rgb(3, 19, 28);
		rectangulo_lleno(ancho/2-350,alto/2+220,ancho/2+350,alto/2+350);
		color_rgb(235, 212, 14 );
		
		linea_p(ancho/2-350,alto/2+285,ancho/2+350,alto/2+285,5);
		
		color(BLANCO);
		rectangulo_r(ancho/2-350,alto/2+150,ancho/2+350,alto/2+350,5);
		
		
		
		switch((int)mover){
			default:
				color_rgb(100,100,100);
				circulo_lleno(ancho/2+movx1,160-movy1,30);
				color_rgb(100,100,100);
				circulo_lleno(ancho/2+movx1,220-movy1,30);
				color_rgb(100,100,100);
				circulo_lleno(ancho/2+movx1,280-movy1,30);
			break;
			
			case 1:
				trax = 0;
				
				color_rgb(255,20,20);
				circulo_lleno(ancho/2+movx1,160-movy1,30);
				color_rgb(100,100,100);
				circulo_lleno(ancho/2+movx1,220-movy1,30);
				color_rgb(100,100,100);
				circulo_lleno(ancho/2+movx1,280-movy1,30);
				
				color_rgb(235, 212, 14);
				rectangulo_lleno(trax+(ancho/2-320),alto/2+240,trax+(ancho/2),alto/2+300);
				rectangulo_lleno(trax+(ancho/2-320),alto/2+210,trax+(ancho/2-60),alto/2+300);
				color_rgb(14, 218, 235);
				rectangulo_lleno(trax+(ancho/2-312),alto/2+218,trax+(ancho/2-68),alto/2+248);
				color_rgb(0,0,0);
				circulo_lleno(trax + ancho/2-285,alto/2+300,25);
				circulo_lleno(trax + ancho/2-80,alto/2+300,25);
				
				
				color_rgb(255,20,20);
				escribir("el color rojo nos indica",ancho/2+125+movx1,145-movy1,30);
				escribir("que no podemos pasar por",ancho/2+125+movx1,170-movy1,30);
				escribir("hay pues hay trafico hay",ancho/2+125+movx1,195-movy1,30);
				escribir("delante dependiendo de ",ancho/2+125+movx1,220-movy1,30);
				escribir("si eres peaton o un ",ancho/2+125+movx1,245-movy1,30);
				escribir("vehiculo.",ancho/2+125+movx1,270-movy1,30);
			break;
			case 2:
				trax = 120;
				
				color_rgb(100,100,100);
				circulo_lleno(ancho/2+movx1,160-movy1,30);
				color(AMARILLO);
				circulo_lleno(ancho/2+movx1,220-movy1,30);
				color_rgb(100,100,100);
				circulo_lleno(ancho/2+movx1,280-movy1,30);
				
				color_rgb(235, 212, 14);
				rectangulo_lleno(trax+(ancho/2-320),alto/2+240,trax+(ancho/2),alto/2+300);
				rectangulo_lleno(trax+(ancho/2-320),alto/2+210,trax+(ancho/2-60),alto/2+300);
				color_rgb(14, 218, 235);
				rectangulo_lleno(trax+(ancho/2-312),alto/2+218,trax+(ancho/2-68),alto/2+248);
				color_rgb(0,0,0);
				circulo_lleno(trax + ancho/2-285,alto/2+300,25);
				circulo_lleno(trax + ancho/2-80,alto/2+300,25);
				
				color(AMARILLO);
				escribir("el color amarillo nos da",ancho/2+125+movx1,145-movy1,30);
				escribir("a entender que esperemos",ancho/2+125+movx1,170-movy1,30);
				escribir("para pasar en el caso de",ancho/2+125+movx1,195-movy1,30);
				escribir("vehiculos pues en peaton",ancho/2+125+movx1,220-movy1,30);
				escribir("este color no existe.",ancho/2+125+movx1,245-movy1,30);
				escribir("",ancho/2+125+movx1,270-movy1,30);
			break;
			break;
			case 3:
				
				trax = 320;
				
				color_rgb(100,100,100);
				circulo_lleno(ancho/2+movx1,160-movy1,30);
				color_rgb(100,110,100);
				circulo_lleno(ancho/2+movx1,220-movy1,30);
				color_rgb(20,255,20);
				circulo_lleno(ancho/2+movx1,280-movy1,30);
				
				color_rgb(235, 212, 14);
				rectangulo_lleno(trax+(ancho/2-320),alto/2+240,trax+(ancho/2),alto/2+300);
				rectangulo_lleno(trax+(ancho/2-320),alto/2+210,trax+(ancho/2-60),alto/2+300);
				color_rgb(14, 218, 235);
				rectangulo_lleno(trax+(ancho/2-312),alto/2+218,trax+(ancho/2-68),alto/2+248);
				color_rgb(0,0,0);
				circulo_lleno(trax + ancho/2-285,alto/2+300,25);
				circulo_lleno(trax + ancho/2-80,alto/2+300,25);
				
				color_rgb(20,255,20);        
				escribir("el color verde nos dice",ancho/2+125+movx1,145-movy1,30);
				escribir("que debemos pasar pues ",ancho/2+125+movx1,170-movy1,30);
				escribir("no hay peligro de ser",ancho/2+125+movx1,195-movy1,30);
				escribir("atropellado o arrollado",ancho/2+125+movx1,220-movy1,30);
				escribir("por otro vehiculo y en ",ancho/2+125+movx1,245-movy1,30);
				escribir("peatones es bueno pasar.",ancho/2+125+movx1,270-movy1,30);
			break;
			break;
		}
		
		if(mover <0){
			mover = 3;
		}if(mover > 3){
			mover = 0;
		}
		
		controls();
		sys();
	}




	int cantidad = 10;

	while(ESCENE == 9){
		
		//fondoC(); //fondo

		color(NEGRO);
		//rectangulo_lleno(ancho/2-200,alto/2-120,ancho/2+200,alto/2+120);
		
		
		//fondo nuevo
		for(float i = 0; i<ancho; i+=citer){
			color_c(255*sin(floor(i)/i));
			linea(i,alto-50+alto/3*sin(i*cos(i-10)/i-(10*sin(i/time-time/150))),i,50+alto/3*sin(i*cos(i)/i-(10*sin(i/time-time/100))),citer);
			//circulo_lleno(i,alto/2+alto/2*sin(i*cos(i)/i-(15*sin(i/time-time/250))),2);
		}
		
		int anios[4];
		
		persona(ancho/2-140, alto/2-(anios[0])-50,30,1);
		persona(ancho/2, alto/2-(anios[1])-50,30,2);
		persona(ancho/2+140, alto/2-(anios[2])-50,30,3);
		
		color_c((anios[1]*255)/255);
		rectangulo_lleno(ancho/2-70, alto/2, ancho/2+70, alto/2-anios[1]);
		color_c((anios[0]*255)/255);
		rectangulo_lleno(ancho/2-105, alto/2, ancho/2-175, alto/2-anios[0]);
		color_c((anios[2]*255)/255);
		rectangulo_lleno(ancho/2+105, alto/2, ancho/2+175, alto/2-anios[2]);
		color(NEGRO);
		rectangulo_lleno(ancho/2-300, alto/2, ancho/2+300, alto);
		int x = ancho/2, y = alto/2+70, w = 25, h = w/2;
		
		color(BLANCO);
		
		char u[10], d[10], t[10];
		itoa(anios[0], u, 10);
		itoa(anios[1], d, 10);
		itoa(anios[2], t, 10);	
				
		escribir(u,ancho/2-165, y+60, 30);
		escribir(d,ancho/2-15, y+60, 30);
		escribir(t,ancho/2+135, y+60, 30);
		
		escribir("pepito",ancho/2-165, y+30, 30);
		escribir("carlos",ancho/2-15, y+30, 30);
		escribir("daniel",ancho/2+135, y+30, 30);
		
		escribir("anios",ancho/2-165, y+80, 30);
		escribir("anios",ancho/2-15, y+80, 30);
		escribir("anios",ancho/2+135, y+80, 30);
		
		color(NEGRO);
		rectangulo_lleno(0, 60, ancho, 140);
		
		color(BLANCO);
		if(anios[0] > anios[1] && anios[0] > anios[2]){	
			escribir_r("pepito es el mayor", ancho/2-135, 100, 60, 2);
		}if(anios[1] > anios[0] && anios[1] > anios[2]){	
			escribir_r("carlos es el mayor", ancho/2-135, 100, 60, 2);
		}if(anios[2] > anios[1] && anios[2] > anios[0]){	
			escribir_r("daniel es el mayor", ancho/2-135, 100, 60, 2);
		}
		
		color(BLANCO);
		for(int i = -1; i <= 1; i++){
			x = ancho/2+(150*i);
			
			linea(x-w,y+h-h*3,x+w,y+h-h*3,4);  	//arriba flecha
			linea(x-w/60,y-h-h*3,x+w,y+h-h*3,4);
			linea(x-w,y+h-h*3,x+w/60,y-h-h*3,4);
			
			if(boton_i(x-w, y-h, x+w, y+h)){
				if(anios[i+1] > 0){
					espera(30);
					anios[i+1] -= 1;
				}
			}
			
			if(boton_i(x-w, y-h*4, x+w, y-h*2)){
				if(anios[i+1] < 99){
					espera(30);
					anios[i+1] += 1;
				}
			}
		
			linea(x-w,y-h,x+w,y-h,4);			//flecha abajo
			linea(x-w/60,y+h,x+w,y-h,4);
			linea(x-w,y-h,x+w/60,y+h,4);
		}
		controls();
		sys();
	}
	
	
	//numeros palindromos
	while(ESCENE == 10){
		
		//fondoC(); //fondo

		color(NEGRO);
		//rectangulo_lleno(ancho/2-200,alto/2-120,ancho/2+200,alto/2+120);
		
		for(float i = 0; i<ancho; i+=citer*4){
			color_c(255*sin(floor(i)/i));
			//linea(i,alto-50+alto/3*sin(i*cos(i)/i-(10*sin(i/time-time/200))),i,50+alto/3*sin(i*cos(i)/i-(10*sin(i/time-time/100))),citer);
			circulo_lleno(i/2,alto/2+alto/4*sin(i/2*cos(i/2)/i/2-(10*sin(i/2/time-time/250))),citer*3);
		}
		
		color(BLANCO);
		
		rectangulo_r(ancho/2,alto-10,ancho-150,10,2);
		escribir("programa palindromos", ancho/2+25,50,50);
		escribir("este programa determinara si el numero ingresado", ancho/2+15, 85, 30);
		escribir("es palindromo o no", ancho/2+15, 105, 30);
		
		int x = ancho/2, y = alto/2-70, w = 25, h = w/2;
		
		for(int i = 0; i < 5; i++){
			num(model_pal[i], ancho/2+150+(62*i), 200, 100);
			
			x = ancho/2+150+(62*i);
			
			linea(x-w,y+h-h*3,x+w,y+h-h*3,4);  	//arriba flecha
			linea(x-w/60,y-h-h*3,x+w,y+h-h*3,4);
			linea(x-w,y+h-h*3,x+w/60,y-h-h*3,4);
			
			if(boton_i(x-w, y-h, x+w, y+h)){
				if(model_pal[i] > 0){
					espera(30);
					model_pal[i] -= 1;
				}
			}
			
			if(boton_i(x-w, y-h*4, x+w, y-h*2)){
				if(model_pal[i] < 9){
					espera(30);
					model_pal[i] += 1;
				}
			}
		
			linea(x-w,y-h,x+w,y-h,4);			//flecha abajo
			linea(x-w/60,y+h,x+w,y-h,4);
			linea(x-w,y-h,x+w/60,y+h,4);
		}
		
		if(!boton(ancho/2+20, alto/2+10, ancho-170, alto/2+100)){
			state_pal = 1;
		}
		
			w = 50 , h = w/2, x = ancho/2+275, y = alto/2+55;
			linea(x-w,y-h,x+w,y-h,4);			//flecha abajo
			linea(x-w/60,y+h,x+w,y-h,4);
			linea(x-w,y-h,x+w/60,y+h,4);
		
		for(int i = 4; i >= 0; i--){
			num(model_pal[i], ancho/2+400+(62*-i), alto/2 + 200, 100);
		}
		
		convert_pal = 0;
		
		for(int i = 1 ; i < 100000; i *=10){
			
			char en[10];
			
			itoa(i , en, 10);
			
			convert_pal += model_pal[strlen(en)-1] * i;
		} 
		
		char enim[10];
		itoa(convert_pal, enim, 10);
		
		if((convert_pal/1000)%10 ==  (convert_pal%100)/10 && (convert_pal/10000) == convert_pal%10){
			color(VERDE);
		}else{
			color(ROJO);
		}
		
		escribir_r("palindromo", ancho/2+180, alto/2+300, 80, 2);
		
		controls();
		sys();
	}
	
	while(ESCENE == 11){
		color(BLANCO);
		escribir("vacary",ancho/2+100,50,100);
		escribir("centro de comercio",ancho/2+250,70,20);
		
		int x, y = alto/2-70, w = 25, h = w/2;
		
		for(int i = 0; i < 5; i++){
			x = ancho/2+100+(62*i);
			
			num(model_vac[i], x, 200, 100);
			linea(ancho/2+120+(62), 125,ancho/2+120+(68), 145,3);
			
			num(0, ancho/2+130+40*7, 225, 50);
			num(0, ancho/2+130+40*8, 225, 50);
			num(0, ancho/2+130+40*9, 225, 50);
			
			linea(x-w,y+h-h*3,x+w,y+h-h*3,4);  	//arriba flecha
			linea(x-w/60,y-h-h*3,x+w,y+h-h*3,4);
			linea(x-w,y+h-h*3,x+w/60,y-h-h*3,4);
			
			if(boton_i(x-w, y-h, x+w, y+h)){
				if(model_vac[i] > 0){
					espera(30);
					model_vac[i] -= 1;
				}
			}
			
			if(boton_i(x-w, y-h*4, x+w, y-h*2)){
				if(model_vac[i] < 9){
					espera(30);
					model_vac[i] += 1;
				}
			}
		
			linea(x-w,y-h,x+w,y-h,4);			//flecha abajo
			linea(x-w/60,y+h,x+w,y-h,4);
			linea(x-w,y-h,x+w/60,y+h,4);
		}
		
		
		    char un[10];
		    
		    itoa(arrtoi(model_vac, 5)*1000, un, 10);
		    
	
		    
		
		color_c(255);
		rectangulo_r(ancho/2+20, 100, ancho-120, alto-10,5);
		
		rectangulo_r(ancho/2-20, alto-10, 120, 10, 5);
		
		color(AMARILLO);
		rectangulo_lleno(ancho/2-30, 20, 130, alto*1/3-10);
		if(boton_i(130, 20, ancho/2-30, alto*1/3-10) == 1){
			model_vac_1 += arrtoi(model_vac, 5)*1000;
			espera(300);
		}else if(boton_i(130, 20, ancho/2-30, alto*1/3-10) == 0){
			color_rgb(20,20,20);
		}else{
			color_rgb(0,0,0);
		}
		rectangulo_lleno(ancho/2-50, 30, 150, alto*1/3-150);
		
		rectangulo_lleno(ancho/2-50, 130, 150, alto*1/3-50);
		
		
		color(VERDE);
		rectangulo_lleno(130, alto*1/3+20, ancho/2-30, alto*2/3-10);
		if(boton_i(130, alto*1/3+20, ancho/2-30, alto*2/3-10) == 1){
			model_vac_2 += arrtoi(model_vac, 5)*1000;
			espera(300);
		}else if(boton_i(130, alto*1/3+20, ancho/2-30, alto*2/3-10) == 0){
			color_rgb(20,20,20);
		}else{
			color_rgb(0,0,0);
		}
		color(NEGRO);
		rectangulo_lleno(ancho/2-50, alto*1/3+30, 150, alto*2/3-150);
		rectangulo_lleno(ancho/2-50, alto*1/3+130, 150, alto*2/3-50);
		
		color(ROJO);
		rectangulo_lleno(130, alto*2/3+20, ancho/2-30, alto-20);
		if(boton_i(130, alto*2/3+20, ancho/2-30, alto-20) == 1){
			model_vac_3 += arrtoi(model_vac, 5)*1000;
			espera(300);
		}else if(boton_i(130, alto*2/3+20, ancho/2-30, alto-20) == 0){
			color_rgb(20,20,20);
		}else{
			color_rgb(0,0,0);
		}
		color(NEGRO);
		rectangulo_lleno(ancho/2-50, alto*2/3+30, 150, alto-150);
		rectangulo_lleno(ancho/2-50, alto*2/3+130, 150, alto-50);
		
		//conversion de entero a char

		itoa(model_vac_1, mv1, 10);
		itoa(model_vac_3, mv2, 10);
		itoa(model_vac_2, mv3, 10);
		
		model_vac_1_d = (model_vac_1*5)/100;
		model_vac_2_d = (model_vac_2*3.5)/100;
		model_vac_3_d = (model_vac_3*8)/100;
		
		itoa(model_vac_1_d, mv1d, 10);
		itoa(model_vac_3_d, mv2d, 10);
		itoa(model_vac_2_d, mv3d, 10);
		
		int sum = model_vac_1 + model_vac_2 + model_vac_3;
		int sumd = model_vac_1_d + model_vac_2_d + model_vac_3_d;
		
		char sun[10], sund[10];
		
		itoa(sum, sun, 10);
		itoa(sumd, sund, 10);
		
		color(BLANCO);
		escribir_r(mv1, 190,70,80,3);
		
		escribir_r(mv1d, 190,170,80,3);
		escribir_r("5", 620,170,80,3);
		
		escribir_r(mv2, 190,alto-190,80,3);
		
		escribir_r(mv2d, 190,alto-90,80,3);
		escribir_r("3.5", 580,alto-90,80,3);
		
		escribir_r(mv3, 190,alto/2-60,80,3);
		
		escribir_r(mv3d, 190,alto/2+40,80,3);
		escribir_r("8", 620,alto/2+40,80,3);
		
		escribir_r("total", ancho/2+50+(62), alto/2+100, 100,3);
		escribir_r(sun, ancho/2+250+(62), alto/2+100, 100,3);
		
		rectangulo_r(ancho/2+250, alto/2+50, ancho-150, alto/2+150,5);
		
		escribir_r("desct", ancho/2+50+(62), alto/2+250, 100,3);
		escribir_r(sund, ancho/2+250+(62), alto/2+250, 100,3);
		
		rectangulo_r(ancho/2+250, alto/2+200, ancho-150, alto/2+300,5);
		
		controls();
		sys();
	}
	while(ESCENE == 12){
		color(BLANCO);
		linea(ancho/2-300, alto/2-300, ancho/2-100, alto/2-300,5);
		linea(ancho/2-300, alto/2-300, ancho/2-400, alto/2-100,5);
		linea(ancho/2-100, alto/2-300, ancho/2, alto/2-100,5);
		linea(ancho/2-400, alto/2-100, ancho/2, alto/2-100,5);
		
		rectangulo_r(225, alto/2-50, ancho/2+100, alto-50,5);
		rectangulo_r(ancho/2+100, alto-50, ancho-150, 50, 5);
		
		int x, y = alto/2-80, w = 25, h = w/2;
		
		for(int i = 0; i < 5; i++){
			x = ancho/2+200+(60*i);
			
			num(model_tra[i], x, 150, 100);
			
			linea(x-w,y+h-h*3,x+w,y+h-h*3,4);  	//arriba flecha
			linea(x-w/60,y-h-h*3,x+w,y+h-h*3,4);
			linea(x-w,y+h-h*3,x+w/60,y-h-h*3,4);
			
			if(boton_i(x-w, y-h, x+w, y+h)){
				if(model_tra[i] > 0){
					espera(30);
					model_tra[i] -= 1;
				}
			}
			
			if(boton_i(x-w, y-h*4, x+w, y-h*2)){
				if(model_tra[i] < 9){
					espera(30);
					model_tra[i] += 1;
				}
			}
		
			linea(x-w,y-h,x+w,y-h,4);			//flecha abajo
			linea(x-w/60,y+h,x+w,y-h,4);
			linea(x-w,y-h,x+w/60,y+h,4);
		}
		
		if(!boton(245, alto-120, ancho/2+85, alto-80)){
			state_trap = 0;
		}
		escribir("decametros", 260, alto-100, 30);
		linea(ancho/2-250, alto-120, ancho/2-200, alto-80,2);
		
		if(!boton(245, alto-170, ancho/2+85, alto-130)){
			state_trap = 1;
		}
		escribir("hectometros", 260, alto-150, 30);
		linea(ancho/2-250, alto-170, ancho/2-200, alto-130,2);
		
		if(!boton(245, alto-220, ancho/2+85, alto-180)){
			state_trap = 2;
		}
		escribir("decimetros", 260, alto-200, 30);
		linea(ancho/2-250, alto-220, ancho/2-200, alto-180,2);
		
		if(!boton(245, alto-270, ancho/2+85, alto-230)){
			state_trap = 3;
		}
		escribir("centimetros", 260, alto-255, 30);
		linea(ancho/2-250, alto-270, ancho/2-200, alto-230,2);
		
		
		if(!boton(245, alto-320, ancho/2+85, alto-280)){
			espera(300);
			asup_trap += arrtoi(model_tra, 5);
		}
		
		itoa(asup_trap, asup, 10);
		
		escribir("ancho superior", 260, alto-305, 30);
		escribir(asup, ancho/2-150, alto-300, 30);
		linea(ancho/2-250, alto-320, ancho/2-200, alto-280,2);
		
		if(!boton(245, alto-370, ancho/2+85, alto-330)){
			espera(300);
			ainf_trap += arrtoi(model_tra, 5);
		}
		
		itoa(ainf_trap, ainf, 10);
		
		escribir("ancho inferior", 260, alto-355, 30);
		escribir(ainf, ancho/2-150, alto-350, 30);
		linea(ancho/2-250, alto-370, ancho/2-200, alto-330,2);
		
		if(!boton(245, alto-420, ancho/2+85, alto-380)){
			espera(300);
			alt_trap += arrtoi(model_tra, 5);
		}
		
		itoa(alt_trap, alt, 10);
		escribir("altura", 260, alto-405, 30);
		escribir(alt, ancho/2-150, alto-400, 30);
		linea(ancho/2-250, alto-420, ancho/2-200, alto-380,2);
		
		circulo_lleno(ancho/2+60, alto-100, 10);
		circulo_lleno(ancho/2+60, alto-150, 10);
		circulo_lleno(ancho/2+60, alto-200, 10);
		circulo_lleno(ancho/2+60, alto-250, 10);
		
		
		switch(state_trap){
			case 0:
				color(VERDE);
				circulo_lleno(ancho/2+60, alto-100, 10);
			break;
			case 1:
				color(VERDE);
				circulo_lleno(ancho/2+60, alto-150, 10);
			break;
			case 2:
				color(VERDE);
				circulo_lleno(ancho/2+60, alto-200, 10);
			break;
			case 3:
				color(VERDE);
				circulo_lleno(ancho/2+60, alto-250, 10);
			break;
		}
		
		int sum_trap = (asup_trap+ainf_trap)/2 * alt_trap;
		char sumt[10];
		
		switch(state_trap){
			case 0:
				itoa(sum_trap/10, sumt, 10);
			break;
			case 1:
				itoa(sum_trap, sumt, 10);
			break;
			case 2:
				itoa(sum_trap*100, sumt, 10);
			break;
			case 3:
				itoa(sum_trap*1000, sumt, 10);
			break;
		}
		
		int per_trap = (asup_trap+ainf_trap) + alt_trap*2;
		char pert[10];
		
		switch(state_trap){
			case 0:
				itoa(per_trap/10, pert, 10);
			break;
			case 1:
				itoa(per_trap, pert, 10);
			break;
			case 2:
				itoa(per_trap*100, pert, 10);
			break;
			case 3:
				itoa(per_trap*1000, pert, 10);
			break;
		}
		
		color(BLANCO);
		escribir("area deci", ancho/2+200, alto/2, 80);
		escribir("perimetro deci", ancho/2+200, alto/2+150, 80);
		color(ROJO);
		escribir(sumt, ancho/2+200, alto/2+60, 50);
		escribir(pert , ancho/2+200, alto/2+210, 50);
		
		controls();
		sys();
	}
	
	int u;
	
	while(ESCENE == 99){
		sys();
	}
	
	}
	
	vcierra(); 
	return 0;
}

