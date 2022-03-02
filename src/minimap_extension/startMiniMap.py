# sudo apt-get install python3-tk
# sudo apt-get install idle3
import tkinter as tk
from idlelib.tooltip import Hovertip

def startMiniMap():
    # create window
    root = tk.Tk()
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