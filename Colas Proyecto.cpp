#include <iostream>       // Biblioteca para operaciones de entrada/salida (cout, cin)
#include <queue>          // Biblioteca para usar la estructura de datos 'cola' (FIFO)
#include <string>         // Biblioteca para manejo de cadenas de texto (string)
#include <windows.h>      // Biblioteca específica de Windows para configuraciones de consola

using namespace std;      // Evita escribir 'std::' antes de cada función estándar

// Estructura que define un cliente del banco
struct Cliente {
    int turno;           // Número de turno asignado al cliente
    string nombre;       // Nombre del cliente (usamos string para permitir espacios)
};

// Función que muestra el menú de opciones
void mostrarMenu() {
    cout << "\n--- BANCO CUCUL POP ---\n";  // Título personalizado del banco
    cout << "1. Agregar cliente\n";        // Opción para agregar nuevo cliente
    cout << "2. Atender cliente\n";        // Opción para atender al siguiente cliente
    cout << "3. Ver cola de espera\n";     // Opción para mostrar la lista de espera
    cout << "4. Mostrar cliente actual\n"; // Opción para ver el cliente siendo atendido
    cout << "0. Salir\n";                  // Opción para terminar el programa
    cout << "Seleccione una opcion: ";     // Solicitud de entrada al usuario
}

// Función para limpiar la pantalla de la consola
void limpiarPantalla() {
    system("cls");       // Comando de Windows para limpiar la consola
}

// Función principal del programa
int main() {
    // Configura la consola para soportar caracteres especiales (tildes, ñ, etc.)
    SetConsoleOutputCP(CP_UTF8);
    // Variables principales:
    queue<Cliente> colaClientes;      // Cola que almacena los clientes en espera
    Cliente clienteActual;            // Almacena temporalmente al cliente siendo atendido
    int contadorTurnos = 1;           // Lleva la secuencia numérica de los turnos
    int opcion;                       // Almacena la opción seleccionada por el usuario
    bool clienteSiendoAtendido = false; // Indica si hay un cliente en atención

    // Bucle principal del programa
    do {
        limpiarPantalla();    // Limpia la pantalla en cada iteración
        mostrarMenu();        // Muestra el menú de opciones
        cin >> opcion;        // Lee la opción seleccionada por el usuario

        // Estructura switch para manejar las diferentes opciones
        switch (opcion) {
        case 1: {  // Agregar nuevo cliente
            Cliente c;    // Crea un nuevo objeto Cliente
            c.turno = contadorTurnos++;  // Asigna número de turno y luego incrementa
            cout << "Ingrese el nombre del cliente: ";
            cin.ignore();  // Limpia el buffer de entrada
            getline(cin, c.nombre);  // Lee el nombre (permite espacios)
            colaClientes.push(c);    // Agrega el cliente a la cola
            cout << "\nCliente agregado con turno #" << c.turno << endl;
            system("pause");  // Pausa para que el usuario vea el mensaje
            break;
        }
        case 2: {  // Atender cliente
            if (!colaClientes.empty()) {  // Verifica si hay clientes en cola
                clienteActual = colaClientes.front();  // Obtiene el primer cliente
                colaClientes.pop();       // Elimina al cliente de la cola
                clienteSiendoAtendido = true;  // Actualiza el estado
                cout << "\nAtendiendo al cliente: " << clienteActual.nombre
                    << " (Turno #" << clienteActual.turno << ")\n";
            }
            else {
                clienteSiendoAtendido = false;
                cout << "\nNo hay clientes en la cola.\n";
            }
            system("pause");
            break;
        }
        case 3: {  // Mostrar cola de espera
            if (colaClientes.empty()) {
                cout << "\nLa cola de espera está vacía.\n";
            }
            else {
                queue<Cliente> copia = colaClientes;  // Copia para no modificar la original
                cout << "\n--- COLA DE ESPERA ---\n";
                while (!copia.empty()) {  // Recorre toda la cola
                    Cliente c = copia.front();  // Obtiene el siguiente cliente
                    cout << "Turno #" << c.turno << " - " << c.nombre << endl;
                    copia.pop();  // Pasa al siguiente cliente
                }
            }
            system("pause");
            break;
        }
        case 4: {  // Mostrar cliente actual
            if (clienteSiendoAtendido) {
                cout << "\nCliente siendo atendido:\n";
                cout << "Turno #" << clienteActual.turno << " - "
                    << clienteActual.nombre << endl;
            }
            else {
                cout << "\nNo hay cliente siendo atendido actualmente.\n";
            }
            system("pause");
            break;
        }
        case 0: {  // Salir del programa
            cout << "\nSaliendo del sistema...\n";
            break;
        }
        default: {  // Opción no válida
            cout << "\nOpción no válida. Intente nuevamente.\n";
            system("pause");
            break;
        }
        }
    } while (opcion != 0);  // El bucle continúa hasta que se seleccione '0'

    return 0;  // Fin exitoso del programa
}//comentado
