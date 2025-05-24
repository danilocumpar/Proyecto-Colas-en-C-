#include <iostream>       // Biblioteca para operaciones de entrada/salida (cout, cin)
#include <queue>          // Biblioteca para usar la estructura de datos 'cola' (FIFO)
#include <string>         // Biblioteca para manejo de cadenas de texto (string)
#include <windows.h>      // Biblioteca espec�fica de Windows para configuraciones de consola

using namespace std;      // Evita escribir 'std::' antes de cada funci�n est�ndar

// Estructura que define un cliente del banco
struct Cliente {
    int turno;           // N�mero de turno asignado al cliente
    string nombre;       // Nombre del cliente (usamos string para permitir espacios)
};

// Funci�n que muestra el men� de opciones
void mostrarMenu() {
    cout << "\n--- BANCO CUCUL POP ---\n";  // T�tulo personalizado del banco
    cout << "1. Agregar cliente\n";        // Opci�n para agregar nuevo cliente
    cout << "2. Atender cliente\n";        // Opci�n para atender al siguiente cliente
    cout << "3. Ver cola de espera\n";     // Opci�n para mostrar la lista de espera
    cout << "4. Mostrar cliente actual\n"; // Opci�n para ver el cliente siendo atendido
    cout << "0. Salir\n";                  // Opci�n para terminar el programa
    cout << "Seleccione una opcion: ";     // Solicitud de entrada al usuario
}

// Funci�n para limpiar la pantalla de la consola
void limpiarPantalla() {
    system("cls");       // Comando de Windows para limpiar la consola
}

// Funci�n principal del programa
int main() {
    // Configura la consola para soportar caracteres especiales (tildes, �, etc.)
    SetConsoleOutputCP(CP_UTF8);
    // Variables principales:
    queue<Cliente> colaClientes;      // Cola que almacena los clientes en espera
    Cliente clienteActual;            // Almacena temporalmente al cliente siendo atendido
    int contadorTurnos = 1;           // Lleva la secuencia num�rica de los turnos
    int opcion;                       // Almacena la opci�n seleccionada por el usuario
    bool clienteSiendoAtendido = false; // Indica si hay un cliente en atenci�n

    // Bucle principal del programa
    do {
        limpiarPantalla();    // Limpia la pantalla en cada iteraci�n
        mostrarMenu();        // Muestra el men� de opciones
        cin >> opcion;        // Lee la opci�n seleccionada por el usuario

        // Estructura switch para manejar las diferentes opciones
        switch (opcion) {
        case 1: {  // Agregar nuevo cliente
            Cliente c;    // Crea un nuevo objeto Cliente
            c.turno = contadorTurnos++;  // Asigna n�mero de turno y luego incrementa
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
                cout << "\nLa cola de espera est� vac�a.\n";
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
        default: {  // Opci�n no v�lida
            cout << "\nOpci�n no v�lida. Intente nuevamente.\n";
            system("pause");
            break;
        }
        }
    } while (opcion != 0);  // El bucle contin�a hasta que se seleccione '0'

    return 0;  // Fin exitoso�del�programa
}//comentado
