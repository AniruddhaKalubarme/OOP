def Deposite(balance, amount):
    balance += amount
    return balance

def Withdraw(balance, amount):
    if(amount<=balance):
        balance -= amount
        return balance
    else:
        print("Not enoughf bank balance")

def Balance(balance):
    return balance

def main():
    trans = input("Enter the transition: ").split(",")
    balance = 0
    for i in trans:
        i = i.strip()
        if(i.startswith("W")):
            amount = int(i.split()[1])
            balance = Withdraw(balance, amount)
        elif(i.startswith("D")):
            amount = int(i.split()[1])
            balance = Deposite(balance, amount)

    print("Account Balance is : ",Balance(balance))

main()