# file to contain the car class
from enum import Enum
import queue as Q


class CarType(Enum):
    SEDAN= 1,
    TRUCK= 3,
    SUV= 2,
    CROSSOVER= 4,
    OTHER= 5

class ErrorType(Enum):
    YEAR=1,
    MAKE=2,
    MODEL=3,
    MPG=4,
    SPEED=5,
    NONE= 0


type_map = {

    'a': CarType.SUV,
    'b': CarType.SEDAN,
    'c': CarType.TRUCK,
    'd': CarType.CROSSOVER,
    'e': CarType.OTHER
}


class Car:

    """Class to represent a car invariant"""
    
    idCounter = 1000

    def __init__(self, make, model, type, year, speed, mpg, pos=None):
        self.make = make
        self.model = model
        self.type = type
        self.year = year
        self.speed = speed
        self.mpg = mpg
        self.uniqID = Car.idCounter
        Car.idCounter = Car.idCounter + 1

        if pos is not None:
            self.pos = pos

    def __str__(self):
        return "({self.make})"



class Garage:

    """ class to represent a garage invariant"""


    ## Constructor
    def __init__(self):
        self.cars = []
        self.count = 0

        self.fastestQueue = Q.PriorityQueue()
        self.efficientQueue = Q.PriorityQueue()


    def add_car(self, car_entry):
        self.cars.append(car_entry)

    def list_cars(self):
        for car in self.cars:
            print(car)

    def clear_cars(self):
        self.cars.clear()
       # self.fastestQueue.clear()
       # self.efficientQueue.clear()

    def race_cars(self):
        if self.count == 0:
            print( "no cars, no race!")
        
        print("racing cars!")
        return None

    def error_check(self, *args):
        return True


class SpeedQueue(Q.PriorityQueue):

    def add_car(self, car):
        car_tuple = (car.speed, car)
        super().put(car_tuple)

