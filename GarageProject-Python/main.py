# Welcome to Garage Project!
from Car import Car, Garage

## Globals to quit program and control verbosity of output
quit_command = False
verbose = False


def print_options():
    my_str = "You can: "
    print(my_str)
    return None


def toggle_verbosity():
    print("toggling Verbosity")

def add_car():
    print("Adding car")

def add_cars_from_file():
    print("adding cars from file")

def race_cars():
    print("racing cars")

def clear_cars():
    print("clearing cars")

def list_cars():
    print("listing cars")

def get_data():
    print("Getting data about cars")

def query_data():
    print("querying data from cars")

def help_msg():
    print("Help Message!")

def quit_program():
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
    print("Hello! :\n")
    while not quit_command:
        command_func = None
        user_command = input("What do you want to do next?")
        command_func = func_map.get(user_command.lower(), None)
        if command_func:
            command_func()
        else:
            print("unrecognized command!")


if __name__ == '__main__':
    main()

