import cs50

while True:
    print("O hai! How much change is owed?")
    amount = cs50.get_float()
    if amount >= 0:
        break

noc = 0
cents = int(round(amount * 100))

noc += cents // 25
cents %= 25

noc += cents // 10
cents %= 10

noc += cents // 5
cents %= 5

noc += cents

print("{}".format(noc))