# sudo apt-get install python3-tk
# sudo apt-get install idle3
import tkinter as tk
from idlelib.tooltip import Hovertip

def setPosition(arguments: list):
    category = arguments[0]
    name = arguments[1]
    color = arguments[2]
    landmarkX = arguments[3]
    landmarkY = arguments[4]
    landarkZ = arguments[5]
    playerX = arguments[6]
    playerY = arguments[7]

    landmark = tk.Button(root, bg=color,#command = teleport to this location#
    )
    Hovertip(landmark, name)
    landmark.place(landmarkX - playerX + 175, landmarkY - playerY + 175)

