#include <iostream>
#include "sniffer.h"
#include "network_scan.h"
#include "port_scan.h"

using namespace std;

int main() {
    int choix;
    
    do {
        cout << "\nMenu :\n";
        cout << "1. Sniffer\n";
        cout << "2. Analyse de la plage réseau\n";
        cout << "3. Analyse des ports vulnérables ouverts\n";
        cout << "0. Quitter\n";
        cout << "Choisissez une option : ";
        cin >> choix;

        switch (choix) {
            case 1:
                start_sniffer();
                break;
            case 2:
                analyse_plage_reseau();
                break;
            case 3:
                analyse_ports_vuln();
                break;
            case 0:
                cout << "Quitter...\n";
                break;
            default:
                cout << "Choix invalide, essayez à nouveau.\n";
                break;
        }
    } while (choix != 0);

    return 0;
}
