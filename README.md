# Ol' Keeper Reader
Program to render old and obscelete map files from early Dungeon Keeper into previewable images.

## Usage
Usage is simple given you've already decompressed the files already. This project doesn't do decompression.
```
$ ./oldkeeperreader render <path-to-file>
```
The output will be a BMP image with the same name as the file but with a '.bmp' extension.

## Compiling
```
git clone https://github.com/Wirlaburla/OldKeeperReader.git
cd OldKeeperReader
mkdir build
cd build
cmake ..
make -j4
```
