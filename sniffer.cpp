#include <pcap.h>
#include <iostream>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/ether.h>
#include "sniffer.h"

using namespace std;

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ether_header *eth_header = (struct ether_header *)packet;

    if (ntohs(eth_header->ether_type) == ETHERTYPE_IP) {
        struct ip *ip_header = (struct ip *)(packet + sizeof(struct ether_header));
        cout << "Source IP: " << inet_ntoa(ip_header->ip_src)
             << " Dest IP: " << inet_ntoa(ip_header->ip_dst);

        if (ip_header->ip_p == IPPROTO_TCP) {
            struct tcphdr *tcp_header = (struct tcphdr *)(packet + sizeof(struct ether_header) + (ip_header->ip_hl * 4));
            cout << " TCP Src Port: " << ntohs(tcp_header->th_sport)
                 << " Dest Port: " << ntohs(tcp_header->th_dport) << endl;
        } else {
            cout << endl;
        }
    }
}

void start_sniffer() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    pcap_if_t *devices, *device;

    if (pcap_findalldevs(&devices, errbuf) == -1) {
        cerr << "Erreur: " << errbuf << endl;
        return;
    }

    cout << "Interfaces réseau disponibles :\n";
    int i = 0;
    for (device = devices; device; device = device->next) {
        cout << ++i << ". " << device->name << endl;
    }

    string dev_name;
    cout << "Choisissez l'interface pour sniffer (ex: eth0, wlan0): ";
    cin >> dev_name;

    handle = pcap_open_live(dev_name.c_str(), BUFSIZ, 1, 1000, errbuf);
    if (!handle) {
        cerr << "Erreur d'ouverture : " << errbuf << endl;
        return;
    }

    cout << "Sniffing sur " << dev_name << "...\n";
    pcap_loop(handle, 10, packet_handler, nullptr);
    pcap_close(handle);
}
