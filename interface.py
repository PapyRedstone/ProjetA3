#!/usr/bin/python3
from functools import partial
from tkinter import *

def writeConsigne(consigneEntry):
    consigne = consigneEntry.get()
    consigneFile = open("consigne.txt", "w")
    consigneFile.write(consigne+"\n")
    consigneFile.close()

def main():
    ihm = Tk()
    consigne = Entry(ihm, textvariable="14.0")
    valider = Button(ihm, text="Valider", command=partial(writeConsigne, consigne))
    labelTint = Label(ihm, text="14.0")
    labelText = Label(ihm, text="14.0")
    labelchauffage = Label(ihm, text="False")

    Text = -1
    Tint = -1
    chauf = False

    consigne.grid(row = 0, column = 0)
    valider.grid(row = 0, column = 1)
    labelText.grid(row = 1, column = 0)
    labelTint.grid(row = 2, column = 0)
    labelchauffage.grid(row = 3, column = 0)
    while ihm.state() == "normal":
        data = open("data.txt", "r")
        lines = data.readlines()
        try:
            Text = float(lines[0])
            Tint = float(lines[1])
            chauf = True if lines[2] == "true\n" else False;
        except:
            pass
        data.close()
        
        labelText.config(text=Text)
        labelTint.config(text=Tint)
        labelchauffage.config(text=str(chauf))
        ihm.update()

if __name__=="__main__":
    main()
