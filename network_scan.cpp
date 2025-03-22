#include <iostream>
#include <string>
#include <stdlib.h> 
#include "network_scan.h"

using namespace std;

void analyse_plage_reseau() {
    string ip_range;
    cout << "Entrez la plage IP à analyser (ex: 192.168.1.0/24) : ";
    cin >> ip_range;

    string command = "nmap -sP " + ip_range;
    system(command.c_str());
}
