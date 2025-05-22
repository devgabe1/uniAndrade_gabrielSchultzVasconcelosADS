class Personagem:
    def __init__(self, nome, nome_armadura:str, protecao:int):
        self.nome = nome
        self.saude = 60
        self.vivo = True
        self.armadura = Armadura(nome_armadura, protecao) # Composição
        self.Inventario = Inventario() # Agregação
        
    def usar_pocao(self, pocao):
        if (self.vivo == False):
            print(f"Personagem está MORTO, não é possível usar nenhuma poção.")
            return
        
        print(f"Personagem {self.nome} usou poção {pocao.tipo}")
        print(f"Saude antes da poção: {self.saude}")
        
        if (pocao.tipo == "Cura"):
            if self.saude >=100:
                self.saude = 100
                print(f"Personagem {self.nome} já possui a vida máxima.")
                return
                
            self.saude += pocao.potencia
            print(f"Cura concedida: {pocao.potencia}\nTotal de saúde: {self.saude}\n")
        
        elif (pocao.tipo == "Dano"):
            self.saude -= pocao.potencia
            if self.saude <= 0:
                self.saude = 0
                self.vivo = False
                print(f"Personagem {self.nome} morreu ao tomar a poção.")
                return
            print(f"Dano aplicado: {pocao.potencia}\nTotal de saúde: {self.saude}\n")
            
class Inventario:
    def __init__(self):
        self.itens =[] # Agregação
    
    def adicionarItem(self, item: Item):
        if not item:
            print("Escolha um item para pegar:  ")
        self.itens.append(item)
        
    def abrirInventario(self):
        for item in self.itens:
            print(f"Item: {item.tipo}\n")
            
class Armadura:
    def __init__(self, nome:str, protecao: int):
        self.nome = nome
        self.protecao = protecao
    
    def blindar(self):
        print(f"Sua proteção foi aumentada!")
        
class PocaoVerde:
    def __init__(self, tipo, potencia):
        self.tipo = tipo
        self.potencia = potencia
        
class PocaoRoxa:
    def __init__(self, tipo, potencia):
        self.tipo = tipo
        self.potencia = potencia
        
class Item:
    def __init__(self, tipo: str, poder: int):
        self.tipo = tipo
        self.poder = poder
        


p1 = Personagem("Pao", "Armadura de Prata", 30)
pocaoTop = PocaoVerde("Cura", 20)
pocaoPaia = PocaoRoxa("Dano", 20)
inventario = Inventario()
espadaLendaria = Item("Espada Lendária", 99999)
escudoQuebrado = Item("Escudo do vagabundo", 0)

inventario.adicionarItem(espadaLendaria)
inventario.adicionarItem(escudoQuebrado)
inventario.abrirInventario()
print(p1.__dict__)
# p1.usar_pocao(pocaoPaia)
# p1.usar_pocao(pocaoPaia)
# p1.usar_pocao(pocaoPaia)
# p1.usar_pocao(pocaoPaia)
# p1.usar_pocao(pocaoPaia)
# p1.usar_pocao(pocaoTop)


