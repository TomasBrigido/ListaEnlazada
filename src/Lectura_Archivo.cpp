#include "Lectura_Archivo.h"

Lectura_Archivo::Lectura_Archivo() {
    almacenar_contenido_archivo();
}

void Lectura_Archivo::ejecutar() {

}
//Lectura y almacenamiento de variables en la lista de Variables
void Lectura_Archivo::almacenar_contenido_archivo() {
    ifstream archivo;

    archivo.open("C:\\Users\\javie\\OneDrive\\Escritorio\\Proyectos-Varios\\TP-1-Algoritmos\\texto.txt", ios::in);
    //archivo.open("/home/js/Escritorio/Facultad/TPs-Algoritmo/TP-1-Algoritmos/texto.txt",ios::in); //Abrimos el archivo en modo lectura

    if(archivo.fail()){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
        while(!archivo.eof()){//Mientras no sea el final del archivo, recorre t0do el archivo el eof
            getline(archivo,linea); //Almacenamos el contenido del archivo en la constante string 'linea'
            //linea += "\n";
            lista_de_variables->add_string(linea); // Pasamos el valor de linea a una variable string para despues poder leerla
        }
    archivo.close();
}

//Convierto los strings en char
char Lectura_Archivo::StringToCharArray(string Cadena){
    int longitud = 1;
    string str = Cadena;
    char nombre[1];
    longitud = str.length();

    for (int i = 0; i < longitud; i++)
    {
        nombre[i] = str[i];
    }
    return nombre[0];
}

