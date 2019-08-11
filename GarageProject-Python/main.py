# Welcome to Garage Project!
from Car import Car, Garage


def print_options():
    my_str = "You can: "
    print(my_str)
    return None


def toggle_verbosity():
    pass

def add_car():
    pass

def add_cars_from_file():
    pass

def race_cars():
    pass

def clear_cars():
    pass

def list_cars():
    pass

def get_data():
    pass

def query_data():
    pass

def help_msg():
    pass


func_map = {

    "v": toggle_verbosity,
    "add": add_car,
    "addfile": add_cars_from_file,
    "clear": clear_cars,
    "list": list_cars,
    "data": get_data,
    "help": help_msg,
    "query": query_data

}

quit_command = False
verbose = False

def main():
    print("Hello! :\n")
    while not quit_command:
        command_func = None
        user_command = input("What do you want to do next?")
        command_func = func_map.get(user_command.lower())
        if command_func is not None:
            command_func()
        else:
            print("unrecognized command!")


if __name__ == '__main__':
    main()

