#include <at89x52.h>

#define cha P0_0
#define cafe P0_1
#define copo P0_2
#define botC P3_0
#define botCh P3_1
#define moeda P3_2

const int ligado = 1;
const int desligado = 0;
const int cheio = 1;
const int vazio = 0;

void delay(unsigned int x){
	unsigned int i,j; 
	for(i=0;i<x;i++){
		for(j=0;j<1275;j++){}
	}
}

void fazer_cafe(){
	if(moeda == ligado && botC == ligado){
		copo = vazio;
		delay(1000);
		cafe = ligado;
		delay(5000);
		cafe = desligado;
		copo = cheio;
		botC = desligado;
		moeda = desligado;
	}
}
	
void fazer_cha(){
	if(moeda == ligado && botCh == ligado){
		copo = vazio;
		delay(1000);
		cha = ligado;
		delay(5000);
		cha = desligado;
		copo = cheio;
		botCh = desligado;
		moeda = desligado;
	}
}

void main(){
	P0 = desligado;
	P3 = desligado;
	while(1){
		fazer_cafe();
		fazer_cha();
	}
}