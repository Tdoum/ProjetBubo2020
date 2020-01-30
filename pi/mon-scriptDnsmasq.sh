# Installation dnsmasq
echo "Installation dnsmasq"
echo "Extraction"
cd /home/pi
tar zxvf dnsmasq-2.78.tar.gz
#cd dnsmasq-2.78/
# sudo cp dnsmasq.conf.example /etc/dnsmasq.conf
sudo cp dnsmasq.conf /etc/dnsmasq.conf
echo "INSTALL COMPLETED"
cd dnsmasq-2.78/
echo "Compilation"
sudo make
echo "Installation"
sudo make install
echo "Installation final terminer"
