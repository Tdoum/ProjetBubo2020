#installation  hostapd

echo "Installation hostapd"
echo "Extraction";
cd /home/pi/
sudo dpkg -i libnl-3-dev_3.2.27-2_armhf.deb

sudo dpkg -i libnl-genl-3-dev_3.2.27-2_armhf.deb

sudo dpkg -i libssl-dev_1.1.0f-3+deb9u1_armhf.deb
tar zxvf  hostapd-2.6.tar.gz
cp /home/pi/dhcpcd.conf /etc/
cd hostapd-2.6/hostapd
cp /home/pi/.config /home/pi/hostapd-2.6/hostapd/ 

sudo cp /home/pi/rc.local /etc/rc.local
echo "Compilation";
sudo make 
echo "Installation";
sudo make install

sudo cp hostapd /etc/default/
sudo mkdir /etc/hostapd
sudo cp /home/pi/hostapd.conf /etc/hostapd/
echo "Installation final terminer"
