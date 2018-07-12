#include <iostream>
#include <sstream>
#include <fstream>

int main() {

    std::string line;
    std::ifstream infile("/proc/net/route");

    while (std::getline(infile, line)) {
        char iface_name[256];
        unsigned int iface_ip, iface_gw, iface_mask, iface_flags;
        if (sscanf(line.c_str(), "%255s %8X %8X %4X %*d %*u %*d %8X", iface_name,
                   &iface_ip, &iface_gw, &iface_flags, &iface_mask) == 5 && iface_mask == 0) {
            std::cout << line << std::endl;
            return true;
        }
    }

    return 0;
}
