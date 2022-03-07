# sudo apt-get install python3-tk
# sudo apt-get install idle3
import tkinter as tk
import os
from idlelib.tooltip import Hovertip

from .gameProtocol import GameProtocol


DIR = os.path.dirname(os.path.realpath(__file__))


Color = {
    'LANDMARK': 'blue',
    'MYSELF': 'green',
    'ENEMY': 'red'
}

IconImage = {
    'LANDMARK': os.path.join(DIR, 'imgs/landmark.png'),
    'EGG': os.path.join(DIR, 'imgs/egg.png'),
    'BACKGROUND': os.path.join(DIR, 'imgs/map.png'),
    'MYSELF': os.path.join(DIR, 'imgs/mario.png')
}


class MoveableLabel:
    def __init__(self, x, y, img_path, canvas: tk.Canvas):
        self.x = x
        self.y = y
        self.canvas = canvas
        self.img = tk.PhotoImage(img_path)
        self.img = self.img.subsample(30, 30)
        self.label = canvas.create_image(x, y, image=self.img)

    def move(self, newX, newY):
        self.canvas.move(self.label, newX - self.x, newY - self.y)
        self.canvas.update()
        self.x = newX
        self.y = newY

class MiniMap:
    def __init__(self, title='MiniMap for PWN Adventure 3') -> None:
        self.root = tk.Tk()
        self.root.title(title)

        background_img = tk.PhotoImage(file=IconImage['BACKGROUND'])
        self.window_width = background_img.width()
        self.window_height = background_img.height()
        
        self.gamemap_width = 80000
        self.gamemap_height = 80000

        self.zoom = self.gamemap_width * 2 / self.window_width

        # set the position of the window to the center of the screen
        self.root.geometry(f'{self.window_width}x{self.window_height}')

        self.canvas = tk.Canvas(self.root, width=self.window_width, height=self.window_height)
        self.canvas.pack()

        # Add background after canvas to show background above canvas
        backgraound = tk.Label(self.root, image=background_img)
        backgraound.image = background_img
        backgraound.place(x=0, y=0, relheight=1, relwidth=1)

        self.moveable_labels = {}

    def drawLandmark(self, name, x: int, y: int, z: int):
        def callback():
            arguments = [x, y, z]
            GameProtocol.call_remote_command('/teleport', arguments)

        img = tk.PhotoImage(file=IconImage['LANDMARK'])
        smallImg = img.subsample(40,40)
        self.imgs.append(smallImg)
        button = tk.Button(self.root, image=smallImg, command=callback)
        # Add a reference as an attribute to avoid img from being destoried by gc
        button.image = smallImg
        Hovertip(button, name)

        relativeX, relativeY = self._calculateRelativePosition(x, y)
        button.place(x=relativeX, y=relativeY)

    def drawEgg(self, name, x: int, y: int, z: int):
        def callback():
            arguments = [x, y, z]
            GameProtocol.call_remote_command('/teleport', arguments)
        
        img = tk.PhotoImage(file = IconImage['EGG'])
        smallImg = img.subsample(40, 40)
        button = tk.Button(self.root, image=smallImg, command=callback)
        # Add a reference as an attribute to avoid img from being destoried by gc
        button.image = smallImg
        Hovertip(button, name)

        relativeX, relativeY = self._calculateRelativePosition(x, y)
        button.place(x=relativeX, y=relativeY) 

    def updateMyselfPosition(self, x: int, y: int, z: int):
        relativeX, relativeY = self._calculateRelativePosition(x, y)
        if 'myself' not in self.moveable_labels.keys():
            self.moveable_labels['myself'] = MoveableLabel(relativeX, relativeY, Color['MYSELF'], self.canvas)
        else:
            self.moveable_labels['myself'].move(relativeX, relativeY)

    def start(self):
        self.root.mainloop()

    def _calculateRelativePosition(self, x, y):
        relativeX = int((x + self.gamemap_width)/2 / self.zoom)
        relativeY = int((y + self.gamemap_height)/2 / self.zoom)

        return relativeX, relativeY


minimap = MiniMap()


