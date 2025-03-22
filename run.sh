#!/bin/bash

# Compilation
echo "Compilation en cours..."
g++ main.cpp sniffer.cpp network_scan.cpp port_scan.cpp -o scanner -lpcap
if [ $? -eq 0 ]; then
    echo "Compilation réussie. Exécution..."
    ./scanner
fi
