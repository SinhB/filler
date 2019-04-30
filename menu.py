#!/usr/bin/python

import sys
import os
#from Tkinter import *
import Tkinter as tk
def close(event):
	sys.exit()

def get_name1(name1, str, self):
	name1['text'] = str

def get_name2(name2, str, self):
	name2['text'] = str

def get_map(map, str, self):
	map['text'] = str

def start_game(pl1, pl2, mp, self, warn):
	if not pl1 or not pl2 or not mp:
		warn['text'] = 'Empty field'
	else:
		cmd = "./filler_vm -f maps/"+mp+" -p1 players/"+pl1+" -p2 players/"+pl2+" | python visu.py"
		os.system(cmd)
		with open('filler.trace', 'r') as file:
			line = file.read().split('\n')[1]
		line = line.replace("players/", "")
		line = line.replace(".filler", "")
		warn['text'] = line

class Menu:
	def __init__(self):
		self.finished = False
		self.init_root()
		name1 = Label(self.root, foreground='cyan', background='white')
		name1.grid(padx=50, row=10, column=0)
		name2 = Label(self.root, foreground='purple', background='white')
		name2.grid(padx=50, row=10, column=2)
		map = Label(self.root, foreground='black', background='white')
		map.grid(padx=50, row=10, column=1)
		self.list1(name1)
		self.list2(name2)
		self.list3(map)
		label1 = Label(self.root, text='Select player 1', foreground='cyan', background='white')
		label1.grid(padx=50, row=0, column=0)
		label2 = Label(self.root, text='Select player 2', foreground='purple', background='white')
		label2.grid(padx=50, row=0, column=2)
		label3 = Label(self.root, text='Select Map', foreground='black', background='white')
		label3.grid(padx=50, row=0, column=1)
		warn = Label(self.root, foreground='red', background='white')
		warn.grid(padx=50, row=100, column=1)
		go = Button(self.root, text='Go!!', foreground='red', background='white', command=lambda: start_game(name1['text'], name2['text'], map['text'], self, warn))
		go.grid(padx=50, row=50, column=1)
		self.root.mainloop()


	def init_root(self):
		self.root = Tk()
		self.root.resizable(width=False, height=False)
		self.root.configure(background= 'white')
		self.root.title("Filler Menu")
		self.root.geometry("680x300")
		self.root.bind('<Escape>', close)

	def list1(self, name1):
		lst = self.player_names()
		for x, item in enumerate(lst, start=1):
			button = Button(self.root, text=item, foreground='purple', background='black', command=lambda arg=item: get_name1(name1, arg, self))
			button.grid(padx=50, row=x, column=0, sticky="NSEW")

	def list2(self, name2):
		lst = self.player_names()
		for x, item in enumerate(lst, start=1):
			button = Button(self.root, text=item, foreground='purple', background='black', command=lambda arg=item: get_name2(name2, arg, self))
			button.grid(padx=50, row=x, column=2, sticky="NSEW")

	def list3(self, map):
		lst = self.map_number()
		for x, item in enumerate(lst, start=1):
			button = Button(self.root, text=item, foreground='purple', background='black', command=lambda arg=item: get_map(map, arg, self))
			button.grid(padx=50, row=x, column=1, sticky="NSEW")

	def player_names(self):
		l = []
		for file in os.listdir("./players"):
				if file.endswith(".filler"):
					l.append(file)
		return l;

	def map_number(self):
		l = []
		for file in os.listdir("./maps"):
					l.append(file)
		return l;

class Example(tk.Frame):
    def __init__(self, parent):
        tk.Frame.__init__(self, parent)
        f1 = GradientFrame(self, borderwidth=1, relief="sunken")
        f2 = GradientFrame(self, "green", "blue", borderwidth=1, relief="sunken")
        f1.pack(side="top", fill="both", expand=True)
        f2.pack(side="bottom", fill="both", expand=True)

class GradientFrame(tk.Canvas):
    '''A gradient frame which uses a canvas to draw the background'''
    def __init__(self, parent, color1="red", color2="black", **kwargs):
        tk.Canvas.__init__(self, parent, **kwargs)
        self._color1 = color1
        self._color2 = color2
        self.bind("<Configure>", self._draw_gradient)

    def _draw_gradient(self, event=None):
        '''Draw the gradient'''
        self.delete("gradient")
        width = self.winfo_width()
        height = self.winfo_height()
        limit = width
        (r1,g1,b1) = self.winfo_rgb(self._color1)
        (r2,g2,b2) = self.winfo_rgb(self._color2)
        r_ratio = float(r2-r1) / limit
        g_ratio = float(g2-g1) / limit
        b_ratio = float(b2-b1) / limit

        for i in range(limit):
            nr = int(r1 + (r_ratio * i))
            ng = int(g1 + (g_ratio * i))
            nb = int(b1 + (b_ratio * i))
            color = "#%4.4x%4.4x%4.4x" % (nr,ng,nb)
            self.create_line(i,0,i,height, tags=("gradient",), fill=color)
        self.lower("gradient")

if __name__ == "__main__":
    root = tk.Tk()
    Example(root).pack(fill="both", expand=True)
    root.mainloop()

#Menu().menu()
