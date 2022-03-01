# sudo apt-get install python3-tk
import tkinter as tk

# to be replaced by the player and the landmark current position
playerX= 90;
playerY= 90;
landmarkX = 200;
landmarkY = 200;

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


player = tk.Button(
    root,
    bg='red',
)
# player in the centre
player.place(x=175, y=175, height=10, width=10)

landmark = tk.Button(
    root,
    bg='black',
)
# calculating landmark position relative to player position. should devide by 1000

landmark.place(x=(landmarkX - playerX + 175), y=(landmarkY - playerY + 175), height=10, width=10)
root.mainloop()

