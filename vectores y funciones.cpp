//Hola Mundo en C++

#include <iostream>
#include <cstdlib>
#include <ctime>  
#include <vector>



using namespace std;

int menu();
int funciones(int);
void numeromagico();
void tablasmultiplicar();
void funcionesvectores();
void vectores();
void cargarvector();
void mostrarvector();

int main() {

    //el programa se ejecuta hasta que la centinela cambie a 1.
    int cent = 0;
    while (cent != 1)
    {
        //funcion mostrar panel principal de opciones y ademas esperar el valor de centinela para finalizar 
        // el programa
       cent =  menu();
    }
    
    return 0;
}


//funcion de letrero principal y menu ademas se incluira la funcion de la toma del valor e la opcion
int menu(){
    //con esta variable tomaremos la opcion elegida por el usuario
    int opcion;
    //con estos cout mostramos las funciones mi menu
    cout << "-------MENU DE OPCIONES-------\n";
    cout << "1.Numero Magico\n";
    cout << "2.Tablas de  Multiplicar\n";
    cout << "3.Vectores\n";
    cout << "4.salir\n";

    //tomamos la elecion del usuario y lo guardamos en la variable opcion
    cin >> opcion; 
   return funciones(opcion);


}

int funciones(int opcion){
    int cent;
    switch (opcion)
    {
    case 1 : //si el usuario marca uno ingresamos a la opcion de numero magico
        numeromagico(); // llamamos la funcion de numero magico
        break;
     case 2:
        tablasmultiplicar();
        break;
    case 3:
        vectores();
        break;
     case 4:
        cent = 1;
        cout << "----------------HA SIDO UN GUSTO NOS VEMOS LUEGO ;) --------------------\n";
        cout << "Creador Por: ";

        break;
    default: 
        cout << "la opcion insertada es incorrecta\n\n";
    }
    return cent;

}

//creamos la funcion numero magico
 void numeromagico(){
    int numeroMenor;
    int numeroMayor;
    int numeroDigitado;
    int numeroGenerado = 0;// se inicia en cero por que el usuario puede escribir el cero como numero menor
    int burbuja;
    int intentos = 1;  // se coloca esta vaiable para saber cuantos intentos se logro

    // se le da la bienvenida al usuario al juego del numero magico
    cout << "BIENVENIDO AL JUEGO DEL NUMERO MAGICO\n";
    cout << "DEBERAS ESCRIBIR EL RANGO DE DONDE DESEAS ADIVINAR\n";
    
    // se solicita el numero minimo del rango 
    cout << "DIGITA TU NUMERO DE MINIMO A ADIVINAR\n";
    cin >> numeroMenor; // se asigna el valor digitado por al usuario a la variable numero menor
    
    cout << "DIGITA TU NUMERO MAXIMO A ADIVINAR\n";
    cin >> numeroMayor; //se asigna el valor digitado por al usuario a la variable numero mayor

    //se verifica que el numero que se digita como menor sea verdadero 
    //si esto resulta falso se realiza el metodo burbuja
    if (numeroMayor < numeroMenor){
        burbuja = numeroMenor;
        numeroMenor = numeroMayor;
        numeroMayor = burbuja;

    }

    
    
    //se le avisa al usuario en que rango de numeros debe de buscar su numero magico
    cout << "Recuerda que tu numero magico esta entre "; 
    cout << numeroMenor;
    cout << " y ";
    cout << numeroMayor;
    cout << "\n";




    while (numeroGenerado <= numeroMenor){
        srand(time(NULL));
        numeroGenerado =  rand() % numeroMayor + 1 ;

    }


    while (numeroDigitado !=  numeroGenerado){
     //se asigna el numero digitado a la variable numeroDigitado
     cin >> numeroDigitado ;   

     
     if (numeroDigitado < numeroGenerado){
        cout << "el numero digitado es menor al numero magico\n";
     }else if ( numeroDigitado > numeroGenerado){
        cout << "el numero digitado es mayor al numero magico\n";
     }else{
         cout << "Eres un genio adivinaste el numero\n";
         cout << "Tu numeros de intentos:\n ";
         cout << intentos;

         
     }

        intentos = intentos + 1 ;

     }
     
     
     

     

}



//creamos las tablas de multiplicar
void tablasmultiplicar(){

    int tablademultiplicar;
    int paroImpar;
    int i; // declaramos la i para los ciclos for

    //saludamos las tablas multiplicar
     cout << "TABLAS DE MULTIPLICAR \n\n";
    //solicitamos el numero de la tabla de multiplicar
     cout << "Digita el numero de la tabla de multiplicar: \n";

    //asignamos el valor ingresado por el usuario a tablasDeMultiplicar
     cin >> tablademultiplicar;
    

     
       
    if(tablademultiplicar % 2 == 0 ){
        for(i= 1; i <= 10; i++){
           int resultado = i * tablademultiplicar;

           cout << tablademultiplicar ;
           cout << " * ";
           cout << i ;    
           cout << " = ";
           cout << resultado;  
           cout << "\n";
        }

    }else{
         for(i= 10; i > 0; i--){
           int resultado = i * tablademultiplicar;

           cout << tablademultiplicar ;
           cout << " * ";
           cout << i ;    
           cout << " = ";
           cout << resultado;  
           cout << "\n";
        }

    }

}



void vectores(){
    funcionesvectores();

}



void funcionesvectores(){
    vector <int> numeros;
    int numero;
    int salir = 0;
    int opcion;
    // con este while verficamos y se garantiza que el programa se quede en
    // el submenu de vectores hasta que el usuario se quede.


    while(salir != 1){ 
    
    cout << "-------MENU DE OPCIONES DE VECTORES-------\n";
    cout << "1.INICIALIZAR\n";
    cout << "2.CARGAR\n";   
    cout << "3.MOSTRAR\n";
    cout << "4.salir\n";

    cin >> opcion; 


    switch (opcion)
    {
    case 1 : //si el usuario marca uno ingresamos a la opcion de numero magico
        cout<<"digita un numero para inicilizar el vector\n";
        cin >> numero;
        for(int i=0 ;  i<=3; i++){
        numeros.push_back(numero);
        }
        
        cout << "( ";
        for(int i = 1; i < numeros.size(); i++){
            
            cout << numeros[i];
            cout<< ",";
        }
         cout << ")\n";

        break;
     case 2:

        if(numeros.size() != 0){
            //ELIMINAMOS TODOS LO OBJETOS DEL VECTOR PARA VOLVER ASIGNARLOS
            while(numeros.size() != 0){
                numeros.pop_back();
            }

            cout << "DIGITA LOS TRES NUMEROS DEL VECTOR\n";
            // se crea el ciclo for para que tome solamente tres datos
            for(int i=1 ;  i<=3; i++){
                int numeroTomado; // se declara para asignarle los numeros del vector
                cout << "digita el numero ";
                cout << i ;
                cout << "\n";
                //tomamo el numero digitado por el usuario y lo asignamos a la variable numeroTomado
                cin >> numeroTomado;

                //guardamos el valor tomado al vector
                numeros.push_back(numeroTomado);

            }

            cout << "EL VAECTOR HA QUEDADO DE LA SIGUIENTE MANERA";
            cout << " (";
            for(int i = 0; i < numeros.size(); i++){
                
                cout << numeros[i];
                cout<< ",";
            }
            cout << ")\n";
        }else{
            cout << "el vector no ha sido inicializado\n";

        }


        break;
    case 3:
         //verificamos si el vector ha sido inicializado en el siguiente if.
        if(numeros.size() != 0){
            
             cout << "-----TU VECTOR CREADO-----\n";
            cout << "( ";
            for(int i = 0; i < numeros.size(); i++){
                
                cout << numeros[i];
                cout<< ",";
            }
            cout << ")\n";

        }else{
            cout << "el vector no ha sido inicializado\n";// advertimos al usuario que no se ha inicializado el vector
        }

        break;
     case 4:
      salir = 1;
        break;
    default: 
        cout << "la opcion insertada es incorrecta\n\n";
    }

}
}

