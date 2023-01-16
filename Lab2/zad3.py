def mymax(iterable, key=lambda x: x):
    max_x = iterable[0]
    max_key = key(iterable[0])

    for x in iterable:
        if (key(x) > max_key):
            max_x = x
            max_key = key(x)

    return max_x

f = lambda x: len(x)

print(mymax(["rijec", "duzarijec", "najduzarijec", "kracarijec"], f))


maxint = mymax([1, 3, 5, 7, 4, 6, 9, 2, 0])
maxchar = mymax("Suncana strana ulice")
maxstring = mymax([
  "Gle", "malu", "vocku", "poslije", "kise",
  "Puna", "je", "kapi", "pa", "ih", "njise"])

print("Max int: ", maxint)
print("Max char: ", maxchar)
print("Max string: ", maxstring)

D={'burek':8, 'buhtla':5}
f = lambda x: D.get(x)

#print("Najskuplji proizvod je:", mymax(D, f))

osobe = [("Marko", "Maric"), ("Pero", "Peric"), ("Mario", "Simic"), ("Luka", "Modric")]
f = lambda x: x[1]

print(mymax(osobe, f))