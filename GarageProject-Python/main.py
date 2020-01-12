# Welcome to Garage Project!
from Car import CarType, type_map, Car, Garage

## Globals to quit program and control verbosity of output
quit_command = False
verbose = False

## Prints the list of commands so user knows what to do
def print_options(gar):
    my_str = "You can: "
    print(my_str)
    return None

# Toggles verbosity
# Verbosity controls how much output the user gets after each action
def toggle_verbosity(gar):
    print("toggling Verbosity")
    global verbose
    verbose = not verbose
    print ("Verbose: " + str(verbose))

# Adds a car to the database
def add_car(gar):
    
    print("What type of car?\n")
    # cast character to lower case so that it's not case sensitive
    user_choice = input("   A. SUV \n B. Sedan \n C. Truck \n D. Crossover: \n E. Other: \n").lower()
    # if user enters any other character than A-D it will be "other"
    select_type = type_map.get(user_choice, CarType.OTHER)
    
    make_model_str = input("What year, make, and model is your car? Enter year, make, then model, with spaces in between: ")

    try:
        select_year, select_make, select_model = make_model_str.split(" ")
    except:
        packed = make_model_str.split(" ")
        select_year = packed[0]
        select_make = packed[1]
        select_model = packed[2]

    select_speed = input("What is the max speed?")
    select_mpg  = input("What is the average MPG?")

  


    print("thanks! Processing...")


    # error check to make sure all values are correct and reasonable
    error = gar.error_check(select_year, select_make, select_model, select_mpg, select_speed)

    # create car model, add it to the garage
    car_entry = Car(select_make,select_model,select_type,select_year,select_speed,select_mpg)
    gar.add_car(car_entry)

    print("Added car successfully!")


# Adds multiple cars to database from an input file
# If any errors pop up, doesn't add any car
def add_cars_from_file(gar):
    print("adding cars from file")

# Simulates a race of all cars in database
def race_cars(gar):
    gar.race_cars()

# Empties database of all cars
def clear_cars(gar):
    gar.clear_cars()

# Lists all cars in database
def list_cars(gar):
    gar.list_cars()

# Lists stats about fastest car, most efficient, etc.
def get_data(gar):
    print("Getting data about cars")

# Allows user to make traditional SQL-style queries on database
def query_data(gar):
    print("querying data from cars")

# Prints out a giant help message to list all the commands
def help_msg(gar):
    print("Help Message!")
# Quits the program
def quit_program(gar):
    print("Goodbye!")
    global quit_command
    quit_command = True

# Default function to hit whenever giberrish is entered
def print_unrecognized(gar):
    print("unrecognized command!")


func_map = {

    "v": toggle_verbosity,
    "add": add_car,
    "addfile": add_cars_from_file,
    "clear": clear_cars,
    "list": list_cars,
    "data": get_data,
    "help": help_msg,
    "query": query_data,
    "quit": quit_program,

}


def main():
    print("Hello! \n")

    gar = Garage()


    while not quit_command:
        command_func = None
        user_command = input("What do you want to do next?")
        command_func = func_map.get(user_command.lower(), print_unrecognized)
        command_func(gar)


if __name__ == '__main__':
    main()

