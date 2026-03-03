#include <stdio.h>
#include <string.h>
//Bibliotecas que contienen funciones ocupadas en el programa
// Estructura Hospital
typedef struct hospital{
    char nombre[30];//se declara una variable de 30 posiciones de tipo char, para almacenar una cadena de caracteres.
    char direccion[40];//Declaracion de una variable de 40 posiciones de tipo char ,almacena una cadena de caracteres.
} hospital;

// Estructura Doctor.
typedef struct doctor{
    char nombre[30];//se declara una variable de 30 posiciones de tipo char, para almacenar una cadena de caracteres.
    int edad;//Declaracion de una variable que almacenara una edad  (numero) por ello es de tipo int.
    char especializacion[40];//Variable de 40 posiciones de tipo char , almacenara una cadena de texto.
    int num_trabajador;//Variable de tipo int que almacenara el numero de trabajador.
    hospital Hospital;//Se declra la variable Hospital de tipo hospital(struct hospital)
} doctor;

// Estructura Paciente
typedef struct paciente{
    char nombre[30];//se declara una variable de 30 posiciones de tipo char, para almacenar una cadena de caracteres
    int edad;//Declaracion de una variable que almacenara una edad  (numero) por ello es de tipo int
    char especializacion[40];//varaible de 40mposiciones de tipo int que almacenara una cadena de caracteres 
    hospital Hospital;//Se declara la variable Hospital de tipo hospital(struct hospital)
    int num_paciente;//Variable de tipo int que almacenara el numero de paciente
    int num_doctor;//Vraibel de tipo int que almacenara el numero de doctor
} paciente;


// Funciones
void llenar_hospital(hospital *Hospital);//Funcion que ayudara a almacenar la informacion ingresada a la estructura hospital
void llenar_doctor(doctor *Doctor);//Funcion que ayudara a almacenar la informacion ingresada a la estructura doctor
void llenar_paciente(paciente *Paciente, doctor Doctor, hospital Hospital);//Funcion que ayudara a almacenar la informacion ungresada a la estructura paciente


// Llenar hospital
void llenar_hospital(hospital *Hospital){
    int valido,i;//varaibles de tipo int
    //Nombre de hospital(solo letras)
     do{
        valido = 1;//valido=1 significa que va bien
        //Solicita el ingreso del nombre del hospital
        printf("\nIngrese el nombre del Hospital: ");
        fgets(Hospital->nombre, sizeof(Hospital->nombre), stdin);//lee toda la cadena incluyendo espacios, guarda maximo el tamaño de la variable y evita desbordamiento
        Hospital->nombre[strcspn(Hospital->nombre, "\n")] = '\0';//fgets guarda el salto de linea , strcspn encuentra la posición del \n y lo reemplaza por '\0' (fin de cadena).

        if(strlen(Hospital->nombre) == 0){//Si el usuario solo presiona Enter , la cadena queda vacía.Entonces se marca como inválido.
            valido = 0;
        }

        for(i = 0; i < strlen(Hospital->nombre); i++){//For para analizar caracter por caracter
            //validación ASCII
            if(!((Hospital->nombre[i] >= 'A' && Hospital->nombre[i] <= 'Z') ||//valida letras Mayusculas
                 (Hospital->nombre[i] >= 'a' && Hospital->nombre[i] <= 'z') ||//Valida letras minusculas
                  Hospital->nombre[i] == ' ')){//valida espacios
                valido = 0;
                break;//break detiene el for por que ya encontro el error
            }
        }

        if(!valido){//si no es valido , imrpime el mensaje
            printf("Error: Solo letras y espacios.\n");//mensaje de error
        }

    }while(!valido);//repite mientras no es valido
    
   //Direccion del Hospital , solo admite lestras , espacios y numeros

    do{
    valido = 1;//valido=1 significa que va bien
    //solicita el ingreso de la direccion del hospital
    printf("Ingrese la direccion del hospital: ");//solicita el ingreso de la direccion del hospital
    fgets(Hospital->direccion, sizeof(Hospital->direccion), stdin);//lee toda la cadena incluyendo espacios , letras y numero , guardando maximom el numero de posiciones de la variable
    Hospital->direccion[strcspn(Hospital->direccion, "\n")] = '\0';//strcspn encuentra la posición del \n y lo reemplaza por '\0' (fin de cadena)
    if(strlen(Hospital->direccion) == 0){//Siel usuario presiona Enter , la cadena queda vacia, por ende se marac como invalido
        valido = 0;
    }

    for(i = 0; i < strlen(Hospital->direccion); i++){//For para analizar posicion por posicion
        //Validación ASCII
        if(!((Hospital->direccion[i] >= 'A' && Hospital->direccion[i] <= 'Z') ||//valida letras Mayusculas
             (Hospital->direccion[i] >= 'a' && Hospital->direccion[i] <= 'z') ||//valida letras minusculas
             (Hospital->direccion[i] >= '0' && Hospital->direccion[i] <= '9') ||//valida numeros
              Hospital->direccion[i] == ' ')){//valida los espacios

            valido = 0;
            break;//break detiene el for por que encontro un error
        }
    }

    if(!valido){//si no es valido
        printf("Error: Solo letras, numeros y espacios.\n");//imprime el mensaje de error
    }

}while(!valido);//repite mientras no es valido

}//void llenar_hospital







// Llenar doctor
void llenar_doctor(doctor *Doctor){
     int valido, i;//variables de tipo int
    // NOMBRE ,solo letras y espacios
    do{
        valido = 1;//valido=1 significa que va bien
        //Se solicita el ingreso del nombre
        printf("\nIngresa el nombre del doctor: ");
        fgets(Doctor->nombre, sizeof(Doctor->nombre), stdin);//lee toda la acadena de texto incluyendo letras y espacios, guardando maximo el tamaño de posiciones de  la variable
        Doctor->nombre[strcspn(Doctor->nombre, "\n")] = '\0';//strcspn encuentra la posición del \n y lo reemplaza por '\0' (fin de cadena)

        if(strlen(Doctor->nombre) == 0){
            valido = 0;
        }

        for(i = 0; i < strlen(Doctor->nombre); i++){
            if(!((Doctor->nombre[i] >= 'A' && Doctor->nombre[i] <= 'Z') ||
                 (Doctor->nombre[i] >= 'a' && Doctor->nombre[i] <= 'z') ||
                  Doctor->nombre[i] == ' ')){
                valido = 0;
                break;
            }
        }

        if(!valido){
            printf("Error: Solo letras y espacios.\n");
        }

    }while(!valido);


    // EDAD (solo números y positivos) 
    do{
        printf("Ingresa la edad del doctor: ");
        valido = scanf("%d", &Doctor->edad);

        while(getchar() != '\n'); // limpiar buffer

        if(valido != 1 || Doctor->edad <= 0){
            printf("Error: Ingresa una edad valida.\n");
        }

    }while(valido != 1 || Doctor->edad <= 0);


    // ESPECIALIZACION (solo letras)
    do{
    valido = 1;

    printf("Ingresa la especializacion: ");
    fgets(Doctor->especializacion, sizeof(Doctor->especializacion), stdin);

    Doctor->especializacion[strcspn(Doctor->especializacion, "\n")] = '\0';

    if(strlen(Doctor->especializacion) == 0){
        valido = 0;
    }

    for(i = 0; i < strlen(Doctor->especializacion); i++){
        if(!((Doctor->especializacion[i] >= 'A' && Doctor->especializacion[i] <= 'Z') ||
             (Doctor->especializacion[i] >= 'a' && Doctor->especializacion[i] <= 'z') ||
              Doctor->especializacion[i] == ' ')){
            valido = 0;
            break;
        }
    }

    if(!valido){
        printf("Error: Solo letras y espacios.\n");
    }

}while(!valido);


    // ---- NUMERO DE TRABAJADOR ----
    do{
        printf("Ingresa el numero de trabajador: ");
        valido = scanf("%d", &Doctor->num_trabajador);

        while(getchar() != '\n');

        if(valido != 1 || Doctor->num_trabajador <= 0){
            printf("Error: Numero invalido.\n");
        }

    }while(valido != 1 || Doctor->num_trabajador <= 0);
}







// Llenar paciente
void llenar_paciente(paciente *Paciente, doctor Doctor, hospital Hospital){
    printf("\nIngresa el nombre del paciente: ");
    scanf("%s", Paciente->nombre);

    printf("Ingresa la edad del paciente: ");
    scanf("%d", &Paciente->edad);

    printf("Ingresa la especializacion : ");
    scanf(" %c", &Paciente->especializacion);

    printf("Ingresa el numero de paciente: ");
    scanf("%d", &Paciente->num_paciente);

    Paciente->num_doctor = Doctor.num_trabajador;
    Paciente->Hospital = Hospital;
}

// Main
int main(){
    hospital Hospital;
    doctor Doctor;
    paciente Paciente;

    llenar_hospital(&Hospital);
    llenar_doctor(&Doctor);
    llenar_paciente(&Paciente, Doctor, Hospital);

    printf("\n\n--- DATOS REGISTRADOS ---\n");

    printf("\nHospital: %s", Hospital.nombre);
    printf("\nDireccion: %s", Hospital.direccion);

    printf("\n\nDoctor: %s", Doctor.nombre);
    printf("\nEdad: %d", Doctor.edad);
    printf("\nNumero trabajador: %d", Doctor.num_trabajador);

    printf("\n\nPaciente: %s", Paciente.nombre);
    printf("\nEdad: %d", Paciente.edad);
    printf("\nNumero paciente: %d", Paciente.num_paciente);
    printf("\nDoctor asignado: %d", Paciente.num_doctor);

    return 0;
}
