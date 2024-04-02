#include<stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;

struct nodo {
    int id;char nombre[30];
    struct nodo *sig;
};



int contarNodosLista (struct nodo *primero) {
    struct nodo *temp;
    temp = primero;
    int contarPos=0;
    while (temp != NULL)
    {
        contarPos ++;
         temp = temp->sig;
    }
    return contarPos;

}

void insertarNodoPosEspecifica(int posicion, struct nodo *primero) {
    struct nodo *nuevo, *temp;
    int i;

    nuevo = (struct nodo*)malloc(sizeof(struct nodo));

    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return;
    }

    printf("Ingrese su id: ");
    scanf("%d", &nuevo->id);
    fflush(stdin);
    printf("Ingrese su nombre: ");
    scanf("%s",nuevo->nombre);

        nuevo->sig = temp->sig;
        temp->sig = nuevo;
    }


void insertarNodoDespues(int posicion, struct nodo *primero) {
    struct nodo *nuevo, *temp, *anterior = NULL;
    int i;

    nuevo = (struct nodo*)malloc(sizeof(struct nodo));

    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return;
    }

    while (temp != NULL)
    { if (temp->id == posicion){
        printf("Ingrese su id: ");
        scanf("%d", &nuevo->id);
        fflush(stdin);
        printf("Ingrese su nombre: ");
        scanf("%s",nuevo->nombre);
        nuevo->sig = temp->sig;
        temp->sig = nuevo;
    }
    
    }

    temp = primero;
    for (i = 1; i < posicion && temp != NULL; i++) {
        anterior = temp;
        temp = temp->sig;
    }

    if (temp == NULL && i != posicion) {
        printf("Error: La posicion indicada excede la longitud de la lista\n");
        free(nuevo);
        return;
    }

    nuevo->sig = temp;
    if (anterior != NULL) {
        anterior->sig = nuevo;
    } else {
        primero = nuevo;  // Si la posición es la primera de la lista, actualiza el puntero primero
    }
}


void agregarnodo(struct nodo *primero)
{
        struct nodo *nuevo;
        nuevo=new(struct nodo);
        printf("Ingrese su id: ");
        cin>>nuevo->id;
        fflush(stdin);
        printf("Ingrese su nombre: ");
        scanf("%s",nuevo->nombre);
        if (primero == NULL)
        {
            nuevo->sig = NULL;
            primero = nuevo;
        }
        else
        {
            struct nodo *temp = primero;
            while (temp->sig != NULL)
            {
                temp = temp->sig;
            }
            temp->sig = nuevo;
            nuevo->sig = NULL;
        }
}


void imprimir(struct nodo *primero)
{
    struct nodo *temp = primero;
    cout<<"Contenido de la lista..."<<endl;
    while (temp != NULL)
    {
        cout<<"Codigo: "<<temp->id<<endl;
        cout<<"Nombre: "<<temp->nombre<<endl;
 		cout<<endl;      
        temp = temp->sig;
    }
    cout<<endl;
}

int main() {
    int opcion, posicion, id;
    struct nodo *primero=NULL;

    do {
        printf("Menu:\n");
        printf("1. Agregar nodo\n");
        printf("2. Insertar nodo en una posicion especifica\n");
        printf("3. Insertar un nodo despues de una persona (id) especificada\n");
        printf("4. Eliminar nodo en una posicion especifica\n");
        printf("5. Eliminar un nodo despues de una persona (id) especificada\n");
        printf("6. Mostrar el contenido de la lista\n");
        printf("7. Salir\n");
        printf("8.Cantidad de nodos\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarnodo(primero);
                break;
            case 2:
                do {printf("Ingrese la posicion donde desea insertar el nodo: ");
                scanf("%d", &posicion);
                }while (posicion > contarNodosLista(primero)|| posicion == 0);
                insertarNodoPosEspecifica(posicion,primero); 
                break;
            case 3:
                printf("Ingrese el id de la persona despues de la cual desea insertar el nodo: ");
                scanf("%d", &id);
                insertarNodoDespues(id,primero);
                break;
            case 4:
                printf("Ingrese la posicion del nodo que desea eliminar: ");
                scanf("%d", &posicion);
                //eliminarNodoPosEspecifica(posicion);
                break;
            case 5:
                printf("Ingrese el id de la persona cuyo nodo siguiente desea eliminar: ");
                scanf("%d", &id);
                //eliminarNodoDespues(id);
                break;
            case 6:
                imprimir(primero);
                break;
            case 7:
                printf("Saliendo del programa...\n");
                break;
            case 8:
                printf("%d\n",contarNodosLista(primero));
                break;
            default:
                printf("Opcion no valida\n");
        }
    } while (opcion != 6);

    return 0;
}