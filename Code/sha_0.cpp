#include <iostream>
#include <vector>
#include <array>
#include <cstring>
#include <algorithm>

using namespace std;

// Rotate left function
uint32_t leftrotate(uint32_t x, int n) {
    return (x << n) | (x >> (32 - n));
}

// SHA-0 implementation
array<uint32_t, 5> sha0(const vector<unsigned char>& message) {
    // Initialize variables
    array<uint32_t, 5> h = {0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0};
    uint64_t ml = message.size() * 8;


    // Pre-processing
    vector<unsigned char> padded_message = message;
    padded_message.push_back(0x80);
    while ((padded_message.size() * 8) % 512 != 448) {
        padded_message.push_back(0x00);
    }

    // Append ml
    for (int i = 7; i >= 0; --i) {
        padded_message.push_back((ml >> (i * 8)) & 0xFF);
    }

    // Process the message in successive 512-bit chunks
    for (size_t i = 0; i < padded_message.size(); i += 64) {
        array<uint32_t, 80> w;
        for (int j = 0; j < 16; ++j) {
            w[j] = (padded_message[i + j * 4] << 24) | (padded_message[i + j * 4 + 1] << 16) |
                   (padded_message[i + j * 4 + 2] << 8) | padded_message[i + j * 4 + 3];
        }


        // Message schedule
        for (auto j{16}; j < 80; ++j) {
            w[j] = (w[j - 3] ^ w[j - 8] ^ w[j - 14] ^ w[j - 16]) ; //leftrotate 1; //  SHA-0 doesn't have leftrotate here
             w[j] = leftrotate(w[j], 1); // SHA-1 would have the rotate left
        }

        // Initialize hash value for this chunk
        uint32_t a = h[0];
        uint32_t b = h[1];
        uint32_t c = h[2];
        uint32_t d = h[3];
        uint32_t e = h[4];


        // Main loop
        for (int j = 0; j < 80; ++j) {
            uint32_t f, k;
            if (j <= 19) {
                f = (b & c) | (~b & d);
                k = 0x5A827999;
            } else if (j <= 39) {
                f = b ^ c ^ d;
                k = 0x6ED9EBA1;
            } else if (j <= 59) {
                f = (b & c) | (b & d) | (c & d);
                k = 0x8F1BBCDC;
            } else {
                f = b ^ c ^ d;
                k = 0xCA62C1D6;
            }

            uint32_t temp = leftrotate(a, 5) + f + e + k + w[j];
            e = d;
            d = c;
            c = leftrotate(b, 30);
            b = a;
            a = temp;
        }

        // Add this chunk's hash to result so far:
        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
    }
    return h;
}



int main() {
    string message_str = "a";
    vector<unsigned char> message(message_str.begin(), message_str.end());
    array<uint32_t, 5> hash = sha0(message);

    for (uint32_t val : hash) {
        printf("%08x", val);
    }
    cout << endl;
    return 0;
}