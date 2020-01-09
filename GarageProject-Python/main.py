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

# verbosity controls how much output the user gets after each action
def toggle_verbosity(gar):
    print("toggling Verbosity")
    global verbose
    verbose = not verbose
    print ("Verbose: " + str(verbose))

# adds a car to the database
def add_car(gar):
    
    print("What type of car?\n")
    user_choice = input("   A. SUV \n B. Sedan \n C. Truck \n D. Crossover: \n E. Other: \n").lower()
    select_type = type_map.get(user_choice, CarType.OTHER)

    make_model_str = input("What year, make, and model is your car? Enter year, make, then model, with spaces in between: \n")

    select_year, select_make, select_model = make_model_str.split(" ")

    select_speed = input ("What is the max speed?\n")
    select_mpg  = input("What is the average MPG?\n")

    print("thanks! Processing...")

    car_entry = Car(select_make,select_model,select_type,select_year,select_speed,select_mpg)

    print("Adding car")

# adds multiple cars to database from an input file
# if any errors pop up, doesn't add any car
def add_cars_from_file(gar):
    print("adding cars from file")

# simulates a race of all cars in database
def race_cars(gar):
    print("racing cars")

# empties database of all cars
def clear_cars(gar):
    print("clearing cars")

# lists all cars in database
def list_cars(gar):
    print("listing cars")

# lists stats about fastest car, most efficient, etc.
def get_data(gar):
    print("Getting data about cars")

# allows user to make traditional SQL-style queries on database
def query_data(gar):
    print("querying data from cars")


def help_msg(gar):
    print("Help Message!")

def quit_program(gar):
    print("Goodbye!")
    global quit_command
    quit_command = True


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
        user_command = input("What do you want to do next? \n")
        command_func = func_map.get(user_command.lower(), None)
        if command_func:
            command_func(gar)
        else:
            print("unrecognized command!")


if __name__ == '__main__':
    main()

