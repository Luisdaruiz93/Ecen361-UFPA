Adafruit Guide: https://learn.adafruit.com/adafruit-amg8833-8x8-th...

1. Enable VNC and I2C interfaces:

sudo raspi-config

select "interfacing options"

activate VNC

activate I2C

select <FINISH>

sudo reboot

2. Check to see if I2C is setup correctly

sudo i2cdetect -y 1 (You should see a 69 on column 9)

3. Download and install packages outlined in Adafruit guide

sudo apt-get install -y build-essential python-pip python-dev python-smbus git
git clone https://github.com/adafruit/Adafruit_Python_GPIO....

cd Adafruit_Python_GPIO

sudo python setup.py install

4. Install pygame and scipy

sudo apt-get install -y python-scipy python-pygame
sudo pip install colour Adafruit_AMG88xx

5. Run example script

cd ~/
git clone https://github.com/adafruit/Adafruit_AMG88xx_pyth...

cd Adafruit_AMG88xx_python/examples

sudo python thermal_cam.py
