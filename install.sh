#!/bin/bash
# Installing binaries & resources
sudo mkdir -p /opt/mandelbulb/bin
sudo cp bin/MandelBulb /opt/mandelbulb/bin/
sudo cp -r res /opt/mandelbulb/
echo "Installed MandelBulb in /opt/mandelbulb/"

# Installing desktop entry & icon
mkdir -p ~/.local/share/pixmaps
cp mandelbulb-logo-nt150.png ~/.local/share/pixmaps/mandelbulb.png
cp MandelBulb.desktop ~/.local/share/applications/
echo "Installed icon in ~/.local/share/applications/"