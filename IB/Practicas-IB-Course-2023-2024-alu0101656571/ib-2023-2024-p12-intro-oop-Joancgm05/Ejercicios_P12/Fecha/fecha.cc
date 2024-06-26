/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date
 * @brief
 * @bug there are no bugs
 *
 * @see https:g/jutge.org/problems/
 */

#include <iostream>

class Fecha {
private:
    int dia;
    int mes;
    int anio;

    bool esBisiesto(int year) const {
        // Método para determinar si un año es bisiesto
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

public:
    // Constructor que valida la fecha al ser creada
    Fecha(int d, int m, int a) {
        if (esFechaValida(d, m, a)) {
            dia = d;
            mes = m;
            anio = a;
        } else {
            std::cerr << "Error: Fecha no válida." << std::endl;
            dia = mes = anio = 0;
        }
    }

    // Método para mostrar la fecha en formato dd/mm/yyyy
    void mostrarFecha() const {
        std::cout << dia << "/" << mes << "/" << anio << std::endl;
    }

    // Método para determinar si un año es bisiesto
    bool esBisiesto() const {
        return esBisiesto(anio);
    }

private:
    // Método para verificar si una fecha es válida
    bool esFechaValida(int d, int m, int a) const {
        if (a < 0 || a > 9999) {
            return false;
        }

        if (m < 1 || m > 12) {
            return false;
        }

        int diasEnMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (esBisiesto(a)) {
            diasEnMes[2] = 29;
        }

        return (d >= 1 && d <= diasEnMes[m]);
    }
};

int main() {
    // Ejemplo de uso de la clase Fecha
    Fecha fecha1(29, 2, 2000); // Fecha válida
    Fecha fecha2(29, 2, 3000); // Fecha no válida

    std::cout << "Fecha 1: ";
    fecha1.mostrarFecha();
    std::cout << "Es bisiesto: " << std::boolalpha << fecha1.esBisiesto() << std::endl;

    std::cout << "Fecha 2: ";
    fecha2.mostrarFecha();
    std::cout << "Es bisiesto: " << std::boolalpha << fecha2.esBisiesto() << std::endl;

    return 0;
}
 
