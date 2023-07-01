/*
Métodos numéricos 2 
Gomez Vega Guadalupe
Paquete de pogramas 
	Newton
	Diferencias Divididas
	Spline*/
/*Librerias a incluir*/
#include <stdio.h>
#include <stdlib.h>		
#include <math.h>
#include <ctype.h>
#include<conio.h>
/*definiciones*/
/*Newton*/
#define N 2
#define M 3
#define t 3
#define r 2
/*Diferencias divididas*/
#define C 2
#define F 300
/*Spline*/
#define S 9
/* Encabezados */
int datos(void);/*Datos del equipo*/
void newton(int);/*Newton*/
int menu(void);/*Menú de sistemas*/
void F1(double, double, double, int);/*Newton*/
void F2(double, double, double, int);/*Newton*/
void F3(double, double, double, double, int);/*Newton*/
void F4(double, double, double, double, int);/*Newton*/
void mult2(double [N][N], double [N], double[N]);/*Newton*/
void mult3(double [M][M], double [M], double[M]);/*Newton*/
/*DIFERENCIAS DIVIDIDAS*/
void difDiv(void);
void lecturaTablaDif(double[][C], int);
void impresionTablaDif(double[][C], int);
void ordenarDif(double[][C], int, int &);

/*Variable global para guardar las tablas*/
double tablaGuardada[F][C];
int puntosTG;

double tablaGInterpolacion[F][C];
int pTGInter;
/*SPLINE*/
void spline(int);
void lecturaTabla(double[][C], int);
void impresionTabla(double[][C], int);
void tablaG(double[][C], int);
void tablaNueva(double[][C], int);
/*Diferenciacion e integracion numerica*/
void diferenciacionIntegracion(int, int);
void metodoDifInt(double [][C], int, int, double);
void entradaDetabla();
void integral(double mat[][C], int n, float h);
void imprime_completa(int m, double mat[][4]);
/*Funcion main*/
int main ()
{
	int opPro, sistema, centinela=0, centiInter=0;//opcion para programa
	char resp;
	do
	{
		system("cls");
		opPro=datos();
		switch(opPro)
		{
			/*Newton*/
			case 1: 
				do
				{
					system("cls");
					printf("Newton Raphson\n");
					sistema=menu();
					newton(sistema);
					fflush(stdin);
					printf("Quieres elegir otro sistema? S/N: ");
					scanf("%c", &resp);
					resp=toupper(resp);
				}while(resp=='S');
			break;
			case 2:
				do
				{
					centinela=1;
					system("cls");
					printf("Diferencias Divididas\n");
					difDiv();
					printf("Deseas cambiar la tabla? S/N: ");
					fflush(stdin);
					scanf("%c", &resp);
					resp=toupper(resp);
				}while(resp=='S');
			break;
			case 3:
				do
				{
					centiInter=1;
					system("cls");
					printf("Spline Cubico\n");
					fflush(stdin);
					spline(centinela);
					printf("\n\nDesea realizar otra aproximacion con otra tabla? S/N: ");
					fflush(stdin);
					scanf("%c", &resp);
					resp=toupper(resp);
				}while(resp=='S');
			break;
			case 4:
				do
				{
					system("cls");
					diferenciacionIntegracion(centinela, centiInter); 
					printf("\nDesea realizar otra estimacion con otra tabla? S/N: ");
					fflush(stdin);
					scanf("%c", &resp);
					resp=toupper(resp);
				}while(resp=='S');
			break;
			case 5:
				printf("\n|*|*|Fin de Programa|*|*|");
				exit(-1);
			break;
		}
		printf("Quieres elegir otro programa? S/N: ");
		fflush(stdin);
		scanf("%c",&resp);
		resp=toupper(resp);
	}while(resp=='S');
	return 0;
}
int datos()
{
	int opcion;
	printf("\tMetodos numericos 2 Grupo: 2401\n\tEquipo:\n\t\tGomez Vega Guadalupe\n\n\n");	
	printf("\n\tQue metodo desea?\n\t\t1).....Metodo de Newton Raphson\n\t\t2).....Diferencias Divididas\n\t\t3).....Spline Cubico\n\t\t4).....Diferenciacion e Integracion\n\t\t5).....Salir\n\tOpcion: ");
	do 
	{
		scanf("%d", &opcion);
		if(opcion<1 || opcion>5)
			printf("\tFuera de rango\n\tDigite Otra Opcion:");
	}while(opcion<1 || opcion>5);
}
/*NEWTON*****************************************************************************************/
void newton(int sis)
{
	int maxi;
	double x, y, z, tol;
	char resp;
	switch(sis)
	{
		case 1:
			do
			{
				system("cls");
				printf("Sistema 1\nDame el punto incial(x,y):\n");
				printf("x: ");
				scanf("%lf", &x);
				printf("y: ");
				scanf("%lf", &y);
				printf("Cual es la tolerancia? ");
				scanf("%lf", &tol);
				printf("Cual es el maximo de iteraciones? ");
				scanf("%d", &maxi);
				F1(x, y, tol, maxi);
				fflush(stdin);
				printf("Quieres ingresar nuevos datos al sistema? S/N: ");
				scanf("%c", &resp);
				resp=toupper(resp);
			}while(resp=='S');	
		break;
		case 2:
			do
			{
				system("cls");
				printf("Sistema 2\nDame el punto incial(x,y):\n");
				printf("x: ");
				scanf("%lf", &x);
				printf("y: ");
				scanf("%lf", &y);
				printf("Cual es la tolerancia? ");
				scanf("%lf", &tol);
				printf("Cual es el maximo de iteraciones? ");
				scanf("%d", &maxi);
				F2(x, y, tol, maxi);
				fflush(stdin);
				printf("Quieres ingresar nuevos datos al sistema? S/N: ");
				scanf("%c", &resp);
				resp=toupper(resp);
			}while(resp=='S');
			break;
		case 3:
			do
			{
				system("cls");
				printf("Sistema 3\nDame el punto incial(x,y,z):\n");
				printf("x: ");
				scanf("%lf", &x);
				printf("y: ");
				scanf("%lf", &y);
				printf("z: ");
				scanf("%lf", &z);
				printf("Cual es la tolerancia? ");
				scanf("%lf", &tol);
				printf("Cual es el maximo de iteraciones? ");
				scanf("%d", &maxi);
				F3(x, y, z, tol, maxi);
				fflush(stdin);
				printf("Quieres ingresar nuevos datos al sistema? S/N: ");
				scanf("%c", &resp);
				resp=toupper(resp);
			}while(resp=='S');
		break;
		case 4:
			do
			{
				system("cls");
				printf("Sistema 4\nDame el punto incial(x,y,z):\n");
				printf("x: ");
				scanf("%lf", &x);
				printf("y: ");
				scanf("%lf", &y);
				printf("z: ");
				scanf("%lf", &z);
				printf("Cual es la tolerancia? ");
				scanf("%lf", &tol);
				printf("Cual es el maximo de iteraciones? ");
				scanf("%d", &maxi);
				F4(x, y, z, tol, maxi);
				fflush(stdin);
				printf("Quieres ingresar nuevos datos al sistema? S/N: ");
				scanf("%c", &resp);
				resp=toupper(resp);
			}while(resp=='S');
		break;
	}
}
int menu()
{
	int sis;
	char c;
	printf("MENU DE SISTEMAS\n");
	printf("1)......Sistema 1\n\tf1(x,y)=x^2+xy-10=0\n\tf2(x,y)=y+3xy^2-50=0\n");
	printf("2)......Sistema 2\n\tf1(x,y)=x^2+y^2-9=0\n\tf2(x,y)=-e^x-2y-3=0\n");
	printf("3)......Sistema 3\n\tf1(x,y,z)=2x^2-4x+y^2+3z^2+6z+2=0\n\tf2(x,y,z)=x^2+y^2-2y+2z^2-5=0\n\tf3(x,y,z)=3x^2-12x+y^2-3z^2+8=0\n");
	printf("4)......Sistema 4\n\tf1(x,y,z)=x^2-4x+y^2=0\n\tf2(x,y,z)=x^2-x-12y+1=0\n\tf3(x,y,z)=3x^2-12x+y^2-3z^2+8=0\n");
	printf("Que sistema quieres elegir: ");
	/*este while valida que hayas ingresado un numero entero y un salto de linea que da como
	redultado 2 y tambien verifica que el entero este entre 1 y 4*/
	while(!(scanf("%d%c", &sis, &c)==2 && c=='\n') || (sis<1 || sis>4))
	{
		printf("No existe esa opcion digite otra opcion: ");
	}
	return sis;
}

//sistemas de ecuaciones

void F1(double x, double y, double tol, int maxi){
	int j,k, ite=0;
	double f1, d1x, d1y;
	double g2, d2x, d2y;
	double  ny, nx, rx, ry;
	double jaco[N][N], fx[N], mult[N], error=0;
	printf("Sistema 1\n%10s %15s %15s %15s\n","iteracion","x", "y","Ea");
	while( ite<=maxi)
	{
		for(j=0;j<N;++j)
		{
			mult[j]=0.0;
		}
		if(ite>=1)
		{
			rx=fabs(nx-x);
			ry=fabs(ny-y);
			if(rx>ry)
				error=rx;
			else
				error=ry;
			x=nx;
			y=ny;
		}
		f1=pow((x), 2) + (x * y)-10;//x^2+xy-10
		d1x=(2*x) + y;	//2x+y
		d1y=x;//x
		g2= y +(3 * x * (pow((y), 2)))-50;//y+3xy^2-50
		d2x= 3*(pow((y), 2));//3y^2
		d2y=1+(6*x*y);//1+6xy
		fx[0]=f1;
		fx[1]=g2;
		/*Jacobiana*/
		jaco[0][0]=d1x;
		jaco[0][1]=d1y;
		jaco[1][0]=d2x;
		jaco[1][1]=d2y;
		/*inversa*/
		//Matriz inversa
		int NoCero,Col,C1,C2,A;
	 	double Pivote,V1,V2, Inv[2][2];
	 	for(C1=0;C1<2;C1++) 
		{
			for(C2=0;C2<2;C2++)
			{
				if (C1==C2) 
				 	Inv[C1][C2]=1; 
				else 
					Inv[C1][C2]=0;
			}
		}
		for(Col=0;Col<2;Col++)
		{
			NoCero=0;
			A=Col;
	  		while(NoCero==0)
			{
				if((jaco[A][Col]>0.0000001)||((jaco[A][Col]<-0.0000001)))
				{
	    			NoCero=1;
				}
	   			else 
				   A++;
			}
			Pivote=jaco[A][Col];
	  		for(C1=0;C1<2;C1++)
			{
	   			V1=jaco[A][C1];
	   			jaco[A][C1]=jaco[Col][C1];
	   			jaco[Col][C1]=V1/Pivote;
	   			V2=Inv[A][C1];
	   			Inv[A][C1]=Inv[Col][C1];
	   			Inv[Col][C1]=V2/Pivote;
	        }
	  		for(C2=Col+1;C2<2;C2++)
			{
				V1=jaco[C2][Col];
				for(C1=0;C1<2;C1++)
				 {
	    				jaco[C2][C1]=jaco[C2][C1]-V1*jaco[Col][C1];
	                	Inv[C2][C1]=Inv[C2][C1]-V1*Inv[Col][C1];
					}
	 		}		
		}
		/*Aqui ya esta triangularizada, con 1s en diagonal, ahora se diagonaliza*/
	 	for(Col=2;Col>=0;Col--) 
		for(C1=(Col-1);C1>=0;C1--)
	    {
	        V1=jaco[C1][Col]; 
	        for(C2=0;C2<2;C2++){
	      jaco[C1][C2]=jaco[C1][C2]-V1*jaco[Col][C2];
	      Inv[C1][C2]=Inv[C1][C2]-V1*Inv[Col][C2];
	     }
		 }
		/*Inversa por f(x)*/
		mult2(Inv, fx, mult);
		/*x y y nuevas*/
		nx=x-mult[0];
		ny=y-mult[1];
		if(ite==0)
			printf("%10d %15lf %15lf \n", ite, x, y);
		else
			printf("%10d %15lf %15lf %15lf\n", ite, x, y, error);
		if(ite>=1 && error<=tol)
		{
			printf("Se alcanzo la tolerancia %f\n", tol);
			printf("Vector solucion:\n");
			printf("x= %lf\n", x);
			printf("y= %lf\n", y);
			printf("Ea= %lf\n", error);
			break;
		}
		if(ite==maxi)
		{
			printf("Se alcanzo el maximo de iteraciones\n");
			printf("Vector solucion:\n");
			printf("x= %lf\n", x);
			printf("y= %lf\n", y);
			printf("Ea= %lf\n", error);
			break;
		}
		++ite;
	}
	
}

void F2(double x, double y, double tol, int maxi){
	int j, k, ite=0;
	double f1, d1x, d1y;
	double g2, d2x, d2y;
	double nx, ny, rx, ry;
	double jaco[N][N], fx[N], mult[N], error=0;
	printf("Sistema 2\n%10s %15s %15s %15s\n","iteracion","x", "y","Ea");
	while( ite<=maxi)
	{
		for(j=0;j<N;++j)
		{
			mult[j]=0.0;
		}
		if(ite>=1)
		{
			rx=fabs(nx-x);
			ry=fabs(ny-y);
			if(rx>ry)
				error=rx;
			else
				error=ry;
			x=nx;
			y=ny;
		}
	
		f1=pow((x), 2) + pow((y),2)-9;//x^2+y^2-9
		d1x=(2*x);//2x
		d1y=2*y;//2y
		
		g2= (-1*exp(x))-(2*y)-3;//-e^x-2y-3
		d2x= -pow((exp(1)), x);//-e^x
		d2y= -2;//-2
		fx[0]=f1;
		fx[1]=g2;
		/*Jacobiana*/
		jaco[0][0]=d1x;
		jaco[0][1]=d1y;
		jaco[1][0]=d2x;
		jaco[1][1]=d2y;
		//Matriz inversa
		int NoCero,Col,C1,C2,A;
	 	double Pivote,V1,V2, Inv[2][2];
	 	for(C1=0;C1<2;C1++) 
		{
			for(C2=0;C2<2;C2++)
			{
				if (C1==C2) 
				 	Inv[C1][C2]=1; 
				else 
					Inv[C1][C2]=0;
			}
		}
		for(Col=0;Col<2;Col++)
		{
			NoCero=0;
			A=Col;
	  		while(NoCero==0)
			{
				if((jaco[A][Col]>0.0000001)||((jaco[A][Col]<-0.0000001)))
				{
	    			NoCero=1;
				}
	   			else 
				   A++;
			}
			Pivote=jaco[A][Col];
	  		for(C1=0;C1<2;C1++)
			{
	   			V1=jaco[A][C1];
	   			jaco[A][C1]=jaco[Col][C1];
	   			jaco[Col][C1]=V1/Pivote;
	   			V2=Inv[A][C1];
	   			Inv[A][C1]=Inv[Col][C1];
	   			Inv[Col][C1]=V2/Pivote;
	        }
	  		for(C2=Col+1;C2<2;C2++)
			{
				V1=jaco[C2][Col];
				for(C1=0;C1<2;C1++)
				 {
	    				jaco[C2][C1]=jaco[C2][C1]-V1*jaco[Col][C1];
	                	Inv[C2][C1]=Inv[C2][C1]-V1*Inv[Col][C1];
					}
	 		}		
		}
		/*Aqui ya esta triangularizada, con 1s en diagonal, ahora se diagonaliza*/
	 	for(Col=2;Col>=0;Col--) 
		for(C1=(Col-1);C1>=0;C1--)
	    {
	        V1=jaco[C1][Col]; 
	        for(C2=0;C2<2;C2++){
	      jaco[C1][C2]=jaco[C1][C2]-V1*jaco[Col][C2];
	      Inv[C1][C2]=Inv[C1][C2]-V1*Inv[Col][C2];
	     }
		 }
		/*Inversa por f(x)*/
		mult2(Inv, fx, mult);
		/*x y y nuevas*/
		nx=x-mult[0];
		ny=y-mult[1];
		if(ite==0)
			printf("%10d %15lf %15lf \n", ite, x, y);
		else
			printf("%10d %15lf %15lf %15lf\n", ite, x, y, error);
		if(ite>=1 && error<=tol)
		{
			printf("Se alcanzo la tolerancia %f\n", tol);
			printf("Vector solucion:\n");
			printf("x= %lf\n", x);
			printf("y= %lf\n", y);
			printf("Ea= %lf\n", error);
			break;
		}
		if(ite==maxi)
		{
			printf("Se alcanzo el maximo de iteraciones\n");
			printf("Vector solucion:\n");
			printf("x= %lf\n", x);
			printf("y= %lf\n", y);
			printf("Ea= %lf\n", error);
			break;
		}
		++ite;
	}
}

void F3(double x, double y, double z, double tol, int maxi){
	int j, k, ite=0;
	double f1, d1x, d1y, d1z;
	double g2, d2x, d2y, d2z;
	double p3, d3x, d3y, d3z;
	double nx, ny, nz, rx, ry, rz;
	double jaco[M][M], fx[M], mult[M], error=0;
	printf("Sistema 3\n%10s %15s %15s %15s %15s\n","iteracion","x", "y","z","Ea");
	while( ite<=maxi)
	{
		for(j=0;j<M;++j)
		{
			mult[j]=0.0;
		}
		if(ite>=1)
		{
			rx=fabs(nx-x);
			ry=fabs(ny-y);
			rz=fabs(nz-z);
			if(rx>ry && rx>rz)
				error=rx;
			else
				if(ry>rz && ry>rx)
					error=ry;
				else
					if(rz>rx && rz>ry)
						error=rz;
			x=nx;
			y=ny;
			z=nz;
		}
		f1=2*(pow((x), 2)) -(4*x) + pow((y), 2) + 3*(pow((z), 2))+(6*z)+2;//2x^2-4x+y^2+3z^2+6z+2
		d1x=(4*x)-4;//4x-4
		d1y=2*y;//2y
		d1z=(6*z)+6;//6z+6
		
		g2= pow((x), 2)+pow((y), 2)-(2*y)+(2*(pow((z), 2)))-5;//x^2+y^2-2y+2z^2-5
		d2x= 2*x;//2x
		d2y=(2*y)-2;//2y-2
		d2z= 4*z;//4z
		
		p3= 3*(pow((x), 2)) - (12*x) +pow((y), 2)-(3*(pow((z), 2)))+8;//3x^2-12x+y^2-3z^2+8
		d3x= (6*x)-12;//6x-12
		d3y=(2*y);//2y
		d3z= -6*z;//-6z
		
		fx[0]=f1;
		fx[1]=g2;
		fx[2]=p3;
		/*Jacobiana*/
		jaco[0][0]=d1x;
		jaco[0][1]=d1y;
		jaco[0][2]=d1z;
		jaco[1][0]=d2x;
		jaco[1][1]=d2y;
		jaco[1][2]=d2z;
		jaco[2][0]=d3x;
		jaco[2][1]=d3y;
		jaco[2][2]=d3z;
		/*inversa*/
		//Matriz inversa
		int NoCero,Col,C1,C2,A;
	 	double Pivote,V1,V2, Inv[3][3];
	 	for(C1=0;C1<3;C1++) 
		{
			for(C2=0;C2<3;C2++)
			{
				if (C1==C2) 
				 	Inv[C1][C2]=1; 
				else 
					Inv[C1][C2]=0;
			}
		}
		for(Col=0;Col<3;Col++)
		{
			NoCero=0;
			A=Col;
	  		while(NoCero==0)
			{
				if((jaco[A][Col]>0.0000001)||((jaco[A][Col]<-0.0000001)))
				{
	    			NoCero=1;
				}
	   			else 
				   A++;
			}
			Pivote=jaco[A][Col];
	  		for(C1=0;C1<3;C1++)
			{
	   			V1=jaco[A][C1];
	   			jaco[A][C1]=jaco[Col][C1];
	   			jaco[Col][C1]=V1/Pivote;
	   			V2=Inv[A][C1];
	   			Inv[A][C1]=Inv[Col][C1];
	   			Inv[Col][C1]=V2/Pivote;
	        }
	  		for(C2=Col+1;C2<3;C2++)
			{
				V1=jaco[C2][Col];
				for(C1=0;C1<3;C1++)
				 {
	    				jaco[C2][C1]=jaco[C2][C1]-V1*jaco[Col][C1];
	                	Inv[C2][C1]=Inv[C2][C1]-V1*Inv[Col][C1];
					}
	 		}		
		}
		/*Aqui ya esta triangularizada, con 1s en diagonal, ahora se diagonaliza*/
	 	for(Col=3;Col>=0;Col--) 
		for(C1=(Col-1);C1>=0;C1--)
	    {
	        V1=jaco[C1][Col]; 
	        for(C2=0;C2<3;C2++){
	      jaco[C1][C2]=jaco[C1][C2]-V1*jaco[Col][C2];
	      Inv[C1][C2]=Inv[C1][C2]-V1*Inv[Col][C2];
	     }
		 }
		/*Inversa por f(x)*/
		mult3(Inv, fx, mult);
		/*x, y, z nuevas*/
		nx=x-mult[0];
		ny=y-mult[1];
		nz=z-mult[2];
		if(ite==0)
			printf("%10d %15lf %15lf %15lf\n", ite, x, y, z);
		else
			printf("%10d %15lf %15lf %15lf %15lf\n", ite, x, y, z, error);
		if(ite>=1 && error<=tol)
		{
			printf("Se alcanzo la tolerancia %f\n", tol);
			printf("Vector solucion:\n");
			printf("x= %lf\n", x);
			printf("y= %lf\n", y);
			printf("z= %lf\n", z);
			printf("Ea= %lf\n", error);
			break;
		}
		if(ite==maxi)
		{
			printf("Se alcanzo el maximo de iteraciones\n");
			printf("Vector solucion:\n");
			printf("x= %lf\n", x);
			printf("y= %lf\n", y);
			printf("z= %lf\n", z);
			printf("Ea= %lf\n", error);
			break;
		}
		++ite;
	}
}

void F4(double x, double y, double z, double tol, int maxi){
	int j, k, ite=0;
	double f1, d1x, d1y, d1z;
	double g2, d2x, d2y, d2z;
	double p3, d3x, d3y, d3z;
	double nx, ny, nz, rx, ry, rz;
	double jaco[M][M], fx[M], mult[M], error=0;
	printf("Sistema 4\n%10s %15s %15s %15s %15s\n","iteracion","x", "y","z","Ea");
	while( ite<=maxi)
	{
		for(j=0;j<M;++j)
		{
			mult[j]=0.0;
		}
		if(ite>=1)
		{
			rx=fabs(nx-x);
			ry=fabs(ny-y);
			rz=fabs(nz-z);
			if(rx>ry && rx>rz)
				error=rx;
			else
				if(ry>rz && ry>rx)
					error=ry;
				else
					if(rz>rx && rz>ry)
						error=rz;
			x=nx;
			y=ny;
			z=nz;
		}
		f1=(pow((x), 2)) -(4*x) + pow((y), 2) ;//x^2-4x+y^2
		d1x=(2*x)-4;//2x-4
		d1y=2*y;//2y
		d1z=0;//0
		
		g2= pow((x), 2)-x-(12*y)+1;//x^2-x-12y+1
		d2x= (2*x)-1;//2x-1
		d2y= -12;//-12
		d2z= 0;//0
		
		p3= 3*(pow((x), 2)) - (12*x) +pow((y), 2)-(3*(pow((z), 2)))+8;//3x^2-12x+y^2-3z^2+8
		d3x= (6*x)-12;//6x-12
		d3y=(2*y);//2y
		d3z= -6*z;//-6z
		fx[0]=f1;
		fx[1]=g2;
		fx[2]=p3;
		/*Jacobiana*/
		jaco[0][0]=d1x;
		jaco[0][1]=d1y;
		jaco[0][2]=d1z;
		jaco[1][0]=d2x;
		jaco[1][1]=d2y;
		jaco[1][2]=d2z;
		jaco[2][0]=d3x;
		jaco[2][1]=d3y;
		jaco[2][2]=d3z;
		/*inversa*/
		//Matriz inversa
		int NoCero,Col,C1,C2,A;
	 	double Pivote,V1,V2, Inv[3][3];
	 	for(C1=0;C1<3;C1++) 
		{
			for(C2=0;C2<3;C2++)
			{
				if (C1==C2) 
				 	Inv[C1][C2]=1; 
				else 
					Inv[C1][C2]=0;
			}
		}
		for(Col=0;Col<3;Col++)
		{
			NoCero=0;
			A=Col;
	  		while(NoCero==0)
			{
				if((jaco[A][Col]>0.0000001)||((jaco[A][Col]<-0.0000001)))
				{
	    			NoCero=1;
				}
	   			else 
				   A++;
			}
			Pivote=jaco[A][Col];
	  		for(C1=0;C1<3;C1++)
			{
	   			V1=jaco[A][C1];
	   			jaco[A][C1]=jaco[Col][C1];
	   			jaco[Col][C1]=V1/Pivote;
	   			V2=Inv[A][C1];
	   			Inv[A][C1]=Inv[Col][C1];
	   			Inv[Col][C1]=V2/Pivote;
	        }
	  		for(C2=Col+1;C2<3;C2++)
			{
				V1=jaco[C2][Col];
				for(C1=0;C1<3;C1++)
				 {
	    				jaco[C2][C1]=jaco[C2][C1]-V1*jaco[Col][C1];
	                	Inv[C2][C1]=Inv[C2][C1]-V1*Inv[Col][C1];
					}
	 		}		
		}
		/*Aqui ya esta triangularizada, con 1s en diagonal, ahora se diagonaliza*/
	 	for(Col=3;Col>=0;Col--) 
		for(C1=(Col-1);C1>=0;C1--)
	    {
	        V1=jaco[C1][Col]; 
	        for(C2=0;C2<3;C2++){
	      jaco[C1][C2]=jaco[C1][C2]-V1*jaco[Col][C2];
	      Inv[C1][C2]=Inv[C1][C2]-V1*Inv[Col][C2];
	     }
		 }
		/*Inversa por f(x)*/
		mult3(Inv, fx, mult);
		/*x, y, z nuevas*/
		nx=x-mult[0];
		ny=y-mult[1];
		nz=z-mult[2];
		if(ite==0)
			printf("%10d %15lf %15lf %15lf\n", ite, x, y, z);
		else
			printf("%10d %15lf %15lf %15lf %15lf\n", ite, x, y, z, error);
		if(ite>=1 && error<=tol)
		{
			printf("Se alcanzo la tolerancia %lf\n", tol);
			printf("Vector solucion:\n");
			printf("x= %lf\n", x);
			printf("y= %lf\n", y);
			printf("z= %lf\n", z);
			printf("Ea= %lf\n", error);
			break;
		}
		if(ite==maxi)
		{
			printf("Se alcanzo el maximo de iteraciones\n");
			printf("Vector solucion:\n");
			printf("x= %lf\n", x);
			printf("y= %lf\n", y);
			printf("z= %lf\n", z);
			printf("Ea= %lf\n", error);
			break;
		}
		++ite;
	}
}

/*multiplicacion de un vector por una matriz*/
void mult2(double inversa[N][N], double fx[N], double mult[N])
{
	int x, y;
	for(x=0; x<N;++x)
	{
		for(y=0; y<N; ++y){
			mult[x]+=(inversa[x][y]*fx[y]);
		}
	}
}
void mult3(double inversa[M][M], double fx[M], double mult[M])
{
	int x, y;
	for(x=0; x<M;++x)
	{
		for(y=0; y<M; ++y){
			mult[x]+=(inversa[x][y]*fx[y]);
		}
	}
}
/*NEWTON*****************************************************************************************/
/*DIFERENCIAS DIVIDIDAS**********************************************************/
void difDiv()
{
	int pts, mal, cambio=0, j, k;
	char res;
	printf("Cuantos puntos tiene tu tabla? ");
	scanf("%d", &pts);
	double tabla[pts][C], diferen[pts][pts+1];
	system("cls");
	lecturaTablaDif(tabla, pts);
	system("cls");
	printf("La tabla ingresada es:\n%5s%15s%15s\n","i","xi", "yi");
	impresionTablaDif(tabla, pts);
	printf("Los datos son correctos? S/N: ");
	fflush(stdin);
	scanf("%c", &res);
	res=toupper(res);
	while(res=='N')
	{
		printf("Cual punto esta mal [0, 1,..., %d]? ", pts-1);
		scanf("%d", &mal);
		printf("Ingresa x%d: ", mal);
		scanf("%lf", &tabla[mal][0]);
		printf("Ingresa y%d: ", mal);
		scanf("%lf", &tabla[mal][1]);
		system("cls");
		printf("La tabla corregida es:\n%5s%15s%15s\n","i","xi", "yi");
		impresionTablaDif(tabla, pts);
		printf("Los datos son correctos? S/N: ");
		fflush(stdin);
		scanf("%c", &res);
		res=toupper(res);
	}
	
	ordenarDif(tabla, pts, cambio);
	
	/*LLenar con ceros la tabla a guardar*/
	puntosTG=pts;//puntos de la tabla a guardar
	for(j=0; j<F;++j)
	{
		for(k=0;k<C;++k)
		{
			tablaGuardada[j][k]=0;
		}
	}
	/*Guardar tabla*/
	for(j=0; j<pts;++j)
	{
		for(k=0;k<C;++k)
		{
			tablaGuardada[j][k]=tabla[j][k];
		}	
	}
	system("cls");
	if(cambio==0)
		printf("Los datos estaban ordenados\n");
	else
		printf("Los datos de la tabla se han ordenado\n");
	printf("%15s%15s\n","x", "y") ;
	impresionTablaDif(tabla, pts);
	/*llenar con ceros la tabla de difrencias*/
	for(j=0; j<pts;++j)
	{
		for(k=0;k<pts+1;++k)
		{
			diferen[j][k]=0;
		}	
	}
	/*Pasar la tabla a la tabla de diferencias*/
	for(j=0; j<pts;++j)
	{
		for(k=0;k<C;++k)
		{
			diferen[j][k]=tabla[j][k];
		}	
	}
	/*calculo de diferencias*/
	int i=0;
	for(k=2; k<pts+1;++k)
	{
		for(j=0; j<=pts-k;++j)
		{
			diferen[j][k]=(diferen[j+1][k-1]-diferen[j][k-1])/(diferen[j+(k-1)][0]-diferen[j][0]);
		}
	}
	do
	{
		system("pause");
		system("cls");
		printf("Tabla de diferencias\n");
		printf("%5s%15s", "i","xi");
		for(j=0;j<pts;++j)
		{	
			printf("%12s", "f");
			printf("[%d]",j );
		
		}
		printf("\n");
		for(j=0; j<pts;++j)
		{
			printf("%5d", j);
			for(k=0;k<pts+1;++k)
			{
				printf("%15lf",diferen[j][k] );
			}	
			printf("\n");
		}
		double punto;
		int no=0;
		do
		{
			printf("Que punto vas a interpolar? ");
			scanf("%lf", &punto);
			if(punto>=diferen[0][0] && punto<=diferen[pts-1][0])
			{
				printf("El punto esta en el intervalo [%f, %f]\n", diferen[0][0], diferen[pts-1][0]);	
				no=0;
			}
			else
			{
				printf("El punto NO esta en el intervalo [%f, %f]\nIngresa otro punto\n", diferen[0][0], diferen[pts-1][0]);
				no=1;
			}
		}while(no==1);
		no=0;
		int grado;
		do
		{
			printf("Ingresa el grado del polinomio: ");
			scanf("%d", &grado);
			if(grado>-1 && grado<=pts-1)
			{
				printf("Los puntos son suficientes :)\nEl valor de x es: %lf\nTu polinomio es: ", punto);
				no=0;	
			}
			else
			{
				printf("Los puntos NO son suficientes: \nIngresa otro grado\n");
				no=1;
			}
		}while(no==1);
		/*imprime polinomio*/
		int aux;
		for(k=0; k<=grado;++k)
		{
			printf("%lf", diferen[0][k+1]);
			if(k>=1)
			{
				for(aux=0; aux<k;++aux)
				{
					if(diferen[aux][0]<0)
						printf("(x+%lf)", diferen[aux][0]);
					else
						printf("(x-%lf)", diferen[aux][0]);
				}
			}
			if( diferen[0][k+2]>=0 &&k<=grado-1 )
				printf("+");
		}
		/*calculo*/
		double resultadofinal=0, multi;
		for(k=0; k<=grado;++k)
		{
			multi=1;
			if(k==0)
				resultadofinal+=diferen[0][k+1];
			else
			{
				for(aux=0; aux<k;++aux)
				{
					multi*=(punto-diferen[aux][0]);
				}
				resultadofinal+=(diferen[0][k+1]*multi);
			}
		}
		printf("\nEl resultado del polinomio es: %lf\n", resultadofinal);
		printf("Desea interpolar otro punto con la misma tabla? S/N: ");
		fflush(stdin);
		scanf("%c", &res);
		res=toupper(res);
	}while(res=='S');
	
	
}
void lecturaTablaDif(double tab[][C], int pu)
{
	int j, k;
	printf("Ingresa los puntos a la tabla\n");
	for(j=0;j<pu;++j)
	{
		for(k=0; k<C;++k)
		{
			if(k==0)
				printf("x%d= ", j);
			else
				printf("y%d= ",j);
			scanf("%lf", &tab[j][k]);
		}
	}
}
void impresionTablaDif(double tabla[][C], int pts)
{
	int j, k;
	for(j=0;j<pts;++j)
	{
		printf("%5d", j);
		for(k=0; k<C;++k)
		{
			printf("%15lf", tabla[j][k]);
		}
		printf("\n");
	}
}
void ordenarDif(double tabla[][C], int pts, int &cambio)
{
	int j, k;
	double tx, ty;
	for (j=0; j<(pts - 1); j++)
	{
		for(k=j+1;k<pts;++k )
		{
			if(tabla[k][0]<tabla[j][0])
			{
				tx=tabla[k][0];
				ty=tabla[k][1];
				tabla[k][0]=tabla[j][0];
				tabla[k][1]=tabla[j][1];
				tabla[j][0]=tx;
				tabla[j][1]=ty;
				++cambio;
			}
		}
	}
}
/*SPLINE*/
void spline(int centinela)
{
	char resp;
	int j, k, pts;
	if(centinela==1)
	{
		printf("Desea emplear La tabla de la opcion anterior(Diferencias Divididas)? S/N: ");
		fflush(stdin);
		scanf("%c", &resp);
		resp=toupper(resp);
	}
	if(centinela==1 && resp=='S')
	{
		printf("ADVERTENCIA. Los puntos estan ordenadosde menor a mayor\n");
		printf("Recuerda que los puntos deben estar ordenados conforme a la secuencia de tu dibujo\n");
		fflush(stdin);
		double tablaGG[puntosTG][C];
		for(j=0; j<puntosTG;++j)
		{
			for(k=0;k<C; ++k)
			{
				tablaGG[j][k]=tablaGuardada[j][k];
			}
		}
		tablaG(tablaGG, puntosTG);
		
	}	
	else
	{
		printf("Recuerda que los puntos deben estar ordenados conforme a la secuencia de tu dibujo\n");
		printf("Cuantos puntos tiene tu tabla? ");
		scanf("%d", &pts);
		double tabla[pts][C];
		system("cls");
		lecturaTabla(tabla, pts);
		system("cls");
		tablaNueva(tabla, pts);
	}

}
void lecturaTabla(double tab[][C], int pu)
{
	int j, k;
	printf("Ingresa los puntos a la tabla\n");
	for(j=0;j<pu;++j)
	{
		for(k=0; k<C;++k)
		{
			if(k==0)
				printf("x%d= ", j);
			else
				printf("y%d= ",j);
			scanf("%lf", &tab[j][k]);
		}
	}
}
void impresionTabla(double tabla[][C], int pts)
{
	int j, k;
	for(j=0;j<pts;++j)
	{
		printf("%5d", j);
		for(k=0; k<C;++k)
		{
			printf("%15lf", tabla[j][k]);
		}
		printf("\n");
	}
}
void tablaG(double tabla[][C], int pts)
{
	char res;
	int mal;
	int j, k;
	printf("La tabla anterior es:\n%5s%15s%15s\n","i","xi", "yi");
		impresionTabla(tabla, pts);
		printf("Los datos son correctos? S/N: ");
		fflush(stdin);
		scanf("%c", &res);
		res=toupper(res);
		while(res=='N')
		{
			printf("Cual punto esta mal [0, 1,..., %d]? ", pts-1);
			scanf("%d", &mal);
			printf("Ingresa x%d: ", mal);
			scanf("%lf", &tabla[mal][0]);
			printf("Ingresa y%d: ", mal);
			scanf("%lf", &tabla[mal][1]);
			system("cls");
			printf("La tabla corregida es:\n%5s%15s%15s\n","i","xi", "yi");
			impresionTabla(tabla, pts);
			printf("Los datos son correctos? S/N: ");
			fflush(stdin);
			scanf("%c", &res);
			res=toupper(res);
		}
		system("cls");
		pTGInter=pts;//puntos de la tabla a guardar
		for(j=0; j<F;++j)
		{
			for(k=0;k<C;++k)
			{
				tablaGInterpolacion[j][k]=0;
			}
		}
		/*Guardar tabla*/
		for(j=0; j<pts;++j)
		{
			for(k=0;k<C;++k)
			{
				tablaGInterpolacion[j][k]=tabla[j][k];
			}	
		}
		printf("\tTabla Ingresada");
		printf("\n%5s%15s%15s\n","i","xi", "yi") ;
		impresionTabla(tabla, pts);
		pTGInter=pts;//puntos de la tabla a guardar
		for(j=0; j<F;++j)
		{
			for(k=0;k<C;++k)
			{
				tablaGInterpolacion[j][k]=0;
			}
		}
		/*Guardar tabla*/
		for(j=0; j<pts;++j)
		{
			for(k=0;k<C;++k)
			{
				tablaGInterpolacion[j][k]=tabla[j][k];
			}	
		}
		double vh[pts-1];
		/*calculo de hi*/
		fflush(stdin);
		for(j=0; j<pts-1;++j)
		{
			vh[j]=tabla[j+1][0]-tabla[j][0];
		}
		double tablaFinal[pts][S];
		/*********************/
		fflush(stdin);
		for(j=0;j<pts;++j)
		{
			for(k=0;k<S;++k)
			{
				tablaFinal[j][k]=0;
			}
		}
		/*Poner los puntos xi yi en la tabla final*/
		for(j=0;j<pts;++j)
		{
			for(k=0;k<C;++k)
			{
				tablaFinal[j][k]=tabla[j][k];
			}
		}
		/*poner hi en la tabla final*/
		for(j=0;j<pts-1;++j)
		{
			tablaFinal[j][2]=vh[j];
		}
		/*Calculo de diferencias*/
		for(j=0;j<pts-1;++j)
		{
			tablaFinal[j][3]=(tablaFinal[j+1][1]-tablaFinal[j][1])/ tablaFinal[j][2];
		}
		/*calculo de vector independiente 6*(diferencias)*/
		double vector[pts-2];
		/*llenar vector con ceros*/
		for(j=0;j<pts-2;++j)
		{
			vector[j]=0;
		}
		for(j=0;j<pts-2;++j)
		{
			vector[j]=6*(tablaFinal[j+1][3]-tablaFinal[j][3]);
		}
		/*matriz para calcular Si*/
		double matriz[pts-2][pts-2];
		//llenar la matriz con ceros
		for(j=0;j<pts-2;++j)
		{
			for(k=0;k<pts-2;++k)
			{
				matriz[j][k]=0;
			}
		}
		for(j=0;j<pts-2;++j)
		{
			for(k=0;k<pts-2;++k)
			{
				if(j==k)
					matriz[j][k]=2*(tablaFinal[j][2]+tablaFinal[j+1][2]);	
				else	
					if(j+1==k)
						matriz[j][k]=tablaFinal[k][2];
					else
						if(j-1==k)
							matriz[j][k]=tablaFinal[j][2];
			}
	
		}
		/*******************************************/
		//Matriz inversa
		int NoCero,Col,C1,C2,A;
	 	double Pivote,V1,V2, Inv[pts-2][pts-2];
	 	for(C1=0;C1<pts-2;C1++) 
		{
			for(C2=0;C2<pts-2;C2++)
			{
				if (C1==C2) 
				 	Inv[C1][C2]=1; 
				else 
					Inv[C1][C2]=0;
			}
		}
		for(Col=0;Col<pts-2;Col++)
		{
			NoCero=0;
			A=Col;
	  		while(NoCero==0)
			{
				if((matriz[A][Col]>0.0000001)||((matriz[A][Col]<-0.0000001)))
				{
	    			NoCero=1;
				}
	   			else 
				   A++;
			}
			Pivote=matriz[A][Col];
	  		for(C1=0;C1<pts-2;C1++)
			{
	   			V1=matriz[A][C1];
	   			matriz[A][C1]=matriz[Col][C1];
	   			matriz[Col][C1]=V1/Pivote;
	   			V2=Inv[A][C1];
	   			Inv[A][C1]=Inv[Col][C1];
	   			Inv[Col][C1]=V2/Pivote;
	        }
	  		for(C2=Col+1;C2<pts-2;C2++)
			{
				V1=matriz[C2][Col];
				for(C1=0;C1<pts-2;C1++)
				 {
	    				matriz[C2][C1]=matriz[C2][C1]-V1*matriz[Col][C1];
	                	Inv[C2][C1]=Inv[C2][C1]-V1*Inv[Col][C1];
					}
	 		}		
		}
		/*Aqui ya esta triangularizada, con 1s en diagonal, ahora se diagonaliza*/
	 	for(Col=pts-2;Col>=0;Col--) 
		for(C1=(Col-1);C1>=0;C1--)
	    {
	        V1=matriz[C1][Col]; 
	        for(C2=0;C2<pts-2;C2++){
	      matriz[C1][C2]=matriz[C1][C2]-V1*matriz[Col][C2];
	      Inv[C1][C2]=Inv[C1][C2]-V1*Inv[Col][C2];
	     }
		 }
		/*Multiplicacion de matriz por vector*/
		double si[pts];
		/*spline Natural*/
		si[0]=0;
		si[pts-1]=0;
		/*Multiplicacion*/
		for(j=0;j<pts-2;++j)
		{
			for(k=0;k<pts-2;++k)
			{
				si[j+1]+=Inv[j][k]*vector[k];
			}
		}
		/*poner Si en la tabla final*/
		for(j=0;j<pts;++j)
		{
			tablaFinal[j][4]=si[j];
		}
		
		/*Calculo de ai, bi, ci y di*/
		/*ai*/
		for(j=0;j<pts-1;++j)
		{
			tablaFinal[j][5]=(tablaFinal[j+1][4]-tablaFinal[j][4])/(6*tablaFinal[j][2]);
		}
		/*bi*/
		for(j=0;j<pts-1;++j)
		{
			tablaFinal[j][6]=tablaFinal[j][4]/2;
		}
		/*ci*/
		for(j=0;j<pts-1;++j)
		{
			tablaFinal[j][7]=((tablaFinal[j+1][1]-tablaFinal[j][1])/tablaFinal[j][2])-(((tablaFinal[j+1][4]+(2*tablaFinal[j][4]))/6)*tablaFinal[j][2]);
		}
		/*di*/
		for(j=0;j<pts-1;++j)
		{
			tablaFinal[j][8]=tablaFinal[j][1];
		}
		system("pause");
		system("cls");
		printf("%5s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n", "i","xi", "yi", "hi", "f[1]","Si" ,"ai", "bi", "ci", "di");
		for(j=0;j<pts;++j)
		{
			printf("%5d", j);
			for(k=0;k<S;++k)
			{
				if((k>1 && j==pts-1 ) && k!=4  && tablaFinal[j][k]==0)
					printf("%15s", "");
				else
					printf("%15lf", tablaFinal[j][k]);
			}
			printf("\n");
		}
		/*Impresion de polinomios e intervalos*/
		printf("\n\tPolinomios:\n");
		fflush(stdin);
		double xi, ai, bi, ci, di, xi2, mayor, menor;
		for(j=0;j<pts-1;++j)
		{
			ai=tablaFinal[j][5];
			bi=tablaFinal[j][6];
			ci=tablaFinal[j][7];
			di=tablaFinal[j][8];
			xi=tablaFinal[j][0];
			xi2=tablaFinal[j+1][0];
			printf("\tg%d(x)= %lf(x",j,ai );
			if(xi>=0)
				printf("-%lf)^3", xi);
			else
				printf("%lf)^3", xi);
			if(bi>=0)
				printf("+%lf(x", bi);
			else
				printf("%lf(x", bi);
			if(xi>=0)
				printf("-%lf)^2", xi);
			else
				printf("%lf)^2", xi);
			if(ci>=0)
				printf("+%lf(x", ci);
			else
				printf("%lf(x", ci);	
			if(xi>=0)
				printf("-%lf)", xi);
			else
				printf("%lf)", xi);
			if(di>=0)
				printf("+%lf", di);
			else
				printf("%lf", di);	
			
			if(xi2<xi)
				printf("%10s %lf >= x >= %lf \n","", xi, xi2);
			else
				printf("%10s %lf <= x <= %lf \n","", xi, xi2);
		}
}
void tablaNueva(double tabla[][C], int pts)
{
	char res;
	int mal, j, k;
	printf("La tabla ingresada es:\n%5s%15s%15s\n","i","xi", "yi");
		impresionTabla(tabla, pts);
		printf("Los datos son correctos? S/N: ");
		fflush(stdin);
		scanf("%c", &res);
		res=toupper(res);
		while(res=='N')
		{
			printf("Cual punto esta mal [0, 1,..., %d]? ", pts-1);
			scanf("%d", &mal);
			printf("Ingresa x%d: ", mal);
			scanf("%lf", &tabla[mal][0]);
			printf("Ingresa y%d: ", mal);
			scanf("%lf", &tabla[mal][1]);
			system("cls");
			printf("La tabla corregida es:\n%5s%15s%15s\n","i","xi", "yi");
			impresionTabla(tabla, pts);
			printf("Los datos son correctos? S/N: ");
			fflush(stdin);
			scanf("%c", &res);
			res=toupper(res);
		}
		system("cls");
		printf("\tTabla Ingresada");
		printf("\n%5s%15s%15s\n","i","xi", "yi") ;
		impresionTabla(tabla, pts);
		pTGInter=pts;//puntos de la tabla a guardar
		for(j=0; j<F;++j)
		{
			for(k=0;k<C;++k)
			{
				tablaGInterpolacion[j][k]=0;
			}
		}
		/*Guardar tabla*/
		for(j=0; j<pts;++j)
		{
			for(k=0;k<C;++k)
			{
				tablaGInterpolacion[j][k]=tabla[j][k];
			}	
		}
		double vh[pts-1];
		/*calculo de hi*/
		for(j=0; j<pts-1;++j)
		{
			vh[j]=tabla[j+1][0]-tabla[j][0];
		}
		double tablaFinal[pts][S];
		/*********************/
		for(j=0;j<pts;++j)
		{
			for(k=0;k<S;++k)
			{
				tablaFinal[j][k]=0;
			}
		}
		/*Poner los puntos xi yi en la tabla final*/
		for(j=0;j<pts;++j)
		{
			for(k=0;k<C;++k)
			{
				tablaFinal[j][k]=tabla[j][k];
			}
		}
		/*poner hi en la tabla final*/
		for(j=0;j<pts-1;++j)
		{
			tablaFinal[j][2]=vh[j];
		}
		/*Calculo de diferencias*/
		for(j=0;j<pts-1;++j)
		{
			tablaFinal[j][3]=(tablaFinal[j+1][1]-tablaFinal[j][1])/ tablaFinal[j][2];
		}
		/*calculo de vector independiente 6*(diferencias)*/
		double vector[pts-2];
		/*llenar vector con ceros*/
		for(j=0;j<pts-2;++j)
		{
			vector[j]=0;
		}
		for(j=0;j<pts-2;++j)
		{
			vector[j]=6*(tablaFinal[j+1][3]-tablaFinal[j][3]);
		}
		/*matriz para calcular Si*/
		double matriz[pts-2][pts-2];
		//llenar la matriz con ceros
		for(j=0;j<pts-2;++j)
		{
			for(k=0;k<pts-2;++k)
			{
				matriz[j][k]=0;
			}
		}
		for(j=0;j<pts-2;++j)
		{
			for(k=0;k<pts-2;++k)
			{
				if(j==k)
					matriz[j][k]=2*(tablaFinal[j][2]+tablaFinal[j+1][2]);	
				else	
					if(j+1==k)
						matriz[j][k]=tablaFinal[k][2];
					else
						if(j-1==k)
							matriz[j][k]=tablaFinal[j][2];
			}
	
		}
		/*******************************************/
		//Matriz inversa
		int NoCero,Col,C1,C2,A;
	 	double Pivote,V1,V2, Inv[pts-2][pts-2];
	 	for(C1=0;C1<pts-2;C1++) 
		{
			for(C2=0;C2<pts-2;C2++)
			{
				if (C1==C2) 
				 	Inv[C1][C2]=1; 
				else 
					Inv[C1][C2]=0;
			}
		}
		for(Col=0;Col<pts-2;Col++)
		{
			NoCero=0;
			A=Col;
	  		while(NoCero==0)
			{
				if((matriz[A][Col]>0.0000001)||((matriz[A][Col]<-0.0000001)))
				{
	    			NoCero=1;
				}
	   			else 
				   A++;
			}
			Pivote=matriz[A][Col];
	  		for(C1=0;C1<pts-2;C1++)
			{
	   			V1=matriz[A][C1];
	   			matriz[A][C1]=matriz[Col][C1];
	   			matriz[Col][C1]=V1/Pivote;
	   			V2=Inv[A][C1];
	   			Inv[A][C1]=Inv[Col][C1];
	   			Inv[Col][C1]=V2/Pivote;
	        }
	  		for(C2=Col+1;C2<pts-2;C2++)
			{
				V1=matriz[C2][Col];
				for(C1=0;C1<pts-2;C1++)
				 {
	    				matriz[C2][C1]=matriz[C2][C1]-V1*matriz[Col][C1];
	                	Inv[C2][C1]=Inv[C2][C1]-V1*Inv[Col][C1];
					}
	 		}		
		}
		/*Aqui ya esta triangularizada, con 1s en diagonal, ahora se diagonaliza*/
	 	for(Col=pts-2;Col>=0;Col--) 
		for(C1=(Col-1);C1>=0;C1--)
	    {
	        V1=matriz[C1][Col]; 
	        for(C2=0;C2<pts-2;C2++){
	      matriz[C1][C2]=matriz[C1][C2]-V1*matriz[Col][C2];
	      Inv[C1][C2]=Inv[C1][C2]-V1*Inv[Col][C2];
	     }
		 }
		/*Multiplicacion de matriz por vector*/
		double si[pts];
		/*spline Natural*/
		si[0]=0;
		si[pts-1]=0;
		/*Multiplicacion*/
		for(j=0;j<pts-2;++j)
		{
			for(k=0;k<pts-2;++k)
			{
				si[j+1]+=Inv[j][k]*vector[k];
			}
		}
		/*poner Si en la tabla final*/
		for(j=0;j<pts;++j)
		{
			tablaFinal[j][4]=si[j];
		}
		
		/*Calculo de ai, bi, ci y di*/
		/*ai*/
		for(j=0;j<pts-1;++j)
		{
			tablaFinal[j][5]=(tablaFinal[j+1][4]-tablaFinal[j][4])/(6*tablaFinal[j][2]);
		}
		/*bi*/
		for(j=0;j<pts-1;++j)
		{
			tablaFinal[j][6]=tablaFinal[j][4]/2;
		}
		/*ci*/
		for(j=0;j<pts-1;++j)
		{
			tablaFinal[j][7]=((tablaFinal[j+1][1]-tablaFinal[j][1])/tablaFinal[j][2])-(((tablaFinal[j+1][4]+(2*tablaFinal[j][4]))/6)*tablaFinal[j][2]);
		}
		/*di*/
		for(j=0;j<pts-1;++j)
		{
			tablaFinal[j][8]=tablaFinal[j][1];
		}
		system("pause");
		system("cls");
		printf("%5s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n", "i","xi", "yi", "hi", "f[1]","Si" ,"ai", "bi", "ci", "di");
		for(j=0;j<pts;++j)
		{
			printf("%5d", j);
			for(k=0;k<S;++k)
			{
				if((k>1 && j==pts-1 ) && k!=4  && tablaFinal[j][k]==0)
					printf("%15s", "");
				else
					printf("%15lf", tablaFinal[j][k]);
			}
			printf("\n");
		}
		/*Impresion de polinomios e intervalos*/
		printf("\n\tPolinomios:\n");
		fflush(stdin);
		double xi, ai, bi, ci, di, xi2, mayor, menor;
		for(j=0;j<pts-1;++j)
		{
			ai=tablaFinal[j][5];
			bi=tablaFinal[j][6];
			ci=tablaFinal[j][7];
			di=tablaFinal[j][8];
			xi=tablaFinal[j][0];
			xi2=tablaFinal[j+1][0];
			printf("\tg%d(x)= %lf(x",j,ai );
			if(xi>=0)
				printf("-%lf)^3", xi);
			else
				printf("%lf)^3", xi);
			if(bi>=0)
				printf("+%lf(x", bi);
			else
				printf("%lf(x", bi);
			if(xi>=0)
				printf("-%lf)^2", xi);
			else
				printf("%lf)^2", xi);
			if(ci>=0)
				printf("+%lf(x", ci);
			else
				printf("%lf(x", ci);	
			if(xi>=0)
				printf("-%lf)", xi);
			else
				printf("%lf)", xi);
			if(di>=0)
				printf("+%lf", di);
			else
				printf("%lf", di);	
			
			if(xi2<xi)
				printf("%10s %lf >= x >= %lf \n","", xi, xi2);
			else
				printf("%10s %lf <= x <= %lf \n","", xi, xi2);
		}
}
/*Diferenciacion e integración*/
void diferenciacionIntegracion(int centinela, int centiInter) 
{
	char resp;
	int opcionAemplear=0, puntos,  i, j, cambio=0, hesigual=-1;
	int auxiliar=0, mal, noSeGuardo=0;
	double h, x0, hv;
	do
	{
		system("cls");
		printf("Diferenciacion e integracion\n");
		fflush(stdin);
		if(centinela==1 || centiInter==1)
		{
			printf("Desea emplear alguna de las tablas guardadas?S/N: ");
			fflush(stdin);
			scanf("%c", &resp);
			resp=toupper(resp);
		}
		if(resp=='S' && (centinela==1 || centiInter==1))
		{
			auxiliar=1;
			printf("Cual tabla desea emplear:\n");
			printf("\t1).....Interpolacion(Diferencias divididas)\n");
			printf("\t2).....Aproximacion(Spline)\n");
			printf("\tOpcion: ");
			do 
			{
				noSeGuardo=0;
				scanf("%d", &opcionAemplear);
				if(centinela==0 && opcionAemplear==1)
				{
					printf("\tNo hay una tabla de Diferencias Divididas guardada\n");
					printf("Digite opcion 2: ");
					noSeGuardo=1;
				}
				if(centiInter==0 && opcionAemplear==2)
				{
					printf("\tNo hay una tabla de Spline cubico guardada\n");
					printf("Digite opcion 1: ");
					noSeGuardo=1;
				}
				if(opcionAemplear<1 || opcionAemplear>2)
					printf("\tFuera de rango\n\tDigite Otra Opcion:");
			}while(opcionAemplear<1 || opcionAemplear>2 || noSeGuardo==1);
			printf("ADVERTENCIA. Los datos tienen que estar igualmente espaciados\n");
			system("pause");
			if(opcionAemplear==1)
			{
				/*verificar si esta igualmente espaciados*/
				double vhDif[puntosTG-1];
				hesigual=0;	
				for(j=0; j<puntosTG-1;++j)
				{
					vhDif[j]=tablaGuardada[j+1][0]-tablaGuardada[j][0];
				}
				for(j=1; j<puntosTG-1;++j)
				{
					if(vhDif[j]==vhDif[0])
					{
						hesigual+=1;
					}
					else
					{
						hesigual=0;	
					}
				}
				if(hesigual!=0)
				{
					printf("Los datos estan igualmente espaciados\n");
					metodoDifInt(tablaGuardada,puntosTG, auxiliar, vhDif[0]);	
				}
			}
			else
			{
				ordenarDif(tablaGInterpolacion,pTGInter, cambio);
				double vhInter[pTGInter-1];
				for(j=0; j<pTGInter-1;++j)
				{
					vhInter[j]=tablaGInterpolacion[j+1][0]-tablaGInterpolacion[j][0];
				}
				hesigual=0;	
				for(j=1; j<=pTGInter-1;++j)
				{
					if(vhInter[j]==vhInter[0])
					{
						hesigual+=1;
					}
					else
					{
						hesigual=0;	
					}
				}
				if(hesigual!=0)
				{
					printf("Los datos se ordenaran de menor a mayor\n");
					printf("Los datos estan igualmente espaciados\n");
					metodoDifInt(tablaGInterpolacion,pTGInter, auxiliar, vhInter[0]);
				}
			}
		}
		if(hesigual==0)
		{
			printf("Los datos de la tabla guardada no estan igualmene espaciados\n");
			printf("Ingrese una tabla nueva por favor :)\n");
			system("pause");
			system("cls");
		}
		if(auxiliar==0)
		{
			if((resp=='N' || (centinela==0 || centiInter==0) ) )
			{	
				entradaDetabla();
			}	
		}
		if(resp=='S' && hesigual==0)
		{
			entradaDetabla();
		}
		printf("Desea cambiar la tabla?? S/N: ");
		fflush(stdin);
		scanf("%c", &resp);
		resp=toupper(resp);
	}while(resp=='S');
	
}
void entradaDetabla()
{
	char resp;
	int opcionAemplear=0, puntos,  i, j, cambio=0, hesigual=0;
	int auxiliar=0, mal, noSeGuardo=0;
	double h, x0, hv;
	printf("Cuantos puntos tiene tu tabla? ");
	scanf("%d", &puntos);
	double valoresX[puntos];
	double valoresfX[puntos];
	double tabla[puntos][C];
	do
	{
		printf("Cual es el valor inicial? x0= ");
		scanf("%lf", &x0);
		printf("Es correcto tu valor inicial??S/N: ");
		fflush(stdin);
		scanf("%c", &resp);
		resp=toupper(resp);	
	}while(resp=='N');
	do
	{
		printf("Cual es el tamanyo de paso? ");
		scanf("%lf", &h);
		printf("Es correcto el tamanyo de paso?? S/N: ");
		fflush(stdin);
		scanf("%c", &resp);
		resp=toupper(resp);	
	}while(resp=='N');
	valoresX[0]=x0;
	for(i=1; i<=puntos;++i)
	{
		valoresX[i]=valoresX[i-1]+h;
	}
	system("cls");
	printf("Los valores de xi son: \n");
	for(i=0; i<puntos;++i)
	{
		printf("x%d=%lf\n", i,valoresX[i]);
	}
	printf("Ingresa los valores de f(x)\n");
	for(i=0; i<puntos;++i)
	{
		printf("f(x%d)= ", i);
		scanf("%lf", &valoresfX[i]);
	}
	printf("Los valores ingresados de f(x) son:\n");
	for(i=0; i<puntos;++i)
	{
		printf("f(x%d)= %lf\n", i,valoresfX[i]);
	}
	printf("Los valores son correctos? S/N: ");
	fflush(stdin);
	scanf("%c", &resp);
	resp=toupper(resp);
	while(resp=='N')
	{
		printf("Cual f(x) esta mal?[0,..., %d]: ",puntos-1);
		scanf("%d", &mal);
		printf("Ingresa f(x%d)= ", mal);
		scanf("%lf", &valoresfX[mal]);
		printf("Los valores ingresados de f(x) son:\n");
		for(i=0; i<puntos;++i)
		{
			printf("f(x%d)= %lf\n", i,valoresfX[i]);
		}
		printf("Los valores son correctos? S/N: ");
		fflush(stdin);
		scanf("%c", &resp);
		resp=toupper(resp);
		system("cls");
	}
	/*pasa x y f(x) a la tabla*/
	for(i=0; i<puntos;++i)
	{
		tabla[i][0]=valoresX[i];
	}
	for(i=0; i<puntos;++i)
	{
		tabla[i][1]=valoresfX[i];
	}
	integral(tabla, puntos, h);
	metodoDifInt(tabla,puntos, auxiliar, h);
}
void metodoDifInt(double tabla[][C], int puntos, int auxiliar, double h)
{
	int i, j;
	double vdif[puntos],tdifcen[puntos][4], vdif2[puntos];
	system("pause");
	system("cls");
	printf("Tu tabla es:\n");
	printf("%5s%15s%15s\n", "i", "xi","f(xi)");
	for(i=0;i<puntos;++i)
	{
		printf("%5d", i);
		for(j=0; j<C;++j)
		{
			printf("%15lf", tabla[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<puntos;++i)
	{
		for(j=0; j<3;++j)
		{
			tdifcen[i][j]=0;
		}
	}
	/*pasas los datos a la tabla de diferencia centrada*/
	for(i=0;i<puntos;++i)
	{
		for(j=0; j<C;++j)
		{
			tdifcen[i][j]=tabla[i][j];
		}
	}
	/*calculo de diferecias centradas*/
	vdif[0]=0;;
	vdif[puntos-1]=0;
	for(i=1;i<puntos-1;++i)
	{
		vdif[i]=(1/(2*h))*(tabla[i+1][1]-tabla[i-1][1]);
	}
	for(i=0;i<puntos;++i)
	{
		tdifcen[i][2]=vdif[i];
	}
	vdif2[0]=0;
	vdif2[puntos-1]=0;
	for(i=1;i<puntos-1;++i)
	{
		vdif2[i]=(1/(h*h))*(tabla[i+1][1]-2*tabla[i][1]+tabla[i-1][1]);
	}
	for(i=0;i<puntos;++i)
	{
		tdifcen[i][3]=vdif2[i];
	}
	/*pide intervalo*/
	int xini, xfin;
	printf("De que intervalo deseas conocer las derivadas?\n");
	do
	{
		printf("x inicial [1,...., %d]: ", puntos-2);
		scanf("%d", &xini);
		if(xini<1 || xini>puntos-2)
		{
			printf("No existe la derivada para x%d.Digite otro valor inicial\n", xini);
		}
	}while(xini<1 || xini>puntos-2);
	printf("x inial= %lf\n",tabla[xini][0]);
	do
	{
		printf("x final [1,...., %d]: ", puntos-2);
		scanf("%d", &xfin);
		if(xfin<1 || xfin>puntos-2)
		{
			printf("No existe la derivada para x%d.Digite otro valor final\n", xini);
		}
	}while(xfin<1 || xfin>puntos-2);
	printf("x final= %lf\n",tabla[xfin][0]);
	system("pause");
	system("cls");
	printf("Tabla para el intervalo [%lf, %lf]\n",tabla[xini][0], tabla[xfin][0]);
	fflush(stdin);
	printf("%5s%15s%15s%20s%30s\n", "i", "xi","f(xi)","Diferencia Centrada", "Segunda Diferencia Centrada");
	for(i=xini;i<=xfin;++i)
	{
		printf("%5d", i);
		for(j=0; j<4;++j)
		{
			if(j==3)
				printf("%25lf", tdifcen[i][j]);
			else
				printf("%15lf", tdifcen[i][j]);
		}
		printf("\n");
	}
}

void integral(double mat_int[][2], int n, float h){
	
	n=n-1;
	
	double mat[n][4];
	for(int i=0; i<=n; i++){
		for(int j=0; j<2; j++){
			mat[i][j]= mat_int[i][j];
		}
	}
	
	for(int i=0; i<=n; i++){
		for(int j=2; j<4; j++){
			mat[i][j]=0;
		}
	}
	
	if(n%2==0){
	
	mat[0][2]= mat[0][1];
	mat[n][2]= mat[n][1];
	
	mat[0][3]= mat[0][1];
	mat[n][3]= mat[n][1];
	int j=2;
	int cn=1;
	
	for(int i=1; i<n; i++){
		
			if(cn==1){
			mat[i][j]= mat[i][j-1]*4;
			cn=2;
			}else{
			mat[i][j]= mat[i][j-1]*2;
			cn=1;
			}
	}
	
	j=3;
	cn=1;
	
	for(int i=1; i<n; i++){
		
			if(cn==1 or cn==2){
			mat[i][j]= mat[i][j-2]*3;
			while(cn==2){
				cn=3;
			}
			while(cn==1){
			cn=2;
			}
			}else{
			mat[i][j]= mat[i][j-2]*2;
			cn=1;	
			}

	}
	
	j=1;
	double trapc, suma, ter, oct, div;
	trapc=0;
	suma=0;
	ter=0;
	oct=0;
	
	for(int i=1; i<n; i++){
	suma=suma + mat[i][j];
	}
	suma= suma*2;
	suma = suma + mat[0][1]+ mat[n][1];
	
	trapc = h/2;
	trapc = trapc * suma;
	
	j=2;
	for(int i=0; i<=n; i++){
	ter = (ter + mat[i][j]);
	}
	suma= h/3;
	ter = suma * ter;
	
	j=3;
	for(int i=0; i<=n; i++){
	oct = (oct + mat[i][j]);
	}
	
	oct= 0.375 * oct;
	oct = h * oct;
	
	printf("las aproximaciones son:\n");
	printf("\nel trapecio = %f", trapc);
	printf("\nS 1/3 = %f", ter);
	printf("\nS 1/8 =%f\n", oct);
	
	imprime_completa(n, mat);

	}else{
	
	printf("\nel numero de puntos es impar");
		mat[0][2]= mat[0][1];
		mat[n-3][2]= mat[n-3][1];
	
		mat[n-3][3]= mat[n-3][1];
		mat[n][3]= mat[n][1];
		
		int j=2;
		int cn=1;
	
	
	for(int i=1; i<n-3; i++){
		
			if(cn==1){
			mat[i][j]= mat[i][j-1]*4;
			cn=2;
			}else{
			mat[i][j]= mat[i][j-1]*2;
			cn=1;
			}
	}
	
	j=3;
	cn=1;
	
	for(int i=n-2; i<n; i++){
		
			if(cn==1 or cn==2){
			mat[i][j]= mat[i][j-2]*3;
			while(cn==2){
				cn=3;
			}
			while(cn==1){
			cn=2;
			}
			}else{
			mat[i][j]= mat[i][j-2]*2;
			cn=1;	
			}

	}
	
	j=1;
	double ter, oct, dvn;
	ter=0;
	oct=0;
	dvn=0;
	
	j=2;
	for(int i=0; i<=n-3; i++){
	ter = (ter + mat[i][j]);
	}
	dvn= h/3;
	ter = dvn * ter;
	
	j=3;
	for(int i=n-3; i<=n; i++){
	oct = (oct + mat[i][j]);
	}
	
	oct= 0.375 * oct;
	oct = h * oct;
	
	printf("\n1/3 + 3/8 =%f\n", ter + oct);
	
	imprime_completa(n, mat);
	}
	
}

void imprime_completa(int m, double mat[][4]){
	
	printf("\n");
	for(int i=0; i<=m; i++){
		for(int j=0; j<2; j++){
			
			printf("%15lf", mat[i][j]);
		}
		printf("\n");
	}
}
