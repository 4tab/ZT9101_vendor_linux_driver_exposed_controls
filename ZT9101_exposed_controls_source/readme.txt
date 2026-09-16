export HOST_PLAT=pc                    (新环境需要在platform.mak中添加)

需要打印信息，在Makefile配置CONFIG_DEBUG = y
wext和nl80211在Makefile配置CONFIG_WIFI_FRAMEWORK
make clean
make

// 驱动加载
insmod zt9101_ztopmac.ko cfg=./wifi.cfg
若Makefile里CONFIG_WIFI_FRAMEWORK配置为nl80211时insmod error出现Unknown symbol in module,
请先执行modprobe cfg80211

加载驱动出现firmware open failed，请确保wifi.cfg里“fw=./fw/ZT9101_fw_r2325.bin”固件信息正确

// 驱动卸载
rmmod zt9101_ztopmac

