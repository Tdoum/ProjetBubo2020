# Installation Cgicc
echo"Installation Cgicc"
echo "Extraction";
cd /home/pi	
tar zxvf cgicc-3.2.16.tar.gz
cd cgicc-3.2.16/

echo "Configuration"
sudo ./configure
echo "Compilation";
sudo make
echo "Installation";
sudo make install
echo"Installtion final terminer "
