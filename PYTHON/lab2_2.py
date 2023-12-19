class TRAIN:
    def __init__(self, pn, nt, tout, tinp):
        self.pn = pn
        self.nt = nt
        self.tout = tout
        self.tinp = tinp
    def get_info(self):
        print('Пункт назначения:', self.pn)
        print('Номер поезда:', self.nt)
        print('Время отбытия:', self.tout)
        print('Время прибытия:', self.tinp)
    def get_nt(self):
        return self.nt
    def get_pn(self):
        return self.pn
    def time(self):
        a = self.tout.split(':')[0]
        b = self.tout.split(':')[1]
        c = self.tinp.split(':')[0]
        d = self.tinp.split(':')[1]
        if a > c:
            timH = 24 - (int(a) - int(c))
        else:
            timH = int(c) - int(a)
        if b > d:
            timM = int(b) - int(d)
        else:
            timM = int(d) - int(b)
        timH = str(timH)
        timM = str(timM)
        if(len(timM) == 1):
            timM = '0'+ timM
        if(len(timH) == 1):
            timH = '0'+ timH
        return(timH + ':' + timM)

trains = list()
n = 0
def trainslist(a):
    trains.append(a)
    return trains

def sort_time(tr):
    return(sorted(tr,key=lambda train: train.tout))

def fastest(pn,t):
    tmp = True
    for i in trains:
        if pn == i.get_pn() and (int(t.split(':')[0]) > int(i.time().split(':')[0])):
            tmp = False
            i.get_info()
    if tmp == True:
        print('Нет таких поездов')

while(n == 0):
    print('Введите 1 для добавления поездов')
    print('Введите 2 для вывода информации о всех поездах')
    print('Введите 3 для вывода информации поезда по его номеру')
    print('Введите 4 для вывода времени поезда в пути по его номеру')
    print('Введите 5 для сортировки поездов по времени')
    print('Введите 6 для вывода быстрого поезда в указанный пункт назначения')
    print('Введите 7 для выхода')
    n = input()
    if(n.isdigit() != True):
        print('Введите корректное число')
        n = 0
    n = int(n)
    if(n == 1):
        c = input('Введите количество добавляемых поездов: ')
        while (c.isdigit() == False) or (list(c)[0] == '0'):
            print('Введите корректное число')
            c = input('Введите количество добавляемых поездов: ')
        for i in range(int(c)):
            pn = input('Введите пункт назначения: ')
            nt = input('Введите номер поезда: ')
            while(nt.isdigit() == False):
                print('Введите корректное число')
                nt = input('Введите номер поезда: ')
            tout = input('Введите время отбытия чч:мм: ')
            while(int(tout.split(':')[0]) > 23 or int(tout.split(':')[1]) > 59):
                print('Введите корректные данные')
                tout = input('Введите время отбытия чч:мм: ')
            tinp = input('Введите время прибытия чч:мм: ')
            while (int(tinp.split(':')[0]) > 23 or int(tinp.split(':')[1]) > 59):
                print('Введите корректные данные')
                tinp = input('Введите время отбытия чч:мм: ')
            a = TRAIN(pn, nt, tout, tinp)
            trainslist(a)
        print('Данные успешно введены!')
        n = 0
    if(n == 2):
        for i in trains:
            i.get_info()
        n = 0
    if(n == 3):
        c = int(input('Введите номер поезда: '))
        for i in trains:
            if int(i.get_nt()) == c:
                i.get_info()
        n = 0
    if(n == 4):
        c = int(input('Введите номер поезда: '))
        for i in trains:
            if int(i.get_nt()) == int(c):
                print('Поезд номер:', i.get_nt(),'\n','В пути:', i.time())
        n = 0
    if(n == 5):
        for i in sort_time(trains):
            i.get_info()
        n = 0
    if(n == 6):
        pn = input('Введите название пункта назначения: ')
        t = input('Введите время пути в формате чч:мм: ')
        while (int(t.split(':')[0]) > 23 or int(t.split(':')[1]) > 59):
            print('Введите корректные данные!')
            t = input('Введите время пути в формате чч:мм: ')
        fastest(pn,t)
        n = 0