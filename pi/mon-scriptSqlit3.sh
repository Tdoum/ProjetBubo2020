
# Installation Sqlite3
echo "Installation SQlite3"
echo "Extraction";
cd /home/pi
tar zxvf sqlite-autoconf-3190200.tar.gz
cd sqlite-autoconf-3190200/

echo "Configuration";
sudo ./configure
echo "Compilation";
sudo make
echo "Installation";
sudo make install 
echo "Installation final terminer"
