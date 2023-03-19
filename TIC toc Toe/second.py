import os


def printBoard(XState=[], ZState=[]) -> None:

    zero = 'X' if XState[0] else ('O' if ZState[0] else 0)
    one = 'X' if XState[1] else ('O' if ZState[1] else 1)
    two = 'X' if XState[2] else ('O' if ZState[2] else 2)
    three = 'X' if XState[3] else ('O' if ZState[3] else 3)
    four = 'X' if XState[4] else ('O' if ZState[4] else 4)
    five = 'X' if XState[5] else ('O' if ZState[5] else 5)
    six = 'X' if XState[6] else ('O' if ZState[6] else 6)
    seven = 'X' if XState[7] else ('O' if ZState[7] else 7)
    eight = 'X' if XState[8] else ('O' if ZState[8] else 8)

    print(f' {zero} | {one} | {two} ')
    print('---|---|----')
    print(f' {three} | {four} | {five} ')
    print('---|---|----')
    print(f' {six} | {seven} | {eight} ')
    pass


def checkWin(x=[], z=[]) -> bool:
    if x[0]+x[1]+x[2] == 3 or x[3]+x[4]+x[5] == 3 or x[6]+x[7]+x[8] == 3 or x[0]+x[3]+x[6] == 3 or x[1]+x[4]+x[7] == 3 or x[2]+x[5]+x[8] == 3 or x[0]+x[4]+x[8] == 3 or x[2]+x[4]+x[6] == 3:
        os.system('cls')
        print("X Win Match...")
        printBoard(x, z)
        return True

    elif z[0]+z[1]+z[2] == 3 or z[3]+z[4]+z[5] == 3 or z[6]+z[7]+z[8] == 3 or z[0]+z[3]+z[6] == 3 or z[1]+z[4]+z[7] == 3 or z[2]+z[5]+z[8] == 3 or z[0]+z[4]+z[8] == 3 or z[2]+z[4]+z[6] == 3:
        os.system('cls')
        print("O Win Match...")
        printBoard(x, z)
        return True

    elif sum(x)+sum(z) == 9:
        os.system('cls')
        print("draw match ...")
        printBoard(x, z)
        return True
    return False


def Xturn(x=[], z=[]) -> None:
    try:
        X = int(input("Enter Value of Chance Of X :"))
        if z[X] == 0:
            x[X] = 1
        else:
            print("This Place Already feel! try to choice another place...")
            Xturn(x, z)
    except:
        print("Please enter correct value ...")
        Xturn(x, z)


def Zturn(x=[], z=[]) -> None:
    try:
        O = int(input("Enter Value of Chance Of O :"))
        if x[O] == 0:
            z[O] = 1
        else:
            print("This Place Already feel! try to choice another place...")
            Zturn(x, z)
    except:
        print("Please enter correct value ...")
        Zturn(x, z)


if __name__ == '__main__':
    xstate = [0 for i in range(9)]
    zstate = [0 for i in range(9)]
    turn = 1
    os.system('cls')
    print("Welcome to tic tac Toe Game !")
    printBoard(xstate, zstate)
    while True:
        if turn == 1:
            Xturn(xstate, zstate)
            turn = 0
            printBoard(xstate, zstate)

        elif turn == 0:
            Zturn(xstate, zstate)
            turn = 1
            printBoard(xstate, zstate)

        if (checkWin(xstate, zstate)):
            break

    input("How is The Josh ...")
    print("X : ", xstate)
    print("O : ", zstate)
