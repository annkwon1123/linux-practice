import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
led_pin1 = 17
led_pin2 = 27
led_pin3 = 5
led_pin4 = 6

GPIO.setup(led_pin1, GPIO.OUT)
GPIO.setup(led_pin2, GPIO.OUT)
GPIO.setup(led_pin3, GPIO.OUT)
GPIO.setup(led_pin4, GPIO.OUT)

def start():
    try:
        while(1):
            sec = time.time()
            number = int(sec%16)
            
            print(sec, number)

            if(number & 0b0001):
                GPIO.output(led_pin1, GPIO.HIGH)
            else:
                GPIO.output(led_pin1, GPIO.LOW)
            if(number & 0b0010):
                GPIO.output(led_pin2, GPIO.HIGH)
            else:
                GPIO.output(led_pin2, GPIO.LOW)
            if(number & 0b0100):
                GPIO.output(led_pin3, GPIO.HIGH)
            else:
                GPIO.output(led_pin3, GPIO.LOW)
            if(number & 0b1000):
                GPIO.output(led_pin4, GPIO.HIGH)
            else:
                GPIO.output(led_pin4, GPIO.LOW)

    except KeyboardInterrupt:
        GPIO.cleanup()

start()

GPIO.cleanup()
