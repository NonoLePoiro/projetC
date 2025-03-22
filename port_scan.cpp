#include <iostream>
#include <string>
#include <stdlib.h> 
#include "port_scan.h"

using namespace std;

void analyse_ports_vuln() {
    string ip;
    cout << "Entrez l'IP à analyser pour les ports vulnérables : ";
    cin >> ip;

    string command = "nmap -sV --script=vuln " + ip;
    system(command.c_str());
}
