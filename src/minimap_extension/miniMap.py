# sudo apt-get install python3-tk
# sudo apt-get install idle3
import tkinter as tk
from idlelib.tooltip import Hovertip


def placeLandmark(xCo,yCo):
    # calculating landmark position relative to player position. should devide by 1000
    landmark.place(x=xCo, y=yCo, height=10, width=10)



# we receive an update of the player's location: (x,y)
# or a request to add a new landmark: (x,y,name,color)

# testing
playerX= 90
playerY= 90
landmarkX = 200
landmarkY = 200
name='house'
color='black'

# when receive an update of the player's location, for all landmarks, replace them realtive to the new coordinates
# placeLandmark(landmarkX - playerX + 175, landmarkY - playerY + 175)

# add a new landmark
# create button
landmark = tk.Button(root, bg=color,#command = teleport to this location#
    )
Hovertip(landmark, name)
#place it
placeLandmark(landmarkX - playerX + 175, landmarkY - playerY + 175)



# root.mainloop()



