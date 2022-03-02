# sudo apt-get install python3-tk
# sudo apt-get install idle3
import tkinter as tk
from idlelib.tooltip import Hovertip

def startMiniMap():
    global savedPositions
    global clicked
    savedPositions = []
    clicked = []
    # create window
    global root
    root= tk.Tk()
    root.title('MiniMap PWN Adventure 3')


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
    player.place(x=175, y=175, height=10, width=10)
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

    positionButton = tk.Button(root, bg=color, command = lambda arguments = [landmarkX, landmarkY, landmarkZ] : testCallback(arguments))
    Hovertip(positionButton, name)
    positionButton.place(x= landmarkX - playerX + 175, y= landmarkY - playerY + 175, height= 10, width= 10)

    savedPositions.append([positionButton,landmarkX,landmarkY])


def updatePositions(arguments: list):
    playerX = arguments[0]
    playerY = arguments[1]

    for i in range(len(savedPositions)):
        landmarkX = savedPositions[i][1]
        landmarkY = savedPositions[i][2]
        savedPositions[i][0].place(x= landmarkX - playerX + 175, y= landmarkY - playerY + 175, height= 10, width= 10)


def testCallback(arguments: list):
    print(arguments)

