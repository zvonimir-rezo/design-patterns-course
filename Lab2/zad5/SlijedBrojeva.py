from multiprocessing.connection import Listener
import time
from typing import List

from Izvor import TipkovnickiIzvor

class ListenerSlijed:
    def __init__(self, func) -> None:
        self.numberAdded = func


class SlijedBrojeva:
    def __init__(self, izvor) -> None:
        self.elements = []
        self.izvor = izvor
        self.listeners = []

    def addListener(self, l: ListenerSlijed):
        self.listeners.append(l)
    
    def removeListener(self, l: ListenerSlijed):
        self.listeners.remove(l)

    def kreni(self):
        while True:
            br = self.izvor.nextInt()
            if br == -1: 
                break
            self.elements.append(br)
            time.sleep(1)

def find_median(l):
    sorted_l = sorted(l)
    if len(sorted_l) % 2 != 0:
        m = int((len(sorted_l)+1)/2 - 1)
        return sorted_l[m]
    else:
        m1 = int(len(sorted_l)/2 - 1)
        m2 = int(len(sorted_l)/2)
        return (sorted_l[m1]+sorted_l[m2])/2

def main():
    tipkovnicki_izvor = TipkovnickiIzvor()
    slijed = SlijedBrojeva(tipkovnicki_izvor)

    slijed.addListener(ListenerSlijed(lambda l: print(f"Sum: {sum(l)}")))
    slijed.addListener(ListenerSlijed(lambda l: print(f"Average: {sum(l) / len(l)}")))
    slijed.addListener(ListenerSlijed(lambda l: print(f"Median: {find_median(l)}")))

    slijed.kreni()

main()