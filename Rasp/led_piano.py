# 키보드를 입력하면 연결된 led와 함께 도레미파솔라시도 소리가 난다. 
import RPi.GPIO as GPIO
import time
from pynput import keyboard
import winsound

GPIO.setmode(GPIO.BCM)

led_C = 17 #11
led_D = 27 #13
led_E = 5 #29
led_F = 6 #31
led_G = 13 #33
led_A = 19 #35
led_B = 23 #16
led_C2 = 24 #18

GPIO.setup(led_C, GPIO.OUT)
GPIO.setup(led_D, GPIO.OUT)
GPIO.setup(led_E, GPIO.OUT)
GPIO.setup(led_F, GPIO.OUT)
GPIO.setup(led_G, GPIO.OUT)
GPIO.setup(led_A, GPIO.OUT)
GPIO.setup(led_B, GPIO.OUT)
GPIO.setup(led_C2, GPIO.OUT)

def blink_LED(led_pin):
    GPIO.output(led_pin, GPIO.HIGH)
    time.sleep(0.2)
    GPIO.output(led_pin, GPIO.LOW)

def sound_SPK(pitch):
    winsound.Beep(pitch, 100)
    print(pitch)

# 음계: 주파수
pitch = {'c': 523, 'd': 587,  'e': 659, 'f': 698, 'g': 784, 'a': 880, 'b': 988, 'c2': 1046}

with keyboard.Events() as events:
    for event in events:
        if event.key == keyboard.Key.esc:
            print("Exit!!")
            break
        elif event.key == keyboard.KeyCode(char='c'):
            blink_LED(led_C)
            sound_SPK(pitch['c'])
        elif event.key == keyboard.KeyCode(char='d'):
            blink_LED(led_D)
            sound_SPK(pitch['d'])
        elif event.key == keyboard.KeyCode(char='e'):
            blink_LED(led_E)
            sound_SPK(pitch['e'])
        elif event.key == keyboard.KeyCode(char='f'):
            blink_LED(led_F)
            sound_SPK(pitch['f'])
        elif event.key == keyboard.KeyCode(char='a'):
            blink_LED(led_A)
            sound_SPK(pitch['a'])
        elif event.key == keyboard.KeyCode(char='b'):
            blink_LED(led_B)
            sound_SPK(pitch['b'])
        elif event.key == keyboard.KeyCode(char='c') and event.key == keyboard.KeyCode(char='2'):
            blink_LED(led_C2)
            sound_SPK(pitch['c2'])

GPIO.cleanup()
