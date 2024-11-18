"""
Pyetest for bank class.
Author: Alex Breger
Reviewed by: Hananya Templeman
"""


import pytest
from ex1 import BankAccount

@pytest.fixture
def test_account():
    return BankAccount("test_account")

def test_init(test_account):
    assert test_account.id == "test_account"
    assert test_account.balance == 0

def test_deposit(test_account):
    assert test_account.deposit(100)
    assert test_account.balance == 100

def test_withdraw(test_account):
    test_account.deposit(100)
    assert test_account.withdraw(100)
    assert test_account.balance == 0

