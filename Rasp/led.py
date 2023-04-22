import RPi.GPIO as GPIO
import time
import random

GPIO.setmode(GPIO.BCM)
redLED = 17
greenLED = 27
GPIO.setup(redLED, GPIO.OUT)
GPIO.setup(greenLED,GPIO.OUT)

def blink_LED(led_pin):
    GPIO.output(led_pin, GPIO.HIGH)
    time.sleep(random.uniform(1, 3))
    GPIO.output(led_pin, GPIO.LOW)

def wait_KEY():
    start_time = time.time()
    input("if the ligh off, Press the enter KEY\n")
    return time.time() - start_time

def start_GAME():
    print("GAME START(1/2)\n")
    blink_LED(redLED)
    reaction1 = wait_KEY()
    
    print("GAME START(2/2)\n")
    blink_LED(greenLED)
    reaction2 = wait_KEY()

    print("reaction1: %.3f sec\n" %reaction1)
    print("reaction2: %.3f sec\n" %reaction2)

start_GAME()

GPIO.cleanup()
