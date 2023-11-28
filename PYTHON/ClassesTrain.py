class TRAIN:
    def __init__(self, destination, number_train, departure_time, arrival_time):
        self.destination = destination
        self.number_train = number_train
        self.departure_time = departure_time
        self.arrival_time = arrival_time
    
    def routeTrainInfo():
        print(f"Number train: {self.number_train}")
        print(f"Destination: {self.destination}")
        print(f"Departure time: {self.departure_time}")
        print(f"Arrival time: {self.arrival_time}")
    

firstTime = str("00:00")
lastTime = str("00:00")

timeInNum1 = firstTime.split(':')
timeInNum2 = lastTime.split(':')

if timeInNum1[0][1] == '0':
    print(timeInNum1[0][0])

# print(timeInNum1, timeInNum2)

# def calculateTime():
#     if int(timeInNum1[0]) > int(timeInNum2[0]):
#         f = 24 - int(timeInNum1[0])
#         time = f + int(timeInNum2[0])
#     print(time)


# k = int(timeInNum2[0]) - int(timeInNum1[0])
# print(k)
# calculateTime()
# for i in range(1, 25):
#     print(i)