def Hanoi(n, start, temp, final):
    if n > 0 :
        Hanoi(n-1, start, final, temp)
        print "Goo Move " + str(n) + " From " + start + " To " + final
        Hanoi(n-1, temp, start, final)

n = int(raw_input('n = '))
Hanoi(n, 'A', 'B', 'C')
