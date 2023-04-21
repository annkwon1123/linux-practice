import RPi.GPIO as rg
import time

rg.setmode(rg.BCM)

ledPlusPin = 17
greenPin = 27

try:
    while True:
        rg.output(ledPlusPin, rg.LOW)
        rg.output(greenPin, rg.HIGH)
        time.sleep(1)
        rg.output(ledPlusPin, rg.HIGH)
        rg.output(greenPin, rg.LOW)
        time.sleep(1)
except KeyboardInterrupt:
    rg.cleanup()
