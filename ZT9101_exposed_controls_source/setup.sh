sup && sudo rmmod zt9101_ztopmac_usb.ko
sudo insmod "$PWD/zt9101_ztopmac_usb.ko" cfg="$PWD/wifi.cfg"
echo "done"
sleep 4
