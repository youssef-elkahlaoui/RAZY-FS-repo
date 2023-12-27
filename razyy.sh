#!/bin/bash

export mon_envi=~/RAZY_FS/bin
export PATH=$mon_envi:$PATH

# Set custom prompt
echo 'export PS1="RAZY\w $ "' >> ~/.bashrc

# Source additional script
source /home/youssef/set_path.sh
clear
bim
bash
