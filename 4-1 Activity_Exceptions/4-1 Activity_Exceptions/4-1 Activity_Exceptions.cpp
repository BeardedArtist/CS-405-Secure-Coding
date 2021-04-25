// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool do_even_more_custom_application_logic()
{

    // TODO: Throw any standard exception
    // 
    // COMPLETED: Throwing a standard std::bad_alloc();
    // Reference: https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm#:~:text=A%20C%2B%2B%20exception%20is%20a,try%2C%20catch%2C%20and%20throw.

    throw std::bad_alloc();

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    return true;
}


//NOTE: I tried creating this custom exception within do_custom_application_logic(). 
//However, this caused issues. It only works when I create it outside of the function.
struct ZaneException : public std::exception {
    const char* what() const throw() {
        return "Zane's Custom error exception";
    }
};

void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    // 
    // COMPLETED: call is wrapped with a TRY and CATCH handler to detect the badalloc exception.
    //            When the exception is found, an error message will display.
    // Reference: https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm#:~:text=A%20C%2B%2B%20exception%20is%20a,try%2C%20catch%2C%20and%20throw.

    std::cout << "Running Custom Application Logic." << std::endl;

    try {
        if (do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    catch (const std::exception& e) {
        //handle the exception
        std::cout << "Error: detecting exception..." << e.what() << std::endl;

    }
    // TODO: Throw a custom exception derived from std::exception
    //  and catch it explictly in main
    // 
    //COMPLETED: Custom exception created above is called here.
    throw ZaneException();
    std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception

    // COMPLETED: Using IF statement to detect if den is 0 and to throw a runtime_error exception if 0 is detected.
    // Referece: https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm#:~:text=A%20C%2B%2B%20exception%20is%20a,try%2C%20catch%2C%20and%20throw.

    if (den == 0) {
        throw std::runtime_error("Error: You are not allowed to divide by ZERO!");
    }
    return (num / den);
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.

    // COMPLETED: Using TRY and CATCH handler to detect a problem in the divide() function.
    // Reference: https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm#:~:text=A%20C%2B%2B%20exception%20is%20a,try%2C%20catch%2C%20and%20throw.

    float numerator = 10.0f;
    float denominator = 0;

    try {
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    catch (const std::exception &msg) {
        std::cout << "Error: EXCEPTION DETECTED" << msg.what() << std::endl;
    }

    
}

int main()
{

    // TODO: Create exception handlers that catch (in this order):
    //  your custom exception
    //  std::exception
    //  uncaught exception 
    //  that wraps the whole main function, and displays a message to the console.

    //COMPLETED: Exceptions are found using TRY and CATCH handlers.
    //Reference: https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm#:~:text=A%20C%2B%2B%20exception%20is%20a,try%2C%20catch%2C%20and%20throw.


    try {
        std::cout << "Exceptions Tests!" << std::endl;

        do_division();
        do_custom_application_logic();
    }
    catch (const ZaneException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (...) {

    }
    

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu