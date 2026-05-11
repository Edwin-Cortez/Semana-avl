#include <iostream>
#include "AVL.h"

int main() {
    AVLTree tree;
    int option;

    do {
        std::cout << "\n--- MENU PRINCIPAL ---\n";
        std::cout << "1. Insertar estudiante\n";
        std::cout << "2. Mostrar ranking academico\n";
        std::cout << "3. Buscar por skill_score\n";
        std::cout << "4. Mostrar estadisticas AVL\n";
        std::cout << "5. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> option;

        if (option == 1) {
            Student s;
            std::cout << "ID: "; std::cin >> s.student_id;
            std::cin.ignore();
            std::cout << "Nombre: "; std::getline(std::cin, s.full_name);
            std::cout << "Carrera: "; std::getline(std::cin, s.career);
            std::cout << "Semestre: "; std::cin >> s.semester;
            std::cout << "GPA: "; std::cin >> s.gpa;
            std::cout << "Skill Score: "; std::cin >> s.skill_score;
            tree.insert(s);
        } else if (option == 2) {
            tree.displayRanking();
        } else if (option == 3) {
            int score;
            std::cout << "Ingrese puntaje a buscar: "; std::cin >> score;
            tree.searchByScore(score);
        } else if (option == 4) {
            tree.displayStats();
        }
    } while (option != 5);

    return 0;
}