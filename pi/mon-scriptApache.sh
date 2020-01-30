#!/bin/bash 

# installation apache
echo"Installation apache"
echo "Extraction";
cd /home/pi/
tar zxvf httpd-2.4.29.tar.gz
cd httpd-2.4.29/
echo "INSTALL COMPLETED";

echo "Prérequis pour la construction apache";
cd srclib/
cp  /home/pi/apr-1.5.2.tar /home/pi/httpd-2.4.29/srclib/
tar xvf apr-1.5.2.tar
mv apr-1.5.2 apr
cp /home/pi/apr-util-1.5.4.tar.gz /home/pi/httpd-2.4.29/srclib/
tar zxvf apr-util-1.5.4.tar.gz
mv apr-util-1.5.4 apr-util
cd ../..
tar xvf pcre-8.38.tar
cd pcre-8.38
echo "Configuration";
sudo ./configure
echo "Compilation";
sudo make 
echo"Installation";
sudo make install
cd ../httpd-2.4.29/
echo "Configuration";
sudo ./configure --with-included-apr
echo "Compilation";
sudo make 
echo"Installation";
sudo make install

sudo ldconfig
sudo cp /home/pi/httpd.conf /usr/local/apache2/conf/
echo " lancement de apache";
sudo /usr/local/apache2/bin/apachectl -k start 
echo"Installation final terminer"






