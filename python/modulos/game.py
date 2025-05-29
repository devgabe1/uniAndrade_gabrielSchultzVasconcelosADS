# from itens import arma, armadura, pocao
# from itens import *
from itens import Pocao, Arma, Armadura



def main():
    faca = Arma("CORTANTE D+")
    pocaoTop = Pocao("QUE CURA MT")
    armaduraFile = Arma("INDESTRUTÍVEL")

    faca.usar()
    pocaoTop.usar()
    armaduraFile.usar()

if __name__ == "__main__":
    main()