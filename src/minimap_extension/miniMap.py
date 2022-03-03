# sudo apt-get install python3-tk
# sudo apt-get install idle3
import tkinter as tk
from idlelib.tooltip import Hovertip
from .gameProtocol import GameProtocol


Color = {
    'LANDMARK': 'blue',
    'MYSELF': 'green',
    'ENEMY': 'red'
}


class MoveableLabel:
    def __init__(self, x, y, color, canvas: tk.Canvas):
        self.x = x
        self.y = y
        self.canvas = canvas
        self.label = canvas.create_rectangle(x, y, x + 10, y + 10, fill=color)

    def move(self, newX, newY):
        self.canvas.move(self.label, newX - self.x, newY - self.y)
        self.canvas.update()
        self.x = newX
        self.y = newY

class MiniMap:
    def __init__(self, window_width=1000, window_height=1000, title='MiniMap for PWN Adventure 3') -> None:
        self.root = tk.Tk()
        self.root.title(title)

        self.window_width = window_width
        self.window_height = window_height
        
        self.gamemap_width = 80000
        self.gamemap_height = 80000

        self.zoom = self.gamemap_width / self.window_width

        # set the position of the window to the center of the screen
        self.root.geometry(f'{window_width}x{window_height}')

        self.canvas = tk.Canvas(self.root, width=self.window_width, height=self.window_height)
        self.canvas.pack()

        self.moveable_labels = {}

    def drawLandmark(self, name, x, y, z):
        def callback():
            arguments = [x, y, z]
            GameProtocol.call_remote_command('/teleport', arguments)
        
        button = tk.Button(self.root, bg=Color['LANDMARK'], command=callback)
        Hovertip(button, name)

        relativeX, relativeY = self._calculateRelativePosition(x, y)
        button.place(x=relativeX, y=relativeY, height=10, width=10)

    def updateMyselfPosition(self, x, y, z):
        relativeX, relativeY = self._calculateRelativePosition(x, y)
        if 'myself' not in self.moveable_labels.keys():
            self.moveable_labels['myself'] = MoveableLabel(relativeX, relativeY, Color['MYSELF'], self.canvas)
        else:
            self.moveable_labels['myself'].move(relativeX, relativeY)

    def start(self):
        self.root.mainloop()

    def _calculateRelativePosition(self, x, y):
        relativeX = int((x + self.gamemap_width) / self.zoom)
        relativeY = int((y + self.gamemap_height) / self.zoom)

        return relativeX, relativeY


minimap = MiniMap()
