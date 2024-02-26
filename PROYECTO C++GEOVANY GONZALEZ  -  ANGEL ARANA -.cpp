//Integrantes: 6590-22-243 Angel Leonel Arana Castillo
			//	6590-22-848 Geovany Emmanuel Gonzalez Diaz


//Sección de librerias
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<windows.h>
//Para acotar la función de cout
using namespace std;
	int opcion;
	int opcionClientes;
	int contadorClientes;
	int opcionEmpleados;
	int contadorEmpleados;
	int contadorProveedores;
	int opcionProveedores;
	int opcionArticulostienda;
	int contadorArticulostienda;
	int contadorArticulosbodega;
	int opcionArticulosbodega;
	int opcionReportes;
	int contadorFacturas;
	int contadorDetalles;

struct sCliente{
	int Codigo;
	char Nit[9];
	char Nombre[50];
	char Direccion[50];
	int Edad;
	int top;
};	
//TDD NombreArreglo[tamaño]
sCliente Cliente[100];

struct sEmpleados{
	int Codigo;
	long long DPI;
	char Nombre[50];
	int Edad;
	char Puesto[50];
	int top;
};
//TDD NombreArreglo[tamaño]
sEmpleados Empleado[100];

struct sArticulos{
	int Codigo;
	char Nombre[50];
	int cantidad;
	float Punitario;
	int Codigoproveedor;
	int top; //Ordenamiento de lista.
};
//TDD NombreArreglo[tamaño]
sArticulos Articuloti[200];
sArticulos Articulobo[200];

struct sProveedores{
	int Codigo;
	char Nit[9];
	char Nombre[50];
	char Mercaderia[50];
	char Direccion[50];
	int Telefono;
	int top; //Ordenamiento de lista.
};
//TDD NombreArreglo[tamaño]
sProveedores Proveedor[100];

struct sDetalles{
	int Codigo;
	char Nombre[50];
	int cantidad;
	float precio;
	float subtotal;
};
struct sFacturas{
	char Fecha[12];
	char Hora[12];
	int Numero;
	int top; //Ordenamiento de lista.
	int Codigovendedor;
	char Nombrevendedor[50];
	int NumeroCaja;
	int Codigocliente;
	char Nit[9];
	char Nombre[50];
	char Direccion[50];
	float subtotal;
	float IVA;
	float total;
	sDetalles Detalles[100];
};
//TDD NombreArreglo[tamaño]
sFacturas Factura[100];
void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon,dwPos); 
}	
int buscarArticulotienda(char nomb[50])
{
	bool x=false;
	int i=0;
	while(i<contadorArticulostienda && x==false)
	{
		if(strcmp(Articuloti[i].Nombre,nomb)==0)
		{
			x=true;
		}else{
			i++;
		}
	}if(x==true)
	{
		return i;
	}else
	{
		return -1;
	}
}
int buscarArticulobodega(char nomb[50])
{
	bool x=false;
	int i=0;
	while(i<contadorArticulosbodega && x==false)
	{
		//Para comparar cadenas.
		if(strcmp(Articulobo[i].Nombre,nomb)==0)
		{
			x=true;
		}else{
			i++;
		}
	}if(x==true)
	{
		return i;
	}else
	{
		return -1;
	}
}
int buscarCodigopro(int codigo){
	bool x=false; //bandera: se utiliza para definir un cambio de estado
	int i=0;
	while (i<contadorProveedores && x==false)
	{
		if (Proveedor[i].Codigo==codigo)
		{
			x=true;
		}
		else
			i++;
	}
	if (x==true)
	{
		return i;
	}
	else 
		return -1;
		getch();
}
int buscarCodigoproductoti(int kodex){

	bool y=false; //bandera: se utiliza para definir un cambio de estado
	int i=0;
	while (i<contadorArticulostienda && y==false)
	{
		if (Articuloti[i].Codigo==kodex)
		{
			y=true;
		}
		else
			i++;
	}
	if (y==true)
	{
		return i;
	}
	else 
		return -1;
		getch();
}
int buscarCodigoproductobo(int kodex){

	bool y=false; //bandera: se utiliza para definir un cambio de estado
	int i=0;
	while (i<contadorArticulosbodega && y==false)
	{
		if (Articulobo[i].Codigo==kodex)
		{
			y=true;
		}
		else
			i++;
	}
	if (y==true)
	{
		return i;
	}
	else 
		return -1;
		getch();
}
void menu(){
	system("cls");
	gotoxy(50,2);cout<<"SUPERTIENDA MAS";
	for(int i=32;i<=82;i++){
	for(int j=1;j<=3;j++){
		gotoxy(i,0);cout<<"__";
		gotoxy(i,3);cout<<"__";
		gotoxy(31,j);cout<<"|";
		gotoxy(84,j);cout<<"|";		
	}}
	cout<<endl<<endl<<"1. Articulos en tienda"<<endl;
	cout<<"2. Articulos en bodega"<<endl;
	cout<<"3. Clientes"<<endl;
	cout<<"4. Facturacion"<<endl;
	cout<<"5. Proveedores"<<endl;
	cout<<"6. Empleados"<<endl;
	cout<<"7. Reportes"<<endl;
	cout<<"8. Salir"<<endl;
	cout<<"Ingrese una opcion: ";
	cin>>opcion;
}
void submenuArticulosentienda(){
	system("cls");
	gotoxy(50,2); cout<<"-ARTICULOS EN TIENDA-"<<endl<<endl;
	cout<<"1. Agregar"<<endl;
	cout<<"2. Modificar"<<endl;
	cout<<"3. Eliminar"<<endl;
	cout<<"4. Buscar"<<endl;
	cout<<"5. Abastecimiento(solicitud de mercancia)"<<endl;
	cout<<"6. Salir"<<endl;
	cout<<"Ingrese una opcion: ";
	cin>>opcionArticulostienda;	
}
void agregarArticulotienda(){
	system("cls");
	char name[50];
	//Buscar codigo de producto.
	int kodex;
	//Buscar codigo de proveedor.
	int code;
	gotoxy(50,2); cout<<"-DATOS DEL ARTICULO-"<<endl<<endl;
	cout<<"Codigo: ";
	cin>>kodex;
	int pos=buscarCodigoproductoti(kodex); //Validación de que no se encuentre un codigo repetido.
	if(pos>=0){
		cout<<"Este codigo ya fue repetido en un ingreso anterior"<<endl;
		getch();
	}
	else{
		cout<<"Nombre: ";
		cin>>name;
		int pos=buscarArticulotienda(name); //Validación de que no se encuentre un nombre repetido.
	if(pos>=0)
	{
		cout<<"Nombre repetido, ya fue ingresado anteriormente"<<endl;
		getch();			
	}else{
		cout<<"Codigo de proveedor: ";
	cin>>code;
	int pre=buscarCodigopro(code); //Encontrar codigo de proveedor.
	if(pre>=0)
	{
	strcpy; Articuloti[contadorArticulostienda].Codigo=kodex;
	strcpy(Articuloti[contadorArticulostienda].Nombre,name);
	strcpy; Articuloti[contadorArticulostienda].Codigoproveedor=code;
	cout<<"Cantidad: ";
	cin>>Articuloti[contadorArticulostienda].cantidad;
	cout<<"Precio Unitario: ";
	cin>>Articuloti[contadorArticulostienda].Punitario;
	Proveedor[pre].top=Proveedor[pre].top+1;
	contadorArticulostienda++;
	}else{
		cout<<"El articulo no esta relacionado a ningun proveedor";
		getch();
		}	
	}}
}
void trasladoArticulostienda()
{	
	int kodex;
	int num;
	system("cls");
	cout<<"Ingrese codigo del articulo: "<<endl;
	cin>>kodex;
	//Articulos en tienda
	int pos=buscarCodigoproductoti(kodex);
	//Articulos en bodega
	int pre=buscarCodigoproductobo(kodex);
	if(pos>=0 and pre>=0)
	{system("cls");
	gotoxy(50,0); cout<<"-DISPONIBILIDAD-";
	gotoxy(1,2); cout<<"Codigo:"<<endl;
	gotoxy(15,2); cout<<"Nombre:"<<endl;
	gotoxy(45,2); cout<<"Cantidad:"<<endl;
	gotoxy(65,2); cout<<"PrecioU:"<<endl;
	gotoxy(85,2); cout<<"Cod.Proveedor:"<<endl;
	gotoxy(105,2); cout<<"UBICACION"<<endl;
		gotoxy(1,4); cout<<Articuloti[pos].Codigo;
		gotoxy(15,4); cout<<Articuloti[pos].Nombre;
		gotoxy(45,4); cout<<Articuloti[pos].cantidad;
		gotoxy(65,4); cout<<Articuloti[pos].Punitario;
		gotoxy(85,4); cout<<Articuloti[pos].Codigoproveedor;
		gotoxy(105,4); cout<<"TIENDA";
		cout<<endl;
		gotoxy(1,5); cout<<Articulobo[pos].Codigo;
		gotoxy(15,5); cout<<Articulobo[pre].Nombre;
		gotoxy(45,5); cout<<Articulobo[pre].cantidad;
		gotoxy(65,5); cout<<Articulobo[pre].Punitario;
		gotoxy(85,5); cout<<Articulobo[pre].Codigoproveedor;
		gotoxy(105,5); cout<<"BODEGA"<<endl;
		cout<<"¿Cuanto desea movilizar de bodega a tienda?"<<endl;
		cin>>num;
		if(num>Articulobo[pre].cantidad)
		{
			cout<<"No existen las existencias necesarias para movilizar a tienda.";
		if(Articulobo[pre].cantidad<=0)
		{
			cout<<"Numero invalido."<<endl;
		}}else{
			Articulobo[pre].cantidad=Articulobo[pre].cantidad-num;
			Articuloti[pos].cantidad=Articuloti[pos].cantidad+num;
		}
		getch();	
	}else
	{cout<<"El articulo no hay en existencias, o no existe";
	getch();
	}
}
//Ordenamiento por seleccion
void reporteArticulosmasvendidos(){
	int opcion,i,j,y,code,codep,canti,min,precio;
		int a,b,cambio,max,d;
		char name[50];
		//ordenamiento
		system("cls");
			
			for(int d=0;d<contadorArticulostienda;d++)
			{max=d;
				for(b=d+1;b<contadorArticulostienda;b++)
				{
					if(Articuloti[b].top>Articuloti[max].top){
						max=b;
					}	
				}
				cambio=Articuloti[d].top;
				Articuloti[d].top=Articuloti[max].top;
				Articuloti[max].top=cambio;//top
				
				code=Articuloti[d].Codigo;
				Articuloti[d].Codigo=Articuloti[max].Codigo;
				Articuloti[max].Codigo=code;//codigo
				
				canti=Articuloti[d].cantidad;
				Articuloti[d].cantidad=Articuloti[max].cantidad;
				Articuloti[max].cantidad=canti;//cantidad
				
				codep=Articuloti[d].Codigoproveedor;
				Articuloti[d].Codigoproveedor=Articuloti[max].Codigoproveedor;
				Articuloti[max].Codigoproveedor=codep;//cod.proveedor
				
				precio=Articuloti[d].Punitario;
				Articuloti[d].Punitario=Articuloti[max].Punitario;
				Articuloti[max].Punitario=precio;//precio
				
				strcpy(name,Articuloti[d].Nombre);
				strcpy(Articuloti[d].Nombre,Articuloti[max].Nombre);
				strcpy(Articuloti[max].Nombre,name);//nombre
				
			}
			gotoxy(50,0); cout<<"-ARTICULOS MAS VENDIDOS-";
			gotoxy(1,2); cout<<"Codigo:"<<endl;
			gotoxy(15,2); cout<<"Nombre:"<<endl;
			gotoxy(45,2); cout<<"Cod.Proveedor:"<<endl;
			gotoxy(62,2);cout<<"Cantidades vendidas"<<endl;
			 y=3;
			 for(int c=0;c<10;c++)
			 {
			 	gotoxy(1,y); cout<<Articuloti[c].Codigo<<endl;
				gotoxy(15,y);cout<<Articuloti[c].Nombre<<endl;
				gotoxy(45,y);cout<<Articuloti[c].Codigoproveedor<<endl;
				gotoxy(65,y);cout<<Articuloti[c].top;
				cout<<endl;
				y++;
			 }
			getch();
}
void reporteArticulostienda(){
		system("cls");
	int opcion,i,j,y,code,codep,canti,min;
	float precio;
	char name[50];
	cout<<"1. Articulos ordenados por codigo"<<endl;
	
	//Ordenamiento por seleccion
		
			for(i=0;i<contadorArticulostienda;i++){
		min=i;
		for(j=i+1;j<contadorArticulostienda;j++){
			if(Articuloti[j].Codigo<Articuloti[min].Codigo)
			{
				min=j;
				}	
		}
		code=Articuloti[i].Codigo;
		Articuloti[i].Codigo=Articuloti[min].Codigo;
		Articuloti[min].Codigo=code;//codigo
		
		canti=Articuloti[i].cantidad;
		Articuloti[i].cantidad=Articuloti[min].cantidad;
		Articuloti[min].cantidad=canti;//cantidad
		
		codep=Articuloti[i].Codigoproveedor;
		Articuloti[i].Codigoproveedor=Articuloti[min].Codigoproveedor;
		Articuloti[min].Codigoproveedor=codep;//cod.proveedor
		
		precio=Articuloti[i].Punitario;
		Articuloti[i].Punitario=Articuloti[min].Punitario;
		Articuloti[min].Punitario=precio;//precio
		
		strcpy(name,Articuloti[i].Nombre);
		strcpy(Articuloti[i].Nombre,Articuloti[min].Nombre);
		strcpy(Articuloti[min].Nombre,name);//nombre
		
			}
			system("cls");
			gotoxy(50,0); cout<<"-REPORTE DE ARTICULOS EN TIENDA-";
			gotoxy(1,2); cout<<"Codigo:"<<endl;
			gotoxy(15,2); cout<<"Nombre:"<<endl;
			gotoxy(45,2); cout<<"Cantidad:"<<endl;
			gotoxy(65,2); cout<<"PrecioU:"<<endl;
			gotoxy(85,2); cout<<"Cod.Proveedor:"<<endl;
			 y=3;
			for(i=0;i<contadorArticulostienda;i++){
				gotoxy(1,y); cout<<Articuloti[i].Codigo<<endl;
				gotoxy(15,y);cout<<Articuloti[i].Nombre<<endl;
				gotoxy(45,y);cout<<Articuloti[i].cantidad<<endl;
				gotoxy(65,y);cout<<Articuloti[i].Punitario<<endl;
				gotoxy(85,y);cout<<Articuloti[i].Codigoproveedor<<endl;
				cout<<endl;
				y++;
		}
	getch();
}
void modificarArticulotienda(){
	system("cls");
	char name[50];
	int code;
	int kodex;
	cout<<"MODIFICAR DATOS"<<endl;
	cout<<"Ingrese codigo"<<endl;
	cin>>kodex;
	int pos3=buscarCodigoproductoti(kodex);
	if(pos3>=0)
	{	system("cls");
		cout<<"Cod.Proveedor"<<endl;
		cin>>code;
		int pos2=buscarCodigopro(code);
		if (pos2>=0){
			strcpy; Articuloti[pos2].Codigoproveedor;
			cout<<"Codigo:"<<endl;
			cin>>Articuloti[pos2].Codigo;
			cout<<"Nombre: "<<endl;
			cin>>Articuloti[pos2].Nombre;
			cout<<"Cantidad:"<<endl;
			cin>>Articuloti[pos2].cantidad;
			cout<<"PrecioU:"<<endl;
			cin>>Articuloti[pos2].Punitario;
		}else{
			cout<<"Codigo de proveedor no exixte, por lo tanto no se puede agregar el articulo.";
			getch();
		}
	}
	else{
		cout<<"El articulo no existe"<<endl;
		getch();
	}	
}
void eliminarArticulotienda()
{
	system("cls");
	int kodex;
	cout<<"ELIMINAR DATOS";
	cout<<"Ingrese Codigo: "<<endl;
	cin>>kodex;
	int pos=buscarCodigoproductoti(kodex);
	if(pos>=0)
	{	for(int i=pos;i<contadorArticulostienda;i++)
	{
		Articuloti[i]=Articuloti[i+1];
		
	}cout<<"DATOS ELIMINADOS DEL INVENTARIO"<<endl;
		
			contadorArticulostienda--;
	}else{
		cout<<"El nombre no existe"<<endl;
	}	
	getch();
}
void buscarArticulotienda(){
	int kodex;
	system("cls");
	gotoxy(50,2); cout<<"-BUSQUEDA DE ARTICULOS EN TIENDA-"<<endl<<endl;
	cout<<"Codigo: ";
	cin>>kodex;
	int pos=buscarCodigoproductoti(kodex);
	if (pos>=0)
	{
		gotoxy(1,6); cout<<"Codigo:"<<endl;
		gotoxy(15,6); cout<<"Nombre:"<<endl;
		gotoxy(45,6); cout<<"Cantidad:"<<endl;
		gotoxy(65,6); cout<<"PrecioU:"<<endl;
		gotoxy(85,6); cout<<"Cod.Proveedor:"<<endl;
		gotoxy(1,7); cout<<Articuloti[pos].Codigo;
		gotoxy(15,7); cout<<Articuloti[pos].Nombre;
		gotoxy(45,7); cout<<Articuloti[pos].cantidad;
		gotoxy(65,7); cout<<Articuloti[pos].Punitario;
		gotoxy(85,7); cout<<Articuloti[pos].Codigoproveedor;
	}
	else 
		cout<<"El codigo no existe!!!";	
		getch();
}
void submenuArticulosenbodega(){
	system("cls");
	gotoxy(50,2); cout<<"-ARTICULOS EN BODEGA-"<<endl<<endl;
	cout<<"1. Agregar"<<endl;
	cout<<"2. Modificar"<<endl;
	cout<<"3. Eliminar"<<endl;
	cout<<"4. Buscar"<<endl;
	cout<<"5. Abastecimiento(solicitud de mercancia)"<<endl;
	cout<<"6. Salir"<<endl;
	cout<<"Ingrese una opcion: ";
	cin>>opcionArticulosbodega;	
}
void agregarArticulobodega(){
	system("cls");
	char name[50];
	int kodex;
	gotoxy(50,2); cout<<"-DATOS DEL ARTICULO-"<<endl<<endl;
	cout<<"Codigo: ";
	cin>>kodex;
	int pos=buscarCodigoproductobo(kodex);
	if(pos>=0){
		cout<<"Este codigo ya fue repetido en un ingreso anterior"<<endl;
		getch();
	}
	else{
		cout<<"Nombre: ";
		cin>>name;
		int pos=buscarArticulobodega(name);
	if(pos>=0)
	{
		cout<<"Nombre repetido, ya fue ingresado anteriormente"<<endl;
		getch();			
	}else{
		cout<<"Codigo de proveedor: ";
	cin>>kodex;
	int pre=buscarCodigopro(kodex);
	if(pre>=0)
	{
	strcpy; Articulobo[contadorArticulostienda].Codigo=kodex;
	strcpy(Articulobo[contadorArticulostienda].Nombre,name);
	strcpy; Articulobo[contadorArticulostienda].Codigoproveedor=kodex;
	cout<<"Cantidad: ";
	cin>>Articulobo[contadorArticulostienda].cantidad;
	cout<<"Precio Unitario: ";
	cin>>Articulobo[contadorArticulostienda].Punitario;
	contadorArticulostienda++;
	}else{
		cout<<"El articulo no esta relacionado a ningun proveedor";
		getch();
		}	
	}}
}
void trasladoArticulosbodega()
{	
	int kodex;
	int num;
	system("cls");
	cout<<"Ingrese codigo del articulo: "<<endl;
	cin>>kodex;
	//Articulos en bodega
	int pos=buscarCodigoproductobo(kodex);
	//Articulos en tienda
	int pre=buscarCodigoproductoti(kodex);
	if(pos>=0 and pre>=0)
	{system("cls");
	gotoxy(50,0); cout<<"-DISPONIBILIDAD-";
	gotoxy(1,2); cout<<"Codigo:"<<endl;
	gotoxy(15,2); cout<<"Nombre:"<<endl;
	gotoxy(45,2); cout<<"Cantidad:"<<endl;
	gotoxy(65,2); cout<<"PrecioU:"<<endl;
	gotoxy(85,2); cout<<"Cod.Proveedor:"<<endl;
	gotoxy(105,2); cout<<"UBICACION"<<endl;
		gotoxy(1,4); cout<<Articulobo[pos].Codigo;
		gotoxy(15,4); cout<<Articulobo[pre].Nombre;
		gotoxy(45,4); cout<<Articulobo[pre].cantidad;
		gotoxy(65,4); cout<<Articulobo[pre].Punitario;
		gotoxy(85,4); cout<<Articulobo[pre].Codigoproveedor;
		gotoxy(105,4); cout<<"BODEGA"<<endl;
		gotoxy(1,5); cout<<Articuloti[pos].Codigo;
		gotoxy(15,5); cout<<Articuloti[pos].Nombre;
		gotoxy(45,5); cout<<Articuloti[pos].cantidad;
		gotoxy(65,5); cout<<Articuloti[pos].Punitario;
		gotoxy(85,5); cout<<Articuloti[pos].Codigoproveedor;
		gotoxy(105,5); cout<<"TIENDA";
		cout<<endl;
		cout<<"¿Cuanto desea movilizar de tienda a bodega?"<<endl;
		cin>>num;
		if(num>Articuloti[pre].cantidad)
		{
			cout<<"No existen las existencias necesarias para movilizar a bodega.";
		if(Articulobo[pre].cantidad<=0)
		{
			cout<<"Numero invalido."<<endl;
		}}else{
			Articuloti[pos].cantidad=Articuloti[pos].cantidad-num;
			Articulobo[pre].cantidad=Articulobo[pre].cantidad+num;
		}
		getch();	
	}else
	{cout<<"El articulo no hay en existencias, o no existe";
	getch();
	}
}
void modificarArticulobodega()
{
	system("cls");
	char name[50];
	int code;
	int kodex;
	cout<<"MODIFICAR DATOS"<<endl;
	cout<<"Ingrese codigo"<<endl;
	cin>>kodex;
	int pos3=buscarCodigoproductobo(kodex);
	if(pos3>=0)
	{	system("cls");
		cout<<"Cod.Proveedor"<<endl;
		cin>>code;
		int pos2=buscarCodigopro(code);
		if (pos2>=0){
			strcpy; Articulobo[pos2].Codigoproveedor;
			cout<<"Codigo:"<<endl;
			cin>>Articulobo[pos2].Codigo;
			cout<<"Nombre: "<<endl;
			cin>>Articulobo[pos2].Nombre;
			cout<<"Cantidad:"<<endl;
			cin>>Articulobo[pos2].cantidad;
			cout<<"PrecioU:"<<endl;
			cin>>Articulobo[pos2].Punitario;
		}else{
			cout<<"Codigo de proveedor no exixte, por lo tanto no se puede agregar el articulo.";
			getch();
		}
	}
	else{
		cout<<"El articulo no existe"<<endl;
		getch();
	}	
}
void eliminarArticulobodega()
{
	system("cls");
	int kodex;
	cout<<"ELIMINAR DATOS";
	cout<<"Ingrese codigo: ";
	cin>>kodex;
	int pos=buscarCodigoproductobo(kodex);
	if(pos>=0)
	{	for(int i=pos;i<contadorArticulosbodega;i++)
	{
		Articulobo[i]=Articulobo[i+1];
		
	}cout<<"DATOS ELIMINADOS DEL INVENTARIO"<<endl;
		
			contadorArticulosbodega--;
	}else{
		cout<<"El articulo no existe"<<endl;
	}	
	getch();
}
//Ordenamiento por seleccion
void reporteArticulosbodega(){
	
	int i,j,aux,min;
	int code,canti,codep,precio;
	char name[50];
	//Primer for para recorrer codigos.
	for(i=0;i<contadorArticulosbodega;i++){
		min=i;
		for(j=i+1;j<contadorArticulosbodega;j++){
			if(Articulobo[j].Codigo<Articulobo[min].Codigo)
			{
				min=j;
				}	
		}
		code=Articulobo[i].Codigo;
		Articulobo[i].Codigo=Articulobo[min].Codigo;
		Articulobo[min].Codigo=code;//
		
		canti=Articulobo[i].cantidad;
		Articulobo[i].cantidad=Articulobo[min].cantidad;
		Articulobo[min].cantidad=canti;//
		
		codep=Articulobo[i].Codigoproveedor;
		Articulobo[i].Codigoproveedor=Articuloti[min].Codigoproveedor;
		Articulobo[min].Codigoproveedor=codep;//
		
		precio=Articulobo[i].Punitario;
		Articulobo[i].Punitario=Articulobo[min].Punitario;
		Articulobo[min].Punitario=precio;//
		
		strcpy(name,Articulobo[i].Nombre);
		strcpy(Articulobo[i].Nombre,Articulobo[min].Nombre);
		strcpy(Articulobo[min].Nombre,name);
		
	}
	system("cls");
	gotoxy(50,0); cout<<"-REPORTE DE ARTICULOS EN BODEGA-";
	gotoxy(1,2); cout<<"Codigo:"<<endl;
	gotoxy(15,2); cout<<"Nombre:"<<endl;
	gotoxy(45,2); cout<<"Cantidad:"<<endl;
	gotoxy(65,2); cout<<"PrecioU:"<<endl;
	gotoxy(85,2); cout<<"Cod.Proveedor:"<<endl;
	int y=3;
	for(i=0;i<contadorArticulosbodega;i++){
		gotoxy(1,y); cout<<Articulobo[i].Codigo<<endl;
		gotoxy(15,y);cout<<Articulobo[i].Nombre<<endl;
		gotoxy(45,y);cout<<Articulobo[i].cantidad<<endl;
		gotoxy(65,y);cout<<Articulobo[i].Punitario<<endl;
		gotoxy(85,y);cout<<Articulobo[i].Codigoproveedor<<endl;
		cout<<endl;
		y++;
	}
	getch();
}

void buscarArticulobodega(){
	int kodex;
	system("cls");
	gotoxy(50,2); cout<<"-BUSQUEDA DE ARTICULOS EN BODEGA-"<<endl<<endl;
	cout<<"Codigo: ";
	cin>>kodex;
	int pos=buscarCodigoproductobo(kodex);
	if (pos>=0)
	{
		gotoxy(1,6); cout<<"Codigo:"<<endl;
		gotoxy(15,6); cout<<"Nombre:"<<endl;
		gotoxy(45,6); cout<<"Cantidad:"<<endl;
		gotoxy(65,6); cout<<"PrecioU:"<<endl;
		gotoxy(85,6); cout<<"C/proveedor:"<<endl;
		gotoxy(1,7); cout<<Articulobo[pos].Codigo;
		gotoxy(15,7); cout<<Articulobo[pos].Nombre;
		gotoxy(45,7); cout<<Articulobo[pos].cantidad;
		gotoxy(65,7); cout<<Articulobo[pos].Punitario;
		gotoxy(85,7); cout<<Articulobo[pos].Codigoproveedor;
	}
	else 
		cout<<"El articulo no existe!!!";
		
		getch();
}
void submenuClientes(){
	system("cls");
	gotoxy(50,2); cout<<"-CLIENTES-"<<endl<<endl;
	cout<<"1. Agregar"<<endl;
	cout<<"2. Modificar"<<endl;
	cout<<"3. Eliminar"<<endl;
	cout<<"4. Buscar"<<endl;
	cout<<"5. Salir"<<endl;
	cout<<"Ingrese una opcion: ";
	cin>>opcionClientes;
}
int buscarNitcliente(char Nit[9])
{
	bool encontrado=false; //bandera: se utiliza para definir un cambio de estado
	int i=0;
	while (i<contadorClientes && encontrado==false)
	{
		if (strcmp(Cliente[i].Nit,Nit)==0)
		{
			encontrado=true;
		}
		else
			i++;
	}
	if (encontrado==true)
	{
		return i;
	}
	else
	{
		return -1;
	}
}
int buscarCodigocliente(int kodex){

	bool y=false; //bandera: se utiliza para definir un cambio de estado
	int i=0;
	while (i<contadorClientes && y==false)
	{
		if (Cliente[i].Codigo==kodex)
		{
			y=true;
		}
		else
			i++;
	}
	if (y==true)
	{
		return i;
	}
	else 
		return -1;
		getch();
}
void agregarCliente(){
	int kodex;
	char nit[9];
	system("cls");
	gotoxy(50,2); cout<<"-AGREGAR CLIENTE-"<<endl<<endl;
	cout<<"NUEVO CLIENTE:"<<endl;
	cout<<"Ingrese codigo: ";
	cin>>kodex;
	int posCodigo=buscarCodigocliente(kodex);
	if(posCodigo>=0)
	{
		cout<<"Codigo ya existente en la base de datos.";
		getch();
	}
	else{
	cout<<"Ingrese NIT: ";
	cin>>nit;
	int pos=buscarNitcliente(nit);
	if(pos>=0)
	{	
		cout<<"NIT ya existente en la base de datos.";
		getch();
	}
	else{
		strcpy; Cliente[contadorClientes].Codigo=kodex;
		strcpy(Cliente[contadorClientes].Nit,nit);
		cout<<"Nombre: ";
		cin>>Cliente[contadorClientes].Nombre;
		cout<<"Direccion: ";
		cin>>Cliente[contadorClientes].Direccion;
		cout<<"Edad: ";
		cin>>Cliente[contadorClientes].Edad;
		contadorClientes++;
		getch();
	}
	}
}	
void reporteClientes(){
	system("cls");
	 int y=3;
	 	int opcion,e,codigo,top;
	 		int i,j,aux,min;
	
	char nombre[50];
	char direccion[50];
	int edad;
	int a,b,max,d;
		char name[50],nit[14];
cout<<"Seleccione la opcion de orden:"<<endl;
cout<<"1. Clientes - Por codigo"<<endl;
cout<<"2. Clientes que mas articulos compran"<<endl;
cin>>opcion;
switch(opcion)
{	
	case 1: 
	//Ordenamiento por seleccion.
	//i,j=inicializadores, aux=auxiliar, min=numero minimo

	//Primer for se repite hasta que sea menor a la cantidad de elementos en el contadorClientes.
	for(i=0;i<contadorClientes;i++){
	//Se va a suponer que la primera posicion en i es el numero minimmo.
		min=i;
		//Recorrer el arreglo a fondo, posicion i+1
		for(j=i+1;j<contadorClientes;j++){
			//Condicional si el codigo en la posicion j es menor a codigo en posicion min.
			//Codigo[j] es donde vamos, Codigo[min] es el numero menor que delimitados.
			//Esto va a verificar si es veridico.
			if(Cliente[j].Codigo<Cliente[min].Codigo){
				//Encuentra el numero mas pequeño del arreglo.
				min=j;	
			}
		}
		//Intercambios correspondientes.
		aux=Cliente[i].Codigo;
		Cliente[i].Codigo=Cliente[min].Codigo;
		Cliente[min].Codigo=aux;
		
		strcpy(nit,Cliente[i].Nit);
		strcpy(Cliente[i].Nit,Cliente[min].Nit);
		strcpy(Cliente[min].Nit,nit);//NIT
		
		strcpy(nombre,Cliente[i].Nombre);
		strcpy(Cliente[i].Nombre,Cliente[min].Nombre);
		strcpy(Cliente[min].Nombre,nombre);//Nombre
		
		strcpy(direccion,Cliente[i].Direccion);
		strcpy(Cliente[i].Direccion,Cliente[min].Direccion);
		strcpy(Cliente[min].Direccion,direccion);//Direccion
		
		edad=Cliente[i].Edad;
		Cliente[i].Edad=Cliente[min].Edad;
		Cliente[min].Edad=edad;//Edad
		
		
	}
	system("cls");	 
	gotoxy(35,0); cout<<"REPORTE DE CLIENTES.";
	gotoxy(5,2); cout<<"Codigo:"<<endl;
	gotoxy(20,2); cout<<"NIT:"<<endl;
	gotoxy(45,2); cout<<"Nombre:"<<endl;
	gotoxy(70,2); cout<<"Direccion:"<<endl;
	gotoxy(100,2); cout<<"Edad:"<<endl;
	;
	for(int i=0;i<contadorClientes;i++){
		gotoxy(5,y); cout<<Cliente[i].Codigo;
		gotoxy(20,y); cout<<Cliente[i].Nit;
		gotoxy(45,y); cout<<Cliente[i].Nombre;
		gotoxy(70,y); cout<<Cliente[i].Direccion;
		gotoxy(100,y); cout<<Cliente[i].Edad;
		y++;
	}
	break;
	case 2:	
		//ordenamiento
		system("cls");
			
			for(int d=0;d<contadorClientes;d++)
			{max=d;
				for(b=d+1;b<contadorClientes;b++)
				{
					if(Cliente[b].top>Cliente[max].top){
						max=b;
					}	
				}
				top=Cliente[d].top;
				Cliente[d].top=Cliente[max].top;
				Cliente[max].top=top;//top
				
				codigo=Cliente[d].Codigo;
				Cliente[d].Codigo=Cliente[max].Codigo;
				Cliente[max].Codigo=codigo;//codigo
				
				strcpy(name,Cliente[d].Nombre);
				strcpy(Cliente[d].Nombre,Cliente[max].Nombre);
				strcpy(Cliente[max].Nombre,name);//nombre
				
				strcpy(nit,Cliente[d].Nit);
				strcpy(Cliente[d].Nit,Cliente[max].Nit);
				strcpy(Cliente[max].Nit,nit);//nit
				
				
			}
			gotoxy(50,0); cout<<"-REPORTE DE CLIENTES CON MAYOR INFLUENCIA DE COMPRAS-";
			gotoxy(1,2); cout<<"CODIGO:"<<endl;
			gotoxy(18,2); cout<<"Nombre:"<<endl;
			gotoxy(32,2); cout<<"NIT:"<<endl;
			gotoxy(49,2);cout<<"ARTICULOS COMPRADOS:"<<endl;
			 e=3;
			 for(int c=0;c<contadorClientes-1;c++)
			 {
			 	gotoxy(1,e); cout<<Cliente[c].Codigo<<endl;
				gotoxy(18,e);cout<<Cliente[c].Nombre<<endl;
				gotoxy(32,e);cout<<Cliente[c].Nit<<endl;
				gotoxy(54,e);cout<<Cliente[c].top;
				cout<<endl;
				e++;
			 }
	break;
}

			getch();

}
void buscarCliente()
{
	char nit[9];
	system("cls");
	gotoxy(35,0); cout<<"-BUSQUEDA DE CLIENTES-"<<endl<<endl;
	cout<<"NIT: ";
	cin>>nit;
	int pos=buscarNitcliente(nit);
	if(pos>=0)
	{
		gotoxy(5,5); cout<<"Codigo:"<<endl;
		gotoxy(20,5); cout<<"NIT:"<<endl;
		gotoxy(45,5); cout<<"Nombre:"<<endl;
		gotoxy(70,5); cout<<"Direccion:"<<endl;
		gotoxy(100,5); cout<<"Edad:"<<endl;
		gotoxy(5,6); cout<<Cliente[pos].Codigo;
		gotoxy(20,6); cout<<Cliente[pos].Nit;
		gotoxy(45,6); cout<<Cliente[pos].Nombre;
		gotoxy(70,6); cout<<Cliente[pos].Direccion;
		gotoxy(100,6); cout<<Cliente[pos].Edad;
	}
	else{cout<<"El cliente no existe en la base de datos!!!";
	}
		
	getche();
}
void modificarCliente(){
	char nit[9];
	system("cls");
	gotoxy(35,0); cout<<"-MODIFICACION DE CLIENTES-"<<endl<<endl;
	cout<<"Ingrese NIT: ";
	cin>>nit;
	int pos=buscarNitcliente(nit);
	if(pos>=0){
		cout<<"INGRESE LOS NUEVOS DATOS: "<<endl<<endl;
		cout<<"Codigo: ";
		cin>>Cliente[pos].Codigo;
		cout<<"NIT: ";
		cin>>Cliente[pos].Nit;
		cout<<"Nombre: ";
		cin>>Cliente[pos].Nombre;
		cout<<"Direccion: ";
		cin>>Cliente[pos].Direccion;
		cout<<"Edad: ";
		cin>>Cliente[pos].Edad;
		cout<<endl<<"DATOS MODIFICADOS EXITOSAMENTE!!!";
		getch();
	}
	else
		cout<<"El cliente no existe en la base de datos!!!";
		getche();
}	
void eliminarCliente(){
	char nit[9];
	system("cls");
	gotoxy(35,0); cout<<"-ELIMINACION DE CLIENTES-"<<endl<<endl;
	cout<<"NIT: ";
	cin>>nit;
	int pos=buscarNitcliente(nit);
	if(pos>=0){
		for(int i=pos; i<contadorClientes; i++){
			Cliente[i]=Cliente[i+1];
		}
		contadorClientes--;
		cout<<endl<<"ClIENTE ELIMINADO EXITOSAMENTE";
	}
	else
		cout<<"El cliente no existe en la base de datos!!!";
		getch();
}
void submenuEmpleados(){
	system("cls");
	gotoxy(50,2); cout<<"-EMPLEADOS-"<<endl<<endl;
	cout<<"1. Agregar"<<endl;
	cout<<"2. Modificar"<<endl;
	cout<<"3. Eliminar"<<endl;
	cout<<"4. Buscar"<<endl;
	cout<<"5. Salir"<<endl;
	cout<<"Ingrese una opcion: ";
	cin>>opcionEmpleados;
}
//Buscar empleado por DPI
int buscarEmpleado(long long dpi){
	bool x=false; //bandera: se utiliza para definir un cambio de estado
	int i=0;
	while (i<contadorEmpleados && x==false)
	{
		if (Empleado[i].DPI==dpi)
		{
			x=true;
		}
		else
			i++;
	}
	if (x==true)
	{
		return i;
	}
	else {
		return -1;
	}
//Buscar empleado por codigo.
}
int buscarCodigo(int Cod){
	bool A=false; //bandera: se utiliza para definir un cambio de estado
	int x=0;
	while(x<contadorEmpleados && A==false)
	{
		if(Empleado[x].Codigo==Cod)
		{
			A=true;
		}
		else
			x++;
	}
	if (A==true)
	{
		return x;
	}
	else{
		return -1;
	}
}
void agregarEmpleado(){
	long long DPI;
	int codigo;
	system("cls");
	gotoxy(50,2); cout<<"-AGREGAR EMPLEADO-"<<endl<<endl;
	cout<<"NUEVO EMPLEADO:"<<endl;
	cout<<"Ingrese codigo: ";
	cin>>codigo;
	int posCodigo=buscarCodigo(codigo);
	if(posCodigo>=0)
	{
		cout<<"Codigo ya existente";
		getch();
	}
	else{
	cout<<"Ingrese DPI: ";
	cin>>DPI;
	int pos=buscarEmpleado(DPI);
	if(pos>=0)
	{	
		cout<<"DPI ya existente";
		getch();
	}
	else{
		strcpy; Empleado[contadorEmpleados].Codigo=codigo;
		strcpy; Empleado[contadorEmpleados].DPI=DPI;
		cout<<"Nombre: ";
		cin>>Empleado[contadorEmpleados].Nombre;
		cout<<"Puesto: ";
		cin>>Empleado[contadorEmpleados].Puesto;
		cout<<"Edad: ";
		cin>>Empleado[contadorEmpleados].Edad;
		contadorEmpleados++;
		getch();
	}
	}
}
void reporteEmpleados(){	
	system("cls");
	int i,j,min,top,max;
	long long DPI;
	char nombre[50];
	char puesto[50];
	int edad,code;	int y=3;
	cout<<"Seleccione forma de listado:"<<endl;
	cout<<"1. Empleados - por codigo"<<endl;
	cout<<"2. Empleados con mas articulos vendidos"<<endl;
	cin>>opcion;
	switch(opcion)
	{
		case 1:
		for(i=0;i<contadorEmpleados;i++){
		min=i;
		for(j=i+1;j<contadorEmpleados;j++){
			if(Empleado[j].Codigo<Empleado[min].Codigo){
				min=j;
			}	
		}
		code=Empleado[i].Codigo;
		Empleado[i].Codigo=Empleado[min].Codigo;
		Empleado[min].Codigo=code; //Codigo
		
		DPI=Empleado[i].DPI;
		Empleado[i].DPI=Empleado[min].DPI;
		Empleado[min].DPI=DPI; //DPI
		
		strcpy(nombre,Empleado[i].Nombre);
		strcpy(Empleado[i].Nombre,Empleado[min].Nombre);
		strcpy(Empleado[min].Nombre,nombre); //Nombre
		
		strcpy(puesto,Empleado[i].Puesto);
		strcpy(Empleado[i].Puesto,Empleado[min].Puesto);
		strcpy(Empleado[min].Puesto,puesto); //Puesto
		
		edad=Empleado[i].Edad;
		Empleado[i].Edad=Empleado[min].Edad;
		Empleado[min].Edad=edad; //Edad
		
		top=Empleado[i].top;
		Empleado[i].top=Empleado[min].top;
		Empleado[min].top=top; //Edad
		
	}
	system("cls");
	gotoxy(50,0); cout<<"-REPORTE DE EMPLEADOS-";
	gotoxy(5,2); cout<<"Codigo:"<<endl;
	gotoxy(20,2); cout<<"DPI:"<<endl;
	gotoxy(45,2); cout<<"Nombre:"<<endl;
	gotoxy(70,2); cout<<"Puesto:"<<endl;
	gotoxy(100,2); cout<<"Edad:"<<endl;

	for(i=0;i<contadorEmpleados;i++){
		gotoxy(5,y); cout<<Empleado[i].Codigo;
		gotoxy(20,y); cout<<Empleado[i].DPI;
		gotoxy(45,y); cout<<Empleado[i].Nombre;
		gotoxy(70,y); cout<<Empleado[i].Puesto;
		gotoxy(100,y); cout<<Empleado[i].Edad;
		y++;
	}
		break;
		case 2:
			for(i=0;i<contadorEmpleados;i++){
		max=i;
		for(j=i+1;j<contadorEmpleados;j++){
			if(Empleado[j].top>Empleado[max].top){
				max=j;
			}	
		}
		code=Empleado[i].Codigo;
		Empleado[i].Codigo=Empleado[max].Codigo;
		Empleado[max].Codigo=code; //Codigo
		
		DPI=Empleado[i].DPI;
		Empleado[i].DPI=Empleado[max].DPI;
		Empleado[max].DPI=DPI; //DPI
		
		strcpy(nombre,Empleado[i].Nombre);
		strcpy(Empleado[i].Nombre,Empleado[max].Nombre);
		strcpy(Empleado[max].Nombre,nombre); //Nombre
		
		strcpy(puesto,Empleado[i].Puesto);
		strcpy(Empleado[i].Puesto,Empleado[max].Puesto);
		strcpy(Empleado[max].Puesto,puesto); //Puesto
		
		edad=Empleado[i].Edad;
		Empleado[i].Edad=Empleado[max].Edad;
		Empleado[max].Edad=edad; //Edad
		
		top=Empleado[i].top;
		Empleado[i].top=Empleado[max].top;
		Empleado[max].top=top; //Edad
		
	}
	system("cls");
	gotoxy(50,0); cout<<"-REPORTE DE EMPLEADOS-";
	gotoxy(5,2); cout<<"Codigo:"<<endl;
	gotoxy(20,2); cout<<"DPI:"<<endl;
	gotoxy(45,2); cout<<"Nombre:"<<endl;
	gotoxy(70,2); cout<<"Puesto:"<<endl;
	gotoxy(100,2); cout<<"Articulos vendidos:"<<endl;

	for(i=0;i<contadorEmpleados;i++){
		gotoxy(5,y); cout<<Empleado[i].Codigo;
		gotoxy(20,y); cout<<Empleado[i].DPI;
		gotoxy(45,y); cout<<Empleado[i].Nombre;
		gotoxy(70,y); cout<<Empleado[i].Puesto;
		gotoxy(100,y); cout<<Empleado[i].top;
		y++;
	}
		break;
		
	}
	
	getch();
}
void buscarEmpleado(){
	system("cls");
	int Codigo;
	gotoxy(50,0); cout<<"-BUSQUEDA DE EMPLEADOS-"<<endl<<endl;
	cout<<"Ingrese codigo: ";
	cin>>Codigo;
	int posCodigo=buscarCodigo(Codigo);
	if(posCodigo>=0){
		gotoxy(5,4); cout<<"Codigo:";
		gotoxy(20,4); cout<<"DPI:";
		gotoxy(45,4); cout<<"Nombre:";
		gotoxy(70,4); cout<<"Puesto:";
		gotoxy(100,4); cout<<"Edad:";
		gotoxy(5,5); cout<<Empleado[posCodigo].Codigo;
		gotoxy(20,5); cout<<Empleado[posCodigo].DPI;
		gotoxy(45,5); cout<<Empleado[posCodigo].Nombre;
		gotoxy(70,5); cout<<Empleado[posCodigo].Puesto;	
		gotoxy(100,5); cout<<Empleado[posCodigo].Edad;
		getch();
	}
	else{
		cout<<"El empleado no existe en la base de datos!!!";	
		getch();
	}	
}
void modificarEmpleado(){
	int Codigo;
	long long DPI;
	system("cls");
	gotoxy(50,0); cout<<"-MODIFICAR EMPLEADOS-"<<endl<<endl;
	cout<<"Ingrese codigo: ";
	cin>>Codigo;
	int posCodigo=buscarCodigo(Codigo);
	if(posCodigo>=0){
		cout<<"INGRESE LOS NUEVOS DATOS: "<<endl<<endl;
		cout<<"Codigo: ";
		cin>>Empleado[posCodigo].Codigo;
		cout<<"DPI: ";
		int pos=buscarEmpleado(DPI);
		if(pos>=0){
			cout<<"DPI ya ingresado en esta base de datos!!!";
			getch();
		}
		else{
			cin>>Empleado[posCodigo].DPI;
			cout<<"Nombre: ";
			cin>>Empleado[posCodigo].Nombre;
			cout<<"Puesto: ";
			cin>>Empleado[posCodigo].Puesto;
			cout<<"Edad: ";
			cin>>Empleado[posCodigo].Edad;
			cout<<endl<<"Datos modificados con exito!!!";
			getch();
		}
	}
	else{
		cout<<"El empleado no existe en la base de datos!!!";
		getch();
	}
}
void eliminarEmpleado(){
	int Codigo;
	system("cls");
	gotoxy(50,0); cout<<"-ELIMINAR EMPLEADOS-"<<endl<<endl;
	cout<<"Codigo: ";
	cin>>Codigo;
	int pos=buscarCodigo(Codigo);
	if(pos>=0)
	{
		for(int i=pos; i<contadorEmpleados; i++){
			Empleado[i]=Empleado[i+1];
		}
		contadorEmpleados--;
		cout<<endl<<"Empleado eliminado con exito";
		getch();
	}
	else{
		cout<<"El empleado no existe!!!";
		getch();	
	}
}

int buscarproveedor(char name[50]){
	bool encontrado=false; //bandera: se utiliza para definir un cambio de estado
	int i=0;
	while (i<contadorProveedores && encontrado==false)
	{
		if (strcmp(Proveedor[i].Nombre,name)==0)
		{
			encontrado=true;
		}
		else
			i++;
	}
	if (encontrado==true)
	{
		return i;
	}
	else 
		return -1;
		
		getch();
}
int buscarNitproveedor(char Nit[9])
{
	bool encontrado=false; //bandera: se utiliza para definir un cambio de estado
	int i=0;
	while (i<contadorProveedores && encontrado==false)
	{
		if (strcmp(Proveedor[i].Nit,Nit)==0)
		{
			encontrado=true;
		}
		else
			i++;
	}
	if (encontrado==true)
	{
		return i;
	}
	else
	{
		return -1;
	}
}

void submenuProveedores(){
	system("cls");
	gotoxy(50,2); cout<<"-PROVEEDORES-"<<endl;
	cout<<"1. Agregar"<<endl;
	cout<<"2. Modificar"<<endl;
	cout<<"3. Eliminar"<<endl;
	cout<<"4. Buscar"<<endl;
	cout<<"5. Salir"<<endl;
	cout<<"Ingrese una opcion: ";
	cin>>opcionProveedores;
}
void agregarProveedor(){
	system("cls");
	bool buscar=false;
	char name[50];
	int code;
	char nit[9];
	gotoxy(50,2); cout<<"-DATOS DEL PROVEEDOR-"<<endl<<endl;
	cout<<"Ingrese Codigo: ";
	cin>>code;
	int i=0;
	int posCodigo=buscarCodigopro(code);
	if(posCodigo>=0)
	{
		cout<<"Este codigo de proveedor ya fue repetido en un ingreso anterior"<<endl;
		getch();
		}
	else{
		cout<<"Nombre: ";
		cin>>name;
		int pos=buscarproveedor(name);
	if(pos>=0)
	{
		cout<<"Nombre repetido, ya fue ingresado anteriormente"<<endl;
		getch();			
	}else
	{
	cout<<"NIT: ";
	cin>>nit;
	int posNIT=buscarNitproveedor(nit);
	if(posNIT>=0){
		cout<<"NIT ya registrado en la base de datos.";
		getch();
	}
	else{
		strcpy; Proveedor[contadorProveedores].Codigo=code;
		strcpy(Proveedor[contadorProveedores].Nombre,name);
		strcpy(Proveedor[contadorProveedores].Nit,nit);
		cout<<"Mercaderia o servicio: ";
		cin>>Proveedor[contadorProveedores].Mercaderia;
		cout<<"Direccion: ";
		cin>>Proveedor[contadorProveedores].Direccion;
		cout<<"Telefono: ";
		cin>>Proveedor[contadorProveedores].Telefono;
		cout<<"Proveedor agregado exitosamente.";
		contadorProveedores++;	
		getch();
	}

	}	
	}			
}
void modificarProveedor()
{
	int kodex;
	system("cls");
	gotoxy(50,0); cout<<"-MODIFICAR PROVEEDOR-"<<endl<<endl;
	cout<<"Ingrese Codigo: ";
	cin>>kodex;
	int pos=buscarCodigopro(kodex);
	if(pos>=0)
	{
	cout<<"CODIGO: ";
	cin>>Proveedor[pos].Codigo;
	cout<<"NOMBRE: ";
	cin>>Proveedor[pos].Nombre;
	cout<<"NIT: ";
	cin>>Proveedor[pos].Nit;
	cout<<"Mercaderia o servicio: ";
	cin>>Proveedor[pos].Mercaderia;
	cout<<"Direccion: ";
	cin>>Proveedor[pos].Direccion;
	cout<<"Telefono: ";
	cin>>Proveedor[pos].Telefono;
	}
	else{
		cout<<"El proveedor no existe!!!";
		getch();	
	}
}
void eliminarProveedor(){
	int kodex;
	system("cls");
	gotoxy(50,0); cout<<"-ELIMINAR PROVEEDOR-"<<endl<<endl;
	cout<<"Codigo: ";
	cin>>kodex;
	int pos=buscarCodigopro(kodex);
	if(pos>=0)
	{
		for(int i=pos; i<contadorProveedores; i++){
			Proveedor[i]=Proveedor[i+1];
		}
		contadorProveedores--;
		cout<<endl<<"Proveedor eliminado con exito";
		getch();
	}
	else{
		cout<<"El Proveedor no existe!!!";
		getch();	
	}
}
void reporteProveedores(){
	system("cls");
	int i,j,min,max,top,opcion;
	int code;int y=3;
	char nit[9];
	char nombre[50];
	char mercaderia[50];
	char direccion[50];
	int telefono;
	cout<<"	Seleccione el listado acontinuacion"<<endl;
	cout<<"1. Proveedor por codigo"<<endl;
	cout<<"2. Proveedores por articulos mas vendidos a la tienda"<<endl;
	cin>>opcion;
	switch(opcion)
	{
		case 1:
		for(i=0;i<contadorProveedores;i++){
		min=i;
		//Recorrer el arreglo a fondo.
		for(j=i+1;j<contadorProveedores;j++){
			if(Proveedor[j].Codigo<Proveedor[min].Codigo){
				min=j;
			}
		}
		code=Proveedor[i].Codigo;
		Proveedor[i].Codigo=Proveedor[min].Codigo;
		Proveedor[min].Codigo=code; //Codigo
		
		strcpy(nit,Proveedor[i].Nit);
		strcpy(Proveedor[i].Nit,Proveedor[min].Nit);
		strcpy(Proveedor[min].Nit,nit); //NIT
		
		strcpy(nombre,Proveedor[i].Nombre);
		strcpy(Proveedor[i].Nombre,Proveedor[min].Nombre);
		strcpy(Proveedor[min].Nombre,nombre); //Nombre
		
		strcpy(mercaderia,Proveedor[i].Mercaderia);
		strcpy(Proveedor[i].Mercaderia,Proveedor[min].Mercaderia);
		strcpy(Proveedor[min].Mercaderia,mercaderia); //Mercaderia
		
		strcpy(direccion,Proveedor[i].Direccion);
		strcpy(Proveedor[i].Direccion,Proveedor[min].Direccion);
		strcpy(Proveedor[min].Direccion,direccion); //Direccion
		
		telefono=Proveedor[i].Telefono;
		Proveedor[i].Telefono=Proveedor[min].Telefono;
		Proveedor[min].Telefono=telefono; //Telefono
		
	}
	system("cls");
	gotoxy(50,0); cout<<"-REPORTE DE PROVEEDORES-";
	gotoxy(1,2); cout<<"Codigo:"<<endl;
	gotoxy(15,2); cout<<"NIT:"<<endl;
	gotoxy(30,2); cout<<"Nombre:"<<endl;
	gotoxy(50,2); cout<<"Mercaderia o servicio:"<<endl;
	gotoxy(75,2); cout<<"Direccion:"<<endl;
	gotoxy(100,2); cout<<"Telefono:"<<endl;
	
	for(i=0;i<contadorProveedores;i++){
		gotoxy(1,y); cout<<Proveedor[i].Codigo;
		gotoxy(15,y); cout<<Proveedor[i].Nit;
		gotoxy(30,y); cout<<Proveedor[i].Nombre;
		gotoxy(50,y); cout<<Proveedor[i].Mercaderia;
		gotoxy(75,y); cout<<Proveedor[i].Direccion;
		gotoxy(100,y); cout<<Proveedor[i].Telefono;
		y++;
	}
		break;
		case 2:
		for(i=0;i<contadorProveedores;i++){
		max=i;
		//Recorrer el arreglo a fondo.
		for(j=i+1;j<contadorProveedores;j++){
			if(Proveedor[j].top>Proveedor[max].top){
				max=j;
			}
		}
		code=Proveedor[i].Codigo;
		Proveedor[i].Codigo=Proveedor[max].Codigo;
		Proveedor[max].Codigo=code; //Codigo
		
		top=Proveedor[i].top;
		Proveedor[i].top=Proveedor[max].top;
		Proveedor[max].top=top; //top
		
		strcpy(nit,Proveedor[i].Nit);
		strcpy(Proveedor[i].Nit,Proveedor[max].Nit);
		strcpy(Proveedor[max].Nit,nit); //NIT
		
		strcpy(nombre,Proveedor[i].Nombre);
		strcpy(Proveedor[i].Nombre,Proveedor[max].Nombre);
		strcpy(Proveedor[max].Nombre,nombre); //Nombre
		
		strcpy(mercaderia,Proveedor[i].Mercaderia);
		strcpy(Proveedor[i].Mercaderia,Proveedor[max].Mercaderia);
		strcpy(Proveedor[max].Mercaderia,mercaderia); //Mercaderia
		
		strcpy(direccion,Proveedor[i].Direccion);
		strcpy(Proveedor[i].Direccion,Proveedor[max].Direccion);
		strcpy(Proveedor[max].Direccion,direccion); //Direccion
		
		telefono=Proveedor[i].Telefono;
		Proveedor[i].Telefono=Proveedor[max].Telefono;
		Proveedor[max].Telefono=telefono; //Telefono
		
	}
	system("cls");
	gotoxy(50,0); cout<<"-REPORTE DE PROVEEDORES-";
	gotoxy(1,2); cout<<"Codigo:"<<endl;
	gotoxy(15,2); cout<<"NIT:"<<endl;
	gotoxy(30,2); cout<<"Nombre:"<<endl;
	gotoxy(50,2); cout<<"Mercaderia o servicio:"<<endl;
	gotoxy(75,2); cout<<"Articulos que mas nos venden:"<<endl;
	
	
	for(i=0;i<contadorProveedores;i++){
		gotoxy(1,y); cout<<Proveedor[i].Codigo;
		gotoxy(15,y); cout<<Proveedor[i].Nit;
		gotoxy(30,y); cout<<Proveedor[i].Nombre;
		gotoxy(50,y); cout<<Proveedor[i].Mercaderia;
		gotoxy(75,y); cout<<Proveedor[i].top;
		
		y++;
	}	break;	
	
	
}	getch();
}
void buscarProveedor(){
	int kodex;
	system("cls");
	gotoxy(50,2); cout<<"-BUSQUEDA DE PROVEEDORES-"<<endl<<endl;
	cout<<"Codigo: ";
	cin>>kodex;
	int pos=buscarCodigopro(kodex);
	if (pos>=0)
	{	system("cls");
		gotoxy(1,4); cout<<"Codigo";
		gotoxy(15,4); cout<<"NIT";
		gotoxy(30,4); cout<<"Nombre";
		gotoxy(50,4); cout<<"Mercaderia o servicio";
		gotoxy(75,4); cout<<"Direccion";
		gotoxy(100,4); cout<<"Telefono";
		gotoxy(5,5); cout<<Proveedor[pos].Codigo;
		gotoxy(15,5); cout<<Proveedor[pos].Nit;
		gotoxy(30,5); cout<<Proveedor[pos].Nombre;
		gotoxy(50,5); cout<<Proveedor[pos].Mercaderia;
		gotoxy(75,5); cout<<Proveedor[pos].Direccion;
		gotoxy(100,5); cout<<Proveedor[pos].Telefono;
	}
	else 
		cout<<"El nombre no existe!!!";
		
		getch();
}
void submenuReportes(){
	system("cls");
	gotoxy(50,2); cout<<"-REPORTES-"<<endl;
	cout<<"1. Facturas"<<endl;
	cout<<"2. Articulos mas vendidos"<<endl;
	cout<<"3. Articulos en bodega"<<endl;
	cout<<"4. Articulos en tienda"<<endl;
	cout<<"5. Clientes"<<endl;
	cout<<"6. Proveedores"<<endl;
	cout<<"7. Empleados"<<endl;
	cout<<"8. Salir"<<endl<<endl;
	cout<<"Ingrese una opcion: ";
	cin>>opcionReportes; }
	

void eliminacionfactura(){
	
	for(int i=contadorFacturas;i<=contadorFacturas;i++)
	{	Factura[contadorFacturas].Numero=Factura[contadorFacturas+1].Numero;
		strcpy(Factura[contadorFacturas].Fecha,Factura[contadorFacturas+1].Fecha);
		strcpy(Factura[contadorFacturas].Hora,Factura[contadorFacturas+1].Hora);
		strcpy(Factura[contadorFacturas].Nombrevendedor,Factura[contadorFacturas+1].Nombrevendedor);
		Factura[contadorFacturas].NumeroCaja=Factura[contadorFacturas+1].NumeroCaja;
		contadorFacturas--;
	}
}
void facturacion(){
	system("cls");
	int Codigo;
	char NIT[12];
	int answer;
	int caja,code,canti,cicle;
	
	gotoxy(40,0); cout<<"<<<<<FACTURA - DATOS GENERALES>>>>>>>"<<endl;
	//Seccion de datos de la empresa.
	cout<<"Fecha: "<<endl;
	cin>>Factura[contadorFacturas].Fecha;
	cout<<endl<<"Hora: ";
	cin>>Factura[contadorFacturas].Hora;
	cout<<endl<<"Factura No. "<<contadorFacturas+1<<endl;
	Factura[contadorFacturas].Numero=contadorFacturas+1;
	cout<<endl<<endl<<"Codigo vendedor: ";
	cin>>Codigo;
	int posCodigo=buscarCodigo(Codigo);
	if(posCodigo>=0)
	{
		strcpy; Factura[contadorFacturas].Codigovendedor=Codigo;
	 	cout<<"Nombre: "<<Empleado[posCodigo].Nombre<<" / "<<Empleado[posCodigo].Puesto<<endl;
		strcpy(Factura[contadorFacturas].Nombrevendedor,Empleado[posCodigo].Nombre);
		
		cout<<endl<<"Numero de caja: ";
		cin>>Factura[contadorFacturas].NumeroCaja;
		cout<<endl<<"Ingrese NIT del cliente: ";
		cin>>NIT;
	int pos=buscarNitcliente(NIT);
		if(pos>=0){
			cout<<"Nombre: "<<Cliente[pos].Nombre<<endl;
			strcpy(Factura[contadorFacturas].Nombre,Cliente[pos].Nombre);
			cout<<"Direccion: "<<Cliente[pos].Direccion<<endl;
			strcpy(Factura[contadorFacturas].Direccion,Cliente[pos].Direccion);
			strcpy(Factura[contadorFacturas].Nit,NIT);
			system("cls");
			gotoxy(40,0); cout<<"<<<<<FACTURA - DATOS GENERALES>>>>>>>"<<endl;
			gotoxy(31,3);cout<<"Digite la cantidad de articulos a vender: ";
			cin>>cicle;
			
			for(int j=1;j<=cicle;j++)
			{	system("cls");
			gotoxy(40,0); cout<<"<<<<<FACTURA - DESCRIPCION DE ARTICULOS>>>>>>>"<<endl;
			gotoxy(47,2);cout<<"Ingreso de productos:"<<endl;
				cout<<"Digite codigo de articulo: ";
				cin>>code;
				int post=buscarCodigoproductoti(code);
				if(post>=0)
				{	cout<<"Digite la cantidad: ";
					cin>>canti;
					if(Articuloti[post].cantidad>0 and canti<=Articuloti[post].cantidad and canti>0)
					{
						gotoxy(2,7);cout<<"Nombre: ";
						gotoxy(30,7);cout<<"Precio/p: ";
						gotoxy(45,7);cout<<"Cantidad: ";
						gotoxy(55,7);cout<<"Cantidad disponible: ";
						gotoxy(2,8);cout<<Articuloti[post].Nombre;
						gotoxy(30,8);cout<<Articuloti[post].Punitario;
						gotoxy(55,8);cout<<Articuloti[post].cantidad;
						gotoxy(45,8);cout<<canti;
						//guardar en el arreglo
						strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,Articuloti[post].Nombre);
						Factura[contadorFacturas].Detalles[contadorDetalles].precio=Articuloti[post].Punitario;
						Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=canti;
						Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=Articuloti[post].Punitario*Factura[contadorFacturas].Detalles[contadorDetalles].cantidad;
						Articuloti[post].cantidad=Articuloti[post].cantidad-canti;
						Articuloti[post].top=Articuloti[post].top+canti; //Top de articulos mas vendidos
						Cliente[pos].top=Cliente[post].top+canti; //Top de clientes que mas productos compran
						Empleado[posCodigo].top=Cliente[posCodigo].top+canti; //Top de empleados que mas productos venden
						contadorDetalles++;
						
					}else {
					cout<<"La cantidad solicitada sobrepasa lo que hay en existencias, o digito un valor invalido"<<endl;j--;
					}	
				}else {cout<<"el articulo no se encuentra"<<endl; j--; //Para no sumar en el ciclo.
				}getch();
				system("cls");	
				gotoxy(40,0); cout<<"<<<<<FACTURA - DATOS GENERALES>>>>>>>"<<endl;
			}gotoxy(30,10);cout<<"DESEA EFECTUAR ESTA VENTA? '1 = si, cualquier numero= ''no':  ";
			cin>>answer;
			if(answer==1)
			{system("cls");
				for(int i=0;i<contadorDetalles;i++)
				{
				Factura[contadorFacturas].subtotal=(Factura[contadorFacturas].subtotal+Factura[contadorFacturas].Detalles[i].subtotal);
				}
				Factura[contadorFacturas].IVA=Factura[contadorFacturas].subtotal*0.12; //Sacar el IVA
			Factura[contadorFacturas].total=Factura[contadorFacturas].subtotal+Factura[contadorFacturas].IVA; //Total de la factura
		
			
			///impresion de factura
			gotoxy(25,0);cout<<"Factura No. "<<Factura[contadorFacturas].Numero;
			gotoxy(35,1);cout<<"**********Supertienda <MAS>**********"<<endl;
			
			gotoxy(25,2);cout<<"Articulos de primera necesidad al alcance de tus bolsillos."<<endl;
			gotoxy(30,3);cout<<"Direccion: 5ta. Avenida, lote 24, Amatitlan."<<endl;
			gotoxy(35,4);cout<<"Fecha: "<<Factura[contadorFacturas].Fecha;
			gotoxy(55,4);cout<<"Hora: "<<Factura[contadorFacturas].Hora;
			gotoxy(45,6);cout<<"DATOS DE CLIENTE";
			gotoxy(30,7);cout<<"Cliente: "<<Factura[contadorFacturas].Nombre;
			gotoxy(55,7);cout<<"Nit: "<<Factura[contadorFacturas].Nit;
			gotoxy(30,8);cout<<"Direccion: "<<Factura[contadorFacturas].Direccion;
			gotoxy(22,9);cout<<"_____________________________________________________________";
			
			int a=13;	
				gotoxy(43,10);cout<<"DESCRIPCION DE COMPRA";
				gotoxy(22,11);cout<<"Cantidad: ";
				gotoxy(35,11);cout<<"Articulo: ";
				gotoxy(56,11);cout<<"Precio/p: ";
				gotoxy(68,11);cout<<"Subtotal-articulo: ";
				
			for(int i=contadorDetalles-cicle;i<contadorDetalles;i++)
			{	gotoxy(25,a);cout<<Factura[contadorFacturas].Detalles[i].cantidad;
				gotoxy(35,a);cout<<Factura[contadorFacturas].Detalles[i].Nombre;
				gotoxy(58,a);cout<<Factura[contadorFacturas].Detalles[i].precio;
				gotoxy(70,a);cout<<Factura[contadorFacturas].Detalles[i].subtotal;
				a++;
			}	gotoxy(22,a+1);cout<<"____________________________________________________________";
			gotoxy(42,a+2);cout<<"El subtotal es: "<<Factura[contadorFacturas].subtotal<<endl;
			gotoxy(46,a+3);cout<<"El IVA  es: "<<Factura[contadorFacturas].IVA<<endl;
			gotoxy(36,a+4);cout<<"El total a pagar  es: "<<Factura[contadorFacturas].total;
			gotoxy(45,a+6);cout<<"Le atendio: "<<Factura[contadorFacturas].Nombrevendedor;
			gotoxy(45,a+7);cout<<"Caja No."<<Factura[contadorFacturas].NumeroCaja;	
			}else if(answer!=1)
			{	eliminacionfactura();
				cout<<endl<<"La compra se ha cancelado";
			}
			
		}else{
		agregarCliente();
		cout<<"Ciente agregado";
		facturacion();
	}	

	contadorFacturas++;
	}
	else{
		cout<<"Vendedor no existe!!!";
			
	}	
getch();	
}
reporteFacturas(){
		int a=1,i;
	system("cls");
	cout<<"						-REPORTE DE FACTURAS-"<<endl;
	gotoxy(27,a);cout<<"CANTIDAD: ";
		gotoxy(40,a);cout<<"ARTICULO: ";
		gotoxy(67,a);cout<<"PRECIO/P: ";
		gotoxy(86,a);cout<<"PRECIO TOTAL:";
	int d=2;
	//Datos generales de la factura
	for(i=0;i<contadorFacturas;i++)
	{cout<<endl;
	gotoxy(0,d);cout<<"No.Fact: "<<Factura[i].Numero<<endl;
	gotoxy(0,d+1);cout<<"Nombre Cliente: "<<Factura[i].Nombre<<endl;
	gotoxy(0,d+2);cout<<"Direccion: "<<Factura[i].Direccion<<endl;
	gotoxy(0,d+3);cout<<"Cod.vendedor: "<<Factura[i].Codigovendedor<<endl;
	gotoxy(0,d+4);cout<<"Nombre vendedor: "<<Factura[i].Nombrevendedor<<endl;

	gotoxy(0,d+5);cout<<"No.caja: "<<Factura[i].NumeroCaja<<endl;
	gotoxy(0,d+6);cout<<"NIT: "<<Factura[i].Nit<<endl;
	gotoxy(0,d+7);cout<<"Fecha: "<<Factura[i].Fecha<<endl;
	gotoxy(0,d+8);cout<<"------------------------------------------------------------------------------------------------------";
	gotoxy(0,d+8);cout<<endl<<endl;	
	gotoxy(88,d+2);cout<<Factura[i].total<<endl;
	//Impresión detalles de articulos
	for(int j=0;j<contadorDetalles;j++)
	{	if(Factura[i].Detalles[j].cantidad>0){
				
			cout<<"				"<<Factura[i].Detalles[j].cantidad<<"	"<<Factura[i].Detalles[j].Nombre;cout<<"		"<<Factura[i].Detalles[j].precio<<endl;
			
		

		}else{
		
		}}d=d+12;
	}
	getch();
}
//Programa principal
main(){
	//Inicializando
	//REGISTROS PROVEEDORES//
	contadorProveedores=0;
	strcpy; Proveedor[contadorProveedores].Codigo=5003;
	strcpy(Proveedor[contadorProveedores].Nit,"34567858");
	strcpy(Proveedor[contadorProveedores].Nombre,"Suli");
	strcpy(Proveedor[contadorProveedores].Mercaderia,"Varios");
	strcpy(Proveedor[contadorProveedores].Direccion,"Guatemala");
	strcpy; Proveedor[contadorProveedores].Telefono=65782234;
	Proveedor[contadorProveedores].top=2;
	contadorProveedores++;
	strcpy; Proveedor[contadorProveedores].Codigo=5005;
	strcpy(Proveedor[contadorProveedores].Nit,"76798045");
	strcpy(Proveedor[contadorProveedores].Nombre,"DISGUATE");
	strcpy(Proveedor[contadorProveedores].Mercaderia,"Productos-limpieza");
	strcpy(Proveedor[contadorProveedores].Direccion,"Guatemala");
	strcpy; Proveedor[contadorProveedores].Telefono=41226530;
	Proveedor[contadorProveedores].top=3;
	contadorProveedores++;
	strcpy; Proveedor[contadorProveedores].Codigo=5004;
	strcpy(Proveedor[contadorProveedores].Nit,"12435671");
	strcpy(Proveedor[contadorProveedores].Nombre,"POLLOREY");
	strcpy(Proveedor[contadorProveedores].Mercaderia,"Alimentos");
	strcpy(Proveedor[contadorProveedores].Direccion,"Guatemala");
	strcpy; Proveedor[contadorProveedores].Telefono=56789034;
	Proveedor[contadorProveedores].top=2;
	contadorProveedores++;
	strcpy; Proveedor[contadorProveedores].Codigo=5001;
	strcpy(Proveedor[contadorProveedores].Nit,"12435679");
	strcpy(Proveedor[contadorProveedores].Nombre,"Cocacola");
	strcpy(Proveedor[contadorProveedores].Mercaderia,"Bebidas");
	strcpy(Proveedor[contadorProveedores].Direccion,"USA");
	strcpy; Proveedor[contadorProveedores].Telefono=22556987;
	Proveedor[contadorProveedores].top=2;
	contadorProveedores++;
	strcpy; Proveedor[contadorProveedores].Codigo=5007;
	strcpy(Proveedor[contadorProveedores].Nit,"45643569");
	strcpy(Proveedor[contadorProveedores].Nombre,"PEPSI");
	strcpy(Proveedor[contadorProveedores].Mercaderia,"Bebidas");
	strcpy(Proveedor[contadorProveedores].Direccion,"GUATEMALA");
	strcpy; Proveedor[contadorProveedores].Telefono=45656987;
	Proveedor[contadorProveedores].top=6;
	contadorProveedores++;
	strcpy; Proveedor[contadorProveedores].Codigo=5009;
	strcpy(Proveedor[contadorProveedores].Nit,"78643567");
	strcpy(Proveedor[contadorProveedores].Nombre,"TOTALLY.SA");
	strcpy(Proveedor[contadorProveedores].Mercaderia,"Comida");
	strcpy(Proveedor[contadorProveedores].Direccion,"GUATEMALA");
	strcpy; Proveedor[contadorProveedores].Telefono=76656987;
	Proveedor[contadorProveedores].top=5;
	contadorProveedores++;
	strcpy; Proveedor[contadorProveedores].Codigo=5008;
	strcpy(Proveedor[contadorProveedores].Nit,"89043567");
	strcpy(Proveedor[contadorProveedores].Nombre,"CLEAN SA");
	strcpy(Proveedor[contadorProveedores].Mercaderia,"LIMPIEZA");
	strcpy(Proveedor[contadorProveedores].Direccion,"MEXICO");
	strcpy; Proveedor[contadorProveedores].Telefono=25656988;
	Proveedor[contadorProveedores].top=6;
	contadorProveedores++;
	strcpy; Proveedor[contadorProveedores].Codigo=5010;
	strcpy(Proveedor[contadorProveedores].Nit,"89043567");
	strcpy(Proveedor[contadorProveedores].Nombre,"TEJANO");
	strcpy(Proveedor[contadorProveedores].Mercaderia,"ALIMENTOS");
	strcpy(Proveedor[contadorProveedores].Direccion,"MEXICO");
	strcpy; Proveedor[contadorProveedores].Telefono=75656980;
	Proveedor[contadorProveedores].top=10;
	contadorProveedores++;
	strcpy; Proveedor[contadorProveedores].Codigo=5006;
	strcpy(Proveedor[contadorProveedores].Nit,"12043567");
	strcpy(Proveedor[contadorProveedores].Nombre,"PRODUCTOS GT");
	strcpy(Proveedor[contadorProveedores].Mercaderia,"VARIOS");
	strcpy(Proveedor[contadorProveedores].Direccion,"GUATEMALA");
	strcpy; Proveedor[contadorProveedores].Telefono=23656987;
	Proveedor[contadorProveedores].top=10;
	contadorProveedores++;
	strcpy; Proveedor[contadorProveedores].Codigo=5002;
	strcpy(Proveedor[contadorProveedores].Nit,"23545678");
	strcpy(Proveedor[contadorProveedores].Nombre,"P&G");
	strcpy(Proveedor[contadorProveedores].Mercaderia,"Productos_de_higiene");
	strcpy(Proveedor[contadorProveedores].Direccion,"Mexico");
	strcpy; Proveedor[contadorProveedores].Telefono=87902354;
	Proveedor[contadorProveedores].top=2;
	contadorProveedores++;
	//REGISTROS EMPLEADOS///
	contadorEmpleados=0;	
	strcpy; Empleado[contadorEmpleados].Codigo=1005;
	strcpy; Empleado[contadorEmpleados].DPI=2865294830114;
	strcpy(Empleado[contadorEmpleados].Nombre,"Geovany");
	strcpy(Empleado[contadorEmpleados].Puesto,"Caja");
	strcpy; Empleado[contadorEmpleados].Edad=19;
	Empleado[contadorEmpleados].top=6;
	contadorEmpleados++;
	strcpy; Empleado[contadorEmpleados].Codigo=1002;
	strcpy; Empleado[contadorEmpleados].DPI=5789635412589;
	strcpy(Empleado[contadorEmpleados].Nombre,"Angel");
	strcpy(Empleado[contadorEmpleados].Puesto,"Caja");
	strcpy; Empleado[contadorEmpleados].Edad=20;
	Empleado[contadorEmpleados].top=4;
	contadorEmpleados++;
	strcpy; Empleado[contadorEmpleados].Codigo=1010;
	strcpy; Empleado[contadorEmpleados].DPI=5478963214569;
	strcpy(Empleado[contadorEmpleados].Nombre,"Carlos");
	strcpy(Empleado[contadorEmpleados].Puesto,"Caja");
	strcpy; Empleado[contadorEmpleados].Edad=25;
	Empleado[contadorEmpleados].top=24;
	contadorEmpleados++;
	strcpy; Empleado[contadorEmpleados].Codigo=1006;
	strcpy; Empleado[contadorEmpleados].DPI=5687478965412;
	strcpy(Empleado[contadorEmpleados].Nombre,"Mariana");
	strcpy(Empleado[contadorEmpleados].Puesto,"Caja");
	strcpy; Empleado[contadorEmpleados].Edad=30;
	Empleado[contadorEmpleados].top=27;
	contadorEmpleados++;
	strcpy; Empleado[contadorEmpleados].Codigo=1001;
	strcpy; Empleado[contadorEmpleados].DPI=5874563258912;
	strcpy(Empleado[contadorEmpleados].Nombre,"Maria");
	strcpy(Empleado[contadorEmpleados].Puesto,"Caja");
	strcpy; Empleado[contadorEmpleados].Edad=29;
	Empleado[contadorEmpleados].top=15;
	contadorEmpleados++;
	strcpy; Empleado[contadorEmpleados].Codigo=1009;
	strcpy; Empleado[contadorEmpleados].DPI=7896325418963;
	strcpy(Empleado[contadorEmpleados].Nombre,"Javier");
	strcpy(Empleado[contadorEmpleados].Puesto,"Caja");
	strcpy; Empleado[contadorEmpleados].Edad=35;
	Empleado[contadorEmpleados].top=8;
	contadorEmpleados++;
	strcpy; Empleado[contadorEmpleados].Codigo=1003;
	strcpy; Empleado[contadorEmpleados].DPI=5897456324569;
	strcpy(Empleado[contadorEmpleados].Nombre,"Susana");
	strcpy(Empleado[contadorEmpleados].Puesto,"Caja");
	strcpy; Empleado[contadorEmpleados].Edad=40;
	Empleado[contadorEmpleados].top=11;
	contadorEmpleados++;
	strcpy; Empleado[contadorEmpleados].Codigo=1008;
	strcpy; Empleado[contadorEmpleados].DPI=1235478963215;
	strcpy(Empleado[contadorEmpleados].Nombre,"Roberto");
	strcpy(Empleado[contadorEmpleados].Puesto,"Caja");
	strcpy; Empleado[contadorEmpleados].Edad=40;
	Empleado[contadorEmpleados].top=19;
	contadorEmpleados++;
	strcpy; Empleado[contadorEmpleados].Codigo=1004;
	strcpy; Empleado[contadorEmpleados].DPI=9874562578963;
	strcpy(Empleado[contadorEmpleados].Nombre,"Karla");
	strcpy(Empleado[contadorEmpleados].Puesto,"Caja");
	strcpy; Empleado[contadorEmpleados].Edad=25;
	Empleado[contadorEmpleados].top=13;
	contadorEmpleados++;
	strcpy; Empleado[contadorEmpleados].Codigo=1007;
	strcpy; Empleado[contadorEmpleados].DPI=5896789632541;
	strcpy(Empleado[contadorEmpleados].Nombre,"Samanda");
	strcpy(Empleado[contadorEmpleados].Puesto,"Caja");
	strcpy; Empleado[contadorEmpleados].Edad=28;
	Empleado[contadorEmpleados].top=15;
	contadorEmpleados++;
	//REGISTROS CLIENTES//
	contadorClientes=0;
		strcpy; Cliente[contadorClientes].Codigo=2003;
		strcpy(Cliente[contadorClientes].Nit,"41577833");
		strcpy(Cliente[contadorClientes].Nombre,"Julio");
		strcpy(Cliente[contadorClientes].Direccion,"Amatitlan");
		strcpy; Cliente[contadorClientes].Edad=19;
		Cliente[contadorClientes].top=4;
		contadorClientes++;
		strcpy; Cliente[contadorClientes].Codigo=2005;
		strcpy(Cliente[contadorClientes].Nit,"15478695");
		strcpy(Cliente[contadorClientes].Nombre,"Monica");
		strcpy(Cliente[contadorClientes].Direccion,"Ciudad");
		strcpy; Cliente[contadorClientes].Edad=18;
		Cliente[contadorClientes].top=5;
		contadorClientes++;
		strcpy; Cliente[contadorClientes].Codigo=2009;
		strcpy(Cliente[contadorClientes].Nit,"45789636");
		strcpy(Cliente[contadorClientes].Nombre,"Israel");
		strcpy(Cliente[contadorClientes].Direccion,"Villa_Nueva");
		strcpy; Cliente[contadorClientes].Edad=20;
		Cliente[contadorClientes].top=8;
		contadorClientes++;
		strcpy; Cliente[contadorClientes].Codigo=2010;
		strcpy(Cliente[contadorClientes].Nit,"58758965");
		strcpy(Cliente[contadorClientes].Nombre,"David");
		strcpy(Cliente[contadorClientes].Direccion,"Amatitlan");
		strcpy; Cliente[contadorClientes].Edad=20;
		Cliente[contadorClientes].top=9;
		contadorClientes++;
		strcpy; Cliente[contadorClientes].Codigo=2001;
		strcpy(Cliente[contadorClientes].Nit,"54786325");
		strcpy(Cliente[contadorClientes].Nombre,"Pedro");
		strcpy(Cliente[contadorClientes].Direccion,"Ciudad");
		strcpy; Cliente[contadorClientes].Edad=25;
		Cliente[contadorClientes].top=11;
		contadorClientes++;
		strcpy; Cliente[contadorClientes].Codigo=2002;
		strcpy(Cliente[contadorClientes].Nit,"58426856");
		strcpy(Cliente[contadorClientes].Nombre,"Sandra");
		strcpy(Cliente[contadorClientes].Direccion,"Amatitlan");
		strcpy; Cliente[contadorClientes].Edad=40;
		Cliente[contadorClientes].top=2;
		contadorClientes++;
		strcpy; Cliente[contadorClientes].Codigo=2004;
		strcpy(Cliente[contadorClientes].Nit,"25478966");
		strcpy(Cliente[contadorClientes].Nombre,"Angelina");
		strcpy(Cliente[contadorClientes].Direccion,"Ciudad");
		strcpy; Cliente[contadorClientes].Edad=28;
		Cliente[contadorClientes].top=1;
		contadorClientes++;
		strcpy; Cliente[contadorClientes].Codigo=2006;
		strcpy(Cliente[contadorClientes].Nit,"84754787");
		strcpy(Cliente[contadorClientes].Nombre,"Lorena");
		strcpy(Cliente[contadorClientes].Direccion,"Villa_Nueva");
		strcpy; Cliente[contadorClientes].Edad=58;
		Cliente[contadorClientes].top=13;
		contadorClientes++;
		strcpy; Cliente[contadorClientes].Codigo=2008;
		strcpy(Cliente[contadorClientes].Nit,"54786328");
		strcpy(Cliente[contadorClientes].Nombre,"Pedro");
		strcpy(Cliente[contadorClientes].Direccion,"Ciudad");
		strcpy; Cliente[contadorClientes].Edad=25;
		Cliente[contadorClientes].top=7;
		contadorClientes++;
		strcpy; Cliente[contadorClientes].Codigo=2007;
		strcpy(Cliente[contadorClientes].Nit,"69787569");
		strcpy(Cliente[contadorClientes].Nombre,"Hugo");
		strcpy(Cliente[contadorClientes].Direccion,"Amatitlan");
		strcpy; Cliente[contadorClientes].Edad=48;
		Cliente[contadorClientes].top=19;
		contadorClientes++;
		
	//articulos tienda
	contadorArticulostienda=0;
	strcpy; Articuloti[contadorArticulostienda].Codigo=8;
	strcpy(Articuloti[contadorArticulostienda].Nombre,"Shampoo-para-mujer");
	Articuloti[contadorArticulostienda].cantidad=4;
	Articuloti[contadorArticulostienda].Punitario=25.00;
	strcpy; Articuloti[contadorArticulostienda].Codigoproveedor=5002;
	Articuloti[contadorArticulostienda].top=3;
	contadorArticulostienda++;
	strcpy; Articuloti[contadorArticulostienda].Codigo=5;
	strcpy(Articuloti[contadorArticulostienda].Nombre,"Detergente-pisos");
	Articuloti[contadorArticulostienda].cantidad=14;
	Articuloti[contadorArticulostienda].Punitario=21.5;
	strcpy; Articuloti[contadorArticulostienda].Codigoproveedor=5005;
	Articuloti[contadorArticulostienda].top=2;
	contadorArticulostienda++;
	strcpy; Articuloti[contadorArticulostienda].Codigo=1;
	strcpy(Articuloti[contadorArticulostienda].Nombre,"Fanta-naranja-16onz");
	Articuloti[contadorArticulostienda].cantidad=25;
	Articuloti[contadorArticulostienda].Punitario=13.5;
	strcpy; Articuloti[contadorArticulostienda].Codigoproveedor=5007;
	Articuloti[contadorArticulostienda].top=8;
	contadorArticulostienda++;
	strcpy; Articuloti[contadorArticulostienda].Codigo=7;
	strcpy(Articuloti[contadorArticulostienda].Nombre,"Limpiador-para-ventanas");
	Articuloti[contadorArticulostienda].cantidad=24;
	Articuloti[contadorArticulostienda].Punitario=17.8;
	strcpy; Articuloti[contadorArticulostienda].Codigoproveedor=5008;
	Articuloti[contadorArticulostienda].top=5;
	contadorArticulostienda++;
	strcpy; Articuloti[contadorArticulostienda].Codigo=6;
	strcpy(Articuloti[contadorArticulostienda].Nombre,"Jabon-para-trastes");
	Articuloti[contadorArticulostienda].cantidad=18;
	Articuloti[contadorArticulostienda].Punitario=10.00;
	strcpy; Articuloti[contadorArticulostienda].Codigoproveedor=5006;
	Articuloti[contadorArticulostienda].top=7;
	contadorArticulostienda++;
	strcpy;  Articuloti[contadorArticulostienda].Codigo=11;
	strcpy(Articuloti[contadorArticulostienda].Nombre,"Salchichas");
	Articuloti[contadorArticulostienda].cantidad=9;
	Articuloti[contadorArticulostienda].Punitario=5.00;
	strcpy; Articuloti[contadorArticulostienda].Codigoproveedor=5003;
	Articuloti[contadorArticulostienda].top=11;
	contadorArticulostienda++;
	strcpy; Articuloti[contadorArticulostienda].Codigo=2;
	strcpy(Articuloti[contadorArticulostienda].Nombre,"Cocacola-3lt");
	Articuloti[contadorArticulostienda].cantidad=15;
	Articuloti[contadorArticulostienda].Punitario=17.5;
	strcpy; Articuloti[contadorArticulostienda].Codigoproveedor=5001;
	Articuloti[contadorArticulostienda].top=14;
	contadorArticulostienda++;
	strcpy; Articuloti[contadorArticulostienda].Codigo=4;
	strcpy(Articuloti[contadorArticulostienda].Nombre,"Pollotejano");
	Articuloti[contadorArticulostienda].cantidad=13;
	Articuloti[contadorArticulostienda].Punitario=17.34;
	strcpy; Articuloti[contadorArticulostienda].Codigoproveedor=5010;
	Articuloti[contadorArticulostienda].top=9;
	contadorArticulostienda++;
	strcpy; Articuloti[contadorArticulostienda].Codigo=9;
	strcpy(Articuloti[contadorArticulostienda].Nombre,"Jabon-sin-olor");
	Articuloti[contadorArticulostienda].cantidad=7;
	Articuloti[contadorArticulostienda].Punitario=7.00;
	strcpy; Articuloti[contadorArticulostienda].Codigoproveedor=5002;
	Articuloti[contadorArticulostienda].top=4;
	contadorArticulostienda++;
	strcpy; Articuloti[contadorArticulostienda].Codigo=10;
	strcpy(Articuloti[contadorArticulostienda].Nombre,"Jamon-pavo");
	Articuloti[contadorArticulostienda].cantidad=8;
	Articuloti[contadorArticulostienda].Punitario=13.00;
	strcpy; Articuloti[contadorArticulostienda].Codigoproveedor=5009;
	Articuloti[contadorArticulostienda].top=10;
	contadorArticulostienda++;
	strcpy; Articuloti[contadorArticulostienda].Codigo=3;
	strcpy(Articuloti[contadorArticulostienda].Nombre,"Pechugas-BBQ");
	Articuloti[contadorArticulostienda].cantidad=12;
	Articuloti[contadorArticulostienda].Punitario=7.90;
	strcpy; Articuloti[contadorArticulostienda].Codigoproveedor=5004;
	Articuloti[contadorArticulostienda].top=17;
	contadorArticulostienda++;
	///articulos bodega
	contadorArticulosbodega=0;
	strcpy; Articulobo[contadorArticulosbodega].Codigo=2;
	strcpy(Articulobo[contadorArticulosbodega].Nombre,"Cocacola-3lt");
	Articulobo[contadorArticulosbodega].cantidad=3;
	Articulobo[contadorArticulosbodega].Punitario=17.5;
	strcpy; Articulobo[contadorArticulosbodega].Codigoproveedor=5001;
	contadorArticulosbodega++;
	strcpy; Articulobo[contadorArticulosbodega].Codigo=4;
	strcpy(Articulobo[contadorArticulosbodega].Nombre,"Pollotejano");
	Articulobo[contadorArticulosbodega].cantidad=8;
	Articulobo[contadorArticulosbodega].Punitario=17.34;
	strcpy; Articulobo[contadorArticulosbodega].Codigoproveedor=5010;
	contadorArticulosbodega++;
	strcpy; Articulobo[contadorArticulosbodega].Codigo=6;
	strcpy(Articulobo[contadorArticulosbodega].Nombre,"Jabon-para-trastes");
	Articulobo[contadorArticulosbodega].cantidad=18;
	Articulobo[contadorArticulosbodega].Punitario=10.00;
	strcpy; Articulobo[contadorArticulosbodega].Codigoproveedor=5006;
	contadorArticulosbodega++;
	strcpy; Articulobo[contadorArticulosbodega].Codigo=5;
	strcpy(Articulobo[contadorArticulosbodega].Nombre,"Detergente-pisos");
	Articulobo[contadorArticulosbodega].cantidad=34;
	Articulobo[contadorArticulosbodega].Punitario=21.5;
	strcpy; Articulobo[contadorArticulosbodega].Codigoproveedor=5005;
	contadorArticulosbodega++;
	strcpy; Articulobo[contadorArticulosbodega].Codigo=7;
	strcpy(Articulobo[contadorArticulosbodega].Nombre,"Limpiador-para-ventanas");
	Articulobo[contadorArticulosbodega].cantidad=23;
	Articulobo[contadorArticulosbodega].Punitario=17.8;
	strcpy; Articulobo[contadorArticulosbodega].Codigoproveedor=5008;
	contadorArticulosbodega++;
	strcpy; Articulobo[contadorArticulosbodega].Codigo=3;
	strcpy(Articulobo[contadorArticulosbodega].Nombre,"Pechugas-BBQ");
	Articulobo[contadorArticulosbodega].cantidad=7;
	Articulobo[contadorArticulosbodega].Punitario=7.90;
	strcpy; Articulobo[contadorArticulosbodega].Codigoproveedor=5004;
	contadorArticulosbodega++;
	strcpy; Articulobo[contadorArticulosbodega].Codigo=8;
	strcpy(Articulobo[contadorArticulosbodega].Nombre,"Shampoo-para-mujer");
	Articulobo[contadorArticulosbodega].cantidad=19;
	Articulobo[contadorArticulosbodega].Punitario=25.00;
	strcpy; Articulobo[contadorArticulosbodega].Codigoproveedor=5002;
	contadorArticulosbodega++;
	strcpy; Articulobo[contadorArticulosbodega].Codigo=9;
	strcpy(Articulobo[contadorArticulosbodega].Nombre,"Jabon-sin-olor");
	Articulobo[contadorArticulosbodega].cantidad=34;
	Articulobo[contadorArticulosbodega].Punitario=7.00;
	strcpy; Articulobo[contadorArticulosbodega].Codigoproveedor=5002;
	contadorArticulosbodega++;
	strcpy; Articulobo[contadorArticulosbodega].Codigo=10;
	strcpy(Articulobo[contadorArticulosbodega].Nombre,"Jamon-pavo");
	Articulobo[contadorArticulosbodega].cantidad=45;
	Articulobo[contadorArticulosbodega].Punitario=13.00;
	strcpy; Articulobo[contadorArticulosbodega].Codigoproveedor=5009;
	contadorArticulosbodega++;
	strcpy; Articulobo[contadorArticulosbodega].Codigo=1;
	strcpy(Articulobo[contadorArticulosbodega].Nombre,"Fanta-naranja-16onz");
	Articulobo[contadorArticulosbodega].cantidad=11;
	Articulobo[contadorArticulosbodega].Punitario=13.5;
	strcpy; Articulobo[contadorArticulosbodega].Codigoproveedor=5007;
	contadorArticulosbodega++;
	strcpy; Articulobo[contadorArticulosbodega].Codigo=11;
	strcpy(Articulobo[contadorArticulosbodega].Nombre,"Salchichas");
	Articulobo[contadorArticulosbodega].cantidad=56;
	Articulobo[contadorArticulosbodega].Punitario=5.00;
	strcpy; Articulobo[contadorArticulosbodega].Codigoproveedor=5003;
	contadorArticulosbodega++;
	//REGISTRO DE FACTURAS
//REGISTRO DE FACTURAS
	contadorFacturas=0;
	contadorDetalles=0;
	//Factura 1
	strcpy(Factura[contadorFacturas].Fecha,"30/10/2022");
	strcpy(Factura[contadorFacturas].Hora,"14:20");
	strcpy; Factura[contadorFacturas].Codigovendedor=1003;
	strcpy(Factura[contadorFacturas].Nombrevendedor,"Susana");
	Factura[contadorFacturas].Numero=1;
	Factura[contadorFacturas].NumeroCaja=1;
	strcpy(Factura[contadorFacturas].Nit,"41577833");
	strcpy(Factura[contadorFacturas].Nombre,"Julio");
	strcpy(Factura[contadorFacturas].Direccion,"Amatitlan");
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=1;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Fanta-naranja-16onz");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=4;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=13.5;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=54;
	contadorDetalles++;
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=2;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Cocacola-3lt");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=6;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=17.5;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=105;	
	contadorDetalles++;
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=3;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Pechugas-BBQ");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=2;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=7.90;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=15.8;
	strcpy; Factura[contadorFacturas].subtotal=174.8;
	strcpy; Factura[contadorFacturas].IVA=20.976;
	strcpy; Factura[contadorFacturas].total=195.776;
	contadorDetalles++;	
	contadorFacturas++;

	//Factura 2
	strcpy(Factura[contadorFacturas].Fecha,"31/10/2022");
	strcpy(Factura[contadorFacturas].Hora,"08:16");
	strcpy; Factura[contadorFacturas].Codigovendedor=1004;
	strcpy(Factura[contadorFacturas].Nombrevendedor,"Karla");
	Factura[contadorFacturas].Numero=2;
	Factura[contadorFacturas].NumeroCaja=2;
	strcpy(Factura[contadorFacturas].Nit,"15478695");
	strcpy(Factura[contadorFacturas].Nombre,"Monica");
	strcpy(Factura[contadorFacturas].Direccion,"Ciudad");
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=4;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Pollotejano");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=5;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=17.34;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=86.7;
	contadorDetalles++;
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=5;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Detergente-pisos");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=1;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=21.5;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=21.5;	
	contadorDetalles++;
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=6;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Jabon-para-trastes");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=5;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=10.00;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=50;
	strcpy; Factura[contadorFacturas].subtotal=158.2;
	strcpy; Factura[contadorFacturas].IVA=18.984;
	strcpy; Factura[contadorFacturas].total=177.184;
	contadorDetalles++;	
	contadorFacturas++;

	//Factura 3
	strcpy(Factura[contadorFacturas].Fecha,"01/11/2022");
	strcpy(Factura[contadorFacturas].Hora,"10:12");
	strcpy; Factura[contadorFacturas].Codigovendedor=1005;
	strcpy(Factura[contadorFacturas].Nombrevendedor,"Geovany");
	Factura[contadorFacturas].Numero=3;
	Factura[contadorFacturas].NumeroCaja=3;
	strcpy(Factura[contadorFacturas].Nit,"45789636");
	strcpy(Factura[contadorFacturas].Nombre,"Israel");
	strcpy(Factura[contadorFacturas].Direccion,"Villa_Nueva");
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=7;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Limpiador-para-ventanas");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=12;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=17.80;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=213.6;
	contadorDetalles++;
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=8;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Shampoo-para-mujer");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=1;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=25.00;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=25.00;	
	contadorDetalles++;
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=9;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Jabon-sin-olor");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=2;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=7.00;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=14;
	strcpy; Factura[contadorFacturas].subtotal=252.6;
	strcpy; Factura[contadorFacturas].IVA=30.312;
	strcpy; Factura[contadorFacturas].total=282.912;
	contadorDetalles++;	
	contadorFacturas++;

	//Factura 4
	strcpy(Factura[contadorFacturas].Fecha,"02/11/2022");
	strcpy(Factura[contadorFacturas].Hora,"14:10");
	strcpy; Factura[contadorFacturas].Codigovendedor=1006;
	strcpy(Factura[contadorFacturas].Nombrevendedor,"Mariana");
	Factura[contadorFacturas].Numero=4;
	Factura[contadorFacturas].NumeroCaja=4;
	strcpy(Factura[contadorFacturas].Nit,"58758965");
	strcpy(Factura[contadorFacturas].Nombre,"David");
	strcpy(Factura[contadorFacturas].Direccion,"Amatitlan");
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=10;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Jamon-pavo");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=4;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=13.00;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=52;
	
	contadorDetalles++;
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=11;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Salchichas");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=3;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=5.00;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=15.00;	
	contadorDetalles++;
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=1;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Fanta-naranja-16onz");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=3;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=13.5;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=40.5;
	strcpy; Factura[contadorFacturas].subtotal=107.5;
	strcpy; Factura[contadorFacturas].IVA=12.9;
	strcpy; Factura[contadorFacturas].total=120.4;
	contadorDetalles++;	
	contadorFacturas++;

	//Factura 5
	strcpy(Factura[contadorFacturas].Fecha,"03/11/2022");
	strcpy(Factura[contadorFacturas].Hora,"07:45");
	strcpy; Factura[contadorFacturas].Codigovendedor=1007;
	strcpy(Factura[contadorFacturas].Nombrevendedor,"Samanda");
	Factura[contadorFacturas].Numero=5;
	Factura[contadorFacturas].NumeroCaja=5;
	strcpy(Factura[contadorFacturas].Nit,"54786325");
	strcpy(Factura[contadorFacturas].Nombre,"Pedro");
	strcpy(Factura[contadorFacturas].Direccion,"Ciudad");
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=2;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Cocacola-3lt");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=2;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=17.5;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=35;
	contadorDetalles++;
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=5;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Detergente-pisos");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=5;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=21.5;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=107.5;	
	contadorDetalles++;
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=8;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Shampoo-para-mujer");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=2;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=25.00;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=50;
	strcpy; Factura[contadorFacturas].subtotal=192.5;
	strcpy; Factura[contadorFacturas].IVA=23.1;
	strcpy; Factura[contadorFacturas].total=215.6;
	contadorDetalles++;	
	contadorFacturas++;
	
	//Factura 6
	strcpy(Factura[contadorFacturas].Fecha,"04/11/2022");
	strcpy(Factura[contadorFacturas].Hora,"07:45");
	strcpy; Factura[contadorFacturas].Codigovendedor=1010;
	strcpy(Factura[contadorFacturas].Nombrevendedor,"Carlos");
	Factura[contadorFacturas].Numero=6;
	Factura[contadorFacturas].NumeroCaja=6;
	strcpy(Factura[contadorFacturas].Nit,"84754787");
	strcpy(Factura[contadorFacturas].Nombre,"Lorena");
	strcpy(Factura[contadorFacturas].Direccion,"Villa_Nueva");
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=11;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Salchichas");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=2;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=5;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=10;
	contadorDetalles++;
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=1;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Fanta-naranja-16onz");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=2;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=13.50;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=27;	
	contadorDetalles++;
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=2;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Cocacola-3lt");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=1;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=17.5;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=17.5;
	strcpy; Factura[contadorFacturas].subtotal=54.5;
	strcpy; Factura[contadorFacturas].IVA=6.54;
	strcpy; Factura[contadorFacturas].total=61.04;
	contadorDetalles++;	
	contadorFacturas++;

	//Factura 7
	strcpy(Factura[contadorFacturas].Fecha,"04/11/2022");
	strcpy(Factura[contadorFacturas].Hora,"10:45");
	strcpy; Factura[contadorFacturas].Codigovendedor=1002;
	strcpy(Factura[contadorFacturas].Nombrevendedor,"Angel");
	Factura[contadorFacturas].Numero=7;
	Factura[contadorFacturas].NumeroCaja=4;
	strcpy(Factura[contadorFacturas].Nit,"25478966");
	strcpy(Factura[contadorFacturas].Nombre,"Angelina");
	strcpy(Factura[contadorFacturas].Direccion,"Ciudad");
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=4;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Pollotejano");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=2;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=17.34;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=34.68;
	contadorDetalles++;
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=1;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Fanta-naranja-16onz");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=2;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=13.50;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=27;	
	contadorDetalles++;
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=7;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Limpiador-para-ventanas");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=1;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=17.80;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=17.80;
	strcpy; Factura[contadorFacturas].subtotal=79.48;
	strcpy; Factura[contadorFacturas].IVA=9.5376;
	strcpy; Factura[contadorFacturas].total=89.0176;
	contadorDetalles++;	
	contadorFacturas++;
	
	//Factura 8
	strcpy(Factura[contadorFacturas].Fecha,"04/11/2022");
	strcpy(Factura[contadorFacturas].Hora,"13:30");
	strcpy; Factura[contadorFacturas].Codigovendedor=1005;
	strcpy(Factura[contadorFacturas].Nombrevendedor,"Geovany");
	Factura[contadorFacturas].Numero=8;
	Factura[contadorFacturas].NumeroCaja=5;
	strcpy(Factura[contadorFacturas].Nit,"69787569");
	strcpy(Factura[contadorFacturas].Nombre,"Hugo");
	strcpy(Factura[contadorFacturas].Direccion,"Amatitlan");
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=7;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Limpiador-para-ventanas");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=3;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=17.80;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=53.4;
	contadorDetalles++;
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=1;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Fanta-naranja-16onz");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=2;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=13.50;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=27;	
	contadorDetalles++;
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=10;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Jamon-pavo");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=1;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=13.00;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=13.00;
	strcpy; Factura[contadorFacturas].subtotal=93.4;
	strcpy; Factura[contadorFacturas].IVA=11.208;
	strcpy; Factura[contadorFacturas].total=104.608;
	contadorDetalles++;	
	contadorFacturas++;

	//Factura 9
	strcpy(Factura[contadorFacturas].Fecha,"05/11/2022");
	strcpy(Factura[contadorFacturas].Hora,"15:30");
	strcpy; Factura[contadorFacturas].Codigovendedor=1001;
	strcpy(Factura[contadorFacturas].Nombrevendedor,"Maria");
	Factura[contadorFacturas].Numero=9;
	Factura[contadorFacturas].NumeroCaja=6;
	strcpy(Factura[contadorFacturas].Nit,"58758965");
	strcpy(Factura[contadorFacturas].Nombre,"David");
	strcpy(Factura[contadorFacturas].Direccion,"Amatitlan");
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=6;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Limpiador-para-trastes");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=2;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=10.00;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=20;
	contadorDetalles++;
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=3;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Pechugas-BBQ");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=1;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=7.90;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=7.90;	
	contadorDetalles++;
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=9;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Jabon-sin-olor");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=1;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=7.00;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=7.00;
	strcpy; Factura[contadorFacturas].subtotal=34.9;
	strcpy; Factura[contadorFacturas].IVA=4.188;
	strcpy; Factura[contadorFacturas].total=39.088;
	contadorDetalles++;	
	contadorFacturas++;
	
	//Factura 10
	strcpy(Factura[contadorFacturas].Fecha,"05/11/2022");
	strcpy(Factura[contadorFacturas].Hora,"18:20");
	strcpy; Factura[contadorFacturas].Codigovendedor=1008;
	strcpy(Factura[contadorFacturas].Nombrevendedor,"Roberto");
	Factura[contadorFacturas].Numero=10;
	Factura[contadorFacturas].NumeroCaja=2;
	strcpy(Factura[contadorFacturas].Nit,"58426856");
	strcpy(Factura[contadorFacturas].Nombre,"Sandra");
	strcpy(Factura[contadorFacturas].Direccion,"Amatitlan");
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=5;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Detergente-pisos");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=2;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=21.5;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=43;
	contadorDetalles++;
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=3;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Pechugas-BBQ");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=1;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=7.90;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=7.90;	
	contadorDetalles++;
	Factura[contadorFacturas].Detalles[contadorDetalles].Codigo=4;
	strcpy(Factura[contadorFacturas].Detalles[contadorDetalles].Nombre,"Pollotejano");
	Factura[contadorFacturas].Detalles[contadorDetalles].cantidad=1;
	Factura[contadorFacturas].Detalles[contadorDetalles].precio=17.34;
	Factura[contadorFacturas].Detalles[contadorDetalles].subtotal=17.34;
	strcpy; Factura[contadorFacturas].subtotal=68.24;
	strcpy; Factura[contadorFacturas].IVA=8.1888;
	strcpy; Factura[contadorFacturas].total=76.4288;
	contadorDetalles++;	
	contadorFacturas++;

	system("COLOR B0");
	do{
		menu();	
		switch(opcion){
			//Articulos en tienda
			case 1:
				do{
					submenuArticulosentienda();
					switch(opcionArticulostienda){
						//Agregar
						case 1:
							agregarArticulotienda();
						break;
						//Modificar
						case 2:
							modificarArticulotienda();
						break;
						//Eliminar
						case 3:
							eliminarArticulotienda();
						break;
						//Buscar
						case 4:
							buscarArticulotienda();
						break;
						case 5:
							trasladoArticulostienda();
						
					}	
				}while(opcionArticulostienda!=6);
			break;
			case 2: //Articulos en bodega
				do{
					submenuArticulosenbodega();
					switch(opcionArticulosbodega){
						//Agregar
						case 1:
							agregarArticulobodega();						
						break;
						//Modificar
						case 2:
							modificarArticulobodega();
						break;
						//Eliminar
						case 3:
							eliminarArticulobodega();
						break;
						//Buscar
						case 4:
							buscarArticulobodega();
						break;
						case 5:
							trasladoArticulosbodega();
						break;
					}				
			}while(opcionArticulosbodega!=6);
			break;
			case 3: //Clientes
				do{
					submenuClientes();
					switch(opcionClientes){
						//Agregar
						case 1:
							agregarCliente();
						break;
						//Modificar
						case 2:
							modificarCliente();
						break;
						//Eliminar
						case 3:
							eliminarCliente();
						break;
						//Buscar
						case 4:
							buscarCliente();
						break;
					}
				}while(opcionClientes!=5);
					break;
			case 4: //Facturacion
				facturacion();
			break;
			case 5: //Proveedores
				do{
					submenuProveedores();
					switch(opcionProveedores){
						//Agregar
						case 1:
							agregarProveedor();
						break;
						//Modificar
						case 2:
							modificarProveedor();
						break;
						//Eliminar
						case 3:
							eliminarProveedor();
						break;
						//Buscar
						case 4:
							buscarProveedor();
						break;
					}
				}while(opcionProveedores!=5);
			break;
			case 6:	//Empleados
				do{
				submenuEmpleados();
				switch(opcionEmpleados){
						//Agregar
						case 1:
							agregarEmpleado();
						break;
						//Modificar
						case 2:
							modificarEmpleado();
						break;
						//Eliminar
						case 3:
							eliminarEmpleado();
						break;
						//Buscar
						case 4:
							buscarEmpleado();
						break;
					}
				}while(opcionEmpleados!=5);
				break;	
			case 7: //Reportes
				do{
				submenuReportes();
				switch(opcionReportes){
						//Facturas
						case 1:
							reporteFacturas();
						break;
						//articulos mas vendidos
						case 2:
						reporteArticulosmasvendidos();	
						break;
						//Articulos en bodega
						case 3:
							reporteArticulosbodega();
						break;
						//Articulos en tienda
						case 4:
							reporteArticulostienda();
						break;
						//Clientes
						case 5:
							reporteClientes();
						break;
						//Proveedores
						case 6:
							reporteProveedores();
						break;
						//Empleados
						case 7:
							reporteEmpleados();
						break;
					}
				}while(opcionReportes!=8);
				break;
			}
	}while(opcion!=8);
}
