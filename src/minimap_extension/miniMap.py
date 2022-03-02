# sudo apt-get install python3-tk
import tkinter as tk
import socket

# function, plot new landmark on map
def addNewLandmark (landmarkX,landmarkY,playerX, playerY,root):
    landmark = tk.Button(
    root,
    bg='black',
    #command = teleport to this location#
    )

    # calculating landmark position relative to player position. should devide by 1000
    landmark.place(x=(landmarkX - playerX + 175), y=(landmarkY - playerY + 175), height=10, width=10)


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
player = tk.Label(
    root,
    bg='red',
)
# place player in the centre
player.place(x=175, y=175, height=10, width=10)

# receive update from game
# to be replaced by the player and the landmark current position
playerX= 90;
playerY= 90;
landmarkX = 200;
landmarkY = 200;
# create socket
#HOST = "127.0.0.1"
#PORT = 65432

#with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    #s.bind((HOST, PORT))
    #s.listen()
    #conn, addr = s.accept()
    #with conn:
        #print(f"Connected by {addr}")
        #while True:
            #data = conn.recv(1024)
            #if not data:
                #break
            #conn.sendall(data)

# if there is an update:
addNewLandmark(landmarkX,landmarkY, playerX, playerY,root)


root.mainloop()



