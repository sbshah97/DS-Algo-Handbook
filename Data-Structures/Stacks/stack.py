"""Implementation of a stack in python."""


class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        """Add an item to the stack."""
        self.items.append(item)

    def pop(self):
        """Remove the most recent item from the stack."""
        if len(self.items) > 0:
            last = self.items[-1]
            del(self.items[-1])
            return last
        else:
            raise IndexError

    def peek(self):
        """Return the most recent item to be pushed to the stack."""
        return self.items[-1]

    def isEmpty(self):
        """Returns True if stack is empty ."""
        return not len(self.items) >= 1

    def size(self):
        """Return the size of the stack."""
        return len(self.items)
