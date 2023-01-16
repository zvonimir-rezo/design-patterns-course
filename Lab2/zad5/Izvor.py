
class Izvor:
    def nextLine():
        pass
    def nextInt():
        pass


class TipkovnickiIzvor(Izvor):
    def nextLine(self):
        return input("Enter input: ")
    
    def nextInt(self):
        return int(input("Enter integer: "))


class DatotecniIzvor(Izvor):
    def __init__(self, path) -> None:
        self.file = open(path, 'r')

    def nextLine(self):
        return self.file.readline()

    def nextInt(self):
        return int(self.file.readline())