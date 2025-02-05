#include <stdio.h>
#include <stdint.h>

#define OCTET_COUNT 4  // Number of octets in IPv4 address

// Define a union that holds either 4 octets or a 32-bit integer
union IPAddress {
    uint8_t octets[OCTET_COUNT];  // 4 octets for the IPv4 address
    uint32_t address;             // 32-bit integer representation of the address
};

int main() {
    union IPAddress ip;
    int i;

    // Accept an IPv4 address as input in the form x.x.x.x
    printf("Enter an IPv4 address (e.g., 192.168.23.24): ");
    if (scanf("%hhd.%hhd.%hhd.%hhd", &ip.octets[0], &ip.octets[1], &ip.octets[2], &ip.octets[3]) != 4) {
        printf("Invalid input format!\n");
        return 1;
    }

    // Print the address in octet form
    printf("IPv4 Address in octet form: ");
    for (i = 0; i < OCTET_COUNT; i++) {
        printf("%d", ip.octets[i]);
        if (i < OCTET_COUNT - 1) {
            printf(".");
        }
    }
    printf("\n");

    // Print the address as a 32-bit integer in hexadecimal form
    printf("IPv4 Address as a 32-bit integer (in hex): 0x%08X\n", ip.address);

    return 0;
}
