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
    

firtTime = str(input())
lastTime = str(input())

timeInNum1 = firstTime.split(':')
timeInNum2 = lastTime.split(':')

for 