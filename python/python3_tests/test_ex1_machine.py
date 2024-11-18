"""
Unittest for machine service.
Author: Alex Breger
Reviewed by: Hananya Templeman
"""



from datetime import datetime

import pytest

from machine import Machine, Service


@pytest.fixture
def machine():
    return Machine("1")

@pytest.fixture
def service():
    return Service()

def test_init_machine():
    machine = Machine(1)
    assert machine.machine_type == 1
    assert isinstance(machine.uid, str)
    assert isinstance(machine.init_time, datetime)
    assert machine.total_time == 0

def test_state_change(machine):
    assert machine.state == 0
    machine.change_state()
    assert machine.state == 1
    machine.change_state()
    assert machine.state == 0

def test_service_turn_on_off(service,machine):
    machine1 = Machine(1)

    service.insert_machine(machine1)

    service.turn_machine_off_on(machine1.uid)

    assert machine1.state == 1

    service.turn_machine_off_on(machine1.uid)

    assert machine1.state == 0
