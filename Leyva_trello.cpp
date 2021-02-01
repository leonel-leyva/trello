#include<iostream>
#include<conio.h>
#include<fstream>
#include<ctime>
#include<windows.h>
#include<direct.h>
#include <string.h>
#include <iomanip>
using namespace  std;
string respuesta="",nombre_usuario="",usuario="",contra="";
fstream  DOCU;
bool busqueda=false;
string nombre_DOCU,nom2;
int opc=0;
string n_tarea;
string nombre,nombre_auxi;
int cont_auxi=0;
const int dato_n=25;
int num_tar,elegir;
int dia=0,ano=0,mes=0,hora=0,minuts=0;
bool buscar_nom=false;
void buscar_contra();
void modificar_fecha();
void ingresa ();
char fechash[25];
time_t current_time;
struct fechas
{
	int dia;
	int mes;
	int Ano;
	int Hora;
    int min;
};
 	 		string aux{};
struct tarea
{
	string nombre;
	string dato_general;
	fechas dato_fechas;
};
tarea almacen_datos[dato_n][dato_n];
 
 int buscar_tablero(string nombre_auxi)
 {
 	 
 	 for(int y=0;y<dato_n;y++)
	 {
	 	if(nombre_auxi==almacen_datos[y][1].nombre)
	 	{
	 	 buscar_nom=true;
	 		return y;
		 }
		 
	 }
	
 	
 }

void AGREGA_NUEVA_TAREAS()
{
    cout<<endl;
    cout<<"*********CREAR NUEVA TAREAS ****** "<<endl;
	cout<<"**********************************"<<endl;
	cout<<"TAREA NOMBRE: ";
	cin>>almacen_datos[cont_auxi][1].nombre;
	cout<<"NUM.DE TAREAS: ";
	cin>>num_tar;
	for(int y=0; y<num_tar;y++)
	{
		cout<<"NOM. DE SUB TAREAS:  ";
		cin>>almacen_datos[cont_auxi][y].dato_general;
	}
	
		 do
   	  {
   	   cout<<"DIA: ";
	   cin>>dia;
	 }while(dia<=0 || dia>=32);
	 
	 do
	 {
	   	 cout<<"MES: ";
		cin>>mes;	
	 }while(mes<=0 || mes>=13);
	 
	 do
	 {
	 	cout<<"AÑO: ";
		cin>>ano;
	 }while(ano<=2000 || ano>=2050);
    
     do
     {
     	cout<<"HORA ";
		cin>>hora;
     	
     	
	 }while(hora<=0 || hora>=25);
	 
	 do
	 {
	 	cout<<"MIN: ";
		cin>>minuts;
	 }while(minuts<0 || minuts>=61);
     
     if(minuts==60)
     {
     	hora+=1;
     	minuts=0;
     	
	 }
	 if(hora>24)
	 {
	 	hora=hora-24;
	 	
	 }
	 else if(hora==24)
	 {
	 	hora=0;
	 }
		
  almacen_datos[cont_auxi][1].dato_fechas.dia=dia;
  almacen_datos[cont_auxi][1].dato_fechas.mes=mes;
  almacen_datos[cont_auxi][1].dato_fechas.Ano=ano;
  almacen_datos[cont_auxi][1].dato_fechas.Hora=hora;
  almacen_datos[cont_auxi][1].dato_fechas.min=minuts;	

    ++cont_auxi;
}

void tareas_pendientes()
{
	cout<<endl;
    cout<<"*********TAREAS PENDIENTES ****** "<<endl;
	cout<<"**********************************"<<endl;
	for(int y=0; y<dato_n;y++)
	{
    	for(int x=0; x<dato_n;x++)
		 if(almacen_datos[y][x].dato_general!="\0")
	  	{
	  	cout<<" *TAREAS: "<<almacen_datos[y][1].nombre<<endl;
		cout<<" *SUBTAREAS: "<<almacen_datos[y][x].dato_general<<" FECHA: "<<setfill('0')<<setw(2)<<almacen_datos[y][1].dato_fechas.dia <<"/"<<setfill('0')<<setw(2)<< almacen_datos[y][1].dato_fechas.mes<< "/"<<almacen_datos[y][1].dato_fechas.Ano<<"  HORA:"<< ('0')<<setw(1)<<almacen_datos[y][1].dato_fechas.Hora<<":"<< ('0')<<setw(1)<< almacen_datos[y][1].dato_fechas.min<<endl;	
	    }	
	}

	}
	
int buscar_subtarea(int pos,string nombre_auxi)
 {
 	 for(int y=0;y<dato_n;y++)
	 {
	 	if(nombre_auxi==almacen_datos[pos][y].dato_general)
	 	{
	 	 buscar_nom=true;
	 		return y;
		 }	 
	 }
 }
	
void eliminar_subtarea(){
    cout<<endl;
    cout<<"*********ELIMINAR SUB TAREA ****** "<<endl;
	cout<<"**********************************"<<endl;
	cout<<endl;
	int dia,mes,ano,hora,minuts;
	bool busqueda2=false;
	cout<<" NOMBRE DE TAREA : " ;
	cin>>nombre;
 	 int pos=buscar_tablero(nombre);
 	 if(buscar_nom)
 	 {
 	 	cout<<"NOMBRE DE SUBTAREA: "; cin>>nombre_auxi;
 	 	int pos2=buscar_subtarea(pos,nombre_auxi);
 	 	if(buscar_nom==true)
 	 	{
 	 		 for(int y=0;y<dato_n;y++)
 	 		 {
 	 		 	
 	 		 	if(almacen_datos[pos][y].dato_general== "")
 	 		 	{
 	 		 		
 	 				
			   	almacen_datos[pos][1].nombre="";
			   	break;
				  }
 	 		 	
			   }
			
	}
 	 		almacen_datos[pos][pos2].dato_general="";
		}
		
}




  

void terminar_subtarea()
{
	cout<<endl;
    cout<<"*********TERMINAR TAREA ********* "<<endl;
	cout<<"**********************************"<<endl;
	cout<<endl;
	int dia,mes,ano,hora,minuts;
	cout<<"NOMBRE DE TAREA:  " ;
	cin>>nombre;
 	 int pos=buscar_tablero(nombre);
 	 if(buscar_nom)
 	 {
 	 	
 	 	cout<<"NOMBRE DE SUBTAREA:  "; 
		cin>>nombre_auxi;
 	 	int pos2=buscar_subtarea(pos,nombre_auxi);
 	 	if(buscar_nom==true)
 	 	{
 	 		almacen_datos[pos][1].nombre="";
 	 		almacen_datos[pos][pos2].dato_general="";
 	 		 do
   	  {
   	   cout<<"DIA: ";
	   cin>>dia;
	 }while(dia<=0 || dia>=32);
	 
	 do
	 {
	   	 cout<<"MES: ";
		cin>>mes;	
	 }while(mes<=0 || mes>=13);
	 
	 do
	 {
	 	cout<<"AÑO: ";
		cin>>ano;
	 }while(ano<=2000 || ano>=2050);
    
     do
     {
     	cout<<"HORA ";
		cin>>hora;
     	
     	
	 }while(hora<=0 || hora>=25);
	 
	 do
	 {
	 	cout<<"MIN: ";
		cin>>minuts;
	 }while(minuts<0 || minuts>=61);
     
     if(minuts==60)
     {
     	hora+=1;
     	minuts=0;
     	
	 }
	 if(hora>24)
	 {
	 	hora=hora-24;
	 	
	 }
	 else if(hora==24)
	 {
	 	hora=0;
	 }
 	 	
}
 	 		
 	 		DOCU.open(nom2.c_str(),ios::app);
 	 		DOCU<<"TAREA:  "<<nombre<<endl;
 	 		DOCU<<"SUBTAREA: "<<nombre_auxi<<" FECHA  "<<dia<<"/"<<mes<<"/"<<ano<<" "<<hora<<":"<<minuts<<'\n';
 	 		DOCU.close();
 	 
 	 		
 	 		cout<<"SE HA TERMINADO CORRECTAMENTE  "<<endl;
		  }
	  
	  else cout<<"NOS SE ENCUENTRA"<<endl;
	  
	 

}

void guardar_datos()
{
	DOCU.open(nombre_DOCU.c_str());
	DOCU<<contra<<endl;
	DOCU.close();
}

void leer_datos()
{
	 DOCU.open(nombre_DOCU.c_str());
	 
	 DOCU>>contra;
	  
	 
	 DOCU.close();
	
}
void taraes_terminadas(){
	cout<<endl;
    cout<<"*********TAREAS COMPLETADAS****** "<<endl;
	cout<<"**********************************"<<endl;
	DOCU.open(nom2.c_str());
	while(!DOCU.eof())
	
	{
	getline(DOCU,aux);
	cout<<aux<<endl;
	}
	DOCU.close();
}
void crear_usuario()
{
	cout << "---------------------------------------------------\n" ;
    cout << "---------********BIENVENIDO*******----------------- \n";
    cout << "****************NUEVO USUARIO**********************  \n";
    cout<<endl;
	cout<<"USUARIO:  "<<endl;
	cin>>usuario;
	nombre_usuario=usuario+".txt";
	do
   	 {
   	cout<<"NIP: "<<endl;
	cin>>contra;
	}while(contra.length()<=3);
	DOCU.open(nombre_usuario.c_str(),ios::app);
	DOCU<<contra<<endl;
	DOCU.close();
   	
}

void princi(){
	int opc;
	system("color 0a");
	system("cls");
	cout << "******************TAREAS TRELLO***********************"<<endl;
  	cout << "1-Ingresar"<<endl;
	cout << "2-Registrar usuario"<<endl;
	cout << "3-Salir"<<endl;
  	cout<<"****************************************************"<<endl;
  	cin>>opc;
	switch(opc){
	   case 1:
	   system("cls");
		return;
		break;
	   case 2:
	   system("cls");
	   crear_usuario();		
		break;
	    case 3:
	    	system("cls");
	    	cout<<"****************************************************"<<endl;
	    	cout<<"*************QUE LE VAYA BONITO :b******************"<<endl;
	    	cout<<"****************************************************"<<endl;
	    	system("pause");
		exit(0);
		
		break;
		}		
}

	void modificar_fecha()
	{
		int linea,dia,mes,ano,hora,minuts;
		cout<<"NOMBRE DE TAREA: "<<endl;
		cin>>n_tarea;
		linea=buscar_tablero(n_tarea);
		if(buscar_nom==true)
		{
			
	   do
   	  {
   	   cout<<"DIA: ";
	   cin>>dia;
	 }while(dia<=0 || dia>=32);
	 
	 do
	 {
	   	 cout<<"MES: ";
		 cin>>mes;	
	 }while(mes<=0 || mes>=13);
	 
	 do
	 {
	 	cout<<"AÑO: ";
		cin>>ano;
	 }while(ano<=2000 || ano>=2050);
    
     do
     {
     	cout<<"HORA: ";
		cin>>hora;
     	
     	
	 }while(hora<=0 || hora>=25);
	 
	 do
	 {
	 	cout<<"MIN: ";
		cin>>minuts;
	 }while(minuts<0 || minuts>=61);
     
     if(minuts==60)
     {
     	hora+=1;
     	minuts=0;
     	
	 }
	 if(hora>24)
	 {
	 	hora=hora-24;
	 	
	 }
	 else if(hora==24)
	 {
	 	hora=0;
	 }
	
  almacen_datos[linea][1].dato_fechas.dia=dia;
  almacen_datos[linea][1].dato_fechas.mes=mes;
  almacen_datos[linea][1].dato_fechas.Ano=ano;
  almacen_datos[linea][1].dato_fechas.Hora=hora;
  almacen_datos[linea][1].dato_fechas.min=minuts;
	}
}
	
 void buscar_contra()
 {
 	string auxiliar;
 	 DOCU.open(nombre_DOCU.c_str());
     DOCU>>auxiliar;  
     if(contra==auxiliar)
     {
     	busqueda=true;
	 }
	 DOCU.close();

 }

int main()
{
princi();
current_time=time(NULL);
ctime(&current_time);
strcpy(fechash, ctime(&current_time));
setlocale(LC_ALL,"spanish");		 	
system("cls");
cout<<fechash<<endl;
cout << "---------------------------------------------------\n" ;
cout << "---------********BIENVENIDO*******----------------- \n";
cout<<endl;
cout<<"USUARIO: "<<endl;
cin>>usuario;
cout<<"NIP: "<<endl;
cin>>contra;
nombre_DOCU=usuario+".txt";


   
buscar_contra();
	if(busqueda)
{
	do
{
	nom2="REGISTROS"+usuario+".txt";
	DOCU.open(nom2.c_str(),ios::app);
	DOCU.close();
	system("cls");	
	leer_datos();
	cout<<"***************** MENU PRINIPAL****************"<<endl;
	cout<<endl;
	cout<<"************TAREAS DE "<<usuario<<" **************"<<endl;
    cout<<"**********************************************"<<endl;
	cout<<  "1-AGREGAR TAREA "<<endl;
	cout<<  "2-MOSTRAR LAS TAREAS PENDIENTES "<<endl;
	cout<<  "3-TERMINAR TAREA. "<<endl;
	cout<<  "4-ELIMINAR SUBTAREAS "<<endl;
	cout<<  "5-CAMBIAR FECHA"<<endl;
	cout<<  "6-LISTA COMPLETADAS "<<endl;
	cout<<  "7-CAMBIAR USUSRIO "<<endl;
	cin>>opc;
		system("cls");
	switch(opc)
	{
		 case 1:
	 	AGREGA_NUEVA_TAREAS();
		break;
		case 2:
		tareas_pendientes();
		break;
		case 3:
		terminar_subtarea();
		break;
		case 4:
		eliminar_subtarea();	
		break;
		case 5:
		modificar_fecha();
		break;
		case 6:
		taraes_terminadas();
		break;
		case 7:
		princi();
		break;
	}
	 	system("pause");
	} while(opc!=7);	
}

else
{
	system("cls");
	cout<<endl;
cout<<"*********EL USUARIO NO SE ENCUENTRA*********** "<<endl;
}
 
	 }

