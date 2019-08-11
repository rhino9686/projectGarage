## Project Garage

Project Garage is a pseudo-database for storing automobile models, running statistical analyses on them, and simulating a race. The main edition will be written in C++, with a secondary version written in Python.
The current edition only runs as a command-line application, with no GUI or persistent data. The main purpose of this project is to strengthen knowledge of C++, OOP principles, and file input/output management.

### Installation
We will make a tar.gz later for easy downloading when we have a stable build. For now just download the files or clone the directory.

### Building
There is a makefile with build commands for Linux platforms, coming soon for Windows/OS X.

To build the main application, use `make garage`.
To compile the test suites, use `make tests`.

### Usage
On startup, you will just run the `./garage` executable from the command line, and will be shown a startup message.

#### The Car:
	The model for a car contains a few fields:

		‘Make’:
		‘Model’:
		‘Year’:
		‘Speed’:
		‘Mpg’:
		‘Type’:
		‘uniqID’:
    Usage rules for the garage program:  
        
#### Commands:  
    'Add'  : adds a singular car to your garage.   
    'Clear': clears all cars from the garage.  
    'List' : lists all cars currently in your garage.  
    'Data' : displays useful information about the cars as a whole.    
    'Race' : simulates a race of your cars and tell you the winner.   
    'Quit' : exits the program.    
        
#### Verbosity:    
    'V' will toggle verbosity of the program, 
    which controls how much output you want when you enter other commands.    
        
#### Multiple Car Input:
    The garage program can handle multiple cars being entered, 
    allowing large datasets to be processed.    
    ‘Addfile' will allow you to submit a text file with car data to input multiple cars at once. 
    It should be a plaintext document, [.txt or equivalent].   
    file input format should be split into lines of parameters,
    with each line formatted as such:    

        [Car Make] [Model] [Type] [Year] [Speed] <end of line> 
    
    All separated by spaces. Data should be valid, or the program will exit with an error.    


### Testing
We are making our own unit test files with the C assert library. The two test files right now are testCars.cpp and testGarage.cpp, which cover most functionality.
To run the tests make the test executables with the `make tests` command and run each one separately.


### Contributing
Right now we are still working on the first working version, and working out the potential bugs and kinks in the UI.
After the first version is completed, we will open up for contributors.


## Authors

* **Robert Cecil** - *Initial work* - [My Page](https://github.com/rhino9686)

## License
[MIT](https://choosealicense.com/licenses/mit/)
