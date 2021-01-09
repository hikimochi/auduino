import time
import serial

ser = serial.Serial()

ser.port = "/dev/tty.usbmodem144401"
ser.baudrate = 115200
ser.setDTR(False)
ser.open()
ser.write(b'g')
time.sleep(5)
ser.close()