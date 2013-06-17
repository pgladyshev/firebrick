#!/bin/sh
#
# Firebrick main script
# last edit 17/06/2013 - Lee Tobin

lcd c
#lcd g 0 1; lcd p "FIRE Brick v1.0"
#lcd g 0 2; lcd p "http://dfire.ucd.ie/"

#--- Check the LCD device nodes
#Get LCD location on USB bus
lcdnodeinfo=$(lsusb | grep 0403:c630)
IFS=' '
set --  $lcdnodeinfo
lcdnodedir=/dev/bus/usb/$2
lcdnode=$lcdnodedir/${4%?}

if [ ! -d $lcdnodedir ]; then
	#create dev dir
	mkdir $lcdnodedir
fi

if [ ! -f $lcdnode ]; then
	#Get major and min dev ids
	deviceline=$(dmesg | grep 'idVendor=0403' | tail -1)
	set -- $deviceline
	cd /sys/bus/usb/devices/${4%?}

	majnum=$(grep MAJOR uevent)
	minnum=$(grep MINOR uevent)

	IFS='='
	set -- $majnum
	majnum=$2
	set -- $minnum
	minnum=$2

	#make the device node
	mknod $lcdnode c $majnum $minnum
	cd /scripts
fi

lcd o 190

sh main.sh 