"""
Unittest for bank class.
Author: Alex Breger
Reviewed by: Hananya Templeman
"""


import unittest

from ex1 import BankAccount


class TestBankAccount(unittest.TestCase):
    def setUp(self):
        self.account = BankAccount("test_account")

    def test_init(self):
        self.assertEqual(self.account.id, "test_account")
        self.assertEqual(self.account.balance, 0)

    def test_deposit(self):
        self.assertTrue(self.account.deposit(100))
        self.assertEqual(self.account.balance, 100)

    def test_withdraw(self):
        self.account.deposit(100)

        self.assertTrue(self.account.withdraw(50))
        self.assertEqual(self.account.balance, 50)

        self.assertTrue(self.account.withdraw(50))
        self.assertEqual(self.account.balance, 0)


    def tearDown(self):
        del self.account

if __name__ == '__main__':
    unittest.main()
