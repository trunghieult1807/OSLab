#!/bin/bash
if [ ! -z "$1" ]; then
	touch ex1.txt
    echo "Successfully create new file"
    echo "User name: " $1 $2 $3 > ex1.txt
    echo -e "\nHardware Overview:\n\tModel Name: MacBook Pro\n\tModel Identifier: MacBookPro13,3\n\tProcessor Name: Quad-Core Intel Core i7\n\tProcessor Speed: 2.7 GHz\n\tNumber of Processors: 1\n\tTotal Number of Cores: 4\n\tL2 Cache (per Core): 256 KB\n\tL3 Cache: 8 MB\n\tHyper-Threading Technology: Enabled\n\tMemory: 16 GB\n\tBoot ROM Version: 264.0.0.0.0\n\tSMC Version (system): 2.38f8\n\tSerial Number (system): C02SP2WQGTF1\n\tHardware UUID: C5924C4A-8ACF-55AA-8503-AD9E72CCC048" >> ex1.txt
    
else
    echo "The variable is null"
fi
