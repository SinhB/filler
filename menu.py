#!/usr/bin/python

import sys
import os
from Tkinter import *

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
		warn['text'] = 'Field empty'
	else:
		warn['text'] = 'Lets kick it!'
		cmd = "./filler_vm -f maps/"+mp+" -p1 players/"+pl1+" -p2 players/"+pl2+" | python visu.py"
		os.system(cmd)

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
		self.root.configure(background= 'white')
		self.root.title("Filler Menu")
		self.root.geometry("650x300")
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

Menu().menu()
