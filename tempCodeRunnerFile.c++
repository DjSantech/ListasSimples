#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

struct Contacto {
    char nombre[30];
    char apellido[50];
    char telefono[20];
    char whatsapp[20];
    char email[30];
    char estado[20];
    struct Contacto* siguiente;
    struct Contacto* anterior;
};

// Función para agregar un contacto a la lista
void agregarContacto(struct Contacto** primero) {
    struct Contacto* nuevo = (struct Contacto*)malloc(sizeof(struct Contacto));
    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo contacto.\n");
        exit(1);
    }

    printf("Ingrese el nombre: ");
    scanf("%s", nuevo->nombre);
    printf("Ingrese el apellido: ");
    scanf("%s", nuevo->apellido);
    printf("Ingrese el teléfono: ");
    scanf("%s", nuevo->telefono);
    printf("Ingrese el WhatsApp: ");
    scanf("%s", nuevo->whatsapp);
    printf("Ingrese el email: ");
    scanf("%s", nuevo->email);
    printf("Ingrese el estado (Activo/Borrado): ");
    scanf("%s", nuevo->estado);

    // Insertar el nuevo contacto al principio de la lista
    nuevo->siguiente = *primero;
    if (*primero != NULL) {
        (*primero)->anterior = nuevo;
    }
    nuevo->anterior = NULL;
    *primero = nuevo;

    printf("Contacto agregado correctamente.\n");
}

// Función para mostrar el contacto actual
void mostrarContactoActual(struct Contacto* actual) {
    printf("Contacto actual:\n");
    printf("Nombre: %s %s\n", actual->nombre, actual->apellido);
    printf("Teléfono: %s\n", actual->telefono);
    printf("WhatsApp: %s\n", actual->whatsapp);
    printf("Email: %s\n", actual->email);
    printf("Estado: %s\n", actual->estado);
}

// Función para mostrar la lista y permitir la navegación con las flechas
void mostrarLista(struct Contacto* primero) {
    struct Contacto* actual = primero;

    while (1) {
        // Limpiar la pantalla
        system("clear");

        // Mostrar el contacto actual
        mostrarContactoActual(actual);

        // Mostrar el menú de navegación
        printf("Navegación:\n");
        printf("↑: Contacto anterior | ↓: Siguiente contacto | Esc: Volver al menú principal\n");

        // Capturar la tecla presionada
        char tecla = getch();

        switch (tecla) {
            case 27: // Tecla Esc (Salir)
                return;
    
                getch(); // Capturar [
                switch (getch()) { // Capturar la tecla de flecha
                    case 'A': // Flecha arriba
                        if (actual->anterior != NULL) {
                            actual = actual->anterior;
                        }
                        break;
                    case 'B': // Flecha abajo
                        if (actual->siguiente != NULL) {
                            actual = actual->siguiente;
                        }
                        break;
                }
                break;
        }
    }
}

int main() {
    int salir = 0;
    struct Contacto* primero = NULL;

    initscr(); // Inicializar ncurses
    keypad(stdscr, TRUE); // Habilitar captura de teclas especiales

    do {
        // Limpiar la pantalla
        system("clear");

        // Mostrar el menú principal
        printf("Menu:\n");
        printf("1. Agregar contacto\n");
        printf("2. Consultar lista\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");

        // Capturar la tecla presionada
        char tecla = getch();

        switch (tecla) {
            case '1':
                agregarContacto(&primero);
                break;
            case '2':
                mostrarLista(primero);
                break;
            case '3':
                salir = 1;
                break;
        }
    } while (!salir);

    endwin(); // Finalizar ncurses

    return 0;
}
