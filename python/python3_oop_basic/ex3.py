import time
import uuid
from datetime import datetime


class Service:
    def __init__(self):
        self.__machines = {}

    def insert_machine(self, machine):
        if machine.uid not in self.__machines:
            self.__machines[machine.uid] = machine

    def calculate_cost(self):
        total_cost = 0
        for machine_id_num in self.__machines:
            if self.__machines[machine_id_num].machine_type == 1:
                total_cost = total_cost + (self.__machines[machine_id_num].up_time() * 2)
            elif self.__machines[machine_id_num].machine_type == 2:
                total_cost = total_cost + (self.__machines[machine_id_num].up_time() * 5)
        return total_cost

    def turn_machine_off_on(self, machine_id_num):
        self.__machines[machine_id_num].change_state()

    def _str_(self):
        for machine in self.__machines.values():
            return f"{machine.uid} : {machine.machine_type} : {machine.up_time()}"


class Machine:
    def __init__(self, machine_type=None):
        self.__machine_type = machine_type
        self.__init_time = datetime.now()
        self.__state = 0
        self.__total_time = 0
        self.__machine_id = str(uuid.uuid4())

    @property
    def machine_type(self):
        return self.__machine_type

    @machine_type.setter
    def machine_type(self, value):
        self.__machine_type = value

    @machine_type.getter
    def machine_type(self):
        return self.__machine_type

    @property
    def init_time(self):
        return self.__init_time

    @init_time.getter
    def init_time(self):
        return self.__init_time

    @property
    def state(self):
        return self.__state

    @state.setter
    def state(self, value):
        if value == 0:
            self.__total_time = self.total_time + (datetime.now() - self.__init_time).total_seconds()
        elif value == 1:
            self.__init_time = datetime.now()

        self.__state = value

    @state.getter
    def state(self):
        return self.__state

    @property
    def uid(self):
        return self.__machine_id

    @uid.getter
    def uid(self):
        return self.__machine_id

    @property
    def total_time(self):
        return self.total_time

    @state.getter
    def total_time(self):
        return self.__total_time

    def up_time(self):
        if self.__state == 1:
            difference_up_time = datetime.now() - self.__init_time
            time_in_seconds = difference_up_time.total_seconds()
        else:
            time_in_seconds = self.__total_time

        return time_in_seconds / 60

    def change_state(self):
        if self.__state == 0:
            self.state = 1

        elif self.__state == 1:
            self.state = 0


machines_list = []

machineA = Machine(1)
machineB = Machine(1)
machineC = Machine(1)
machineD = Machine(2)

machines_list.append(machineA)
machines_list.append(machineB)
machines_list.append(machineC)
machines_list.append(machineD)

service = Service()

for machine_id in machines_list:
    service.insert_machine(machine_id)
    service.turn_machine_off_on(machine_id.uid)

time.sleep(10)

machineE = Machine(2)
service.insert_machine(machineE)
service.turn_machine_off_on(machineE.uid)

time.sleep(10)

service.turn_machine_off_on(machineB.uid)
time.sleep(10)

print(service.calculate_cost())