# file to contain the car class
from typing import Any
from enum import Enum
import queue as Q


class CarType(Enum):
    SEDAN: 1
    TRUCK: 3
    SUV: 2
    CROSSOVER: 4
    OTHER: 5


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




class Garage:

    """ class to represent a garage invariant"""

    cars = []
    fastestQueue = Q.PriorityQueue()
    efficientQueue = Q.PriorityQueue()
    
    count = 0

    ## Constructor
    def __init__(self):
        self.cars = []
        self.count = 0

    def add_car(self, car_entry):
        self.cars.append(car_entry)

    def clear_cars(self):
        self.cars.clear()
       # self.fastestQueue.clear()
       # self.efficientQueue.clear()

    def race_cars(self):
        if self.count == 0:
            return "no cars, no race!"

        return None


class SpeedQueue(Q.PriorityQueue):

    def add_car(self, car):
        car_tuple = (car.speed, car)
        super().put(car_tuple)

