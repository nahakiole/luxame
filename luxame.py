import tkinter as tk
from time import sleep
from tkinter import ttk
import serial

# Initialize serial port (change to your Arduino's port)
ser = serial.Serial('/dev/cu.usbserial-120', 9600)

def send_command(command):
    print(command)
    ser.write(f"{command}\n".encode('utf-8'))
    sleep(0.1)

def turn_on_single_color(color):
    # Turn off all LEDs
    for col in ['blue', 'red', 'yellow', 'green']:
        if col != color:
            send_command(f"{col} 0")
    # Turn on the selected LED
    send_command(f"{color} 1")

# GUI Setup
root = tk.Tk()
root.title("Luxame")

frame = ttk.Frame(root, padding="10")
frame.grid(row=0, column=0)

# Blue LED
ttk.Button(frame, text="Coffee ☕️", command=lambda: turn_on_single_color("blue")).grid(row=0, column=0)

# Red LED
ttk.Button(frame, text="Busy ❌", command=lambda: turn_on_single_color("red")).grid(row=1, column=0)

# Yellow LED
ttk.Button(frame, text="Offline 🍌", command=lambda: turn_on_single_color("yellow")).grid(row=2, column=0)

# Green LED
ttk.Button(frame, text="Available ✅", command=lambda: turn_on_single_color("green")).grid(row=3, column=0)

root.mainloop()

# Close the serial port
ser.close()
