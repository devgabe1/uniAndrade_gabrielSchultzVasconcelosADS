class Personagem:
    def __init__(self, nome):
        self.nome = nome
        self.saude = 60
        self.vivo = True
        
    def usar_pocao(self, pocao):
        if (self.vivo == False):
            print(f"Personagem está MORTO, não é possível usar nenhuma poção.")
            return
        
        print(f"Personagem {self.nome} usou poção {pocao.tipo}")
        print(f"Saude antes da poção: {self.saude}")
        
        if (pocao.tipo == "Cura"):
            self.saude += pocao.potencia
            print(f"Cura concedida: {pocao.potencia}\nTotal de saúde: {self.saude}\n")
        
        elif (pocao.tipo == "Dano"):
            self.saude -= pocao.potencia
            if self.saude <= 0:
                self.vivo = False
                print(f"Personagem {self.nome} morreu ao tomar a poção.")
                return
            
            print(f"Dano aplicado: {pocao.potencia}\nTotal de saúde: {self.saude}\n")
            
class PocaoVerde:
    def __init__(self, tipo, potencia):
        self.tipo = tipo
        self.potencia = potencia
        
class PocaoRoxa:
    def __init__(self, tipo, potencia):
        self.tipo = tipo
        self.potencia = potencia

p1 = Personagem("Pao")
pocaoTop = PocaoVerde("Cura", 20)
pocaoPaia = PocaoRoxa("Dano", 20)


p1.usar_pocao(pocaoTop)
p1.usar_pocao(pocaoPaia)
p1.usar_pocao(pocaoPaia)
p1.usar_pocao(pocaoPaia)
p1.usar_pocao(pocaoPaia)
p1.usar_pocao(pocaoTop)



