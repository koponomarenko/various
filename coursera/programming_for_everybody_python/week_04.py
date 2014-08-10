# Write a program to prompt the user for hours and rate per hour using raw_input to compute gross pay. Award time-and-a-half for the hourly rate for all hours worked above 40 hours. Put the logic to do the computation of time-and-a-half in a function called computepay() and use the function to do the computation. The function should return a value. Use 45 hours and a rate of 10.50 per hour to test the program (the pay should be 498.75). You should use raw_input to read a string and float() to convert the string to a number. Do not worry about error checking the user input unless you want to - you can assume the user types numbers properly.


def computepay(hours, rate):
    week_hours = 40
    over_rate = 1.5
    salary = 0

    if hours > week_hours:
        over_hours = hours - week_hours
        salary = (week_hours * rate) + (over_hours * rate * over_rate)
    else:
        salary = hours * rate

    return salary


hours = raw_input("Enter Hours:")
hours = float(hours)
rate = raw_input("Enter rate:")
rate = float(rate)

print computepay(hours, rate)
