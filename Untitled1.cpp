#include <fstream>
#include "miniwin.h"

using namespace std;
using namespace miniwin;

int main(){
	
	string linea;
	ifstream F("image.jpg");
	
	if(!F.is_open()){
		vcierra();
		return 1;
	}
	getline(F,linea);
	if(linea != "P2"){
		vcierra();
		return 1;
	}
	
	getline(F, linea);
	while(linea[0] == '#'){
		getline(F,linea);
	}
	
	istringstream S(linea);
	int an1, al1;
	S >> an1 >> al1;
	
	int max;
	
	F >> max;
	
	short an=200, al=an, xs=ancho/2, ys=alto/2;
		
	for(short c = -(an/2); c<an/2; c++){
		for(short r = -(al/2); r<al/2; r++){
			punto(xs+((an*c+tx-(100*sin(time*2)))/an+(100*sin(time*2)*r)/100),ys+((al*r+ty-(100*cos(time*3)))/al+(100*cos(time*3)*c)/100));
		}
	}
	
	return 0;
}
