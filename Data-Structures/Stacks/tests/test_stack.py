import unittest
from stack import Stack

class StackTest(unittest.TestCase):
    def setUp(self):
        self.simple_stack = Stack()

    def test_stack_push(self):
        self.assertEqual(self.simple_stack.isEmpty(), True)
        self.simple_stack.push(20)
        self.assertEqual(self.simple_stack.isEmpty(), False)

    def test_stack_pop(self):
        self.simple_stack.push('item')
        stack_size = self.simple_stack.size()
        self.assertEqual(self.simple_stack.pop(), 'item')
        self.assertNotEqual(self.simple_stack.size(), stack_size)
        self.assertEqual(self.simple_stack.size(), stack_size - 1)

    def test_stack_peek_returns_last_item(self):
        self.simple_stack.push('last')
        self.assertEqual(self.simple_stack.peek(), 'last')

    def test_stack_is_not_empty_after_push(self):
        self.simple_stack.push(10)
        self.assertFalse(self.simple_stack.isEmpty())

    def test_popping_beyond_stack_size(self):
        self.simple_stack.push(20)
        self.simple_stack.pop()
        with self.assertRaises(IndexError):
            self.simple_stack.pop()
