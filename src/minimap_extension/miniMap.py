# sudo apt-get install python3-tk
# sudo apt-get install idle3
import tkinter as tk
from turtle import window_height, window_width
from idlelib.tooltip import Hovertip
from gameProtocol import GameProtocol

def startMiniMap():
    # define a global list to hold all saved places
    global savedPositions
    savedPositions = []


    # create window
    global root
    root= tk.Tk()
    root.title('MiniMap for PWN Adventure 3')

    # set window size in pixels
    window_width = 350
    window_height = 350

    # get the screen dimension
    screen_width = root.winfo_screenwidth()
    screen_height = root.winfo_screenheight()

    # find the center point
    center_x = int(screen_width/2 - window_width / 2)
    center_y = int(screen_height/2 - window_height / 2)

    # set the position of the window to the center of the screen
    root.geometry(f'{window_width}x{window_height}+{center_x}+{center_y}')

    # create label representing the player
    player = tk.Label(root, bg='red')
    # place player in the centre
    player.place(x=window_width/2, y=window_height/2, height=10, width=10)
    # create tooltip to display 'You' on mouse hover
    Hovertip(player, 'You')

    return root

def setPosition(arguments: list):
    name = arguments[0]
    color = arguments[1]
    landmarkX = arguments[2]
    landmarkY = arguments[3]
    landmarkZ = arguments[4]
    playerX = arguments[5]
    playerY = arguments[6]

    # create a button for new landmark, teleport if clicked
    positionButton = tk.Button(root, bg=color, command = lambda arguments = [landmarkX, landmarkY, landmarkZ] : GameProtocol.call_remote_command('/teleport', arguments))
    # create tooltip to display place name on mouse hover
    Hovertip(positionButton, name)
    # place landmark relative to the player
    realtiveX = landmarkX - playerX + 175
    realtiveY = landmarkX - playerY + 175
    positionButton.place(x= realtiveX, y= realtiveY, height= 10, width= 10)

    # adding landmark to the global list
    savedPositions.append([positionButton,landmarkX,landmarkY])


def updatePositions(arguments: list):
    playerX = arguments[0]
    playerY = arguments[1]

    # re-place all saved landmarks based on player's new position
    for i in range(len(savedPositions)):
        landmarkX = savedPositions[i][1]
        landmarkY = savedPositions[i][2]
        savedPositions[i][0].place(x= landmarkX - playerX + 175, y= landmarkY - playerY + 175, height= 10, width= 10)

    

