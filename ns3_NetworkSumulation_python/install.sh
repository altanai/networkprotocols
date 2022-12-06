#!/bin/bash
echo "Installing..."

#   basic OS update
apt update
apt upgrade -y
apt dist-upgrade -y
apt autoremove -y
apt autoclean -y

#   install prerequisites
apt install git -y
apt install gcc -y
apt install g++ -y
apt install mercurial -y
apt install cvs -y
apt install bzr -y
apt install make -y
apt install cmake -y
apt install qt5-default -y
apt install qtcreator -y
apt install python-gi-cairo -y
apt install gir1.2-goocanvas-2.0 -y
apt install python-pygraphviz -y
apt install python-dev -y
apt install python-setuptools -y

##  acquire Bake
git clone https://gitlab.com/nsnam/bake

#   add Bake to PATH
export BAKE_HOME=`pwd`/bake 
export PATH=$PATH:$BAKE_HOME
export PYTHONPATH=$PYTHONPATH:$BAKE_HOME

#   check if all valid
bake.py check

#   configure Bake for ns-3
bake.py configure -e ns-3.29
bake.py show

#   download and build ns-3
bake.py download
cd ./source/ns-3.29/ && ./waf configure && cd ../../
bake.py build
#instead of 3 lines above this comment there was previously just "bake.py deploy"

./source/ns-3.29/test.py #this causes an error

echo "Finished Install!"