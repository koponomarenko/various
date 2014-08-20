#! /usr/bin/env python3

# example of doc-strings
"""

This is a docstring describing this python file (module).

You may briefly describe the classes, etc.

"""


class ASimpleClass:

    """A Simple Class that does nothing. OK?

    Here you may briefly describe the class,
    it's purpose, public attributes, etc.
    """

    a_static = 'blah'

    def __init__(self, name):
        """The __init__ method for ASimpleClass.

        The __init__ method sets the initial values
        for ASimpleClass attributes, may perform 
        some initial checks, like platform, etc.
        """
        var = 'attribute'
        self.a = var + " 'a'"
        self.b = var + ' "b"'
        self.name = name

    def say_hello(self):
        """This method will print something.
        """
        print(self.__doc__)
        print(self.__init__.__doc__)
        print(__doc__)
        print("Hello, " + self.name)
        print(self.a)
        print(self.b)
        print(self.a_static)


if __name__ == '__main__':
    print(__doc__)

    a = ASimpleClass('Kostya')
    a.say_hello()