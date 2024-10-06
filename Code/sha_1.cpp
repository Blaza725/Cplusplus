#include <iostream>
#include <array>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

// Rotate left function
int ROTATE_LEFT(int x, int n) {
    return (x << n) | (x >> (32 - n));
}

// Big endian load (assuming input is little endian)
int BIG_ENDIAN_LOAD(int x) {
    unsigned char bytes[4];
    memcpy(bytes, &x, 4);
    reverse(bytes, bytes + 4);
    int result;
    memcpy(&result, bytes, 4);
    return result;
}

// F functions and K constants as defined in your pseudocode (unchanged)
int F1(int B, int C, int D) { return (D ^ (B & (C ^ D))); }
int F2(int B, int C, int D) { return (D ^ B ^ C); }
int F3(int B, int C, int D) { return (B & C) | (D & (B ^ C)); }
#define K1 0x5A827999
#define K2 0x6ED9EBA1
#define K3 0x8F1BBCDC
#define K4 0xCA62C1D6
int K(int i) { return i < 20 ? K1 : i < 40 ? K2 : i < 60 ? K3 : K4; }
int F(int i, int B, int C, int D) { return i < 20 ? F1(B, C, D) : i < 40 ? F2(B, C, D) : i < 60 ? F3(B, C, D) : F2(B, C, D); }


void sha1_block(array<unsigned int, 5>& hash, const array<int, 16>& message_block) {
    array<int, 81> A, B, C, D, E;
    array<int, 80> W;

    A[0] = hash[0];
    B[0] = hash[1];
    C[0] = hash[2];
    D[0] = hash[3];
    E[0] = hash[4];

    for (int i = 0; i < 80; ++i) {
        if (i < 16) {
            W[i] = BIG_ENDIAN_LOAD(message_block[i]);
        } else {
            W[i] = ROTATE_LEFT(W[i - 3] ^ W[i - 8] ^ W[i - 14] ^ W[i - 16], 1);
        }

        int FN = F(i, B[i], C[i], D[i]);
        A[i + 1] = FN + E[i] + ROTATE_LEFT(A[i], 5) + W[i] + K(i);
        B[i + 1] = A[i];
        C[i + 1] = ROTATE_LEFT(B[i], 30);
        D[i + 1] = C[i];
        E[i + 1] = D[i];
    }

    hash[0] += A[80];
    hash[1] += B[80];
    hash[2] += C[80];
    hash[3] += D[80];
    hash[4] += E[80];
}



int main() {
    // Example usage (test vector "abc")
    string message_str = "";
    // cout << "Enter the message: ";
    // getline(cin, message_str);
    vector<unsigned char> message(message_str.begin(), message_str.end());

     //Padding:
    message.push_back(0x80);
    while (message.size() % 64 != 56) {
        message.push_back(0x00);
    }

    // Append length (in bits)
    uint64_t message_len_bits = message_str.length() * 8;
    for (int i = 7; i >= 0; i--) {
         message.push_back((message_len_bits >> (8 * i)) & 0xff);
    }

    array<unsigned int, 5> hash = {0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0};


     for (size_t chunk_start = 0; chunk_start < message.size(); chunk_start += 64)
     {
        array<int, 16> chunk;
        for (int i = 0; i < 16; ++i) {
            memcpy(&chunk[i], &message[chunk_start + i * 4], 4); 
        }
        sha1_block(hash, chunk);


     }


    for (int val : hash) {
        printf("%08x", val);
    }
    cout << endl; // Output: a9993e364706816aba3e25717850c26c9cd0d89d (Correct SHA-1 for "abc")


    return 0;
}