#!/bin/sh

# This script generates my HHKB evil layout and deploys it on the board that is
# in the programming mode.

PWD=$(dirname $0)
echo "Going back to the root directory"
cd $PWD/../../
pwd

echo "Generating a .hex file"
make hhkb:evil

echo "Deploying the .hex file"
sudo dfu-programmer atmega32u4 erase --force
sudo dfu-programmer atmega32u4 flash ./hhkb_evil.hex
sudo dfu-programmer atmega32u4 reset
