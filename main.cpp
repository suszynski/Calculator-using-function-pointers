#include <iostream>
#include <limits>
#include <functional>


using ArithmeticFunction = std::function<int(int, int)>;



void ignoreLine() // Clears the input buffer.
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


// Clears bad input and returns true if the input was invalid.
bool clearInput()
{
	if (!std::cin)
	{
		std::cin.clear();
		ignoreLine();
		return true;
	}
	return false;
}


// Function to prompt the user to enter an integer and handle invalid inputs
int askNumber()
{

	int number{};

	while (true)
	{
		std::cout << "Enter your integer: ";
		
		std::cin >> number;

		// Check for invalid input
		if (clearInput()) 
		{
			std::cerr << "Wrong input. Try again.\n";
			continue;
		}
		ignoreLine(); // Clear any remaining input from the buffer
		return number;
	}

}


// Arithmetic operation functions
int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int divide(int x, int y)
{
	return x / y;
}



// Function to prompt the user to enter an arithmetic operation and handle invalid inputs
char askOperation()
{
	char operation{};

	while (true)
	{
		std::cout << "Enter a valid operation. (+, -, *, /) ";
		std::cin >> operation;

		// Check for invalid input or invalid operation
		if (clearInput() || (operation != '+' && operation != '-' && operation != '*' && operation != '/'))
		{
			std::cerr << "Wrong input. Try again.\n";
			continue;
		}
		ignoreLine(); // Clear any remaining input from the buffer
		return operation;
	}

}

// Function to get the corresponding arithmetic function based on the operation
ArithmeticFunction getArithmeticFunction(char operation)
{
	switch (operation)
	{
	case '+':
		return ArithmeticFunction{ &add };

	case '-':
		return ArithmeticFunction{ &subtract };

	case '*':
		return ArithmeticFunction{ &multiply };

	case '/':
		return ArithmeticFunction{ &divide };

	default:
		return nullptr;
	}
}


// Function to print the result sentence based on the operation (returns false if the program should close due to an error)
bool outputSentence(char operation)
{
	switch (operation)
	{
	case '+':
		std::cout << "Your addition result is: ";
		return true;

	case '-':
		std::cout << "Your subtraction result is: ";
		return true;

	case '*':
		std::cout << "Your multiplication result is: ";
		return true;

	case '/':
		std::cout << "Your division result is: ";
		return true;

	default:
		std::cerr << "Error occurred.";
		return false;
	}
}









int main()
{

	int number1{ askNumber() };
	int number2{ askNumber() };

	char operation{ askOperation()};

	int result{ (getArithmeticFunction(operation))(number1, number2) }; // Get the corresponding arithmetic function and compute the result

	if (!outputSentence(operation))
	{
		return 1; // Exit with an error code if an invalid operation
	}
	else
	{
		std::cout << result << '\n';
	}

	return 0;
}