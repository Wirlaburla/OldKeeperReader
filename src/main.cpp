#include <iostream>
#include <fstream>

#include "bmp.h"
#include "dumbutil.h"

std::string output;

using namespace std;
int render_flg(char* path) {
    streampos size;
    char * memblock;

    ifstream file(path, ios::in|ios::binary|ios::ate);
    if (file.is_open()) {
        size = file.tellg();
        memblock = new char [size];
        file.seekg (0, ios::beg);
        file.read (memblock, size);
        file.close();

        BMP bmp(256,256,true);
        int channels = bmp.bmp_info_header.bit_count / 8;

        int c = 0;
        for (size_t x {0}; x < 256; x++){
            for (size_t y {0}; y < 256; y++){
                int b1 = (int) memblock[c];
                int b2 = (int) memblock[c+1];

                int color_b {0};
                int color_g {0};
                int color_r {0};
                int color_a {255};

                if (b1 == -48 || b1 == 0 || b1 == 80) { // Bedrock
                    // Do nothing for black
                } else if (b1 == 96) { // Dirt
                    color_r = 36;
                    color_g = 23;
                } else if (b1 == 2) { // Path
                    color_r = 52;
                    color_g = 36;
                    color_b = 4;
                } else if (b1 == 65) { // Gold
                    color_r = 96;
                    color_g = 93;
                    color_b = 16;
                } else if (b1 == -64 || b1 == 84) { // Wall
                    color_r = 64;
                    color_g = 48;
                    color_b = 28;
                } else if (b1 == 22) { // Room
                    color_r = 255;
                    color_g = 255;
                    color_b = 255;
                } else if (b1 == 64) { // Door
                    if (b2 == 1) {
                        color_r = 244;
                        color_g = 132;
                        color_b = 92;
                    } else {
                        color_r = 144;
                        color_g = 152;
                        color_b = 80;
                    }
                } else {
                    color_a = 0;
                    cout << "Unknown byte '" << hex << b1 << "'.\n";
                }

                if (b2) {
                    cout << "Byte of '" << hex << b1 << "' has a secondary byte of '" << hex << b2 << "'.\n";
                }

                bmp.data[channels * (x * bmp.bmp_info_header.width + y) + 0] = color_b;  // B
                bmp.data[channels * (x * bmp.bmp_info_header.width + y) + 1] = color_g;  // G
                bmp.data[channels * (x * bmp.bmp_info_header.width + y) + 2] = color_r;  // R
                bmp.data[channels * (x * bmp.bmp_info_header.width + y) + 3] = color_a;  // A

                c+=2;
            }
        }
        bmp.bmp_info_header.height *=-1;
        bmp.write(output.c_str());

        delete[] memblock;
    } else return 1;
    return 0;
}

int render_ori(char* path) {
    streampos size;
    char * memblock;

    cout << "Reading File: " << path << "\n";
    ifstream file(path, ios::in|ios::binary|ios::ate);
    if (file.is_open()) {
        size = file.tellg();
        memblock = new char [size];
        file.seekg (0, ios::beg);
        file.read (memblock, size);
        file.close();

        BMP bmp(256,256,true);
        int channels = bmp.bmp_info_header.bit_count / 8;

        int c = 0;
        for (size_t x {0}; x < 256; x++){
            for (size_t y {0}; y < 256; y++){
                int b1 = (int) memblock[c];

                int color_b {0};
                int color_g {0};
                int color_r {0};
                int color_a {255};

                if (b1 == 0) {
                    color_r = 255;
                    color_g = 255;
                    color_b = 255;
                } else {
                    color_a = 0;
                    cout << "Unknown byte '" << hex << b1 << "'.\n";
                }

                 bmp.data[channels * (x * bmp.bmp_info_header.width + y) + 0] = color_b;  // B
                 bmp.data[channels * (x * bmp.bmp_info_header.width + y) + 1] = color_g;  // G
                 bmp.data[channels * (x * bmp.bmp_info_header.width + y) + 2] = color_r;  // R
                 bmp.data[channels * (x * bmp.bmp_info_header.width + y) + 3] = color_a;  // A

                c++;
            }
        }
         bmp.bmp_info_header.height *=-1;
         bmp.write(output.c_str());

        delete[] memblock;
    } else return 1;
    return 0;
}

int render_cei(char* path) {
    streampos size;
    char * memblock;

    cout << "Reading File: " << path << "\n";
    ifstream file(path, ios::in|ios::binary|ios::ate);
    if (file.is_open()) {
        size = file.tellg();
        memblock = new char [size];
        file.seekg (0, ios::beg);
        file.read (memblock, size);
        file.close();

        BMP bmp(256,256,true);
        int channels = bmp.bmp_info_header.bit_count / 8;

        int c = 0;
        for (size_t x {0}; x < 256; x++){
            for (size_t y {0}; y < 256; y++){
                int b1 = (int) memblock[c];

                int lightness = 0;
                int alpha {255};

                if (b1 == 0) {
                    // Do nothing for black
                } else if (b1 == 1) {
                    lightness = 17;
                } else if (b1 == 2) {
                    lightness = 34;
                } else if (b1 == 3) {
                    lightness = 51;
                } else if (b1 == 4) {
                    lightness = 68;
                } else if (b1 == 5) {
                    lightness = 85;
                } else if (b1 == 6) {
                    lightness = 102;
                } else if (b1 == 7) {
                    lightness = 119;
                } else if (b1 == 8) {
                    lightness = 136;
                } else if (b1 == 9) {
                    lightness = 153;
                } else if (b1 == 10) {
                    lightness = 170;
                } else if (b1 == 11) {
                    lightness = 204;
                } else if (b1 == 12) {
                    lightness = 255;
                } else {
                    alpha = 0;
                    cout << "Unknown byte '" << hex << b1 << "'.\n";
                }

                 bmp.data[channels * (x * bmp.bmp_info_header.width + y) + 0] = lightness;  // B
                 bmp.data[channels * (x * bmp.bmp_info_header.width + y) + 1] = lightness;  // G
                 bmp.data[channels * (x * bmp.bmp_info_header.width + y) + 2] = lightness;  // R
                 bmp.data[channels * (x * bmp.bmp_info_header.width + y) + 3] = alpha;  // A

                c++;
            }
        }
         bmp.bmp_info_header.height *=-1;
         bmp.write(output.c_str());

        delete[] memblock;
    } else return 1;
    return 0;
}

int main (int argc, char **argv) {
    if (argc >= 1) {
        for(int i = 1; i < argc; i++) {
            std::string arg = std::string(argv[i]);
            if (arg == "render") {
                output = std::string(argv[i+1]) + ".bmp";
                cout << output << "\n";
                if (str_ends_with(argv[i+1], ".flg")) {
                    return render_flg(argv[i+1]);
                } else if (str_ends_with(argv[i+1], ".ori")) {
                    return render_ori(argv[i+1]);
                } else if (str_ends_with(argv[i+1], ".cei")) {
                    return render_cei(argv[i+1]);
                } else {
                    cout << "Format not supported.\n";
                    return 1;
                }
            } else {
                cout << "Old Keeper Render by Wirlaburla (v0.1)\n";
                cout << "oldkeeperrender render <file>\n";
            }
        }
    }

    return 0;
}
